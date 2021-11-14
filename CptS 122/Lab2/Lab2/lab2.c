#include "lab2.h"

void printList(Node *pList) {
	while (pList != NULL) {
		printf("%s,%s,%s,%s\n", pList->data.name, pList->data.phone, pList->data.email, pList->data.title);
		pList = pList->pNext;
	}
}