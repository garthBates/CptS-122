#pragma once
#include <iostream>


using std::string;
using std::cout;

class BST{
public:
	void insert(string newData);
	void inOrder();
	void postOrder();
	void preOrder();
	bool isEmpty(Node * pTree)
private:
	Node * mpRoot;
	void insert(node * pTree, string newData);
	void destroyTree();
	void inOrder(Node * pTree);
	void postOrder(Node * pTree);
	void preOrder(Node * pTree);
}