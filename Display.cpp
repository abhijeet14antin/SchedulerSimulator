#include "Display.hpp"

using std::cout;

void displayProcesses(std::vector<ProcessInfo> info) {
	cout << "PID\t\tarrival\t\texecution\tservice\n";
	for (auto item : info) {
		cout << item.processID << "\t\t" << item.arrivalTime << "\t\t"
			<< item.executeTime << "\t\t" << item.serviceTime << "\n";
	}
}

void displayAlgorithmStats(AlgorithmStats stats) {
	cout << "\nAlgorithm:\t";
	switch (stats.algorithm) {
	case SchedulerAlgorithms::FCFS:
		cout << "FCFS\n";
		break;
	case SchedulerAlgorithms::SJF:
		cout << "SJF\n";
		break;
	case SchedulerAlgorithms::SRT:
		cout << "SRT\n";
		break;
	case SchedulerAlgorithms::RR:
		cout << "RR\n";
		break;
	}
	
	cout << "Avg Throughput:\t" << stats.avgThroughput << "\n";
	cout << "Avg Wait Time:\t" << stats.avgWaitTime << "\n";
	cout << "Avg Latency:\t" << stats.avgLatency << "\n";
}