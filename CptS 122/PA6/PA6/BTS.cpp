/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA6
Date: 10/24/2018
Discription: BST Morse Code Translator
*/


#include "BTS.h"


BST::BST()
{
	char tempC;
	string tempS;
	fstream inputFile("MorseTable.txt", std::ios::in);
	pRoot = nullptr;
	while (!inputFile.std::ios::eof()) {
		inputFile >> tempC;
		inputFile >> tempS;
		insert(tempC, tempS);
	}
	inputFile.close();
	cout << "BTS created!" << endl;
}

BST::~BST()
{
	destroyTree(pRoot);
}

void BST::insert(char & newChar, string & newData)
{
	insert(pRoot, newData, newChar);
}

void BST::printInOrder()
{
	printInOrder(pRoot);
}

void BST::translate()
{
	std::locale loc;
	string temp;
	string temp2;
	fstream infile("Convert.txt", std::ios::in);
	while (!infile.std::ios::eof()) {
		infile >> temp;
		if (temp == "\n") {
			temp2 += "\n";
		}
		else {
			for (std::string::size_type i = 0; i < temp.length(); ++i) {
				temp2 += std::toupper(temp[i], loc);
			}
			translate(pRoot, temp2);
			temp2 = "";
		}
	}
	infile.close();
}

void BST::translate(Node * pTree, string & newString)
{
	string temp;
	for (std::string::size_type i = 0; i < newString.length(); ++i) {
		temp += search(newString[i]);
		temp += " ";
	}
	cout << temp << "   ";
}

void BST::printInOrder(Node * pTree) 
{
	if (!isEmpty(pTree)) {
		printInOrder(pTree->getNextLeft());
		cout << "Character: " << pTree->getCharacter() << endl;
		cout << "Morse Code: " << pTree->getData() << endl;
		printInOrder(pTree->getNextRight());
	}
}

bool BST::isEmpty(Node * pTree)
{
	return pTree == nullptr;
}

string BST::search(char & lookUpChar)
{
	return search(pRoot, lookUpChar);
}

void BST::insert(Node * pTree, string & newData, char & newChar)
{
	if (!isEmpty(pTree)) {
		if (newChar > pTree->getCharacter()) { //Right
			if (pTree->getNextRight() == nullptr) {
				pTree->setRight(new Node(newData, newChar));
			}
			else {
				insert(pTree->getNextRight(), newData, newChar);
			}
		}
		else {
			if (pTree->getNextLeft() == nullptr) { //Left
				pTree->setLeft(new Node(newData, newChar));
			}
			else {
				insert(pTree->getNextLeft(), newData, newChar);
			}
		}
	}
	else {
		pRoot = new Node(newData, newChar);
	}
}

string BST::search(Node * pTree, char & lookUpChar)
{
	if (lookUpChar == pTree->getCharacter()) { //Process
		return pTree->getData();
	}
	else if (lookUpChar < pTree->getCharacter()) { //left
		return search(pTree->getNextLeft(), lookUpChar);
	}
	else if (lookUpChar > pTree->getCharacter()) { //Right
		return search(pTree->getNextRight(), lookUpChar);
	}
}

void BST::destroyTree(Node * pTree)
{
	if (!isEmpty(pTree)) {
		destroyTree(pTree->getNextLeft());
		destroyTree(pTree->getNextRight());
		delete pTree;
	}
}
