#include "Node.h"

Node::Node(string const &newString)
{
	mPrintJob = newString;
	mpNext = nullptr;
}

void Node::setNextPtr(Node *newNextPtr)
{
	this->mpNext = newNextPtr;
}

string Node::getPrintJob() const
{
	return this->mPrintJob;
}

Node * Node::getNextPtr() const
{
	return this->mpNext;
}