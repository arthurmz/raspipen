#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include "Physics.h"

#define G_FORCE_X 4000
#define G_FORCE_Y 4000
#define G_FORCE_Z 4000

using namespace std;


/*
 *
 * Dados esperados:
 * ângulo de euler x, y, z
 * aceleração em milimetros por segundo ao quadrado x, y, z
 *
 * Os ângulos vão de -180 até 180. Sendo 0 quando o sensor está posicionado totalmente na horizontal.
 *
 * As acelerações são centradas em 0, de modo que uma aceleração positiva é um numero positivo,
 * assim como uma aceleração negativa é de fato um número negativo.
 * 
 * Saída: os 3 ângulos inalterados
 * O vetor de deslocamento x,y,z
 */

int main(){

  while(true){//Processa os dados indefinidamente.
    
    string str;
    getline (cin,str);

    float EulerX, EulerY, EulerZ, AccX, AccY, AccZ;
    
    sscanf(str.c_str(), "%f %f %f %f %f %f", &EulerX, &EulerY, &EulerZ, &AccX, &AccY, &AccZ);
   
    //Calculando o vetor deslocamento com base na aceleração pra cada eixo
    //A base de tempo é 1 segundo / taxa de leitura (20Hz)
    float * deslVector = deslVectorial(0, 0.05, AccX, AccY, AccZ);
    
    cout << EulerX << " " << EulerY << " " << EulerZ << " " << deslVector[0] << " " << deslVector[1] << " " << deslVector[2] << "\n";
  }
  
 return 0; 
}






