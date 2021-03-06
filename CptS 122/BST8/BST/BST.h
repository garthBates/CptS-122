#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Node.h"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

class BST
{
public:
	BST();

	Node *getRootPtr() const;

	void insert(Data const &newData); // will complete definition 10/12
	void inorderTraversal();

private:
	Node *mpRoot;

	// helper
	void insert(Node *pTree, Data const &newData); // will complete definition 10/12
	void inorderTraversal(Node *pTree);

};