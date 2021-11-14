/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA4
Date: 10/8/2018
Discription: Fitness App
*/

#include "deitPlan.h"

DietPlan::DietPlan(string const & newName, string const & newDate, int const newGoal)
{
	name = newName;
	date = newDate;
	goal = newGoal;
}

int DietPlan::getGoal() const
{
	return this->goal;
}

string DietPlan::getDate() const
{
	return this->date;
}


void DietPlan::setGoal(int newGoal)
{
	goal = newGoal;
}

void DietPlan::setName(string newName)
{
	name = newName;
}

void DietPlan::setDate(string newDate)
{
	date = newDate;
}


string DietPlan::getName() const
{
	return this->name;
}
