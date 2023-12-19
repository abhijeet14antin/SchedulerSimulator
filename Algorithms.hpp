#pragma once

#include <cstdint>
#include "Scheduler.hpp"

/*	Object to store statistics per algorithm
 */
class AlgorithmStats {
public:
	uint32_t avgThroughput;
	uint32_t avgWaitTime;
	uint32_t avgLatency;
	SchedulerAlgorithms algorithm;
	AlgorithmStats();
};

AlgorithmStats FCFS(Scheduler scheduler);

AlgorithmStats SJF(Scheduler scheduler);

AlgorithmStats SRT(Scheduler scheduler);

AlgorithmStats RR(Scheduler scheduler);