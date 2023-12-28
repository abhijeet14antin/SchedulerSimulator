#pragma once

enum class SchedulerAlgorithmsEnum 
{
	INVALID,	// Default invalid algorithm
	FCFS,		// First Come First Serve
	SJF,		// Shortest Job First
	SRTF,		// Shortest Remaining Time First
	RR			// Round Robin
};