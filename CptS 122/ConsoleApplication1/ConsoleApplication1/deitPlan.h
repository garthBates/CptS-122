/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA4
Date: 10/8/2018
Discription: Fitness App
*/

#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class DietPlan {
public:
	DietPlan(string const &newName = "", string const &newDate = "", int const newGoal = 0); //constructor with default values
	//getters
	int getGoal() const;
	string getName() const;
	string getDate() const;
	//setters
	void setGoal(int newGoal); 
	void setName(string newName);
	void setDate(string newDate);
	
private: 
	string name;
	string date;
	int goal;
};