/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA7
Date: 11/08/2018
Discription: Attendance Tracker App
*/

#pragma once
#include <iostream>
#include "Stack.h"

using std::string;
using std::cout;
using std::endl;

class Data {
public:
	Data(int &newRecord, int &newID, string &newName, string &newEmail, string &newUnits, string &newMajor, string &newLevel);
	void setRcord(int &record);
	void setID(int &ID);
	void setName(string &name);
	void setEmail(string &email);
	void setUnits(string &units);
	void setMajor(string &major);
	void setLevel(string &level);
	void setAbsences(int absences);

	int getRecord();
	int getID();
	string getName();
	string getEmail();
	string getUnits();
	string getMajor();
	string getLevel();
	int getAbsences();

private:
	int record;
	int ID;
	string name;
	string email;
	string units;
	string major;
	string level;
	int absences;
	Stack dates;
};