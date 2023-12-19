#pragma once

#include <cstdint>
#include "Scheduler.hpp"

/*	Object to store statistics per algorithm
 */
class AlgorithmStats {
public:
	uint32_t totalTurnaroundTime;
	uint32_t totalWaitTime;
	uint32_t currentCycle;
	uint32_t freeCycles;
	uint32_t busyCycles;
	uint32_t commandsProcessed;
	double cpuUtilization;
	double avgThroughput;
	double avgTurnaroundTime;
	double avgWaitTime;
	SchedulerAlgorithms algorithm;
	AlgorithmStats();
};

AlgorithmStats FCFS(Scheduler& scheduler);

AlgorithmStats SJF(Scheduler& scheduler);

AlgorithmStats SRT(Scheduler& scheduler);

AlgorithmStats RR(Scheduler& scheduler);