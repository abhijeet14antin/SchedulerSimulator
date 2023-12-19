// TODO: Move everything here into scheduler class lol

#include "Algorithms.hpp"

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
	AlgorithmStats::algorithm = SchedulerAlgorithms::INVALID;
}

AlgorithmStats FCFS(Scheduler& scheduler) {
	AlgorithmStats stats;
	stats.algorithm = SchedulerAlgorithms::FCFS;
	size_t size = scheduler.processInfo.size();

	for (auto& process : scheduler.processInfo) {
		while (process.arrivalTime > stats.currentCycle) {
			stats.freeCycles++;
			stats.currentCycle++;
		}
		process.startTime = stats.currentCycle;
		process.completionTime = process.startTime + process.burstTime;

		//std::cout << "PID = " << process.processID << "\tCompletion Time = " << process.completionTime << "\tStart Time = " << process.startTime << "\n";
		process.isCompleted = true;
		stats.busyCycles += process.burstTime;
		stats.currentCycle = process.completionTime;
		stats.commandsProcessed += 1;

		// TODO: move to separate function called calculateFixedStats or something
		stats.totalWaitTime += process.startTime - process.arrivalTime;
		stats.totalTurnaroundTime += process.completionTime - process.arrivalTime;
	}
	// TODO: move to separate function called calculateFixedStats or something
	stats.cpuUtilization = (double)stats.busyCycles / stats.currentCycle;
	stats.avgThroughput = (double)stats.commandsProcessed / stats.currentCycle;
	stats.avgTurnaroundTime = (double)stats.totalTurnaroundTime / size;
	stats.avgWaitTime = (double)stats.totalWaitTime / size;

	return stats;
}

AlgorithmStats SJF(Scheduler& scheduler) {
	AlgorithmStats stats;
	stats.algorithm = SchedulerAlgorithms::SJF;

	return stats;
}

AlgorithmStats SRT(Scheduler& scheduler) {
	AlgorithmStats stats;
	stats.algorithm = SchedulerAlgorithms::SRT;

	return stats;
}

AlgorithmStats RR(Scheduler& scheduler) {
	AlgorithmStats stats;
	stats.algorithm = SchedulerAlgorithms::RR;

	return stats;
}