/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA8
Date: 11/15/2018
Discription: Transaction Analysis App
*/
#pragma once
#include <iostream>
#include <fstream>
#include "BST.h"

using std::ifstream;

#include <fstream>
class DataAnalysis {
public:
	void runAnalysis();
private:
	BST TreeSold;
	BST TreePurchased;
	ifstream mCsvStream;

	void openInfile();
	void readLine(string* type, string* transaction, int* numUnits);
	void populateTrees();
	void compareTransaction(string transaction, string type, int units);
	void displayTrends();
};