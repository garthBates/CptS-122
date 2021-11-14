/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA8
Date: 11/15/2018
Discription: Transaction Analysis App
*/
#include "DataAnalysis.h"

void DataAnalysis::runAnalysis()
{
	openInfile();
	populateTrees();
	displayTrends();
}

void DataAnalysis::openInfile()
{
	mCsvStream.open("data.csv");
}

void DataAnalysis::readLine(string * type, string * transaction, int * numUnits)
{
	string units;
	getline(mCsvStream, units, ',');
	*(numUnits) = atoi(units.c_str());
	getline(mCsvStream, *type, ',');
	getline(mCsvStream, *transaction);
}


void DataAnalysis::populateTrees()
{
	string temp;
	string type ="", transaction = "";
	int units = 0;

	getline(mCsvStream, temp);
	while (true) {
		readLine(&type, &transaction, &units);
		if (mCsvStream.eof()) break;
		compareTransaction(transaction, type, units);
	}
	cout << "Purchased Items" << endl;
	TreePurchased.inOrderTraversal();
	cout << "Sold Items" << endl;
	TreeSold.inOrderTraversal();
	system("pause");
}

void DataAnalysis::compareTransaction(string transaction, string type, int units)
{
	if (transaction == "Purchased") {
		TreePurchased.insert(type, units);
	}
	else {
		TreeSold.insert(type, units);
	}
}

void DataAnalysis::displayTrends()
{
	cout << "Most Purchased" << endl;
	TransactionNode temp = TreePurchased.findLargest();
	temp.printData();
	cout << "Least Purchased" << endl;
	temp = TreePurchased.findSmallest();
	temp.printData();
	cout << "Most Sold" << endl;
	temp = TreeSold.findLargest();
	temp.printData();
	cout << "Least Sold" << endl;
	temp = TreeSold.findSmallest();
	temp.printData();
	system("pause");
}
