/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA7
Date: 11/08/2018
Discription: Attendance Tracker App
*/
#pragma once
#include <iostream>

template <class T>
class Node {
public:
	Node(T* &newData);
	void setData(T &newData);
	void setNext(Node<T>* pNext);

	T* getData();
	Node* getNext();
private:
	Node<T>* pNext;
	T* data;
};

template<class T>
inline Node<T>::Node(T* & newData)
{
	this->data = newData;
	this->pNext = nullptr;
}

template<class T>
inline void Node<T>::setData(T & newData)
{
	this->data = newData;
}

template<class T>
inline void Node<T>::setNext(Node<T>* pNext)
{
	this->pNext = pNext;
}

template<class T>
inline T* Node<T>::getData()
{
	return this->data;
}

template<class T> //I keep getting read errors thrown at me point to this function, but its it not being called and I have no idea what is going on, I speant too much time trying to debug it
inline Node<T> * Node<T>::getNext()
{
	return this->pNext;
}
