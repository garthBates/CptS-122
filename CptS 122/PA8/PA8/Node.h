/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA8
Date: 11/15/2018
Discription: Transaction Analysis App
*/
#pragma once
#include <iostream>

using std::string;

class Node {
public:
	Node(string &newData);
	virtual ~Node();
	virtual void printData() = 0;

	void setData(string &newData);
	void setLeft(Node* newLeft);
	void setRight(Node* newRight);

	string getData();
	Node*& getLeft();
	Node*& getRight();
protected:
	string mData;
	Node* mpLeft;
	Node* mpRight;
};