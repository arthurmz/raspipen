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
pthread_cond_t conditionSignal;//Signal telling that a state changed

SixDegreesOfFreedom actualReading;

void Producer(SixDegreesOfFreedom d){

	pthread_mutex_lock(&mutex);

	actualReading = d;

	pthread_cond_signal(&conditionSignal);
	pthread_mutex_unlock(&mutex);
}

void * consumer(void* arg){
	while(true){
		pthread_mutex_lock(&mutex);

		pthread_cond_wait(&conditionSignal,&mutex);
		std::cout << "Consuming: " << actualReading.EX << " " << actualReading.EY << " " << actualReading.EZ << " " << actualReading.AX
			<< " " << actualReading.AY << " " << actualReading.AZ << "\n";
		
		SixDegreesOfFreedom actualReadingOut = removeAceleracaoGravidade(actualReading);

		std::cout << "ConsumingProcessed: " << actualReadingOut.EX << " " << actualReadingOut.EY << " " << actualReadingOut.EZ << " " << actualReadingOut.AX
			<< " " << actualReadingOut.AY << " " << actualReadingOut.AZ << "\n";
		pthread_mutex_unlock(&mutex);
	}
}

void *startSensor(void* arg){
	//Here we start the sensor passing the callback function to handle the raw values
	//should be passed a funcion with pattern: void (*) SixDegreesOfFreedom
	GyroscopeStartReading(&Producer);
}


int main() {

	pthread_mutex_init(&mutex,0);
	pthread_cond_init(&conditionSignal,0);

	pthread_t producerThread;
	pthread_t consumerThread;

	pthread_create(&producerThread,0,startSensor,0);
	pthread_create(&consumerThread,0,consumer,0);

	pthread_join(producerThread,NULL);
	pthread_join(consumerThread,NULL);

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&conditionSignal);

return 0;
}

