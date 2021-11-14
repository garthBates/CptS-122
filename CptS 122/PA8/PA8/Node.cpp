/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA8
Date: 11/15/2018
Discription: Transaction Analysis App
*/
#include "Node.h"

Node::Node(string & newData)
{
	this->mData = newData;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

Node::~Node()
{
}

void Node::setData(string & newData)
{
	this->mData = newData;
}

void Node::setLeft(Node * newLeft)
{
	this->mpLeft = newLeft;
}

void Node::setRight(Node * newRight)
{
	this->mpRight = newRight;
}

string Node::getData()
{
	return this->mData;
}

Node *& Node::getLeft()
{
	return this->mpLeft;
}

Node *& Node::getRight()
{
	return this->mpRight;
}
