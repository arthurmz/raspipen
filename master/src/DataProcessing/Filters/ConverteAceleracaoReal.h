#pragma once

#include "Filter.h"
#include "Pipe.h"
#include <SixDegreesOfFreedom.h>

class ConverteAceleracaoReal : public Filter{
public:
	std::queue<SixDegreesOfFreedom> startFiltering(std::queue<SixDegreesOfFreedom>);
};
