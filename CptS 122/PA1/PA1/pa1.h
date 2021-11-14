/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA1
Date: 9/1/2018
Discription: FitBit data analysis
*/



#ifndef PA1
#define PA1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3, MISSING_DATA = 4
} Sleep;


typedef struct fitbit
{
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;


void populateList(FitbitData data[], FILE* infile);

#endif