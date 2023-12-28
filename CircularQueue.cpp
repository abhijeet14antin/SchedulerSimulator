/*********************************************************************
 * \file   CircularQueue.cpp
 * \brief  Definition of circular queue for processes 
 * 
 * \author abhij
 * \date   December 2023
 *********************************************************************/

#include "CircularQueue.hpp"

/**
 * Constructor to initialize data members
 * 
 * \param maxSize Maximum size for circular queue
 */
CircularQueue::CircularQueue(uint32_t maxSize) {
	front = 0;
	back = 0;
	this->maxSize = maxSize;
	currentSize = 0;
	queue.resize(maxSize);
}

/**
 * Enqueue process in circular queue
 * 
 * \param input Process to be queued
 * \return whether enqueue was successful
 */
bool CircularQueue::enqueue(const ProcessInfo& input) {
	/** If full, return failure */
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

/**
 * Dequeue process from circular queue
 * 
 * \param output Reference where output is returned
 * \return whether dequeu was successful
 */
bool CircularQueue::dequeue(ProcessInfo& output) {
	/** If empty, return failure */
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