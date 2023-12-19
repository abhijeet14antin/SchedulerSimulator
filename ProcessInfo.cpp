#include "ProcessInfo.hpp"

ProcessInfo::ProcessInfo() {
	// Value of 0 means invalid for all fields
	processID = 0;
	arrivalTime = 0;
	startTime = 0;
	burstTime = 0;
	completionTime = 0;
	isCompleted = false;
}

bool ProcessInfo::operator<(const ProcessInfo& other) {
	return (arrivalTime < other.arrivalTime) 
		|| (arrivalTime == other.arrivalTime && burstTime < other.burstTime);
}