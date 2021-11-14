/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA7
Date: 11/08/2018
Discription: Attendance Tracker App
*/
#pragma once
#include "Menu.h"


int main(void) {
	Menu run;
	int selection = 0;
	while (selection != 7) {
		cout << "1) Import course list\n2) Load master list\n3) Store master list\n4) Mark absences\n5) Edit absneces\n6) Generate report\n7) EXIT" << endl;
		cin >> selection;
		if (selection == 1) {
			run.importCourseList();
		}
		else if (selection == 2) {
			run.loadMasterList();
		}
		else if (selection == 3) {
			run.storeMasterList();
		}
		else if (selection == 4) {
			run.markAbsences();
		}
		else if (selection == 5) {
			run.editAbsences();
		}
		else if (selection == 6) {
			run.generateReport();
		}
		system("cls");
	}

	return 0;
}