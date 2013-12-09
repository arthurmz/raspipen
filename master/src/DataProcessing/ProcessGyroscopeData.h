#pragma once
#include <ThreeDegreesOfFreedom.h>
#include <SixDegreesOfFreedom.h>
#include <queue>

std::queue<SixDegreesOfFreedom> ProcessGyroscopeData(std::queue<SixDegreesOfFreedom> d);

SixDegreesOfFreedom removeAceleracaoGravidade(SixDegreesOfFreedom inp);