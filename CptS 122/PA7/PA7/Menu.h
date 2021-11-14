/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA7
Date: 11/08/2018
Discription: Attendance Tracker App
*/
#pragma once
#include <iostream>
#include <string>
#include<fstream>

#include "List.h"
#include "Data.h"

using std::fstream;
using std::getline;
using std::cin;
using std::endl;

class Menu {
public:
	Menu();
	~Menu();
	void importCourseList();
	void loadMasterList();
	void storeMasterList();
	void markAbsences();
	void editAbsences();
	void generateReport();

private:
	void storeMasterList(List<Node<Data>> list);
	fstream courseFile;
	fstream masterFile;
	List<Node<Data>> courseList;
	List<Node<Data>> masterList;


};