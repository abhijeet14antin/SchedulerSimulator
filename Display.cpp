#include "Display.hpp"

using std::cout;

void displayProcesses(std::vector<ProcessInfo> info) {
	cout << "\nPID\t\tarrival\t\tburst\t\tstart\t\tcompletion\n";
	for (const auto& item : info) {
		cout << item.processID << "\t\t" << item.arrivalTime << "\t\t"
			<< item.burstTime << "\t\t" << item.startTime << "\t\t" 
			<< item.completionTime << "\n";
	}
}

void displayProcessesFromPtrs(std::vector<std::shared_ptr<ProcessInfo>> infoPtrs) {
	cout << "\nPID\t\tarrival\t\tburst\t\tstart\t\tcompletion\n";
	for (const auto& itemPtr : infoPtrs) {
		cout << itemPtr->processID << "\t\t" << itemPtr->arrivalTime << "\t\t"
			<< itemPtr->burstTime << "\t\t" << itemPtr->startTime << "\t\t"
			<< itemPtr->completionTime << "\n";
	}
}

void displayAlgorithmStats(AlgorithmStats stats) {
	cout << "\nAlgorithm:\t\t";
	switch (stats.algorithm) {
	case SchedulerAlgorithms::FCFS:
		cout << "FCFS\n";
		break;
	case SchedulerAlgorithms::SJF:
		cout << "SJF\n";
		break;
	case SchedulerAlgorithms::SRTF:
		cout << "SRTF\n";
		break;
	case SchedulerAlgorithms::RR:
		cout << "RR\n";
		break;
	}
	
	cout << "CPU Utilization:\t" << stats.cpuUtilization << "\n";
	cout << "Avg Throughput:\t\t" << stats.avgThroughput << "\n";
	cout << "Avg Turnaround Time:\t" << stats.avgTurnaroundTime << "\n";
	cout << "Avg Wait Time:\t\t" << stats.avgWaitTime << "\n";
	cout << "Busy Cycles:\t\t" << stats.busyCycles << "\n";
	cout << "Free Cycles:\t\t" << stats.freeCycles << "\n";
	cout << "Total Cycles:\t\t" << stats.currentCycle<< "\n";
	cout << "Toal Turnaround Time:\t" << stats.totalTurnaroundTime << "\n";
	cout << "Total Wait Time:\t" << stats.totalWaitTime << "\n";
}