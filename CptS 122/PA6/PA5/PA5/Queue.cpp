/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA5
Date: 10/19/2018
Discription: Supermarket Simulation
*/


#include "Queue.h"


Queue::Queue(QueueNode * newHead, QueueNode * newTail)
{
	this->pHead = newHead;
	this->pTail = newTail;
}

QueueNode * Queue::getHead() const
{
	return this->pHead;
}

QueueNode * Queue::getTail() const
{
	return this->pTail;
}

void Queue::enqueue(QueueNode * newNode)
{
	if (newNode != nullptr) { //change to insert at tail and delete at head
		if (this->pHead == nullptr) {
			//queue is empty
			this->setHead(newNode);
		}
		else {
			//not empty insert at tail
			this->pTail->setpNext(newNode);
		}
		this->setTail(newNode);
	}
}

Data Queue::dequeue()
{

	Data returnData;
	QueueNode * pTemp = nullptr;

	pTemp = this->pHead;
	returnData = *this->pHead->getpData();

	//single node
	if (this->pHead->getpData() == this->pTail->getpData()) {
		this->pHead = this->pTail = nullptr;
	}
	else { //multiple nodes
		this->setHead(this->pHead->getpNext());
	}

	pTemp->getpData()->printData();
	delete pTemp;
	return returnData;
}

void Queue::setHead(QueueNode * const newHead)
{
	this->pHead = newHead;
}

void Queue::setTail(QueueNode * const newTail)
{
	this->pTail = newTail;
}

void Queue::printQueue(QueueNode * pHead)
{
	QueueNode * pCur = pHead;
	while (pCur != nullptr) {
		pCur->getpData()->printData();
		//printQueue(pHead->getpNext());
		pCur = pCur->getpNext();
	}
}

bool Queue::isEmpty()
{
	return this->pHead == nullptr;
}
