#include "ConverteAceleracaoReal.h"
#include <SixDegreesOfFreedom.h>


int main (){


Pipe<SixDegreesOfFreedom> inputBuffer;
Pipe<SixDegreesOfFreedom> outputBuffer;

ConverteAceleracaoReal conversor(inputBuffer, outputBuffer);



return 0;
}
