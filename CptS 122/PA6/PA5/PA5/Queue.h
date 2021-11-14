/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA5
Date: 10/19/2018
Discription: Supermarket Simulation
*/

#pragma once

#include "QueueNode.h"

class Queue {
public:
	Queue(QueueNode *newHead = nullptr, QueueNode * newTail = nullptr);

	QueueNode * getHead() const;
	QueueNode * getTail() const;

	void enqueue(QueueNode *newNode);
	Data dequeue();

	void setHead(QueueNode * const newHead);
	void setTail(QueueNode * const newTail);

	void printQueue(QueueNode *pHead);


	bool isEmpty();

private:
	QueueNode *pHead;
	QueueNode *pTail;
};