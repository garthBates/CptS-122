/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA5
Date: 10/19/2018
Discription: Supermarket Simulation
*/

#include "QueueNode.h"

QueueNode::QueueNode(Data * newData)
{
	this->pData = newData;
	this->pNext = nullptr;
}


Data * QueueNode::getpData() const
{
	return this->pData;
}

QueueNode * QueueNode::getpNext() const
{
	return this->pNext;
}

void QueueNode::setpData(Data * const &newData)
{
	this->pData = newData;
}

void QueueNode::setpNext(QueueNode * const  &newpNext)
{
	this->pNext = newpNext;
}
