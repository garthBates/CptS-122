/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA7
Date: 11/08/2018
Discription: Attendance Tracker App
*/
#pragma once
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

class Stack {
public:
	bool isEmpty();
	void push(string &newDate);
	void pop();
	string peek();

private:
	vector<string> abs;
	//string Date;

};