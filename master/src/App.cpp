#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Gyroscope/Gyroscope.h"
#include <iostream>

void *startSensor(void* arg){
	Gyroscope gyro;
	gyro.start();
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

