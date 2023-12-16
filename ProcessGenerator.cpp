#include "ProcessGenerator.hpp"

vector<ProcessInfo> generateRandomProcesses()
{
	uint32_t n = 100;					// Number of processes
	uint32_t minArrivalTime = 1;		// Earliest possible arrival
	uint32_t maxArrivalTime = n * 2;	// Latest possible arrival
	uint32_t minExecuteTime = 1;		// Minimum time to execute
	uint32_t maxExecuteTime = n / 2;	// Maximum time to execute

	vector<ProcessInfo> list(n);
	std::default_random_engine generator;
	std::uniform_int_distribution<uint32_t> arrivalDistribution(minArrivalTime,
		maxArrivalTime);
	std::uniform_int_distribution<uint32_t> executeDistribution(minExecuteTime,
		maxExecuteTime);

	for (uint32_t i = 0; i < n; i++) {
		list[i].processID = i + 1;
		list[i].arrivalTime = arrivalDistribution(generator);
		list[i].executeTime = executeDistribution(generator);
		list[i].isCompleted = false;
		list[i].serviceTime = 0;
	}

	// Sort list
	sort(list.begin(), list.end());

	return list;
}