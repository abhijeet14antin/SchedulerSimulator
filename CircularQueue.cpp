#include "CircularQueue.hpp"

CircularQueue::CircularQueue(uint32_t maxSize) {
	front = 0;
	back = 0;
	this->maxSize = maxSize;
	currentSize = 0;
	queue.resize(maxSize);
}

bool CircularQueue::enqueue(const ProcessInfo& input) {
	// If full, return failure
	if (currentSize == maxSize) {
		return false;
	}
	queue[back] = input;
	back++;
	if (back == maxSize) {
		back = 0;
	}
	currentSize++;
	return true;
}

bool CircularQueue::dequeue(ProcessInfo& output) {
	// If empty, return failure
	if (currentSize == 0) {
		return false;
	}
	output = queue[front];
	front++;
	if (front == maxSize) {
		front = 0;
	}
	currentSize--;
	return true;
}