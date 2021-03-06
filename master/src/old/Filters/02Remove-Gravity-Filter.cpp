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
 * vetor de acelerações
 *
 * Os ângulos vão de -180 até 180. Sendo 0 quando o sensor está posicionado totalmente na horizontal.
 *
 * 
 * Saída: angulos inalterados, 
 * acelerações compensadas, removendo o efeito da gravidade.
 */

int main(){

  while(true){//Processa os dados indefinidamente.
       
    	string str;
    	getline (cin,str);

    	float EulerX, EulerY, EulerZ, AccX, AccY, AccZ;
    
    	if (sscanf(str.c_str(), "%f %f %f %f %f %f", &EulerX, &EulerY, &EulerZ, &AccX, &AccY, &AccZ) == 6){
	

	float wt_gravityX = AccX * cos(EulerY) * cos(EulerZ);
	float wt_gravity
	
	float wt_gravityZ = AccZ - ( (G_FORCE_Z * 90/EulerY)*(G_FORCE_Y * 90/EulerX) );
	float wt_gravityY = AccY - (G_FORCE_Y * 180/
	



    	float RealX = realAcceleration(AccX, G_FORCE_X);
    	float RealY = realAcceleration(AccY, G_FORCE_Y);
    	float RealZ = realAcceleration(AccZ, G_FORCE_Z);
    
    	cout << EulerX << " " << EulerY << " " << EulerZ << " " << RealX << " " << RealY << " " << RealZ << "\n"; 
 
	}
 }
  
 return 0; 
}

