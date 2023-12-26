/*	CircularQueue to work on any object type
 */

#pragma once

#include<iostream>
#include<vector>

#include "ProcessInfo.hpp"

class CircularQueue {
public:
	uint32_t maxSize;
	uint32_t currentSize;
	uint32_t front;
	uint32_t back;
	std::vector<ProcessInfo> queue;

	CircularQueue(uint32_t maxSize);

	bool enqueue(const ProcessInfo& enqueuePtr);
	bool dequeue(ProcessInfo& dequeuePtr);
};