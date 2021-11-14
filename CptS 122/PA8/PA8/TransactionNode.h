/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA8
Date: 11/15/2018
Discription: Transaction Analysis App
*/
#pragma once

#include <iostream>
#include <string>

#include "Node.h"

using std::string;
using std::cout;
using std::endl;


class TransactionNode : public Node
{	
public:
	TransactionNode(string &newData, int &newUnits) : Node(newData) {
		this->mUnits = newUnits;
	}
	~TransactionNode();
	void setUnits(int &newUnits);
	int getUnits();
	void printData();
private:
	int mUnits;
};