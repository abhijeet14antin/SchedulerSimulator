/*********************************************************************
 * \file   Algorithms.hpp
 * \brief  Algorithms stubs
 * 
 * \author abhij
 * \date   December 2023
 *********************************************************************/

#pragma once

#include <cstdint>
#include <queue>
#include <unordered_map>

#include "Scheduler.hpp"
#include "CircularQueue.hpp"
#include "AlgorithmStats.hpp"

AlgorithmStats FCFS(Scheduler& scheduler);

AlgorithmStats SJF(Scheduler& scheduler);

AlgorithmStats SRTF(Scheduler& scheduler);

AlgorithmStats RR(Scheduler& scheduler, uint32_t numCycles);