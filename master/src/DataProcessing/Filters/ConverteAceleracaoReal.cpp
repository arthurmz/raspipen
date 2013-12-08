#include <iostream>
#include "ConverteAceleracaoReal.h"

void ConverteAceleracaoReal::startFiltering(){
	SixDegreesOfFreedom d = inputBuffer.read();
	outputBuffer.write(d);
}
