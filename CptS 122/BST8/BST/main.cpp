// History: 10/17 - Implemented inorderTraversal (). Discussed
//                  the function call stack's role in traversing
//                  the tree recursively.
//          10/15 - Completed insert () for inserting into a 
//                  binary search tree. We added a partial test
//                  for inserting into an empty tree, testInsertOnEmptyTree().
//          10/12 - Completed parts of insert () for inserting
//                  into an empty tree and for inserting into a left
//                  subtree. Will complete inserting into a right
//                  subtree on Monday, 10/15.
//          10/10 - Defined attributes of class Node. Created
//                  a constructor for class Node. Defined
//                  attributes of class BST. Declared both
//                  private and public insert () functions
//          10/8 - Worked on parts of the class Node and class Data.

#include "Node.h"
#include "BST.h"
#include "BSTTests.h"

int main(void)
{
	BSTTests test;

	test.testInsertOnEmptyTree();

	Data d1(20), d2(10), d3(30);
	Node n1(d1);
	BST tree; // empty tree

	tree.insert(d1); // insert into empty tree
	tree.insert(d2); // insert into left subtree
	tree.insert(d3);
	tree.inorderTraversal();
	//if (tree.)

	d2 = n1.getData(); // when the data is returned from getData (), which function is called here? the copy constructor for a Data object!

	return 0;
}