#pragma once

#include <cstdint>
#include <vector>
#include <iostream>

#include "ProcessInfo.hpp"
#include "Enums.hpp"

using std::vector;

class Scheduler {
public:
	vector<ProcessInfo> processInfo;
	vector<std::shared_ptr<ProcessInfo>> processInfoPtrs;

	Scheduler(vector<ProcessInfo>& processList);
};