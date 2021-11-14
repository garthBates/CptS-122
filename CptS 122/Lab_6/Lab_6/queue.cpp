#include "queue.h"

Queue::Queue()
{
}

Queue::~Queue()
{
}

void Queue::enQueue(int newData)
{
	Node* pMem = new Node(newData);
	if (isEmpty() == true) {
		setHead();
		setTail(); 
	}
}

int Queue::deQueue()
{
	if (isEmpty() == true) {
		return 0;
	}
	Node* pTemp = pHead;
	this->pHead = this->pHead->getNext();
	return pTemp->getData();
	delete pTemp;
}

bool Queue::isEmpty()
{
	return (this->pHead == nullptr);
}

void Queue::printQueue()
{

}

void Queue::setHead()
{

}

void Queue::setTail()
{

}

void Queue::getHead()
{

}

void Queue::getTail()
{

}
