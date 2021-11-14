/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA7
Date: 11/08/2018
Discription: Attendance Tracker App
*/
#include "Stack.h"

bool Stack::isEmpty()
{
	return abs.empty();
}

void Stack::push(string & newDate)
{
	abs.push_back(newDate);
}

void Stack::pop()
{
	abs.pop_back();
}

string Stack::peek()
{
	if (!isEmpty()) {
		return abs.back();
	}
	else {
		cout << "Stack is Empty" << endl;
	}
	
}
