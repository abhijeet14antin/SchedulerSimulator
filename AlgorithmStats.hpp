/*********************************************************************
 * \file   AlgorithmStats.hpp
 * \brief  Declaration of AlgorithmStats class
 * 
 * \author abhij
 * \date   December 2023
 *********************************************************************/

#include <cstdint>
#include "enums.hpp"

/**
 * Constructor to initialize data members
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
	SchedulerAlgorithmsEnum algorithm;
	AlgorithmStats();
};