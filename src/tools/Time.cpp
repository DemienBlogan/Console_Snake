#include "Time.h"

#include <ctime>

double Time::previousTime = 0;
double Time::currentTime = std::clock();

double Time::DeltaTime()
{
	previousTime = currentTime;
	currentTime = std::clock();
	return (currentTime - previousTime) / MILLISEC_IN_SEC;
}