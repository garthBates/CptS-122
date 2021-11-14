/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA5
Date: 10/19/2018
Discription: Supermarket Simulation
*/

#include "QueueTESTS.h"
#include "Queue.h"


int main(void) {

	QueueTests test;
	Queue express;
	Queue reg;

	//Tests
	test.testInsertOnEmptyQueue();
 	system("pause");
	test.testInsertOnOneNodeQueue();
	system("pause");
	test.testDequeueOnOneNode();
	system("pause");
	test.testDequeueOnTwoNodes();
	system("pause");
	test.test24HourRun();
	system("pause");


	//Main
	system("cls");
	cout << "Express Lane!" << endl;
	system("pause");
	srand(time(NULL));
	int arrivalTimeEx = rand() % 5 + 1;
	int newSeriveTimeEx = rand() % 4 + 2;
	int serviceTimeEx = 1;
	int totalTimeEx = newSeriveTimeEx;
	int customerNumberEx = 1;
	Data c1(customerNumberEx, newSeriveTimeEx, totalTimeEx);
	QueueNode * customer1Ex = new QueueNode(&c1);
	QueueNode * newCustomerEx;
	express.enqueue(customer1Ex);

	for (int i = 1; i <= 1441; i++) {
		if (arrivalTimeEx == 0) {
			newSeriveTimeEx = rand() % 4 + 2;
			if (!express.isEmpty()) {
				totalTimeEx = newSeriveTimeEx + express.getTail()->getpData()->getTotalTime();
			}
			else {
				totalTimeEx = newSeriveTimeEx;
			}
			Data temp(++customerNumberEx, newSeriveTimeEx, totalTimeEx);
			newCustomerEx = new QueueNode(&temp);
			express.enqueue(newCustomerEx);
			arrivalTimeEx = rand() % 5 + 1;
		}
		--arrivalTimeEx;

		if (i % 10 == 0) {
			if (!express.isEmpty()) {
				cout << "Currently in Express lane: " << endl;
				express.printQueue(express.getHead());
			}
			else {
				cout << "Express lane is Empty!" << endl;
			}
		}

		if (!express.isEmpty()) {
			int checkoutTimer = express.getHead()->getpData()->getServiceTime();
			express.getHead()->getpData()->setServiceTime(--checkoutTimer);
			if (express.getHead()->getpData()->getServiceTime() == 0) {
				express.getHead()->getpData()->setServiceTime(serviceTimeEx);
				express.dequeue();
				serviceTimeEx = 0;
			}
			++serviceTimeEx;
		}
	}
	system("pause");
	system("cls");
	cout << "Regular Lane!" << endl;
	system("pause");
	int arrivalTime = rand() % 8 + 3;
	int newSeriveTime = rand() % 10 + 5;
	int serviceTime = 1;
	int totalTime = newSeriveTime;
	int customerNumber = 1;
    Data c2(customerNumber, newSeriveTime, totalTime);
	QueueNode * customer1 = new QueueNode(&c2);
	QueueNode * newCustomer;
	reg.enqueue(customer1);

	for (int i = 1; i <= 1441; i++) {
		if (arrivalTime == 0) {
			newSeriveTime = rand() % 10 + 5;
			if (!reg.isEmpty()) {
				totalTime = newSeriveTime + reg.getTail()->getpData()->getTotalTime();
			}
			else {
				totalTime = newSeriveTime;
			}
			Data temp(++customerNumber, newSeriveTime, totalTime);
			newCustomer = new QueueNode(&temp);
			reg.enqueue(newCustomer);
			arrivalTime = rand() % 8 + 3;
		}
		--arrivalTime;

		if (i % 10 == 0) {
			if (!reg.isEmpty()) {
				cout << "Currently in Regular lane: " << endl;
				reg.printQueue(reg.getHead());
			}
			else {
				cout << "Regular lane is Empty!" << endl;
			}
		}

		if (!reg.isEmpty()) {
			int checkoutTimer = reg.getHead()->getpData()->getServiceTime();
			reg.getHead()->getpData()->setServiceTime(--checkoutTimer);
			if (reg.getHead()->getpData()->getServiceTime() == 0) {
				reg.getHead()->getpData()->setServiceTime(serviceTime);
				reg.dequeue();
				serviceTime = 0;
			}
			++serviceTime;
		}
	}
	system("pause");
 }