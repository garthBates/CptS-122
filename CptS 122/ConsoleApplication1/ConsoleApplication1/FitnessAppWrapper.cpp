/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA4
Date: 10/8/2018
Discription: Fitness App
*/

#include "FitnessAppWrapper.h"
using std::getline;

/*
Funtcion: editDailyPlan()
Despcription: user can edit a daily plan
Preconditions: The node must already exist
Postconditions: none
*/
void Wrapper::editDailyPlan(DietPlan dPlan[])
{
	int choice;
	int newGoal;
	cout << "Enter the day of the week you would like to edit (1-7)" << endl;
	cin >> choice;
	cout << "Enter the new goal for the selected day" << endl;
	cin >> newGoal;
	dPlan[choice - 1].setGoal(newGoal);
}

/*
Funtcion: editDailyPlan()
Despcription: user can edit a daily plan
Preconditions: The node must already exist
Postconditions: none
*/
void Wrapper::editDailyPlan(ExercisePlan exPlan[])
{
	int choice;
	int newGoal;
	cout << "Enter the day of the week you would like to edit (1-7)" << endl;
	cin >> choice;
	cout << "Enter the new goal for the selected day" << endl;
	cin >> newGoal;
	dPlan[choice - 1].setGoal(newGoal);
}

/*
Funtcion: displayMenu()
Despcription: displays the user menu
Preconditions: none
Postconditions: none
*/
void Wrapper::displayMenu(void)
{
	cout << "Welcome to the Fitness App!" << endl;
	cout << "\t1) Load weekly diet plan from file." << endl;
	cout << "\t2) Load weekly exercise plan from file." << endl;
	cout << "\t3) Store weekly diet plan to file." << endl;
	cout << "\t4) Store weekly exercise plan to file." << endl;
	cout << "\t5) Display weekly diet plan to screen." << endl;
	cout << "\t6) Display weekly exercise plan to screen." << endl;
	cout << "\t7) Edit daily diet plan." << endl;
	cout << "\t8) Edit daily exercise plan." << endl;
	cout << "\t9) Exit." << endl;
}

/*
Funtcion: Wrapper()
Despcription: wrapper constuctor
Preconditions: none
Postconditions: none
*/
Wrapper::Wrapper()
{
	ExercisePlan exPlan[7];
	DietPlan dPlan[7];
	fstream diesPlansFile;
	fstream exercisePlansFile;
}

/*
Funtcion: runApp()
Despcription: runs all the functions of the fitness app
Preconditions: none
Postconditions: none
*/
void Wrapper::runApp(void)
{
	int selection = 0;

	dietPlansFile.open("dietPlans.txt", std::ios::in | std::ios::out);
	while (selection != 9) {
		system("cls");
		displayMenu();
		cin >> selection;
		if (selection == 1) {
			loadWeeklyPlan(dietPlansFile, dPlan);
			system("pause");
		}
		else if (selection == 2) {
			loadWeeklyPlan(exercisePlansFile, exPlan);
			system("pause");
		}
		else if (selection == 3) {
			storeWeeklyPlan(dietPlansFile, dPlan);
			system("pause");
		}
		else if (selection == 4) {
			storeWeeklyPlan(exercisePlansFile, exPlan);
			system("pause");
		}
		else if (selection == 5) {
			displayWeeklyPlan(dPlan);
			system("pause");
		}
		else if (selection == 6) {
			displayWeeklyPlan(exPlan);
			system("pause");
		}
		else if (selection == 7) {
			editDailyPlan(dPlan);
			system("pause");
		}
		else if (selection == 8) {
			editDailyPlan(exPlan);
			system("pause");
		}
	}
	storeWeeklyPlan(dietPlansFile, dPlan);
	storeWeeklyPlan(exercisePlansFile, exPlan);
	system("cls");

	dietPlansFile.close();
	exercisePlansFile.close();
	cout << "Press any key" << endl;
}

/*
Funtcion: loadDailyPlan()
Despcription: loads the information for one day into a node
Preconditions: The node must already exist
Postconditions: none
*/
void Wrapper::loadDailyPlan(fstream & dietPlansFile, DietPlan & plan)
{
	string planName;
	string date;
	string line;
	int goal;
	getline(dietPlansFile, planName);
	dietPlansFile >> goal;
	dietPlansFile.ignore(SIZE_MAX, '\n');
	getline(dietPlansFile, date);
	getline(dietPlansFile, line);

	//setting values
	plan.setName(planName);
	plan.setGoal(goal);
	plan.setDate(date);
}

/*
Funtcion: loadDailyPlan()
Despcription: loads the information for one day into a node
Preconditions: The node must already exist
Postconditions: none
*/
void Wrapper::loadDailyPlan(fstream & exercisePlansFile, ExercisePlan & plan)
{
	string planName;
	string date;
	string line;
	int goal;
	getline(exercisePlansFile, planName);
	exercisePlansFile >> goal;
	exercisePlansFile.ignore(SIZE_MAX, '\n');
	getline(exercisePlansFile, date);
	getline(exercisePlansFile, line);

	//setting values
	plan.setName(planName);
	plan.setGoal(goal);
	plan.setDate(date);
}

/*
Funtcion: loadWeeklyPlan()
Despcription: loads the information for one week into an array
Preconditions: The array must already exist
Postconditions: none
*/
void Wrapper::loadWeeklyPlan(fstream & dietPlansFile, DietPlan dPlan[])
{
	cout << "Loading Weekly Diet Plan" << endl;
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(dietPlansFile, dPlan[i]);
	}
}

/*
Funtcion: loadWeeklyPlan()
Despcription: loads the information for one week into an array
Preconditions: The array must already exist
Postconditions: none
*/
void Wrapper::loadWeeklyPlan(fstream & exercisePlansFile, ExercisePlan exPlan[])
{
	cout << "Loading Weekly Exercise Plan" << endl;
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(exercisePlansFile, exPlan[i]);
	}
}

/*
Funtcion: displayDailyPlan()
Despcription: displays the information for one day to the console
Preconditions: The node must already exist
Postconditions: none
*/
void Wrapper::displayDailyPlan(DietPlan dPlan[], int index)
{
		string name = dPlan[index].getName();
		string date = dPlan[index].getDate();
		int goal = dPlan[index].getGoal();
		cout << "Plan name: " << name << endl;
		cout << "Goal: " << goal << endl;
		cout << "Date: " << date << endl;
		cout << endl;
}

/*
Funtcion: displayDailyPlan()
Despcription: displays the information for one day to the console
Preconditions: The node must already exist
Postconditions: none
*/
void Wrapper::displayDailyPlan(ExercisePlan exPlan[], int index)
{
	string name = exPlan[index].getName();
	string date = exPlan[index].getDate();
	int goal = exPlan[index].getGoal();
	cout << "Plan name: " << name << endl;
	cout << "Goal: " << goal << endl;
	cout << "Date: " << date << endl;
	cout << endl;
}

/*
Funtcion: displayWeeklyPlan()
Despcription: displays the information for one week to the console
Preconditions: The array must already exist
Postconditions: none
*/
void Wrapper::displayWeeklyPlan(DietPlan dPlan[])
{
	cout << "Displaying Weekly Diet Plan." << endl;
	for (int i = 0; i < 7; i++) {
		displayDailyPlan(dPlan, i);
	}
}

/*
Funtcion: displayWeeklyPlan()
Despcription: displays the information for one week to the console
Preconditions: The array must already exist
Postconditions: none
*/
void Wrapper::displayWeeklyPlan(ExercisePlan exPlan[])
{
	cout << "Displaying Weekly Exercise Plan." << endl;
	for (int i = 0; i < 7; i++) {
		displayDailyPlan(exPlan, i);
	}
}

/*
Funtcion: storeDailyPlan()
Despcription: stores the information for one day to the output file
Preconditions: The node must already exist
Postconditions: none
*/
void Wrapper::storeDailyPlan(fstream & dietPlansFile, DietPlan & plan)
{
	string planName = plan.getName();
	string date = plan.getDate();
	int goal = plan.getGoal();
	dietPlansFile << planName << endl;
	dietPlansFile << goal << endl;
	dietPlansFile << date << endl;
}

/*
Funtcion: storeDailyPlan()
Despcription: stores the information for one day to the output file
Preconditions: The node must already exist
Postconditions: none
*/
void Wrapper::storeDailyPlan(fstream & exercisePlansFile, ExercisePlan & plan)
{
	string planName = plan.getName();
	string date = plan.getDate();
	int goal = plan.getGoal();
	exercisePlansFile << planName << endl;
	exercisePlansFile << goal << endl;
	exercisePlansFile << date << endl;
}

/*
Funtcion: storeWeeklyPlan()
Despcription: stores the information for one week to the output file
Preconditions: The array must already exist
Postconditions: none
*/
void Wrapper::storeWeeklyPlan(fstream & dietPlansFile, DietPlan dPlan[])
{
	cout << "Storing Weekly Diet Plan." << endl;
	for (int i = 0; i < 7; i++) {
		storeDailyPlan(dietPlansFile, dPlan[i]);
	}
}

/*
Funtcion: storeWeeklyPlan()
Despcription: stores the information for one week to the output file
Preconditions: The array must already exist
Postconditions: none
*/
void Wrapper::storeWeeklyPlan(fstream & exercisePlansFile, ExercisePlan exPlan[])
{
	cout << "Storing Weekly Exercise Plan." << endl;
	for (int i = 0; i < 7; i++) {
		storeDailyPlan(exercisePlansFile, exPlan[i]);
	}
}
