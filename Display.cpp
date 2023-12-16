#include "Display.hpp"

using std::cout;

void displayProcesses(std::vector<ProcessInfo> info) {
	cout << "PID\t\tarrival\t\texecution\tservice\n";
	for (auto item : info) {
		cout << item.processID << "\t\t" << item.arrivalTime << "\t\t"
			<< item.executeTime << "\t\t" << item.serviceTime << "\n";
	}
}