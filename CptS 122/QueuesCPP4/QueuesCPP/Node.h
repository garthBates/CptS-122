#pragma once

#include <iostream>
#include <string>

// using namespace std;

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Node
{
public:
	Node(string const &newString = ""); // constructor w/ default arguments
	~Node()
	{
		cout << "Inside of node destructor!" << endl;
	}

	void setNextPtr(Node *newNextPtr);
	string getPrintJob() const;
	Node *getNextPtr() const;

private:
	// data members
	Node *mpNext;
	string mPrintJob;
};