#pragma once

#include <cstdint>

class ProcessInfo 
{
public:
	uint32_t processID;
	uint32_t arrivalTime;
	uint32_t executeTime;
	uint32_t serviceTime;
	bool isCompleted;
	ProcessInfo();
	bool operator<(const ProcessInfo& other);
};