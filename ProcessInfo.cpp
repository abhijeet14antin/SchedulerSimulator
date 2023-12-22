#include "ProcessInfo.hpp"

ProcessInfo::ProcessInfo() {
	// Value of 0 means invalid for all fields
	processID = 0;
	arrivalTime = 0;
	startTime = 0;
	burstTime = 0;
	remainingTime = 0;
	completionTime = 0;
	index = 0;
}

/*	Object to compare using arrival time + burst time
*/
bool ArrivalTimeComparator::operator() (const ProcessInfo& a, const ProcessInfo& b) {
	return (a.arrivalTime < b.arrivalTime)
		|| (a.arrivalTime == b.arrivalTime && a.burstTime < b.burstTime);
}

/*	Object to compare using burst time + arrival time
*/
bool BurstTimeComparator::operator() (const ProcessInfo& a, const ProcessInfo& b) {
	return (a.burstTime > b.burstTime)
		|| (a.burstTime == b.burstTime && a.arrivalTime > b.arrivalTime);
}
