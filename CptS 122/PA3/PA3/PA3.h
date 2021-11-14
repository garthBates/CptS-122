/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA3
Date: 9/17/2018
Discription: DDM
*/



#ifndef PA3
#define PA3


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct duration {
	int minutes;
	int seconds;
} Duration;


typedef struct song {
	char artist[100];
	char album[100];
	char song[100];
	char genre[100];
	Duration length;
	int played;
	int rating;
} Song;

typedef struct node {
	Song song;
	struct node *pPrev;
	struct node *pNext;
} Node;


void printMenu(void);
char *
seperate(char **stringp, const char *delim);
void inputData(Node **pList, char line[]);
Node * makeNode(char artist[], char title[], char song[], char genre[], int minutes, int seconds, int played, int rating);
int insertAtFront(Node **pList, char artist[], char title[], char song[], char genre[], int minutes, int seconds, int played, int rating);
void printList(Node *pList);
int storePlayList(FILE* outfile, Node *pList);
int deleteNode(Node **pList, char key[]);
void printArtist(Node *pList, char key[]);
void editSong(Node *pList, char keyArtist[], char keySong[]);

#endif