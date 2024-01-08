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
	std::vector<ProcessInfo> list(constants::n);
	std::default_random_engine generator;
	std::uniform_int_distribution<uint32_t> arrivalDistribution(constants::minArrivalTime,
		constants::maxArrivalTime);
	std::uniform_int_distribution<uint32_t> executeDistribution(constants::minBurstTime,
		constants::maxBurstTime);

	for (uint32_t i = 0; i < constants::n; i++) {
		list[i].processID = i + 1;
		list[i].arrivalTime = arrivalDistribution(generator);
		list[i].burstTime = executeDistribution(generator);
		list[i].remainingTime = list[i].burstTime;
		list[i].completionTime = 0;
	}

	// Sort list
	sort(list.begin(), list.end(), ArrivalTimeComparatorForGeneration());

	// Store vector indices in each object
	for (uint32_t i = 0; i < list.size(); i++) {
		list[i].index = i;
	}

	return list;
}