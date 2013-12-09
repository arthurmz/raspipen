#pragma once

#include "Pipe.h"
#include "../../Gyroscope/SixDegreesOfFreedom.h"

class Filter{
protected:
	Pipe<SixDegreesOfFreedom> inputBuffer;
	Pipe<SixDegreesOfFreedom> outputBuffer;

public:
	bool running;
	void setValues(Pipe<SixDegreesOfFreedom> inpBuffer, Pipe<SixDegreesOfFreedom> outBuffer){
		running = true;
		inputBuffer = inpBuffer;
		outputBuffer = outBuffer;
	}
	virtual std::queue<SixDegreesOfFreedom> startFiltering(std::queue<SixDegreesOfFreedom>) = 0;//tells the compiler that this method must be overriden by a derived class, and might not have its own implementation.
};
