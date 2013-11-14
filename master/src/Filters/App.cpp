#include <iostream>
#include <cstdio>
#include <iomanip>
#include <math.h>
#include "Physics/Physics.h"
#include "../DataSource/MPU6050-Pi-Demo/SixDegreesOfFreedom.h"
#include "../DataSource/MPU6050-Pi-Demo/demo_dmp.h"

#define PI 3.141592653589793
//Definindo os valores de aceleração 1G
#define GYRO_G_FORCE_X 4300
#define GYRO_G_FORCE_Y 4300
#define GYRO_G_FORCE_Z 4300

//Soma será aplicado a cada ângulo, já que o mesmo pode estar desalinhado com o acelerometro
#define OFFSET_ANGLE_X 0
#define OFFSET_ANGLE_Y 0
#define OFFSET_ANGLE_Z 0

using namespace std;


SixDegreesOfFreedom calculeVelocidadeReal(SixDegreesOfFreedom inp){
	
	SixDegreesOfFreedom out;
	out.EX = inp.EX;
	out.EY = inp.EY;
	out.EZ = inp.EZ;
	out.AX = realAcceleration(inp.AX, GYRO_G_FORCE_X);
        out.AY = realAcceleration(inp.AY, GYRO_G_FORCE_Y);
        out.AZ = realAcceleration(inp.AZ, GYRO_G_FORCE_Z);
	//cout << "Callback " << out.EX << " "  << out.EY << " " << out.EZ << " " << out.AX << " " << out.AY << " " << out.AZ;

	return out;
}


SixDegreesOfFreedom alinharValoresGiroscopioAcelerometro(SixDegreesOfFreedom inp){
	//Aplicando a adição aos angulos(caso estejam desalinhados com o acelerometro)
	inp.EX+=OFFSET_ANGLE_X;
	inp.EY+=OFFSET_ANGLE_Y;
	inp.EZ+=OFFSET_ANGLE_Z;
	return inp;
}

SixDegreesOfFreedom grausParaRadianos(SixDegreesOfFreedom inp){
	inp.EX = inp.EX*PI/180;
	inp.EY = inp.EY*PI/180;
	inp.EZ = inp.EZ*PI/180;
	return inp;
}

SixDegreesOfFreedom removeAceleracaoGravidade(SixDegreesOfFreedom inp){
	
	//Definindo o vetor de gravidade inicial
	SixDegreesOfFreedom gravity;
	
	gravity.AX = 0;
	gravity.AY = 0;
	gravity.AZ = G_FORCE;

	//==============================================	
	//Primeiro deslocamento, plano xy
	gravity.AX = gravity.AX * cos(inp.EZ);
	gravity.AY = gravity.AY * sin(inp.EZ);

	//Segundo deslocamento, plano yz
	gravity.AY = gravity.AY * cos(inp.EX);
	gravity.AZ = gravity.AZ * sin(inp.EX);

	//Terceito deslocamento, plano zx
	gravity.AZ = gravity.AZ * cos(inp.EY);
	gravity.AX = gravity.AX * sin(inp.EY);
	//===============================================
	
	//Subtraindo a gravidade da aceleração lida
	SixDegreesOfFreedom out;
	out.EX = inp.EX;
	out.EY = inp.EY;
	out.EZ = inp.EZ;
	out.AX = inp.AX - gravity.AX;
	out.AY = inp.AY - gravity.AY;
	out.AZ = inp.AZ - gravity.AZ;
	
	cout << setiosflags(ios::fixed) << setprecision(2) << "input " << inp.EX << " "  << inp.EY << " " << inp.EZ << " " << inp.AX << " " << inp.AY << " " << inp.AZ;
        cout << setiosflags(ios::fixed) << setprecision(2) << " output " << out.EX << " "  << out.EY << " " << out.EZ << " " << out.AX << " " << out.AY << " " << out.AZ << "\n";

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


        //cout << setiosflags(ios::fixed) << setprecision(2) << "input " << inp.EX << " "  << inp.EY << " " << inp.EZ << " " << inp.AX << " " << inp.AY << " " << inp.AZ << "\n";
	//cout << setiosflags(ios::fixed) << setprecision(2) << " output " << out.EX << " "  << out.EY << " " << out.EZ << " " << out.AX << " " << out.AY << " " << out.AZ << "\n";

        return out;
}


	
void doThings(SixDegreesOfFreedom sixDoF){
        //cout << "Callback " << sixDoF.EX << " "  << sixDoF.EY << " " << sixDoF.EZ << " " << sixDoF.AX << " " << sixDoF.AY << " " << sixDoF.AZ;
        //compensaVetorDeslocamento
	//removeAceleracaoGravidade
	//grausParaRadianos
	//alinharValoresGyroscopioAcelerometro
	
	SixDegreesOfFreedom hue = alinharValoresGiroscopioAcelerometro(sixDoF);
	SixDegreesOfFreedom hha = grausParaRadianos(hue);
	SixDegreesOfFreedom lala = removeAceleracaoGravidade(hha);
	//SixDegreesOfFreedom poh = compensaVetorDeslocamento(lala);

}

int main (){

	void (*callback)(SixDegreesOfFreedom);
	callback = &doThings;

	StartReading(callback);

	return 0;
}
