#include "Queue.h"

Queue::Queue(Node *newpHead, Node *newPTail)
{
	this->mpHead = newpHead;
	this->mpTail = newPTail;
}

Queue::~Queue()
{
	this->destroyQueue();
}

bool Queue::enqueue(const string &newString)
{
	bool success = false;

	Node *pMem = new Node(newString);

	if (pMem != nullptr)
	{
		success = true;

		// works if queue is empty
		if (this->mpHead == nullptr)
		{
			this->setHeadPtr(pMem);
			this->setTailPtr(pMem);
			//this->mpHead = this->mpTail = pMem;
		}
		else
		{
			// not empty - insert at the tail
			this->mpTail->setNextPtr(pMem);
			this->setTailPtr(pMem);
		}
	}

	return success;
}

// precondition: queue must not be empty
string Queue::dequeue()
{
	string returnData = "";
	Node *pTemp = nullptr;

	pTemp = this->mpHead;
	returnData = this->mpHead->getPrintJob();

	// think state of queue
	if (this->mpHead == this->mpTail)
	{
		// single node in queue
		this->mpHead = this->mpTail = nullptr;
	}
	else
	{
		// more than one node in queue
		this->setHeadPtr(this->mpHead->getNextPtr());
	}

	delete pTemp;
	
	return returnData;

}


bool Queue::isEmpty()
{
	return this->mpHead == nullptr;
}

void Queue::setHeadPtr(Node * const newHeadPtr)
{
	this->mpHead = newHeadPtr;
}

void Queue::setTailPtr(Node * const newTailPtr)
{
	this->mpTail = newTailPtr;
}

void Queue::destroyQueue()
{
	// check empty queue
	while (!this->isEmpty ())//this->mpHead != nullptr)
	{
		this->dequeue();
	}
}