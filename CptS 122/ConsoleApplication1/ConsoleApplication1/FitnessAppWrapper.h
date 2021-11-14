/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA4
Date: 10/8/2018
Discription: Fitness App
*/

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include "exercisePlans.h"
#include "deitPlan.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;

class Wrapper {
public:
	Wrapper();
	void runApp(void);
	void loadDailyPlan(fstream &dietPlansFile, DietPlan &plan);
	void loadDailyPlan(fstream &exercisePlansFile, ExercisePlan &plan);
	void loadWeeklyPlan(fstream &dietPlansFile, DietPlan dPlan[]);
	void loadWeeklyPlan(fstream &exercisePlansFile, ExercisePlan exPlan[]);
	void displayDailyPlan(DietPlan dPlan[], int index);
	void displayDailyPlan(ExercisePlan exPlan[], int index);
	void displayWeeklyPlan(DietPlan dPlan[]);
	void displayWeeklyPlan(ExercisePlan exPlan[]);
	void storeDailyPlan(fstream &dietPlansFile, DietPlan &plan);
	void storeDailyPlan(fstream &exercisePlansFile, ExercisePlan &plan);
	void storeWeeklyPlan(fstream &dietPlansFile, DietPlan dPlan[]);
	void storeWeeklyPlan(fstream &exercisePlansFile, ExercisePlan exPlan[]);
	void editDailyPlan(DietPlan dPlan[]);
	void editDailyPlan(ExercisePlan exPlan[]);
	void displayMenu(void);

private: 
	ExercisePlan exPlan[7];
	DietPlan dPlan[7];
	fstream dietPlansFile;
	fstream exercisePlansFile;
};