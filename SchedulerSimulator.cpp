// SchedulerSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdint>
#include <vector>

#include "enums.hpp"
#include "Scheduler.hpp"
#include "ProcessGenerator.hpp"
#include "Display.hpp"
#include "Algorithms.hpp"

void test() {

}

int main() {

    test();

    std::cout << "For now, using hardcoded parameters\n";
    vector<ProcessInfo> processInfo = generateRandomProcesses();
    Scheduler* scheduler;

    bool displayProcessInfo = false;
    
    scheduler = new Scheduler(processInfo);
    AlgorithmStats stats = FCFS(*scheduler);
    if (displayProcessInfo) displayProcesses(scheduler->processInfo);
    displayAlgorithmStats(stats);

    scheduler = new Scheduler(processInfo);
    stats = SJF(*scheduler);
    if (displayProcessInfo) displayProcesses(scheduler->processInfo);
    displayAlgorithmStats(stats);

    scheduler = new Scheduler(processInfo);
    stats = RR(*scheduler, 1);
    if (displayProcessInfo) displayProcesses(scheduler->processInfo);
    displayAlgorithmStats(stats);

    scheduler = new Scheduler(processInfo);
    stats = RR(*scheduler, 2);
    if (displayProcessInfo) displayProcesses(scheduler->processInfo);
    displayAlgorithmStats(stats);

    scheduler = new Scheduler(processInfo);
    stats = RR(*scheduler, 5);
    if (displayProcessInfo) displayProcesses(scheduler->processInfo);
    displayAlgorithmStats(stats);
    
    /*
    stats = SRTF(scheduler);
    displayProcesses(scheduler.processInfo);
    displayAlgorithmStats(stats);
    */
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
