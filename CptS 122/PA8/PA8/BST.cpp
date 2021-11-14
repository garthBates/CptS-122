/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA8
Date: 11/15/2018
Discription: Transaction Analysis App
*/
#include "BST.h"

BST::BST()
{
	mpRoot = nullptr;
}

BST::~BST()
{
	destroyTree(mpRoot);
}

void BST::setRoot(Node * newRoot)
{
	this->mpRoot = newRoot;
}

Node * BST::getRoot()
{
	return this->mpRoot;
}

void BST::insert(string newData, int newUnits)
{
	insert(mpRoot, newData, newUnits);
}

void BST::inOrderTraversal()
{
	inOrderTraversal(mpRoot);
}

TransactionNode & BST::findSmallest()
{
	return findSmallest(mpRoot);
}

TransactionNode & BST::findLargest()
{
	return findLargest(mpRoot);
}

TransactionNode & BST::findSmallest(Node * &pTree)
{
	if (!isEmpty(pTree)) {
		while (pTree->getRight() != nullptr) {
			pTree = pTree->getRight();
		}
		return *(dynamic_cast<TransactionNode *>(pTree));
	}

}

TransactionNode & BST::findLargest(Node *& pTree)
{
	if (!isEmpty(pTree)) {
		while (pTree->getLeft() != nullptr) {
			pTree = pTree->getLeft();
		}
		return *(dynamic_cast<TransactionNode*>(pTree));
	}
}


bool BST::isEmpty(Node * pTree)
{
	return pTree == nullptr;
}

void BST::destroyTree(Node * pTree)
{
	if (!isEmpty(pTree)) {
		destroyTree(pTree->getLeft());
		destroyTree(pTree->getRight());
		delete pTree;
	}
}

void BST::insert(Node*& pTree, string newData, int newUnits)
{
	if (!isEmpty(pTree)) {
		if (newUnits > (dynamic_cast<TransactionNode*>(pTree))->getUnits()) { //Right
			if (pTree->getRight() == nullptr) {
				pTree->setRight(new TransactionNode(newData, newUnits));
			}
			else {
				insert(pTree->getRight(), newData, newUnits);
			}
		}
		else {
			if (pTree->getLeft() == nullptr) { //Left
				pTree->setLeft(new TransactionNode(newData, newUnits));
			}
			else {
				insert(pTree->getLeft(), newData, newUnits);
			}
		}
	}
	else {
		mpRoot = new TransactionNode(newData, newUnits);
	}
}

void BST::inOrderTraversal(Node *& pTree)
{
	if (!isEmpty(pTree)) {
		inOrderTraversal(pTree->getLeft());
		(dynamic_cast<TransactionNode*>(pTree))->printData();
		inOrderTraversal(pTree->getRight());
	}
}


