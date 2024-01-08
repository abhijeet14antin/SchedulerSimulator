/*****************************************************************//**
 * \file   Scheduler.cpp
 * \brief  Contains implementation of scheduler class
 * 
 * \author abhij
 * \date   December 2023
 *********************************************************************/

#include "Scheduler.hpp"

/**
 * Constructor for Scheduler Class
 * 
 * \param processList Vector of process information
 */
Scheduler::Scheduler(std::vector<ProcessInfo>& processList) : processInfoList(processList) {
	globalTime = 0;
	for (const auto& process : processInfoList) {
		std::shared_ptr<ProcessInfo> processPtr (new ProcessInfo);
		processPtr->arrivalTime		= process.arrivalTime;
		processPtr->burstTime		= process.burstTime;
		processPtr->completionTime	= process.completionTime;
		processPtr->index			= process.index;
		processPtr->processID		= process.processID;
		processPtr->remainingTime	= process.completionTime;
		processPtr->startTime		= process.startTime;
		processPtr->isStarted		= process.isStarted;
		processPtr->remainingTime	= process.remainingTime;
		processInfoPtrs.push_back(processPtr);
	}
}

/**
 * Function that periodically increments time counter based on sleepTimeMillis
 * 
 */
void Scheduler::incrementTime() {
	/** Stop if all processes have completed */
	while (numProcessesCompleted < constants::n) {
		/** Sleep for a bit to help visualize/debug */
		std::this_thread::sleep_for(std::chrono::milliseconds(constants::sleepTimeMillis));
		globalTime++;
		//std::cout << "New current time = \t" << globalTime << "\n";
	}
}

/**
 * Function that each process thread calls
 * 
 * \param info
 */
void Scheduler::startProcess(ProcessInfo& info) {
	/** Wait until arrival time */
	while (info.arrivalTime > globalTime);

	/** Wait until queue is unlocked, then push this process info to queue */
	while (isQueueLocked.exchange(true)) {
		/** Empty loop */
	}
	processQueue.push(info);
	//std::cout << "thread for PID " << info.processID << "\tqueue size = " << processQueue.size() << "\n";
	isQueueLocked = false;
	
	/** Wait until process is completed before releasing thread */
	//while (!info.isCompleted);
}

void test(ProcessInfo& info) {

}

/**
 * Function that spawns all process threads when called. Each process thread at its arrival time,
 * will add its ProcessInfo to the queue that the scheduler is monitoring.
 * 
 * \param infoList
 */
void Scheduler::spawnProcessThreads(std::vector<ProcessInfo>& infoList) {
	std::vector<std::thread> processThreads(infoList.size());
	for (uint32_t i = 0; i < infoList.size(); i++) {
		processThreads[i] = std::thread(&Scheduler::startProcess, this, std::ref(infoList[i]));
	}

	/** Wait for all processes to join back */
	for (auto& thread : processThreads) {
		thread.join();
	}
}

/**
 * Performs scheduler simulation using FCFS on processes
 * 
 * \return object with algorithm stats
 */
AlgorithmStats Scheduler::FCFS() {
	AlgorithmStats stats;
	stats.algorithm = SchedulerAlgorithmsEnum::FCFS;

	/** Priority queue to organize pending processes */
	std::priority_queue<ProcessInfo, std::vector<ProcessInfo>, ArrivalTimeComparator> pq;

	/** To track of process running at current time */
	ProcessInfo currentProcess;
	bool isProcessRunning = false;
	uint32_t currentTime = globalTime;

	/** Start thread that will increment time */
	std::thread timeCounter(&Scheduler::incrementTime, this);

	/** Start thread that will spawn process threads using the processInfo received above */
	std::thread processSpawner(&Scheduler::spawnProcessThreads, this, std::ref(processInfoList));

	while (numProcessesCompleted < processInfoList.size()) {
		/** Wait until queue is unlocked */
		while (isQueueLocked.exchange(true)) {
			/** Empty loop */
		}

		/** Then get all pending process from thread queue and add them to local PQ */
		while (processQueue.size() != 0) {
			pq.push(processQueue.front());
			processQueue.pop();
			std::cout << "Main thread received PID\t" << pq.top().processID << "\tfrom global queue\n";
		}
		isQueueLocked = false;

		/** Do stuff is there is increment in global counter */
		if (currentTime != globalTime) {
			stats.currentCycle = currentTime;
			if (isProcessRunning) {
				if (currentProcess.remainingTime == 0) {
					/** Update details for this process */
					currentProcess.completionTime = currentTime;
					currentProcess.isCompleted = true;

					/** Update stats for this process */
					stats.commandsProcessed += 1;
					stats.totalWaitTime += currentProcess.startTime - currentProcess.arrivalTime;
					stats.totalTurnaroundTime += currentProcess.completionTime - currentProcess.arrivalTime;

					numProcessesCompleted++;
					isProcessRunning = false;

					std::cout << "time = " << currentTime << "\tEnding process with PID = \t" << currentProcess.processID << "\n";
				}
				else {
					currentProcess.remainingTime--;
				}
				stats.busyCycles++;
			}
			else {
				if (pq.size() == 0) {
					stats.freeCycles++;
				}
			}
			if (!isProcessRunning) {
				if (pq.size() != 0) {
					currentProcess = pq.top();
					std::cout << "time = " << currentTime << "\tStarting process with PID = \t" << currentProcess.processID << "\n";
					pq.pop();
					currentProcess.startTime = currentTime;
					currentProcess.isStarted = true;
					currentProcess.remainingTime--;
					isProcessRunning = true;
				}
			}
			currentTime = globalTime;
		}
	}

	stats.cpuUtilization = (double)stats.busyCycles / stats.currentCycle;
	stats.avgThroughput = (double)stats.commandsProcessed / stats.currentCycle;
	stats.avgTurnaroundTime = (double)stats.totalTurnaroundTime / constants::n;
	stats.avgWaitTime = (double)stats.totalWaitTime / constants::n;

	/** Wait for threads to join before exiting */
	timeCounter.join();
	processSpawner.join();

	return stats;
}

/**
 * Performs scheduler simulation using SJF on processes
 * 
 * \return object with algorithm stats
 */
AlgorithmStats Scheduler::SJF() {
	AlgorithmStats stats;

	return stats;
}

/**
 * Performs scheduler simulation using RR on processes
 * 
 * \return object with algorithm stats
 */
AlgorithmStats Scheduler::RR() {
	AlgorithmStats stats;

	return stats;
}