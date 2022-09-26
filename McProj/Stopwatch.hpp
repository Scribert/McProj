#pragma once

#include <chrono>

class Stopwatch {
	std::chrono::time_point<std::chrono::steady_clock> lapStart;
	double savedTime;
public:
	Stopwatch();
	void NewLap();
	double TimeElapsed();
	void SaveTime();
	double SavedTime();
};

