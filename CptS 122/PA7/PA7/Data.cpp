/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA7
Date: 11/08/2018
Discription: Attendance Tracker App
*/
#include "Data.h"

Data::Data(int & newRecord, int & newID, string & newName, string & newEmail, string & newUnits, string & newMajor, string & newLevel)
{
	this->record = newRecord;
	this->ID = newID;
	this->name = newName;
	this->email = newEmail;
	this->units = newUnits;
	this->major = newMajor;
	this->level = newLevel;
	this->absences = 0;
}

void Data::setRcord(int & record)
{
	this->record = record;
}

void Data::setID(int & ID)
{
	this->ID = ID;
}

void Data::setName(string & name)
{
	this->name = name;
}

void Data::setEmail(string & email)
{
	this->email = email;
}

void Data::setUnits(string & units)
{
	this->units = units;
}

void Data::setMajor(string & major)
{
	this->major = major;
}

void Data::setLevel(string & level)
{
	this->level = level;
}

void Data::setAbsences(int  absences)
{
	this->absences = absences;
}

int Data::getRecord()
{
	return this->record;
}

int Data::getID()
{
	return this->ID;
}

string Data::getName()
{
	return this->name;
}

string Data::getEmail()
{
	return this->email;
}

string Data::getUnits()
{
	return this->units;
}

string Data::getMajor()
{
	return this->major;
}

string Data::getLevel()
{
	return this->level;
}

int Data::getAbsences()
{
	return this->absences;
}
