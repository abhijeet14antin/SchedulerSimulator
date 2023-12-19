#pragma once

#include <cstdint>
#include <vector>
#include "ProcessInfo.hpp"
#include "Enums.hpp"

using std::vector;

class Scheduler 
{
private:
	vector<ProcessInfo> processInfo;

public:
	Scheduler(vector<ProcessInfo> processList);
};