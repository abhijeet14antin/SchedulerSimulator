#include "Algorithms.hpp"

AlgorithmStats::AlgorithmStats() {
	avgThroughput = 0; 
	avgWaitTime = 0;
	avgLatency = 0;
	AlgorithmStats::algorithm = SchedulerAlgorithms::INVALID;
}

AlgorithmStats FCFS(Scheduler scheduler) {
	AlgorithmStats stats;
	stats.algorithm = SchedulerAlgorithms::FCFS;

	return stats;
}

AlgorithmStats SJF(Scheduler scheduler) {
	AlgorithmStats stats;
	stats.algorithm = SchedulerAlgorithms::SJF;

	return stats;
}

AlgorithmStats SRT(Scheduler scheduler) {
	AlgorithmStats stats;
	stats.algorithm = SchedulerAlgorithms::SRT;

	return stats;
}

AlgorithmStats RR(Scheduler scheduler) {
	AlgorithmStats stats;
	stats.algorithm = SchedulerAlgorithms::RR;

	return stats;
}