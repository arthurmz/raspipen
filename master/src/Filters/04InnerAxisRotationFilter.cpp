#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdio>
#include <math.h>
#include "Physics/Physics.h"

#define G_FORCE_X 4000
#define G_FORCE_Y 4000
#define G_FORCE_Z 4000
#define PI 3.141592653589793
 
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
	

	float wt_gravityX = AccX * cos(PI*EulerY/180) * cos(PI*EulerZ/180);
	float wt_gravityY = AccY * cos(PI*EulerX/180) * cos(PI*EulerZ/180);
	float wt_gravityZ = AccZ * cos(PI*EulerX/180) * cos(PI*EulerY/180);
    
    	cout << setiosflags(ios::fixed) << setprecision(10) << wt_gravityX << " " << wt_gravityY << " " << wt_gravityZ <<  "\n"; 
 
	}
 }
  
 return 0; 
}

