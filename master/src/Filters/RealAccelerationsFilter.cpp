#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include "Physics/Physics.h"

#define G_FORCE_X 4000
#define G_FORCE_Y 4000
#define G_FORCE_Z 4000

using namespace std;


/*
 *
 * Dados esperados:
 * ângulo de euler x, y, z
 * aceleração em valores brutos x, y, z
 *
 * Os ângulos vão de -180 até 180. Sendo 0 quando o sensor está posicionado totalmente na horizontal.
 *
 * As acelerações são centradas em 0, de modo que uma aceleração positiva é um numero positivo,
 * assim como uma aceleração negativa é de fato um número negativo.
 *
 * Ex: "1.1 0.0 3.4 400 -500 202" é uma entrada válida
 *      999 999 2.9 300 -345 223" é inválida (angulo maior que 180)
 */

int main(){

  while(true){//Processa os dados indefinidamente.
       
    string str;
    getline (cin,str);

    float EulerX, EulerY, EulerZ, AccX, AccY, AccZ;
    
    sscanf(str.c_str(), "%f %f %f %f %f %f", &EulerX, &EulerY, &EulerZ, &AccX, &AccY, &AccZ);

    float RealX = realAcceleration(AccX, G_FORCE_X);
    float RealY = realAcceleration(AccY, G_FORCE_Y);
    float RealZ = realAcceleration(AccZ, G_FORCE_Z);
    
    cout << EulerX << " " << EulerY << " " << EulerZ << " " << RealX << " " << RealY << " " << RealZ << "\n"; 
  }
  
 return 0; 
}

