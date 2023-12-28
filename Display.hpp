/*********************************************************************
 * \file   Display.hpp
 * \brief  Functions to display various info
 * 
 * \author abhij
 * \date   December 2023
 *********************************************************************/

#pragma once

#include <iostream>
#include <vector>

#include "ProcessInfo.hpp"
#include "Algorithms.hpp"

 /**
  * Displays process info
  *
  * \param info Vector of process info
  */
void displayProcesses(std::vector<ProcessInfo> info);

/**
 * Displays process info that has been stored using pointers
 *
 * \param infoPtrs Vector of pointers to process info
 */
void displayProcessesFromPtrs(std::vector<std::shared_ptr<ProcessInfo>> infoPtrs);

/**
 * Display algorithm statistics
 *
 * \param stats The algorithm stats to be displayed
 */
void displayAlgorithmStats(AlgorithmStats stats);