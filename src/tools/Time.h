#pragma once

// Calculates time between two frames (delta time)
class Time
{
public:
	static double DeltaTime();

private:
	static double previousTime;
	static double currentTime;
	static const int MILLISEC_IN_SEC = 1000;
};