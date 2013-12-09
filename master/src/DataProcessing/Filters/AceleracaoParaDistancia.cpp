
#include <iostream>
#include <math.h>
#include <Physics.h>
#include "AceleracaoParaDistancia.h"



SixDegreesOfFreedom aceleracaoParaDistanciaAux(SixDegreesOfFreedom inp){
	SixDegreesOfFreedom out;


	float * deslVector = deslVectorial(0, 0.05, inp.AX, inp.AY, inp.AZ);
	out.EX = inp.EX;
	out.EY = inp.EY;
	out.EZ = inp.EZ;
	out.AX = deslVector[0];
	out.AY = deslVector[1];
	out.AZ = deslVector[2];
	return out;

}

std::queue<SixDegreesOfFreedom> AceleracaoParaDistancia::startFiltering(std::queue<SixDegreesOfFreedom> dataHolder){
	std::queue<SixDegreesOfFreedom> dataOut;

	while(dataHolder.size() > 0){
		SixDegreesOfFreedom d = dataHolder.front();
		dataHolder.pop();
		dataOut.push(aceleracaoParaDistanciaAux(d));
	}
	return dataOut;
}
