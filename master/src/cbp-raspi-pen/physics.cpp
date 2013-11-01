#include <stdlib.h>
using namespace std;

#define G_FORCE 9806.65 //milimeters per second at square

float deslEscalar(float vel, float time, float acel){
	return (vel*time)+ ((acel*time*time)/2);
}


float* deslVectorial(float vel, float time, float acelX, float acelY, float acelZ){
	float *deslVector = (float*)malloc(sizeof(float) * 3);

	deslVector[0] = deslEscalar(vel, time, acelX);
	deslVector[1] = deslEscalar(vel, time, acelY);
	deslVector[2] = deslEscalar(vel, time, acelZ);
	return deslVector;
}

float* destPoint(float *origPoint, float * deslVector){
	float *destPoint = (float*)malloc(sizeof(float) * 3);

	destPoint[0] = origPoint[0] + deslVector[0];
	destPoint[1] = origPoint[1] + deslVector[1];
	destPoint[2] = origPoint[2] + deslVector[2];
	return destPoint;
}

/*
 * Entrada: valor de aceleração em formato bruto, i.e. sua razão para alguma unidade de medida padrão (metros por segundo) é diferente de 1
 * Ex: 4000 = 1g, 2542 = 1g, etc
 * 
 * OneGReference: valor correspondente 1G, verificado junto ao sensor
 * 
 * 
 * Saída: aceleração real em MILIMETROS POR SEGUNDO
 */
float realAcceleration(float accelerationMeasure, float OneGReference){

    float relativyGA = G_FORCE / OneGReference;

    return accelerationMeasure * relativyGA;
}

