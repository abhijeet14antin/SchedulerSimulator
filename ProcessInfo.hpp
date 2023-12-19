#pragma once

#include <cstdint>

class ProcessInfo 
{
public:
	uint32_t processID;
	uint32_t arrivalTime;
	uint32_t startTime;
	uint32_t burstTime;
	uint32_t completionTime;
	bool isCompleted;
	ProcessInfo();
	bool operator<(const ProcessInfo& other);
};