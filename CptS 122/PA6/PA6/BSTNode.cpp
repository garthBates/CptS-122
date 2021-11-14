/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA6
Date: 10/24/2018
Discription: BST Morse Code Translator
*/


#include "BSTNode.h"

Node::Node(string & newData, char & newChar)
{
	this->Data = newData;
	this->Chatacter = newChar;
	this->pLeft = nullptr;
	this->pRight = nullptr;
}

string Node::getData()
{
	return this->Data;
}

char Node::getCharacter()
{
	return this->Chatacter;
}

Node * Node::getNextLeft()
{
	return this->pLeft;
}

Node * Node::getNextRight()
{
	return this->pRight;
}

void Node::setData(string & newData)
{
	this->Data = newData;
}

void Node::setCharacter(char & newChar)
{
	this->Chatacter = newChar;
}

void Node::setLeft(Node * newLeft)
{
	this->pLeft = newLeft;
}

void Node::setRight(Node * newRight)
{
	this->pRight = newRight;
}
