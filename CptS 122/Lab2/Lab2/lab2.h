#ifndef LAB2
#define LAB2


#include <stdio.h>
#include <string.h>
#include <string.h>



typedef enum boolean

{

	FALSE, TRUE

} Boolean;



typedef struct contact

{

	char name[50];

	char phone[12]; // 18005557577

	char email[50];

	char title[20];

} Contact;



typedef struct node

{

	Contact data;

	struct node *pNext;

} Node;


#endif