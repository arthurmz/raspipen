#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "Gyroscope.h"
#include <iostream>

void *startSensor(void* arg){
	Gyroscope gyro;
	gyro.start();
}

int main() {
	
	/*Turn on the thread sensor*/
	pthread_t sensor;
	int result;
	result = pthread_create(&sensor, NULL, startSensor, NULL);
	if(result != 0 ){
		std::cout << "Thread start got wrong";
	}
	pthread_exit(NULL);
	
return 0;
}
