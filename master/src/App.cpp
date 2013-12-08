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
#include <ImageGenerator.h>
#include <EasyBMP.h>
#include <ConverteAceleracaoReal.h>

//==============================================
//variáveis de estado do sistema

bool gravando;

std::queue<SixDegreesOfFreedom> dataHolder; 

pthread_mutex_t mutex;

//==============================================

int chamadas = 0;
//Chamado a partir da thread do giroscópio, cada vez que um novo valor for gerado.

void callbackThreadFunction(SixDegreesOfFreedom d){

//Por algum motivo insano, o código só funciona se imprimir as mensagems
//usleep(1) não funciona.
    if(gravando){
	//std::cout << "Gravando\n";
      pthread_mutex_lock(&mutex);

      dataHolder.push(d);

      pthread_mutex_unlock(&mutex);
	chamadas = 0;
    }
    else if (chamadas < 1){
     std::cout << "-----------Parou\n";
	chamadas++;
    }
}

//Thread do giroscópio, inicia o módulo e faz chamadas regulares a callbackThreadFunction
void *gyroscopeThread(void* arg){
  GyroscopeStartReading(&callbackThreadFunction);
}


void HandleUserInput(){


std::cout << "Raspipen, Ver 1.5\n";
  while(true){
	if(!gravando){
	
	std::cout << "\nPara gravar, pressione 'r' seguido da tecla Enter: ";
	}
	else{
	std::cout << "\nPara Parar a gravação, pressione 's' seguido da tecla Enter: ";
	}
    char c;
    std::cin >> c;

	if(c == 'r'){
		gravando = true;
		std::cout << "Iniciou a gravação\n";
	}
	else if ( c == 's'){
		gravando = false;
		std::cout << "\nParando a gravação, inciando processamento da imagem, aguarde... ";
		BMP bmp;
		GenerateImage(&bmp,dataHolder);
		std::cout << "Concluído\nImagem criada com o titulo \"teste.bmp\"";
		dataHolder = std::queue<SixDegreesOfFreedom>();
	}
  }
  
}


int main() {
  
  /*gravando = false;

  //Cria a thread do giroscópio
  pthread_t my_thread;
  int ret;
  ret =  pthread_create(&my_thread, NULL, &gyroscopeThread, NULL);
  if(ret != 0) {
  printf("Error: pthread_create() failed\n");
    exit(EXIT_FAILURE);
  }
  
  HandleUserInput();
  
  pthread_exit(NULL);*/


SixDegreesOfFreedom sgs;
sgs.AX = 33;
dataHolder.push(sgs);
  Pipe<SixDegreesOfFreedom> inp(dataHolder);
  Pipe<SixDegreesOfFreedom> out;

  ConverteAceleracaoReal conversor(inp,out);

  conversor.startFiltering();
dataHolder = out.getBuffer();

SixDegreesOfFreedom sixf = dataHolder.front();

std::cout << sixf.AX << "\n";
  
  return 0;
}


