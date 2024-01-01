/*****************************************************************//**
 * \file   ProcessInfo.cpp
 * \brief  Definition of ProcessInfo class
 * 
 * \author abhij
 * \date   December 2023
 *********************************************************************/

#include "ProcessInfo.hpp"

/**
 * Default Constructor
 * 
 */
ProcessInfo::ProcessInfo() {
	/** Value of 0 means invalid for all fields */
	processID = 0;
	arrivalTime = 0;
	startTime = 0;
	burstTime = 0;
	remainingTime = 0;
	completionTime = 0;
	index = 0;
	priority = 0;
	isStarted = false;
}

/**
 * Object to compare using arrival time + burst time
 * 
 * \param a
 * \param b
 * \return wheter a < b
 */
bool ArrivalTimeComparator::operator() (const ProcessInfo& a, const ProcessInfo& b) {
	return (a.arrivalTime < b.arrivalTime)
		|| (a.arrivalTime == b.arrivalTime && a.burstTime < b.burstTime);
}

/**
 * Object to compare using burst time + arrival time
 * 
 * \param a
 * \param b
 * \return wheter a < b
 */
bool BurstTimeComparator::operator() (const ProcessInfo& a, const ProcessInfo& b) {
	return (a.burstTime > b.burstTime)
		|| (a.burstTime == b.burstTime && a.arrivalTime > b.arrivalTime);
}

/**
 * Object to compare using remaining time + arrival time
 * 
 * \param a
 * \param b
 * \return wheter a < b
 */
bool RemainingTimeComparator::operator() (const ProcessInfo& a, const ProcessInfo& b) {
	return (a.remainingTime > b.remainingTime)
		|| (a.remainingTime == b.remainingTime && a.arrivalTime > b.arrivalTime);
}