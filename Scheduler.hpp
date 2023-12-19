#pragma once

#include <cstdint>
#include <vector>
#include "ProcessInfo.hpp"
#include "Enums.hpp"

using std::vector;

class Scheduler {
public:
	vector<ProcessInfo> processInfo;

	Scheduler(vector<ProcessInfo>& processList);
};