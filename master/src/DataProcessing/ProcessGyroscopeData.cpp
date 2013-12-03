#include <SixDegreesOfFreedom.h>
#include <ThreeDegreesOfFreedom.h>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <math.h>
#include "Physics/Physics.h"
#include "ProcessGyroscopeData.h"
#include "Physics/Rotation.h"

#define PI 3.141592653589793

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
	out.AX = realAcceleration(inp.AX, G_FORCE_RAW_X );
        out.AY = realAcceleration(inp.AY, G_FORCE_RAW_Y );
        out.AZ = realAcceleration(inp.AZ, G_FORCE_RAW_Z );

	return out;
}

/*De fábrica, o giroscópio pode vir com os eixos de aceleração e velocidade angular desalinhados,
  Isso significa que os eixos que medem a aceleração podem não coincidir com os eixos que medem o deslocamento angular
  causando problemas nos calculos da posição relativa.
  deve-se portanto aplicar um ajuste aos valores dos angulos medidos, de acordo com o quanto o eixo está desalinhado.
*/
SixDegreesOfFreedom alinharValoresGiroscopioAcelerometro(SixDegreesOfFreedom inp){
	//Aplicando a adição aos angulos(caso estejam desalinhados com o acelerometro)
	inp.EX+=OFFSET_ANGLE_X;
	inp.EY+=OFFSET_ANGLE_Y;
	inp.EZ+=OFFSET_ANGLE_Z;
	return inp;
}

/*Subtrai o vetor de gravidade (9.8m/s²) da medida de entrada do sensor
  Desse modo, estando o sensor em repouso sobre a terra, a aceleração medida deve ser (0,0,0)
*/

SixDegreesOfFreedom removeAceleracaoGravidade(SixDegreesOfFreedom inp){

	float vector[6];
	vector[0] = inp.EX;
	vector[1] = inp.EY;
	vector[2] = inp.EZ;
	vector[3] = inp.AX;
	vector[4] = inp.AY;
	vector[5] = inp.AZ;

	float gravity[6];
	gravity[0] = inp.EX;
	gravity[1] = inp.EY;
	gravity[2] = inp.EZ;
	gravity[3] = 0;
	gravity[4] = 0;
	gravity[5] = G_FORCE_RAW_Z;

	ApplyRotation(gravity);

	inp.AX -= gravity[3];
	inp.AY -= gravity[4];
	inp.AZ -= gravity[5];

	return inp;
}

SixDegreesOfFreedom removeAceleracaoGravidade2(SixDegreesOfFreedom inp){
	if (inp.AX < 300 && inp.AX > -300)
		inp.AX = 0;
	if (inp.AY < 300 && inp.AX > -300)
		inp.AY = 0;
	if (inp.AZ < 300 && inp.AX > -300)
		inp.AZ = 0;

	return inp;
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



SixDegreesOfFreedom ProcessGyroscopeData(SixDegreesOfFreedom sixDoF){
	/*SixDegreesOfFreedom result1 = alinharValoresGiroscopioAcelerometro(sixDoF);
	SixDegreesOfFreedom result2 = grausParaRadianos(result1);
	SixDegreesOfFreedom result3 = removeAceleracaoGravidade(result2);
	ThreeDegreesOfFreedom result4;
	result4.X = result3.AX;
	result4.Y = result3.AY;
	result4.Z = result3.AZ;
	return result4;*/

	//SixDegreesOfFreedom rst1 = removeAceleracaoGravidade2(sixDoF);

	SixDegreesOfFreedom rst2 = calculeVelocidadeReal ( sixDoF);

	return rst2;
}
