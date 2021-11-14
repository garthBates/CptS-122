/*
Programmer: Garth Bates
Class: CptS 122, Fall 2018
Programming Assignment: PA3
Date: 9/19/2018
Discription: DDM
*/


#include "PA3.h"


int main(void) {
	int selection = 0;
	int disSelect = 0;
	char disArtist[50];
	char delSong[50];
	char insSong[50];
	char insAlbum[50];
	char insArtist[50];
	char insGenre[50];
	int insMinutes;
	int insSeconds;
	int insPlayed;
	int insRating;
	int count = 0;
	int stored = 0;
	char dataCur[100];
	char dataLive[100];
	int *order;
	Node* pHead = NULL;
	FILE * infile = NULL;
	FILE * outfile = NULL;

	infile = fopen("musicPlayList.csv", "r+");
	//outfile = fopen("musicPlayList.csv", "w");

	while (selection != 11) {
		printMenu();
		scanf("%d", &selection);
		if (selection == 1) {
			while (feof(infile) == 0) {
				fgets(dataCur, 100, infile);
				strcpy(dataLive, dataCur);
				inputData(&pHead, dataLive);
			}
			deleteNode(&pHead, dataLive);
		}
		else if (selection == 2) {
			stored = storePlayList(infile, pHead);
			if (stored == 1) {
				printf("Playlist successfully stored\n");
				system("pause");
				system("cls");
			}
			else {
				printf("Playlist failed to save\n");
				system("pause");
				system("cls");
			}
		}
		else if (selection == 3) {
			printf("(1) Print all records\n(2) Print all records that match an artist\n");
			scanf("%d", &disSelect);
			if (disSelect == 1) {
				printList(pHead);
				system("pause");
				system("cls");
			}
			else {
				printf("Enter an artist to display\n ");
				scanf("%s", &disArtist);
				printArtist(pHead, disArtist);
				system("pause");
				system("cls");
			}
		}
		else if (selection == 5) {
			printf("Enter a song you wish to delete: \n");
			scanf("%s", &delSong);
			deleteNode(&pHead, delSong);
			system("pause");
			system("cls");
		}
		else if (selection == 4) {
			printf("Enter the artist, album, song, genre, length, times play, and rating for a new song (ARTIST ALBUM SONG GENRE MINUTES SECONDS PLAYED RATING)\n");
			scanf("%s %s %s %s %d %d %d %d", &insArtist, &insAlbum, &insSong, &insGenre, &insMinutes, &insSeconds, &insPlayed, &insRating);
			insertAtFront(&pHead, insArtist, insAlbum, insSong, insGenre, insMinutes, insSeconds, insPlayed, insRating);
			system("cls");
			printArtist(pHead, disArtist);
			system("pause");
			system("cls");
		}
		else if (selection == 6) {
			printf("Enter the name of the artist and song you wish to edit(ARTIST SONG)\n");
			scanf("%s %s", &insArtist, &insSong);
			editSong(pHead, insArtist, insSong);
		}
		else if (selection == 8) {
			printf("Enter the name of the arist and song you wish to rate (ARTIST SONG)\n");
			scanf("%s %s", &insArtist, &insSong);
			rateSong(pHead, insArtist, insSong);
		}
		else if (selection == 9) {
			printf("Enter the name of the arist and the song you wish to start playing from (ARTIST SONG)\n");
			scanf("%s %s", &insArtist, &insSong);
			playSongs(pHead, insArtist, insSong);
		}
		else if (selection == 10) {
			order = shuffleOrder(pHead);
			for (int i = 0; i < 100; i++) {
				printf("*(order + %d) : %d\n", i, *(order + i));
			}
			shuffleSongs(pHead, order);
		}
	}
	stored = storePlayList(infile, pHead);
	system("pause");
	fclose(infile);
	//fclose(outfile);
	return 0;
}