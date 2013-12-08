#pragma once

#include "Filter.h"
#include "Pipe.h"
#include <SixDegreesOfFreedom.h>

class ConverteAceleracaoReal : public Filter{
public:
	ConverteAceleracaoReal(Pipe<SixDegreesOfFreedom> inpBuffer, Pipe<SixDegreesOfFreedom> outBuffer) : 
		Filter(inpBuffer, outBuffer){ }
	void startFiltering();
};
