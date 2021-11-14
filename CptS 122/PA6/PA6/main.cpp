/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA6
Date: 10/24/2018
Discription: BST Morse Code Translator
*/


#pragma once

#include "BTS.h"


int main(void) {

	BST codex;
	codex.printInOrder();
	system("pause");
	codex.translate();
	system("pause");
}