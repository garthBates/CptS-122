#pragma once

#include <iostream>
#include "Node.h"

using std::cin;
using std::cout;
using std::endl;

class Queue
{
public:
	Queue(Node *newpHead = nullptr, Node *newPTail = nullptr);
	~Queue();

	bool enqueue(const string &newString);
	string dequeue();
	bool isEmpty();


	void setHeadPtr(Node * const newHeadPtr);
	void setTailPtr(Node * const newTailPtr);

private:
	Node *mpHead;
	Node *mpTail;

	void destroyQueue();
};