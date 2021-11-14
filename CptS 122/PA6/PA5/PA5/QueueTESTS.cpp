/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA5
Date: 10/19/2018
Discription: Supermarket Simulation
*/

#include "QueueTESTS.h"

#include <iostream>
#include <ctime> 
void QueueTests::testInsertOnEmptyQueue()
{
	Data newData(1, 4, 0);
	QueueNode * newNode = new QueueNode(&newData);
	test.enqueue(newNode); 
	if (test.getHead()->getpData()->getCustomerNumber() == 1) {
		cout << "Inserted node correctly!" << endl;
	}
	else {
		cout << "Warning: inserted node incorrectly!" << endl;
	}
}

void QueueTests::testInsertOnOneNodeQueue()
{
	Data d1(1, 4, 0);
	Data d2(2, 7, 13);
	QueueNode * Node1 = new QueueNode(&d1);
	QueueNode * Node2 = new QueueNode(&d2);
	test.enqueue(Node1);
	test.enqueue(Node2);
	if (test.getHead()->getpData()->getCustomerNumber() == 1 && test.getTail()->getpData()->getCustomerNumber() == 2) {
		cout << "Inserted nodes correctly!" << endl;
	}
	else {
		cout << "Warning: Inserted nodes incorrectly!" << endl;
	}
}

void QueueTests::testDequeueOnOneNode()
{
	Data newData(1, 4, 0);
	QueueNode * newNode = new QueueNode(&newData);
	test.enqueue(newNode);

	test.dequeue();
	if (test.getTail() == nullptr) {
		cout << "Dequeued node correctly!" << endl;
	}
	else {
		cout << "Warning: dequeued node incorrectly!" << endl;
	}
}

void QueueTests::testDequeueOnTwoNodes()
{	
	Data d1(1, 4, 0);
	Data d2(2, 7, 13);
	Data temp();
	QueueNode * Node1 = new QueueNode(&d1);
	QueueNode * Node2 = new QueueNode(&d2);
	test.enqueue(Node1);
	test.enqueue(Node2);
	test.dequeue();
	test.dequeue();
	if (test.getTail() == nullptr) {
		cout << "Dequeued nodes correctly!" << endl;
	}
	else {
		cout << "Warning: dequeued nodes incorrectly!" << endl;
	}

}

void QueueTests::test24HourRun()
{
	srand(time(NULL));
	int arrivalTime = rand() % 5 + 1;
	int newSeriveTime = rand() % 4 + 2;
	int serviceTime = 1;
	int totalTime = newSeriveTime;
	int customerNumber = 1;
	Data c1(customerNumber, newSeriveTime, totalTime);
	QueueNode * customer1 = new QueueNode(&c1);
	QueueNode * newCustomer;
	test.enqueue(customer1);

	for (int i = 1; i <= 1441; i++) {
		if (arrivalTime == 0) {
			newSeriveTime = rand() % 3 + 1;
			if (!test.isEmpty()) {
				totalTime = newSeriveTime + test.getTail()->getpData()->getTotalTime();
			}
			else {
				totalTime = newSeriveTime;
			}
			Data temp(++customerNumber, newSeriveTime, totalTime);
			newCustomer = new QueueNode(&temp);
			test.enqueue(newCustomer);
			arrivalTime = rand() % 5 + 1;
		}
		--arrivalTime;

		if (i % 10 == 0) {
			if (!test.isEmpty()) {
				cout << "Currently in Test lane: " << endl;
				test.printQueue(test.getHead());
			}
			else {
				cout << "Test lane is Empty!" << endl;
			}
		}

		if (!test.isEmpty()) {
			int checkoutTimer = test.getHead()->getpData()->getServiceTime();
			test.getHead()->getpData()->setServiceTime(--checkoutTimer);
			if (test.getHead()->getpData()->getServiceTime() == 0) {
				test.getHead()->getpData()->setServiceTime(serviceTime);
				test.dequeue();
				serviceTime = 0;
			}
			++serviceTime;
		}
	}
}
