/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA7
Date: 11/08/2018
Discription: Attendance Tracker App
*/
#pragma once
#include <iostream>

#include "Node.h"

using std::cout;
using std::endl;

template <class T>
class List
{
public:
	List();
	~List();

	Node<T>* getHead();
	void setHead(Node<T>* newHead);

	void insertAtFront(T* newData);

	bool isEmpty();

	void deleteAtFront();

	void printList();

private:
	Node<T>* pHead;
	Node<T>* makeNode(T* newData);
	void destroyList(Node<T> *pMem);
	void destroyList();
};

template<class T>
inline List<T>::List()
{
	pHead = nullptr;
}

template<class T>
inline List<T>::~List()
{
	destroyList();
}

template<class T>
inline Node<T>* List<T>::getHead()
{
	return pHead;
}


template<class T>
inline void List<T>::setHead(Node<T> * newHead)
{
	this->pHead = newHead;
}

template<class T>
inline void List<T>::insertAtFront(T* newData)
{
	Node<T> *pMem = makeNode(newData);


	if (pMem != nullptr) {
		pMem->setNext(pHead);
		pHead = pMem;
	}
}

template<class T>
inline bool List<T>::isEmpty()
{
	return (pHead == nullptr);
}

template<class T>
inline void List<T>::deleteAtFront()
{
	Node *pTemp = pHead;
	pHead = pHead->getNext();
	delete pTemp;
}

template<class T>
inline void List<T>::printList()
{
	Node *pCur = pHead;

	while (pCur != nullptr) {
		cout <<pCur->getData() << endl;
		pCur = pCur->getNext();
	}
}

template<class T>
inline Node<T> * List<T>::makeNode(T* newData)
{
	Node<T> *pMem = new Node<T>(newData);

	return pMem;
}

template<class T>
inline void List<T>::destroyList(Node<T> * pMem)
{
	if (pMem != nullptr) {
		destroyList(pMem->getNext());
		delete pMem;
	}

}

template<class T>
inline void List<T>::destroyList()
{
	destroyList(pHead);
}


