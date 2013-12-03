#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <queue>
#include <Gyroscope.h>
#include <ProcessGyroscopeData.h>
#include <SixDegreesOfFreedom.h>
#include <ThreeDegreesOfFreedom.h>


//==============================================
//variáveis de estado do sistema

bool gravando = false;

std::queue<SixDegreesOfFreedom> dataHolder; 

pthread_mutex_t mutex;

pthread_cond_t conditionSignal;//Signal telling that a state changed

//==============================================


//Chamado a partir da thread do giroscópio, cada vez que um novo valor for gerado.
void callbackThreadFunction(SixDegreesOfFreedom d){
    if(gravando){
      pthread_mutex_lock(&mutex);
      
      dataHolder.push(d);

      pthread_cond_signal(&conditionSignal);
      
      pthread_mutex_unlock(&mutex);
    }
}
/*
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
*/

//Thread do giroscópio, inicia o módulo e faz chamadas regulares a callbackThreadFunction
void *gyroscopeThread(void* arg){
  //Inicia o módulo do giroscópio
  GyroscopeStartReading(&callbackThreadFunction);
}


void HandleUserInput(){
  
  while(true){
    char c;
    std::cin.get(c);
    
    if (c == 'r'){
      gravando = true;
      std::cout << "Iniciou a gravação\n";
    }
    else if (c == 's'){
      gravando = false;
      std::cout << "Parou de gravar\n";
    }
  }
  
}


int main() {
  
  //Cria a thread do giroscópio
  pthread_t my_thread;
  int ret;
  ret =  pthread_create(&my_thread, NULL, &gyroscopeThread, NULL);
  if(ret != 0) {
  printf("Error: pthread_create() failed\n");
    exit(EXIT_FAILURE);
  }
  
  
  HandleUserInput();
  
  pthread_exit(NULL);
  return 0;
}


