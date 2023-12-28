/*********************************************************************
 * \file   ProcessGenerator.cpp
 * \brief  Definition of process generator
 * 
 * \author abhij
 * \date   December 2023
 *********************************************************************/

#include "ProcessGenerator.hpp"

/**
 * Generates process using RNG
 * 
 * \return A vector of processes generated
 */
std::vector<ProcessInfo> generateRandomProcesses()
{
	uint32_t n = 200;						// Number of processes
	uint32_t minArrivalTime = 1;			// Earliest possible arrival
	uint32_t maxArrivalTime = n * 2;		// Latest possible arrival
	uint32_t minBurstTime = 1;			// Minimum time to execute
	uint32_t maxBurstTime = n / 2 ;		// Maximum time to execute

	std::vector<ProcessInfo> list(n);
	std::default_random_engine generator;
	std::uniform_int_distribution<uint32_t> arrivalDistribution(minArrivalTime,
		maxArrivalTime);
	std::uniform_int_distribution<uint32_t> executeDistribution(minBurstTime,
		maxBurstTime);

	for (uint32_t i = 0; i < n; i++) {
		list[i].processID = i + 1;
		list[i].arrivalTime = arrivalDistribution(generator);
		list[i].burstTime = executeDistribution(generator);
		list[i].remainingTime = list[i].burstTime;
		list[i].completionTime = 0;
	}

	// Sort list
	sort(list.begin(), list.end(), ArrivalTimeComparator());

	// Store vector indices in each object
	for (size_t i = 0; i < list.size(); i++) {
		list[i].index = i;
	}

	return list;
}