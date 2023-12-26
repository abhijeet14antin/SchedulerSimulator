// TODO: Move everything here into scheduler class?

#include "Algorithms.hpp"

#include<iostream>

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
	size_t size = scheduler.processInfo.size();
	
	/*	Priority queue to store new processes as they arrive and sort based on job length
	 */
	std::priority_queue<ProcessInfo, vector<ProcessInfo>, BurstTimeComparator> pq;
	uint32_t processIdx = 0;
	uint32_t currentEndTime = 0;
	ProcessInfo process;

	/*	This loop runs as long as there are processes remaining in the scheduler or in the pq
	 */
	while (processIdx < scheduler.processInfo.size() || pq.size() != 0) {
		/*	Add all new processes that just arrived to PQ
		 */
		while (processIdx < size && scheduler.processInfo[processIdx].arrivalTime == stats.currentCycle) {
			pq.push(scheduler.processInfo[processIdx]);
			processIdx++;
		}
		/*	If current running process is about to end or has already ended
		 */
		if (currentEndTime <= stats.currentCycle) {
			/* If no process in PQ, just update free cycles
			 */
			if (pq.size() == 0) {
				stats.freeCycles++;
			}
			else {
				process = pq.top();
				pq.pop();
				process.startTime = stats.currentCycle;
				process.completionTime = stats.currentCycle + process.burstTime;
				scheduler.processInfo[process.index] = process;
				currentEndTime = process.completionTime;

				stats.commandsProcessed += 1;
				stats.busyCycles++;
				stats.totalWaitTime += process.startTime - process.arrivalTime;
				stats.totalTurnaroundTime += process.completionTime - process.arrivalTime;
			}
		}
		else {
			stats.busyCycles++;
		}
		stats.currentCycle++;
	}
	//std::cout << stats.currentCycle << "\tpq.size = " << pq.size() << "\n";
	stats.currentCycle += process.burstTime - 1;
	stats.busyCycles += process.burstTime - 1;
	stats.cpuUtilization = (double)stats.busyCycles / stats.currentCycle;
	stats.avgThroughput = (double)stats.commandsProcessed / stats.currentCycle;
	stats.avgTurnaroundTime = (double)stats.totalTurnaroundTime / size;
	stats.avgWaitTime = (double)stats.totalWaitTime / size;

	return stats;
}

AlgorithmStats SRTF(Scheduler& scheduler) {
	AlgorithmStats stats;
	stats.algorithm = SchedulerAlgorithms::SRTF;

	return stats;
}

AlgorithmStats RR(Scheduler& scheduler, uint32_t numCyclesPerRound) {
	AlgorithmStats stats;
	stats.algorithm = SchedulerAlgorithms::RR;
	size_t size = scheduler.processInfo.size();

	/*	Circular Queue to store current running processes
	 */
	CircularQueue cq(100);
	uint32_t processIdx = 0;
	ProcessInfo process;
	uint32_t numCyclesInCurrentRound = 1;
	bool isProcessRunning = false;

	while (processIdx < scheduler.processInfo.size() || cq.currentSize != 0) {
		/*	First add any new processes that may have arrived, unless circular queue is full
		 */
		while (processIdx < size && scheduler.processInfo[processIdx].arrivalTime <= stats.currentCycle) {
			bool enqueueSuccess = cq.enqueue(scheduler.processInfo[processIdx]);
			if (enqueueSuccess) {
				processIdx++;
			}
			else {
				break;
			}
		}
		/*	If no process is running, get a new one from queue. If no processes in queue, continue to next cycle
		 */
		if (!isProcessRunning) {
			ProcessInfo temp;
			bool dequeueSuccess = cq.dequeue(temp);
			if (dequeueSuccess) {
				process = temp;
				isProcessRunning = true;
				/*	If new process, save start time
				 */
				if (!process.isStarted) {
					process.startTime = stats.currentCycle;
					process.isStarted = true;
					scheduler.processInfo[process.index] = process;
				}
			}
		}
		/*	Give current process additional cycles until round is completed
		 */
		if (isProcessRunning) {
			process.remainingTime--;
			if (process.remainingTime == 0) {
				process.completionTime = stats.currentCycle;
				scheduler.processInfo[process.index] = process;
				numCyclesInCurrentRound = 1;
				isProcessRunning = false;
				stats.commandsProcessed += 1;
				stats.totalWaitTime += process.startTime - process.arrivalTime;
				stats.totalTurnaroundTime += process.completionTime - process.arrivalTime;
			}
			else if (numCyclesInCurrentRound < numCyclesPerRound) {
				numCyclesInCurrentRound++;
			}
			else {
				// TODO: handle full circular queue below
				cq.enqueue(process);
				numCyclesInCurrentRound = 1;
				isProcessRunning = false;
			}
			stats.busyCycles++;
		}
		else {
			stats.freeCycles++;
		}
		//std::cout << stats.currentCycle << "\t" << process.processID << "\n";
		stats.currentCycle++;
	}

	stats.cpuUtilization = (double)stats.busyCycles / stats.currentCycle;
	stats.avgThroughput = (double)stats.commandsProcessed / stats.currentCycle;
	stats.avgTurnaroundTime = (double)stats.totalTurnaroundTime / size;
	stats.avgWaitTime = (double)stats.totalWaitTime / size;

	return stats;
}