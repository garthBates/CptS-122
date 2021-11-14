/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA6
Date: 10/24/2018
Discription: BST Morse Code Translator
*/


#pragma once
#include <iostream>


using std::string;



class Node {
public:
	Node(string &newData, char &newChar);
	string getData();
	char getCharacter();
	Node * getNextLeft();
	Node * getNextRight();

	void setData(string &newData);
	void setCharacter(char &newChar);
	void setLeft(Node * newLeft);
	void setRight(Node * newRight);
private:
	string Data;
	char Chatacter;
	Node * pLeft;
	Node * pRight;
};