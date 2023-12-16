#pragma once

#include <cstdint>

/*	Object to store statistics per algorithm
 */
class AlgorithmStats 
{
private:
	uint32_t throughput;
	uint32_t watTime;
	uint32_t latency;
};

