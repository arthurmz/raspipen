#pragma once

#include "Filter.h"
#include "Pipe.h"
#include <iostream>

class RemoveGravidade : public Filter{
public:
	std::queue<SixDegreesOfFreedom> startFiltering(std::queue<SixDegreesOfFreedom>);
};
