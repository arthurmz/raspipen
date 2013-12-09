#pragma once

#include "Filter.h"
#include "Pipe.h"
#include <iostream>
#include "../../Gyroscope/SixDegreesOfFreedom.h"
#include <queue>

class AceleracaoParaDistancia : public Filter{
public:
	std::queue<SixDegreesOfFreedom> startFiltering(std::queue<SixDegreesOfFreedom>);
};
