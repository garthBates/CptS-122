/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA5
Date: 10/19/2018
Discription: Supermarket Simulation
*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>


#include "Queue.h"


using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

class QueueTests {

public:
	void testInsertOnEmptyQueue();
	void testInsertOnOneNodeQueue();
	void testDequeueOnOneNode();
	void testDequeueOnTwoNodes();
	void test24HourRun();

private:

	Queue test;
};