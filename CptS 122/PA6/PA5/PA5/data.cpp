/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA5
Date: 10/19/2018
Discription: Supermarket Simulation
*/

#include "data.h"

Data::Data(int const & newCustomerNumber, int const & newServiceTime, int const & newTotalTime)
{
	customerNumber = newCustomerNumber;
	serviceTime = newServiceTime;
	totalTime = newTotalTime;
}


int Data::getCustomerNumber() const
{
	return this->customerNumber;
}

int Data::getServiceTime() const
{
	return this->serviceTime;
}

int Data::getTotalTime() const
{
	return this->totalTime;
}

void Data::setCustomerNumber(int newCustomerNumber)
{
	customerNumber = newCustomerNumber;
}

void Data::setServiceTime(int newServiceTime)
{
	serviceTime = newServiceTime;
}

void Data::setTotalTime(int newTotalTime)
{
	totalTime = newTotalTime;
}

void Data::printData()
{
	cout << "Customer Number: "<< customerNumber << endl;
	cout << "Service Time: " << serviceTime << endl;
	cout << "Total Time: " << totalTime << endl;
	cout << endl;
}

Data & Data::operator=(Data const & rhs)
{
	if (this != &rhs)
	{
		this->customerNumber = rhs.getCustomerNumber();
		this->serviceTime = rhs.getServiceTime();
		this->totalTime = rhs.getTotalTime();
	}

	return (*this);
}
