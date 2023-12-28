/*********************************************************************
 * \file   AlgorithmStats.cpp
 * \brief  Definition of AlgorithmStats
 * 
 * \author abhij
 * \date   December 2023
 *********************************************************************/

#include "AlgorithmStats.hpp"

/**
 * Default constructor to initialize data members for statistics
 *
 */
AlgorithmStats::AlgorithmStats() {
	totalTurnaroundTime = 0;
	totalWaitTime = 0;
	currentCycle = 0;
	freeCycles = 0;
	busyCycles = 0;
	commandsProcessed = 0;
	cpuUtilization = 0;
	avgThroughput = 0;
	avgTurnaroundTime = 0;
	avgWaitTime = 0;
	AlgorithmStats::algorithm = SchedulerAlgorithmsEnum::INVALID;
}