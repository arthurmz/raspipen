#include <iostream>
#include "../DataSource/MPU6050-Pi-Demo/SixDegreesOfFreedom.h"
#include "../DataSource/MPU6050-Pi-Demo/demo_dmp.h"

using namespace std;

void test(SixDegreesOfFreedom){
	cout << "Test Freedom";
}


int main (){

void (*callback)(SixDegreesOfFreedom);
callback = &test;

StartReading(callback);

return 0;
}
