#include <iostream>
#include <Physics.h>
#include "ConverteAceleracaoReal.h"


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

std::queue<SixDegreesOfFreedom> ConverteAceleracaoReal::startFiltering(std::queue<SixDegreesOfFreedom> dataHolder){
	std::queue<SixDegreesOfFreedom> dataOut;

	while(dataHolder.size() > 0){
		SixDegreesOfFreedom d = dataHolder.front();
		dataHolder.pop();
		dataOut.push(calculeVelocidadeReal(d));
	}
	return dataOut;
}
