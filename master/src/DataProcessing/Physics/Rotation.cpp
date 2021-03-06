#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "Rotation.h"

using namespace std;

void rotacaoVetor(float angulo, float ux, float uy, float uz, float r[][3]){
	float anguloRad = angulo * 2 * M_PI / 360;
	r[0][0] = cos(anguloRad) + (ux * ux) * (1 - cos(anguloRad));
	r[0][1] = (ux * uy) * (1 - cos(anguloRad)) - uz * sin(anguloRad);
	r[0][2] = (ux * uz) * (1 - cos(anguloRad)) + uy * sin(anguloRad);
	r[1][0] = (uy * ux) * (1 - cos(anguloRad)) + uz * sin(anguloRad);
	r[1][1] = cos(anguloRad) + (uy * uy) * (1 - cos(anguloRad));
	r[1][2] = (uy * uz) * (1 - cos(anguloRad)) - ux * sin(anguloRad);
	r[2][0] = (uz * ux) * (1 - cos(anguloRad)) - uy * sin(anguloRad);
	r[2][1] = (uz * uy) * (1 - cos(anguloRad)) + ux * sin(anguloRad);
	r[2][2] = cos(anguloRad) + (uz * uz) * (1 - cos(anguloRad));
}



void multiplicar(float matriz[][3], float vet[3]){
	float result[3];
	for(int i = 0; i < 3; i++){
		result[i] = vet[0]* matriz[i][0] + vet[1]* matriz[i][1] + vet[2]* matriz[i][2];
	}
	vet[0] = result[0];
	vet[1] = result[1];
	vet[2] = result[2];
}

void arredondar(float vetor[3]){
	for(int i = 0; i < 3; i++){
		if(vetor[i] < 0.0001 && vetor[i] > -0.0001){
			vetor[i] = 0;
		}
	}	
}

void rotacaoX(float vetor[3], float angulox){
	float matrizRotacao[3][3];
	rotacaoVetor(angulox, 1, 0, 0, matrizRotacao);
	multiplicar(matrizRotacao, vetor);
	arredondar(vetor);

}

void rotacaoY(float vetor[3], float anguloy){
	float matrizRotacao[3][3];
	rotacaoVetor(anguloy, 0, 1, 0, matrizRotacao);
	multiplicar(matrizRotacao, vetor);
	arredondar(vetor);
}

void rotacaoZ(float vetor[3], float anguloz){
	float matrizRotacao[3][3];
	rotacaoVetor(anguloz, 0, 0, 1, matrizRotacao);
	multiplicar(matrizRotacao, vetor);
	arredondar(vetor);
}

	
	

void ApplyRotation(float input[6]){//three angles and three accelerations



	//three positions
	float accVector[3];
	accVector[0] = input[3];
	accVector[1] = input[4];
	accVector[2] = input[5];

	rotacaoX(accVector, input[0]);
	rotacaoY(accVector, input[1]);
	rotacaoZ(accVector, input[2]);

	//setting back

	input[3] = accVector[0];
	input[4] = accVector[1];
	input[5] = accVector[2];
}
