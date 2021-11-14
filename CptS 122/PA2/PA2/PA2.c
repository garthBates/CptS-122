/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA2
Date: 9/17/2018
Discription: DDM
*/

#include "PA2.h"


void printMenu(void) {
	printf("Welcome to the DMM, select an option\n");
	printf("\t(1) load\n\t(2) store\n\t(3) display\n\t(4) insert\n\t(5) delete\n\t(6) edit\n\t(7) sort\n\t(8) rate\n\t(9) play\n\t(10) shuffle\n\t(11) exit\n");
}

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
seperate(char **stringp, const char *delim)
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
Function: inputData()
Descrpition: Seperates a line of data and stores it in a node
Input parameters: Linked list and line of data
Returns: Void
Precondiions: None
Postcondidions: A new node is created with the data
*/
void inputData(Node **pList, char line[]) {
	const char s[2] = ",";
	const char t[2] = ":";
	const char q[2] = "\"";
	char *token;
	char artist[50];
	char album[50];
	char song[50];
	char genre[50];
	double token2;
	int minutes;
	int seconds;
	int played;
	int rating;
	//Artist
	if (strcmp(line, "\n") == 0) {
		return;
	}
	if (line[0] == '\"') {
		token = seperate(&line, q);
		token = seperate(&line, q);
		strcpy(artist, token);
		token = seperate(&line, s);
	}
	else {
		token = seperate(&line, s);
		strcpy(artist, token);
	}
	//Album
	token = seperate(&line, s);
	strcpy(album, token);
	//Song
	token = seperate(&line, s);
	strcpy(song, token);
	//Genre
	token = seperate(&line, s);
	strcpy(genre, token);
	//Minutes
	token = seperate(&line, t);
	minutes = atoi(token);
	//Seconds
	token = seperate(&line, s);
	seconds = atoi(token);
	//Played
	token = seperate(&line, s);
	played = atoi(token);
	//Rating
	token = seperate(&line, s);
	rating = atoi(token);

	insertAtFront(pList, artist, album, song, genre, minutes, seconds, played, rating);
}

/*
Function: makeNode()
Description: Makes a new node with the proper data
Input parameters: char artist[], char title[], char song[], char genre[], int minutes, int seconds, int played, int rating
Returns: node *
Precondtions: The data must be scliced properly
Postconditions: A new node is made in the linked list
*/
Node * makeNode(char artist[], char title[], char song[], char genre[], int minutes, int seconds, int played, int rating)
{
	Node *pMem = NULL;

	pMem = (Node *)malloc(sizeof(Node));

	strcpy(pMem->song.artist, artist);
	strcpy(pMem->song.album, title);
	strcpy(pMem->song.song, song);
	strcpy(pMem->song.genre, genre);
	(*pMem).song.length.minutes = minutes;
	(*pMem).song.length.seconds = seconds;
	(*pMem).song.played = played;
	(*pMem).song.rating = rating;

	pMem->pPrev = NULL;
	pMem->pNext = NULL;

	return pMem;
}

/*
Function: insertAtFront()
Description: Inserts a new node at the front of the linked list
Input parameters: Node **pList, char artist[], char title[], char song[], char genre[], int minutes, int seconds, int played, int rating
Returns: int signifying success or failular
Precondtions: The data must be scliced properly
Postconditions: A new node is made at the front of the linked list
*/

int insertAtFront(Node **pList, char artist[], char title[], char song[], char genre[], int minutes, int seconds, int played, int rating)
{
	int success = 0;
	Node *pMem = NULL;
	Node *pHead = pList;

	pMem = makeNode(artist, title, song, genre, minutes, seconds, played, rating);


	if (pMem != NULL)
	{
		success = 1;

		pHead->pPrev = pMem;
		pMem->pNext = *pList;
		*pList = pMem;

	}

	return success;

}


/*
Function: printList()
Description: Prints out the linked list
Input parameters: None
Returns: Void
Precondtions: A linked list must exist
Postcondtions: none
*/
void printList(Node *pList)
{
	while (pList != NULL)
	{
		printf("\tArtist: %s\n\tAlbum: %s\n\tSong: %s\n\tGenre: %s\n\tLength: %d:%d\n\tTimes played: %d\n\tRating: %d\n", pList->song.artist, pList->song.album, pList->song.song, pList->song.genre, pList->song.length.minutes, pList->song.length.seconds, pList->song.played, pList->song.rating);
		printf("---------------------------------------------\n");
		pList = pList->pNext;
	}
}

/*
Function: storePlayList()
Description: saves the current play list to the deignated file
Input parameters: FILE* outfile, Node *pList
Returns: int signifying success or failular
Precondtions: a linked list must exist
Postconditions: new file is made with data saved
*/
int storePlayList(FILE* outfile, Node *pList) {
	int success = 0;
	char insSong[50];
	char insAlbum[50];
	char insArtist[50];
	char insGenre[50];
	int insMinutes;
	int insSeconds;
	int insPlayed;
	int insRating;
	while (pList != NULL) {
		strcpy(insArtist, pList->song.artist);
		strcpy(insAlbum, pList->song.album);
		strcpy(insSong, pList->song.song);
		strcpy(insGenre, pList->song.genre);
		insMinutes = pList->song.length.minutes;
		insSeconds = pList->song.length.seconds;
		insPlayed = pList->song.played;
		insRating = pList->song.rating;
		fprintf(outfile, "\"%s\",%s,%s,%s,%d:%d,%d,%d\n", insArtist, insAlbum, insSong, insGenre, insMinutes, insSeconds, insPlayed, insRating);
		pList = pList->pNext;
	}
	success = 1;
	return success;
}

/*
Function: deleteNode()
Description: deletes selected node
Input parameters: Node **pList, char key[]
Returns: int signifying success or failular
Precondtions: a linked list must exist
Postconditions: none
*/
int deleteNode(Node **pList, char key[]) {
	int success = 0;
	Node *temp = *pList, *pPrev;

	if (temp != NULL && strcmp(temp->song.song, key) != 0) {
		*pList = temp->pNext;
		free(temp);
		success = 1;
	}

	while (strcmp(temp->song.song, key) == 0) {
		pPrev = temp;
		temp = temp->pNext;
		pPrev->pNext = temp->pNext;
		free(temp);
	}
	if (temp == NULL) {
		return success;
	}

	//pPrev->pNext = temp->pNext;

	//free(temp);
	return success;
}

/*
Function: printArtist
Description: Prints all records for a specific artist
Input parameters: Node *pList, char key[]
Returns: void
Precondtions: a linked list must exist
Postconditions: none
*/
void printArtist(Node *pList, char key[]) {
	while (pList != NULL) {
		if (strcmp(pList->song.artist, key) == 0) {
			printf("\tArtist: %s\n\tAlbum: %s\n\tSong: %s\n\tGenre: %s\n\tLength: %d:%d\n\tTimes played: %d\n\tRating: %d\n", pList->song.artist, pList->song.album, pList->song.song, pList->song.genre, pList->song.length.minutes, pList->song.length.seconds, pList->song.played, pList->song.rating);
			printf("---------------------------------------------\n");
		}
		pList = pList->pNext;
	}
	return;
}

/*
Function: editSong()
Description: User can edit all fields for a specific song
Input parameters: Node *pList, char keyArtist[], char keySong[]
Returns: void
Precondtions: a linked list must exist with specified song
Postconditions: The fields in the node have updated values
*/
void editSong(Node *pList, char keyArtist[], char keySong[]) {
	char insSong[50];
	char insAlbum[50];
	char insArtist[50];
	char insGenre[50];
	int insMinutes;
	int insSeconds;
	int insPlayed;
	int insRating;
	while (pList != NULL) {
		if (strcmp(pList->song.artist, keyArtist) == 0 && strcmp(pList->song.song, keySong) == 0) {
			printf("Enter the new Artist name\n");
			scanf("%s", &insArtist);
			printf("Enter the new Album name\n");
			scanf("%s", &insAlbum);
			printf("ENter the new Song name\n");
			scanf("%s", &insSong);
			printf("Enter the new Genre\n");
			scanf("%s", &insGenre);
			printf("Enter the new Length (MINUTES SECONDS)\n");
			scanf("%d %d", &insMinutes, &insSeconds);
			printf("Enter the new Times Played\n");
			scanf("%d", &insPlayed);
			printf("Enter the new rating (1-5)\n");
			scanf("%d", &insRating);

			strcpy(pList->song.artist, insArtist);
			strcpy(pList->song.album, insAlbum);
			strcpy(pList->song.song, insSong);
			strcpy(pList->song.genre, insGenre);
			pList->song.length.minutes = insMinutes;
			pList->song.length.seconds = insSeconds;
			pList->song.played = insPlayed;
			pList->song.rating = insRating;
		}
		pList = pList->pNext;
	}
}

void rateSong(Node *pList, char keyArtist[], char keySong[]) {
	int insRating;
	while (pList != NULL) {
		if (strcmp(pList->song.artist, keyArtist) == 0 && strcmp(pList->song.song, keySong) == 0) {
			printf("Enter the new rating (1-5)\n");
			scanf("%d", &insRating);
			pList->song.rating = insRating;
		}
		pList = pList->pNext;
	}
}