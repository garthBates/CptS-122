/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA4
Date: 10/8/2018
Discription: Fitness App
*/

#include "exercisePlans.h"

ExercisePlan::ExercisePlan(string const & newName, string const & newDate, int const newGoal)
{
	name = newName;
	date = newDate;
	goal = newGoal;
}

int ExercisePlan::getGoal() const
{
	return this->goal;
}

string ExercisePlan::getName() const
{
	return this->name;
}

string ExercisePlan::getDate() const
{
	return this->date;
}

void ExercisePlan::setGoal(int newGoal)
{
	goal = newGoal;
}

void ExercisePlan::setName(string newName)
{
	name = newName;
}

void ExercisePlan::setDate(string newDate)
{
	date = newDate;
}
