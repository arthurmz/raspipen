#include <iostream>
#include <cstdio>
#include <iomanip>
#include <math.h>
#include "Physics/Physics.h"
#include "../DataSource/MPU6050-Pi-Demo/SixDegreesOfFreedom.h"
#include "../DataSource/MPU6050-Pi-Demo/demo_dmp.h"

#define PI 3.141592653589793
#define G_FORCE_X 4300
#define G_FORCE_Y 4300
#define G_FORCE_Z 4300

using namespace std;


SixDegreesOfFreedom calculeVelocidadeReal(SixDegreesOfFreedom inp){
	
	SixDegreesOfFreedom out;
	out.EX = inp.EX;
	out.EY = inp.EY;
	out.EZ = inp.EZ;
	out.AX = realAcceleration(inp.AX, G_FORCE_X);
        out.AY = realAcceleration(inp.AY, G_FORCE_Y);
        out.AZ = realAcceleration(inp.AZ, G_FORCE_Z);
	//cout << "Callback " << out.EX << " "  << out.EY << " " << out.EZ << " " << out.AX << " " << out.AY << " " << out.AZ;

	return out;
}

SixDegreesOfFreedom removeAceleracaoGravidade(SixDegreesOfFreedom inp){
	
	//Definindo o vetor de gravidade de acordo com a orientação
	
	float gx = G_FORCE * cos(PI* inp.EY/180) * cos(PI * inp.EZ/180);
	float gy = G_FORCE * cos(PI* inp.EX/180) * cos(PI * inp.EZ/180);
	float gz = G_FORCE * cos(PI* inp.EX/180) * cos(PI * inp.EY/180);//ok
	
	//Subtraindo a gravidade da aceleração lida
	SixDegreesOfFreedom out;
	out.EX = inp.EX;
	out.EY = inp.EY;
	out.EZ = inp.EZ;
	out.AX = inp.AX - gx;
	out.AY = inp.AY - gy;
	out.AZ = inp.AZ - gz;
	
	cout << setiosflags(ios::fixed) << setprecision(2) << "input " << inp.EX << " "  << inp.EY << " " << inp.EZ << " " << inp.AX << " " << inp.AY << " " << inp.AZ;
        cout << setiosflags(ios::fixed) << setprecision(2) << " output " << out.EX << " "  << out.EY << " " << out.EZ << " " << out.AX << " " << out.AY << " " << out.AZ;

	return out;

}

//Recebe como entrada os 3 angulos de orientação e o vetor de deslocamento
//A saída é o vetor de deslocamento ajustado de acordo com orientação do sensor
SixDegreesOfFreedom compensaVetorDeslocamento(SixDegreesOfFreedom inp){

        SixDegreesOfFreedom out;
        out.EX = inp.EX;
        out.EY = inp.EY;
        out.EZ = inp.EZ;
        out.AX = inp.AX * cos(PI * inp.EY/180) * cos(PI * inp.EZ/180);
        out.AY = inp.AY * cos(PI * inp.EX/180) * cos(PI * inp.EZ/180);
        out.AZ = inp.AZ * cos(PI * inp.EX/180) * cos(PI * inp.EY/180);


        //cout << setiosflags(ios::fixed) << setprecision(2) << "input " << inp.EX << " "  << inp.EY << " " << inp.EZ << " " << inp.AX << " " << inp.AY << " " << inp.AZ;
	//cout << setiosflags(ios::fixed) << setprecision(2) << " output " << out.EX << " "  << out.EY << " " << out.EZ << " " << out.AX << " " << out.AY << " " << out.AZ;

        return out;
}


	
void test(SixDegreesOfFreedom sixDoF){
        //cout << "Callback " << sixDoF.EX << " "  << sixDoF.EY << " " << sixDoF.EZ << " " << sixDoF.AX << " " << sixDoF.AY << " " << sixDoF.AZ;
        removeAceleracaoGravidade ( calculeVelocidadeReal(sixDoF) );
}

int main (){

void (*callback)(SixDegreesOfFreedom);
callback = &test;

StartReading(callback);

return 0;
}
