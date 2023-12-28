/*********************************************************************
 * \file   ProcessGenerator.hpp
 * \brief  ProcessGenerator header
 * 
 * \author abhij
 * \date   December 2023
 *********************************************************************/

#pragma once

#include <vector>
#include <random>

#include "ProcessInfo.hpp"

using std::vector;

/**
 * Generates process using RNG
 *
 * \return A vector of processes generated
 */
vector<ProcessInfo> generateRandomProcesses();