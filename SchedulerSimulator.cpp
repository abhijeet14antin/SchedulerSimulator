/*********************************************************************
 * \file   SchedulerSimulator.cpp
 * \brief  Starting point for the scheduler simulator
 * 
 * \author abhij
 * \date   December 2023
 *********************************************************************/

#include <iostream>
#include <cstdint>
#include <vector>

#include "enums.hpp"
#include "Scheduler.hpp"
#include "ProcessGenerator.hpp"
#include "Display.hpp"
#include "Algorithms.hpp"

/**
 * 
 * 
 */
void test() {

}

/**
 * Where the program starts
 * 
 * \return Exit code
 */
int main() {

    test();

    std::cout << "For now, using hardcoded parameters\n";
    std::vector<ProcessInfo> processInfo = generateRandomProcesses();
    Scheduler* scheduler;

    bool displayProcessInfo = true;
    
    scheduler = new Scheduler(processInfo);
    std::cout << "Single thread________________________:\n";
    AlgorithmStats stats = FCFS(*scheduler);
    if (displayProcessInfo) displayProcesses(scheduler->processInfoList);
    displayAlgorithmStats(stats);
    std::cout << "\n\nMultiple threads________________________\n";
    stats = scheduler->FCFS();
    if (displayProcessInfo) displayProcesses(scheduler->processInfoList);
    displayAlgorithmStats(stats);

    /*
    scheduler = new Scheduler(processInfo);
    stats = SJF(*scheduler);
    if (displayProcessInfo) displayProcesses(scheduler->processInfoList);
    displayAlgorithmStats(stats);

    scheduler = new Scheduler(processInfo);
    stats = RR(*scheduler, 1);
    if (displayProcessInfo) displayProcesses(scheduler->processInfoList);
    displayAlgorithmStats(stats);

    scheduler = new Scheduler(processInfo);
    stats = RR(*scheduler, 2);
    if (displayProcessInfo) displayProcesses(scheduler->processInfoList);
    displayAlgorithmStats(stats);

    scheduler = new Scheduler(processInfo);
    stats = RR(*scheduler, 5);
    if (displayProcessInfo) displayProcesses(scheduler->processInfoList);
    displayAlgorithmStats(stats);
    */
    
    /*
    stats = SRTF(scheduler);
    displayProcesses(scheduler.processInfo);
    displayAlgorithmStats(stats);
    */
}