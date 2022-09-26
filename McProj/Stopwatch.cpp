#include "Stopwatch.hpp"

#include <chrono>

Stopwatch::Stopwatch() : savedTime(0.0) {
	NewLap();
}

void Stopwatch::NewLap() {
	lapStart = std::chrono::steady_clock::now();
}

double Stopwatch::TimeElapsed() {
	return static_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - lapStart).count();
}

void Stopwatch::SaveTime() {
	savedTime = TimeElapsed();
}

double Stopwatch::SavedTime() {
	return savedTime;
}