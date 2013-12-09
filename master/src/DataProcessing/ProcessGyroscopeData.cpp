#include <SixDegreesOfFreedom.h>
#include <ThreeDegreesOfFreedom.h>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <pthread.h>
#include <queue>
#include <ConverteAceleracaoReal.h>
#include <RemoveGravidade.h>
#include <math.h>
#include "Physics/Physics.h"
#include "ProcessGyroscopeData.h"
#include "Physics/Rotation.h"

#define PI 3.141592653589793

using namespace std;


std::queue<SixDegreesOfFreedom> ProcessGyroscopeData(std::queue<SixDegreesOfFreedom> dataHolder){

	ConverteAceleracaoReal filtro1;
	RemoveGravidade filtro2;

	std::queue<SixDegreesOfFreedom> saida = filtro2.startFiltering (
						filtro1.startFiltering(dataHolder));
	return saida;

}
