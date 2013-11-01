#pragma once

/* vel - milimeter per second
 time - second
 acel - milimeter per second ²
 output - space in milimeters
*/
float deslEscalar(float vel, float time, float acel);

float* deslVectorial(float vel, float time, float acelX, float acelY, float acelZ);

float* destPoint(float *origPoint, float * deslVector);

float realAcceleration(float accelerationMeasure, float OneGReference);
