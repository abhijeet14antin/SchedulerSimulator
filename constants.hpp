/*********************************************************************
 * \file   constants.hpp
 * \brief  contains constants used across project
 * 
 * \author abhij
 * \date   January 2024
 *********************************************************************/

#pragma once

#include <cstdint>

namespace constants {
	/** Number of processes in simulation */
	const uint32_t n = 5;

	/** Constants related to process generation */
	const uint32_t minArrivalTime = 1;
	const uint32_t maxArrivalTime = n * 2;
	const uint32_t minBurstTime = 1;
	const uint32_t maxBurstTime = n; // / 2;

	/** Sleep duration for each time cycle */
	const int64_t sleepTimeMillis = 50;
}
