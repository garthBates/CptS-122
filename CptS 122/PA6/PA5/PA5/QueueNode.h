/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA5
Date: 10/19/2018
Discription: Supermarket Simulation
*/

#pragma once

#include "data.h"

#include <ctime>

class QueueNode {
public:
	//Constructor
	QueueNode(Data * newData = nullptr);
	//getters
	Data * getpData() const;
	QueueNode * getpNext() const ;
	//setters
	void setpData(Data * const &newData);
	void setpNext(QueueNode * const &newpNext);

private:
	Data *pData;
	QueueNode *pNext;
};