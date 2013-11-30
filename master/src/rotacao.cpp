#include <stdlib.h>
#include <iostream>
#include <cmath>
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

int main(){
	float angulo = 30;
	float ux = 1;
	float uy = 0;
	float uz = 0;
	float r[3][3];
	rotacaoVetor(angulo, ux, uy, uz, r);
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << r[i][j] <<"\t";
		}
		cout<<"\n";
	}
}
