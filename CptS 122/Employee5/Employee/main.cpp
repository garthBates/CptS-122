// AO

// This example introduces inheritance. Note that
// the Manager class is derived from the Employee class

// History: 11/9 - Discussed abstract classes and pure virtual
//                 functions. We made the calculatePay () member
//                 function in Employee pure virtual. This makes
//                 the Employee class abstract. A pure virtual
//                 function is not required to have an implementation
//                 or definition. However, any class that is derived
//                 from the abstract class (i.e. Manager) MUST
//                 override the pure virtual functon with it's own
//                 version.

#include <iostream>
#include <string>

// Inheritance starter code! Not yet complete!

#include "Employee.h"
#include "Manager.h"

void printPay(Employee &e); // we want to be able to program
                            // in the general. 

int main(void)
{
	//Employee e1("Scott", 20.0, 5);
	//Manager m1("Madeline", 4000, 20, true);
	Employee *emplArr[100];

	cout << "Enter an employee type: 1 - Employee, 2: Manager ";
	int option;
	cin >> option;

	if (option == 1) // basic employee
	{
		// if Employee has a pure virtual function, then it's now an abstract
		// class. We can no longer instantiate an object of that type.
		// However, we can still use pointers or references
		// to Employee type.
		//emplArr[0] = new Employee("Scott", 20.0, 5); 
	}
	else if (option == 2) // manager
	{
		emplArr[0] = new Manager("Madeline", 4000, 20, true);
	}

	printPay(*emplArr[0]);

	delete emplArr[0];

	//printPay(e1); // how can we create a function that only has 1 version, but can be used with different objects in the same class hierarchy
	//printPay(m1);

	//e1.getHours();

	//m1.getHours();

	//cout << "Pay: " << e1.calculatePay() << endl;
	//cout << "Pay: " << m1.calculatePay() << endl;


	return 0;
}

void printPay(Employee &e)
{
	cout << e.calculatePay() << endl; // as of 10/31 this function
									  // does not apply programming in the general
}