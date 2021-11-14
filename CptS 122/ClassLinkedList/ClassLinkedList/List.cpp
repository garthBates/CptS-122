#include "List.h"

// default constructor; will always set mpHead to NULL or nullptr
List::List()                    
{
	mpHead = nullptr;
}

// copy constructor - implicitly invoked copying a List object during construction of 
// another List object, or when a List object is passed-by-value - must perform a deep copy, 
// which means create new memory for each node copied!
List::List(const List &copyList)     
{
	ListNode *pCur;
	while (copyList.mpHead != nullptr){
		pCur = new ListNode(copyList.mpHead->getData());
		if (mpHead->getNextPtr() == nullptr) {
			mpHead = pCur;
			mpHead->setNextPtr(pCur->getNextPtr());
		}
		else {
			mpHead->setData(pCur->getData());
			//mpHead->setNextPtr(pCur->getNextPtr());
		}
		mpHead->setNextPtr(pCur);
		pCur->setNextPtr(pCur->getNextPtr());
		copyList.mpHead->setNextPtr(copyList.mpHead->getNextPtr());
	}
}

List::~List()                   // destructor - implicitly invoked when a List object leaves scope
{
	cout << "Inside List's destructor! Freeing each ListNode in the List!" << endl;
	destroyList();
}

// this function must allocate new memory for each of the nodes in rhs to construct "this" object
List & List::operator= (const List &rhs) // overloaded assignment operator - must perform a deep copy
{
	// you must use a loop, which visits each of the nodes in List rhs, and assign the data to the new nodes
	// How to use new operator? ListNode *pMem = new ListNode; new is similar to the results of using malloc ()

	// fill in your code here!

	return (*this);
}

// getter
ListNode * List::getHeadPtr() const     // returns a copy of the address stored in mpHead
{
	return mpHead;
}

// setter
void List::setHeadPtr(ListNode * const pNewHead) // modifies mpHead
{
	mpHead = pNewHead;
}

// This function creates a new ListNode on the heap, and uses the ListNode constructor to initialize the node!
bool List::insertAtFront(const int newData)     // inserts newData at the beginning or front of the list
{
	ListNode *pMem = makeNode(newData);
	bool success = false;                   // C++ has built in bool types - false, true

	if (pMem != nullptr)
	{
		success = true; // allocated memory successfully
		// pMem is pointing to a ListNode object, but a List object does not have direct access to it; must use a setter!
		pMem->setNextPtr(mpHead);
		mpHead = pMem;
	}

	return success;
}

// insert newData in ascending order
bool List::insertInOrder(const int newData)     
{
	bool success = false;
	if (mpHead == nullptr)
		return success;
	ListNode *pCur;
	ListNode *newNode = new ListNode(newData);

	while (pCur->getData() < newData || pCur != nullptr) {
		pCur = pCur->getNextPtr();
	}
	newNode->setNextPtr(pCur->getNextPtr());
	pCur->setNextPtr(newNode);
	success = true;

	return success;
}

// inserts newData at the end of the list
bool List::insertAtEnd(const int newData)       
{
	bool success = false;

	ListNode *pCur = mpHead;
	ListNode *newNode = new ListNode(newData);
	while (pCur != nullptr) {
		pCur = pCur->getNextPtr();
	}

	pCur->setNextPtr(newNode);

	return success;
}

// determines if the list is empty;  
// returns true if the list is empty; false otherwise
bool List::isEmpty()                           
{
	return (mpHead == nullptr);
}

// deletes the node at the front of the list and returns a copy of the data
// precondition: list must not be empty
int List::deleteAtFront()                       
{
	int data = 0;

	ListNode *pTemp = mpHead;
	data = mpHead->getData();
	mpHead = mpHead->getNextPtr();
	delete pTemp;

	return data;
}

// deletes the node with data == searchValue;
// returns true if the value was found; false otherwise
// precondition: list must not be empty
bool List::deleteNode(const int searchValue)    
{
	bool success = false;

	ListNode *pCur = mpHead;
	ListNode *pTemp;
	while (pCur->getNextPtr() != nullptr) {
		if (pCur->getNextPtr()->getData() == searchValue) {
			pTemp = pCur->getNextPtr();
			pCur->setNextPtr(pTemp->getNextPtr());
			delete pTemp;
			success = true;
			break;
		}
		pCur = pCur->getNextPtr();
	}

	return success;
}

// deletes the node at the end of the list and returns a copy of the data
// precondition: list must not be empty
int List::deleteAtEnd()                         
{
	int data = 0;
	if (mpHead == nullptr) {
		return data;
	}

	ListNode *pCur = mpHead;
	ListNode *pTemp;
	if (pCur->getNextPtr == nullptr) {
		deleteAtFront();
	}
	else {
		while (pCur->getNextPtr() != nullptr) {
			pCur = pTemp;
			pTemp = pTemp->getNextPtr();
		}
		pCur->setNextPtr(nullptr);
		data = pTemp->getData();
		delete pTemp;
	}
	return data;
}

// visits each node, print the node's data
void List::printList()                          
{
	ListNode *pCur = mpHead;

	while (pCur != nullptr)
	{
		cout << pCur->getData() << endl;
		pCur = pCur->getNextPtr();
	}
}


//////////// private member functions! //////////////

// allocates memory for a Listnode; initializes the memory with newData
ListNode * List::makeNode(const int newData)    // will only call within insert functions
{
	ListNode *pMem = new ListNode(newData);  // ListNode constructor is invoked!

	return pMem;
}

// we created this function so that we could use recursion to delete the nodes!
void List::destroyListHelper(ListNode * const pMem)
{
	if (pMem != nullptr)
	{
		destroyListHelper(pMem->getNextPtr());
		delete pMem;    // delete from the back of list to the front!
	}
}

// deletes each node to free memory; will call in the destructor
void List::destroyList()                        
{
	destroyListHelper(mpHead);
}