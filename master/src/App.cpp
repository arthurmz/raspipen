#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <Gyroscope.h>
#include <SixDegreesOfFreedom.h>

void ProcessData(SixDegreesOfFreedom d){
	std::cout << d.EX << "\n";	
}

void *startSensor(void* arg){
	int value;
	//Here should be passed a funcion with pattern: void (*) SixDegreesOfFreedom
	GyroscopeStartReading(&ProcessData);
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

