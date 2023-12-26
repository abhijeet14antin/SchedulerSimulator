#include "Scheduler.hpp"

Scheduler::Scheduler(vector<ProcessInfo>& processList) : processInfo(processList) {
	for (const auto& process : processInfo) {
		std::shared_ptr<ProcessInfo> processPtr (new ProcessInfo);
		processPtr->arrivalTime = process.arrivalTime;
		processPtr->burstTime = process.burstTime;
		processPtr->completionTime = process.completionTime;
		processPtr->index = process.index;
		processPtr->processID = process.processID;
		processPtr->remainingTime = process.completionTime;
		processPtr->startTime = process.startTime;
		processPtr->isStarted = process.isStarted;
		processPtr->remainingTime = process.remainingTime;
		processInfoPtrs.push_back(processPtr);
	}
}