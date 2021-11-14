/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA6
Date: 10/24/2018
Discription: BST Morse Code Translator
*/


#pragma once 

#include <fstream>
#include <iostream>
#include <string>
#include <locale>
#include "BSTNode.h"

using std::string;
using std::endl;
using std::cout;
using std::fstream;

class BST {

public:
	BST();
	~BST();
	void insert(char &newChar, string &newData);
	void printInOrder(); //LPR
	void translate();
	bool isEmpty(Node * pTree);
	string search(char &lookUpChar);

private:
	Node * pRoot;
	void insert(Node *pTree, string &newData, char &newChar);
	string search(Node * pTree, char &lookUpChar);
	void printInOrder(Node * pTree);
	void translate(Node * pTree, string &newString);
	void destroyTree(Node * pTree);
};