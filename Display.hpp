#pragma once

#include <iostream>
#include <vector>

#include "ProcessInfo.hpp"
#include "Algorithms.hpp"

void displayProcesses(std::vector<ProcessInfo> info);

void displayProcessesFromPtrs(std::vector<std::shared_ptr<ProcessInfo>> infoPtrs);

void displayAlgorithmStats(AlgorithmStats stats);