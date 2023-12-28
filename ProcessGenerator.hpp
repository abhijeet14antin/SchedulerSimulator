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

/**
 * Generates process using RNG
 *
 * \return A vector of processes generated
 */
std::vector<ProcessInfo> generateRandomProcesses();