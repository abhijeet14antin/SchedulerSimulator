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

/**
 * Scheduler Class
 */
class Scheduler {
public:
	std::vector<ProcessInfo> processInfo;
	std::vector<std::shared_ptr<ProcessInfo>> processInfoPtrs;

	Scheduler(std::vector<ProcessInfo>& processList);
};