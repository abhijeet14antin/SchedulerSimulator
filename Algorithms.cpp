/*****************************************************************//**
 * \file   Algorithms.cpp
 * \brief  Contains implementation of the various scheduling algorithms
 * 
 * \author abhij
 * \date   December 2023
 *********************************************************************/

// TODO: Move everything here into scheduler class?

#include "Algorithms.hpp"

/**
 * First Come First Served algorithm implementation
 * 
 * \param scheduler Takes a scheduler object
 * \return Statistics of current algorithm
 */
AlgorithmStats FCFS(Scheduler& scheduler) {
	AlgorithmStats stats;
	stats.algorithm = SchedulerAlgorithmsEnum::FCFS;
	size_t size = scheduler.processInfoList.size();

	for (auto& process : scheduler.processInfoList) {
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

/**
 * Shortest Job First algorithm implementation
 *
 * \param scheduler Takes a scheduler object
 * \return Statistics of current algorithm
 */
AlgorithmStats SJF(Scheduler& scheduler) {
	AlgorithmStats stats;
	stats.algorithm = SchedulerAlgorithmsEnum::SJF;
	size_t size = scheduler.processInfoList.size();
	
	/** Priority queue to store new processes as they arrive and sort based on job length */
	std::priority_queue<ProcessInfo, std::vector<ProcessInfo>, BurstTimeComparator> pq;
	uint32_t processIdx = 0;
	uint32_t currentEndTime = 0;
	ProcessInfo process;

	/** This loop runs as long as there are processes remaining in the scheduler or in the pq */
	while (processIdx < scheduler.processInfoList.size() || pq.size() != 0) {
		/** Add all new processes that just arrived to PQ */
		while (processIdx < size && scheduler.processInfoList[processIdx].arrivalTime == stats.currentCycle) {
			pq.push(scheduler.processInfoList[processIdx]);
			processIdx++;
		}
		/** If current running process is about to end or has already ended */
		if (currentEndTime <= stats.currentCycle) {
			/** If no process in PQ, just update free cycles */
			if (pq.size() == 0) {
				stats.freeCycles++;
			}
			else {
				process = pq.top();
				pq.pop();
				process.startTime = stats.currentCycle;
				process.completionTime = stats.currentCycle + process.burstTime;
				scheduler.processInfoList[process.index] = process;
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

/**
 * Shortest Remaning Time First algorithm implementation
 * 
 * \param scheduler Takes a scheduler object
 * \return Statistics of current algorithm
 */
AlgorithmStats SRTF(Scheduler& scheduler) {
	AlgorithmStats stats;
	stats.algorithm = SchedulerAlgorithmsEnum::SRTF;

	return stats;
}

/**
 * Round Robin algorithm implementation
 * 
 * \param scheduler Takes a scheduler object
 * \param numCyclesPerRound Size of each round in time cycles
 * \return Statistics of current algorithm
 */
AlgorithmStats RR(Scheduler& scheduler, uint32_t numCyclesPerRound) {
	AlgorithmStats stats;
	stats.algorithm = SchedulerAlgorithmsEnum::RR;
	size_t size = scheduler.processInfoList.size();

	/** Circular Queue to store current running processes */
	CircularQueue cq(size);
	uint32_t processIdx = 0;
	ProcessInfo process;
	uint32_t numCyclesInCurrentRound = 1;
	bool isProcessRunning = false;

	while (processIdx < scheduler.processInfoList.size() || cq.currentSize != 0) {
		//std::cout << "Cycle: " << stats.currentCycle << "\n";
		/** First add any new processes that may have arrived, unless circular queue is full */
		while (processIdx < size && scheduler.processInfoList[processIdx].arrivalTime <= stats.currentCycle) {
			bool enqueueSuccess = cq.enqueue(scheduler.processInfoList[processIdx]);
			if (enqueueSuccess) {
				processIdx++;
			}
			else {
				break;
			}
		}
		/** If no process is running, get a new one from queue. If no processes in queue, continue to next cycle */
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
					scheduler.processInfoList[process.index] = process;
				}
			}
		}
		/** Give current process additional cycles until round is completed */
		if (isProcessRunning) {
			process.remainingTime--;
			//std::cout << "processID: " << process.processID << "\n";
			if (process.remainingTime == 0) {
				//std::cout << "remaining time = 0\n";
				process.completionTime = stats.currentCycle + 1;
				scheduler.processInfoList[process.index] = process;
				numCyclesInCurrentRound = 1;
				isProcessRunning = false;
				stats.commandsProcessed += 1;
				stats.totalWaitTime += process.startTime - process.arrivalTime;
				stats.totalTurnaroundTime += process.completionTime - process.arrivalTime;
			}
			else if (numCyclesInCurrentRound < numCyclesPerRound) {
				//std::cout << "numCycles < max\n";
				numCyclesInCurrentRound++;
			}
			else {
				// TODO: handle full circular queue below
				//std::cout << "numCycles = max\n";
				cq.enqueue(process);
				numCyclesInCurrentRound = 1;
				isProcessRunning = false;
			}
			stats.busyCycles++;
		}
		else {
			stats.freeCycles++;
		}
		//std::cout << stats.currentCycle << "\t" << process.processID << "\t" << process.remainingTime << "\n";
		stats.currentCycle++;
	}
	/** Include stats of process that was last dequeued */
	stats.busyCycles += process.remainingTime;
	stats.currentCycle += process.remainingTime;
	process.completionTime = stats.currentCycle;
	scheduler.processInfoList[process.index] = process;
	/** Calculate final stats */
	stats.cpuUtilization = (double)stats.busyCycles / stats.currentCycle;
	stats.avgThroughput = (double)stats.commandsProcessed / stats.currentCycle;
	stats.avgTurnaroundTime = (double)stats.totalTurnaroundTime / size;
	stats.avgWaitTime = (double)stats.totalWaitTime / size;

	return stats;
}