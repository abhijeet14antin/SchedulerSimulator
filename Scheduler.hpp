/*********************************************************************
 * \file   Scheduler.hpp
 * \brief  Scheduler class declaration
 * 
 * \author abhij
 * \date   December 2023
 *********************************************************************/

#pragma once

#include <cstdint>
#include <vector>
#include <queue>
#include <mutex>
#include <iostream>
#include <thread>

#include "ProcessInfo.hpp"
#include "Enums.hpp"
#include "AlgorithmStats.hpp"
#include "constants.hpp"

/**
 * Scheduler Class
 */
class Scheduler {
public:
	/** Keeps track of current time */
	std::atomic<uint32_t> globalTime;

	/** Used by threads to signal completion of each process */
	std::atomic<uint32_t> numProcessesCompleted;

	/** Queue to store current waiting process threads */
	std::queue<ProcessInfo> processQueue;

	/** Atomic boolean to control access to the queue */
	std::atomic<bool> isQueueLocked;

	/** Vector of objects and pointers to store process info */
	std::vector<ProcessInfo>& processInfoList;
	std::vector<std::shared_ptr<ProcessInfo>> processInfoPtrs;

	/** Constructor */
	Scheduler(std::vector<ProcessInfo>& processList);

	/** Multi-threaded scheduling algorithms */
	AlgorithmStats FCFS();
	AlgorithmStats SJF();
	AlgorithmStats RR();

	/** Function which spawns process threads */
	void spawnProcessThreads(std::vector<ProcessInfo>& infoList);

	/** Function to start each process */
	void startProcess(ProcessInfo& info);

	/** Function for thread to just increment time counter */
	void incrementTime();
};




