/*********************************************************************
 * \file   CircularQueue.hpp
 * \brief  Header for of CircularQueue class for processes 
 * 
 * \author abhij
 * \date   December 2023
 *********************************************************************/

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

	/**
	 * Constructor to initialize data members
	 *
	 * \param maxSize Maximum size for circular queue
	 */
	CircularQueue(uint32_t maxSize);

	/**
	 * Enqueue process in circular queue
	 *
	 * \param input Process to be queued
	 * \return whether enqueue was successful
	 */
	bool enqueue(const ProcessInfo& enqueuePtr);

	/**
	 * Dequeue process from circular queue
	 *
	 * \param output Reference where output is returned
	 * \return whether dequeu was successful
	 */
	bool dequeue(ProcessInfo& dequeuePtr);
};