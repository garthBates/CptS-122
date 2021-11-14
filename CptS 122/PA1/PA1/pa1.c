/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA1
Date: 9/1/2018
Discription: FitBit data analysis
*/


#include "pa1.h"

/*
Function: seperate()
Description: Seperates a string based on the passed in delimiter
Input parameters: A string pointer and delimiter
Returns: returns a spointer to a string that has been seperated
Preconditions: a string and delimiter must already exist
Postconditions: a new string pointer is returned
NOTE**!!** I did not write this code. It is the scource code for the strsep() function, however strsep() was not found in my string.h so I copied this out of the source code
*/

char *
seperate (char **stringp, const char *delim)
{
	char *begin, *end;
	begin = *stringp;
	if (begin == NULL)
		return NULL;
	/* Find the end of the token.  */
	end = begin + strcspn(begin, delim);
	if (*end)
	{
		/* Terminate the token and set *STRINGP past NUL character.  */
		*end++ = '\0';
		*stringp = end;
	}
	else
		/* No more delimiters; this is the last token.  */
		*stringp = NULL;
	return begin;
}

/*
Funtcion: inputData()
Despcription: populate the data for one index in the array with cleansed data from the input csv file
Inputparameters: FitbitData data[], char line[], int count
Returns: void
Preconditions: The csv file must already be read in successfully
Postconditions: none
*/
void inputData(FitbitData data[], char line[], int count) {
	const char s[2] = ",";
	char *token;
	double token2;
	int token3;
	//Patient Number
	token = seperate(&line, s);
	strcpy(data[count].patient, token);
	//Minute
	token = seperate(&line, s);
	strcpy(data[count].minute, token);
	//Calories
	token = seperate(&line, s);
	token2 = atof(token);
	data[count].calories = token2;
	//Distance
	token = seperate(&line, s);
	token2 = atof(token);
	data[count].distance = token2;
	//Floors
	token = seperate(&line, s);
	token3 = atoi(token);
	data[count].floors = token3;
	//Heartrate
	token = seperate(&line, s);
	token3 = atoi(token);
	if (token3 > 40) {
		data[count].heartRate = token3;
	}
	else {
		data[count].heartRate = 0;
	}
	//Steps
	token = seperate(&line, s);
	token3 = atoi(token);
	data[count].steps = token3;
	//Sleep level
	token = seperate(&line, s);
	if (strcmp(token, "\n") == 0) {
		data[count].sleepLevel = 4;
	}
	else {
		token3 = atoi(token);
		data[count].sleepLevel = token3;
	}
}

/*
Function: populateList()
Description: Dedupes and reads in each line of the csv file to be fed into the inputData function
Input parameters: FitbitData data[], FILE* infile
Returns: void
Preconditions: the csv file must have been opened successfully
Postconiditons: none
*/
void populateList(FitbitData data[], FILE* infile) {
	char dataCur[100];
	char dataPrev[100];
	char dataLive[100];
	int count = 0;

	fgets(dataCur, 100, infile);
	fgets(dataCur, 100, infile);

	while (feof(infile) == 0) {
		fgets(dataCur, 100, infile);
		strcpy(dataLive, dataCur);
		if (strcmp(dataCur, dataPrev) == 0) {
			fgets(dataCur, 100, infile);
			strcpy(dataLive, dataCur);
			strcpy(dataPrev, dataCur);
		}
		else {
			//populate list with each part
			//must seperate values and data cleansed first
			inputData(data, dataLive, count);

			strcpy(dataPrev, dataCur);
			count++;
		}
	}
	return;
}

/*
Function: printResults()
Description: Prints all required values and the cleansed data to Results.csv
Input parameters: FitbitData data[], FILE* outfile, double totalCal, double totalDis, int totalFloors, int totalSteps, double avgHR, int maxSteps, char sleepStart[], char sleepEnd[]
Returns: void
Precondtions: all other program functions must have been successfully completed
Postconditions: none
*/
void printResults(FitbitData data[], FILE* outfile, double totalCal, double totalDis, int totalFloors, int totalSteps, double avgHR, int maxSteps, char sleepStart[], char sleepEnd[]) {
	fprintf(outfile, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
	fprintf(outfile, "%lf,%lf,%d,%d,%lf,%d,%s,%s\n", totalCal, totalDis, totalFloors, totalSteps, avgHR, maxSteps, sleepStart, sleepEnd);

	for (int i = 0; i < 1440; i++) {
		fprintf(outfile, "%s,%s,%lf,%lf,%d,%d,%d,%d\n", data[i].patient, data[i].minute, data[i].calories, data[i].distance, data[i].floors, data[i].heartRate, data[i].steps, data[i].sleepLevel);
	}
}