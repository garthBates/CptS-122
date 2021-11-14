/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA5
Date: 10/19/2018
Discription: Supermarket Simulation
*/

#pragma once
#include <iostream>

using std::cout;
using std::endl;

class Data {
public:
	//constuctor
	Data(int const &newCustomerNumber = 0, int const &newServiceTime = 0, int const &newTotalTime = 0);
	//Destructor
	//getters
	int getCustomerNumber() const;
	int getServiceTime() const;
	int getTotalTime() const;
	//setters
	void setCustomerNumber(int newCustomerNumber);
	void setServiceTime(int newServiceTime);
	void setTotalTime(int newTotalTime);

	void printData();

	Data & operator= (Data const &rhs); //overloading = operator for data object

private:
	int customerNumber;
	int serviceTime;
	int totalTime;
};