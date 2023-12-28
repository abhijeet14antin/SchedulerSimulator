/*********************************************************************
 * \file   Scheduler.hpp
 * \brief  Scheduler class declaration
 * 
 * \author abhij
 * \date   December 2023
 *********************************************************************/

#pragma once

#include <cstdint>
#include <vector>
#include <iostream>

#include "ProcessInfo.hpp"
#include "Enums.hpp"

using std::vector;

/**
 * Scheduler Class
 */
class Scheduler {
public:
	vector<ProcessInfo> processInfo;
	vector<std::shared_ptr<ProcessInfo>> processInfoPtrs;

	Scheduler(vector<ProcessInfo>& processList);
};