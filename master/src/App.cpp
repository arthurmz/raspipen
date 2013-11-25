#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <Gyroscope.h>
#include <ProcessGyroscopeData.h>
#include <SixDegreesOfFreedom.h>
#include <ThreeDegreesOfFreedom.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

ThreeDegreesOfFreedom bufferProcessedData[100];
ThreeDegreesOfFreedom actualState;

int length = 0;

void Producer(SixDegreesOfFreedom d){
	//Process the data from a SixDegreesOfFreedom type to a ThreeDegreesOfFreedom type (xyz relative position)
	ThreeDegreesOfFreedom relativePosition = ProcessGyroscopeData(d);
	pthread_mutex_lock(&mutex);
	//bufferProcessedData[length++] = relativePosition;
	actualState = relativePosition;
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&mutex);		
}


void Consumer(){
	
}

void *startSensor(void* arg){
	//Here we start the sensor passing the callback function to handle the raw values
	//should be passed a funcion with pattern: void (*) SixDegreesOfFreedom
	GyroscopeStartReading(&Producer);
}


int main() {
	
	/*Starting the sensor's thread*/
	pthread_t sensorThread;
	int result;
	result = pthread_create(&sensorThread, NULL, startSensor, NULL);
	if(result != 0 ){
		std::cout << "Thread start got wrong";
	}
	pthread_join(sensorThread,NULL);
	pthread_exit(NULL);
	
return 0;
}

