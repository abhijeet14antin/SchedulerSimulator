#pragma once

enum class SchedulerAlgorithms 
{
	INVALID,	// Default invalid algorithm
	FCFS,		// First Come First Serve
	SJF,		// Shortest Job First
	SRT,		// Shortest Remaining Time
	RR			// Round Robin
};