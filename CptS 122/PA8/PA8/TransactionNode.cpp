/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA8
Date: 11/15/2018
Discription: Transaction Analysis App
*/
#include "TransactionNode.h"

TransactionNode::~TransactionNode()
{
}

void TransactionNode::setUnits(int & newUnits)
{
	this->mUnits = newUnits;
}

int TransactionNode::getUnits()
{
	return this->mUnits;
}

void TransactionNode::printData()
{
	cout << "Item: " << mData << endl;
	cout << "Units: " << mUnits << endl;
}
