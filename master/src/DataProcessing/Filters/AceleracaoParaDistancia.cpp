
#include <iostream>
#include <math.h>
#include "AceleracaoParaDistancia.h"



SixDegreesOfFreedom aceleracaoParaDistanciaAux(SixDegreesOfFreedom inp){
	SixDegreesOfFreedom out;

	out.EX = inp.EX;
	out.EY = inp.EY;
	out.EZ = inp.EZ;
	out.AX = 0;
	out.AY = inp.AY;
	out.AZ = inp.AZ;
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
