/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA1
Date: 9/1/2018
Discription: FitBit data analysis
*/

#include "pa1.h"

int main(void) {
	FILE * infile = NULL;
	FILE * outfile = NULL;
	char sleepEnd[8];
	char sleepStart[8];
	double avgHR = 0.0;
	double totalCal = 0;
	double totalDis = 0;
	int totalFloors = 0;
	int totalSteps = 0;
	int count = 0;
	int maxSteps = 0;

	FitbitData data[1440]; 

	infile = fopen("FitbitData.csv", "r");
	outfile = fopen("Results.csv", "w");

	populateList(data, infile);
	printf("Data read in: Complete\n");

	system("pause");

	//Calculating totals
	for (int i = 0; i < 1440; i++) {
		totalCal += data[i].calories;
	}

	for (int i = 0; i < 1440; i++) {
		totalDis += data[i].distance;
	}

	for (int i = 0; i < 1440; i++) {
		totalFloors += data[i].floors;
	}

	for (int i = 0; i < 1440; i++) {
		totalSteps += data[i].steps;
	}

	printf("Total Calories: %lf\n", totalCal);
	printf("Total Distance: %lf\n", totalDis);
	printf("Total Floors: %d\n", totalFloors);
	printf("Total Steps: %d\n", totalSteps);
	//Calculating average heart rate
	for (int i = 0; i < 1440; i++) {
		if (data[i].heartRate != 0) {
			avgHR += data[i].heartRate;
			count++;
		}
		else {
			avgHR += 0.0;
		}
	}

	avgHR = avgHR / count;

	printf("Average Heart Rate: %lf\n", avgHR);

	//calculating max steps taken
	for (int i = 0; i < 1440; i++) {
		if (data[i].steps > maxSteps) {
			maxSteps = data[i].steps;
		}
	}
	printf("Max Steps: %d\n", maxSteps);

	//Calculating when sleep ended
	count = 0;
	while (data[count].sleepLevel == 1 || data[count].sleepLevel == 2) {
		strcpy(sleepEnd, data[count].minute);
		count++;
	}
	//Calculating when sleep started
	while (data[count].sleepLevel != 1 && data[count].sleepLevel != 2) {
		strcpy(sleepStart, data[count].minute);
		count++;
	}
	printf("Sleep End: %s\n", sleepEnd);
	printf("Sleep Start: %s\n", sleepStart);
	system("pause");

	printResults(data, outfile, totalCal, totalDis, totalFloors, totalSteps, avgHR, maxSteps, sleepStart, sleepEnd);

	printf("Printing data to \"Results.csv\": Complete\n");
	system("pause");
	//Closing files
	fclose(infile);
	fclose(outfile);

	return 0;
}