#pragma once

#include <cstdint>

class ProcessInfo 
{
public:
	uint32_t processID;			// Unique process ID
	uint32_t arrivalTime;		// Time instant that process arrives
	uint32_t startTime;			// Actual start time of process
	uint32_t burstTime;			// Time taken for process to run
	uint32_t remainingTime;		// Time remaining for current process
	uint32_t completionTime;	// Time instant that process completes
	uint32_t index;				// Index within vector, needed to update startTime, completionTime in original vector
	ProcessInfo();
};

/*	Object to compare using arrival time + burst time
*/
class ArrivalTimeComparator {
public:
	bool operator() (const ProcessInfo& a, const ProcessInfo& b);
};

/*	Object to compare using burst time + arrival time
*/
class BurstTimeComparator {
public:
	bool operator() (const ProcessInfo& a, const ProcessInfo& b);
};