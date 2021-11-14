/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA8
Date: 11/15/2018
Discription: Transaction Analysis App
*/
#pragma once
#include <iostream>
#include <string>
#include "TransactionNode.h"

using std::string;
using std::cout;
using std::endl;

class BST {
public:
	BST();
	~BST();
	void setRoot(Node* newRoot);
	Node* getRoot();
	void insert(string newData, int newUnits); 
	void inOrderTraversal();
	TransactionNode & findSmallest();
	TransactionNode & findLargest();
private:
	Node* mpRoot;
	bool isEmpty(Node* pTree);
	void destroyTree(Node* pTree); //LRP
	void insert(Node*& pTree, string newData, int newUnits);
	void inOrderTraversal(Node*& pTree); //LPR
	TransactionNode & findSmallest(Node* &pTree);
	TransactionNode & findLargest(Node* &pTree);

};