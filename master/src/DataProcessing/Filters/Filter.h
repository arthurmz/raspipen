#pragma once

#include "Pipe.h"
#include <SixDegreesOfFreedom.h>

class Filter{
protected:
	Pipe<SixDegreesOfFreedom> inputBuffer;
	Pipe<SixDegreesOfFreedom> outputBuffer;

public:
	Filter(Pipe<SixDegreesOfFreedom> inpBuffer, Pipe<SixDegreesOfFreedom> outBuffer){

	inputBuffer = inpBuffer;
	outputBuffer = outBuffer;

	}
	virtual void startFiltering() = 0;//tells the compiler that this method must be overriden by a derived class, and might not have its own implementation.
};
