/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA7
Date: 11/08/2018
Discription: Attendance Tracker App
*/
#include "Menu.h"

Menu::Menu()
{

}

Menu::~Menu()
{
	storeMasterList(masterList);
}



void Menu::importCourseList()
{
	courseFile.open("classList.csv", std::ios::in);
	string temp, record, ID, firstName, lastName, name, email, units, program, level;
	int recordNum, IDNum;
	getline(courseFile, temp);
	while (true) {
		getline(courseFile, record, ',');
		recordNum = atoi(record.c_str());
		getline(courseFile, ID, ',');
		IDNum = atoi(ID.c_str());
		getline(courseFile, firstName, ',');
		getline(courseFile, lastName, ',');
		name = firstName + "," + lastName;
		getline(courseFile, email, ',');
		getline(courseFile, units, ',');
		getline(courseFile, program, ',');
		getline(courseFile, level, '\n');
		if (courseFile.eof()) break;
		Data* newData = new Data(recordNum, IDNum, name, email, units, program, level);
		Node<Data>* newNode = new Node<Data>(newData);
		courseList.insertAtFront(newNode);
	}

	storeMasterList(courseList);
	courseFile.close();

}

void Menu::loadMasterList()
{
	masterFile.open("masterList.csv", std::ios::in);
	string record, ID, firstName, lastName, name, email, absences, units, major, level;
	int recordNum, IDNum, absNum;
	while (true) {
		getline(masterFile, record, ',');
		recordNum = atoi(record.c_str());
		getline(masterFile, ID, ',');
		IDNum = atoi(ID.c_str());
		getline(masterFile, firstName, ',');
		getline(masterFile, lastName, ',');
		name = firstName + "," + lastName;
		getline(masterFile, email, ',');
		getline(masterFile, absences, ',');
		absNum = atoi(absences.c_str());
		getline(masterFile, units, ',');
		getline(masterFile, major, ',');
		getline(masterFile, level, '\n');
		if (masterFile.eof()) break;
		Data* newData = new Data(recordNum, IDNum, name, email, units, major, level);
		newData->setAbsences(absNum);
		Node<Data>* newNode = new Node<Data>(newData);
		masterList.insertAtFront(newNode);
	}

	masterFile.close();
}

void Menu::storeMasterList()
{
	storeMasterList(masterList);
}

void Menu::storeMasterList(List<Node<Data>> list)
{
	masterFile.open("masterList.csv", std::ios::out);
	Node<Node<Data>>* pCur= list.getHead();
	while (pCur != nullptr) {
		Node<Data>* pCurData = pCur->getData();
		Data* pData = pCurData->getData();
		masterFile << pData->getRecord() << ',' << pData->getID() << ',' << pData->getName() << ',' << pData->getEmail()<< ',';
		masterFile << pData->getAbsences() << ',' << pData->getUnits() << ',' << pData->getMajor() << ',' << pData->getLevel() << endl;
		pCur = pCur->getNext();
	}
	masterFile.close();
}

void Menu::markAbsences()
{
	Node<Node<Data>>* pCur = masterList.getHead();
	char selection;
	while (pCur != nullptr) {
		Node<Data>* pCurData = pCur->getData();
		Data* pData = pCurData->getData();
		cout << "Is " << pData->getName() << " present? y/n" << endl;
		cin >> selection;
		if (selection != 'y') {
			pData->setAbsences(pData->getAbsences() + 1);
		}
		pCur = pCur->getNext();
	}
}

void Menu::editAbsences()
{
	cout << "Option not implimented" << endl;
}

void Menu::generateReport()
{
	int selection;
	cout << "1) Generate report for all students\n2) Generate report for students with 3 or more absences" << endl;
	cin >> selection;
	Node<Node<Data>>* pCur = masterList.getHead();
	if (selection == 1) {
		while (pCur != nullptr) {
			Node<Data>* pCurData = pCur->getData();
			Data* pData = pCurData->getData();
			cout << pData->getRecord() << ',' << pData->getID() << ',' << pData->getName() << ',' << pData->getEmail() << ',';
			cout << pData->getAbsences() << ',' << pData->getUnits() << ',' << pData->getMajor() << ',' << pData->getLevel() << endl;
			pCur = pCur->getNext();
		}
		system("pause");
	}
	else {
		while (pCur != nullptr) {
			Node<Data>* pCurData = pCur->getData();
			Data* pData = pCurData->getData();
			if (pData->getAbsences() >= 3) {
				cout << pData->getRecord() << ',' << pData->getID() << ',' << pData->getName() << ',' << pData->getEmail() << ',';
				cout << pData->getAbsences() << ',' << pData->getUnits() << ',' << pData->getMajor() << ',' << pData->getLevel() << endl;
			}
			pCur = pCur->getNext();
		}
		system("pause");
	}
}

