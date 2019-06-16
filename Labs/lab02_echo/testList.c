// testList.c - testing DLList data type
// Written by John Shepherd, March 2013

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "DLList.h"

typedef struct DLListNode {
	char *value;        /**< value of this list item (string) */
	struct DLListNode *prev;
	                    /**< pointer to previous node in list */
	struct DLListNode *next;
	                    /**< pointer to next node in list */
} DLListNode;

typedef struct DLListRep {
	size_t nitems;      /**< count of items in list */
	DLListNode *first;  /**< first node in list */
	DLListNode *curr;   /**< current node in list */
	DLListNode *last;   /**< last node in list */
} DLListRep;

void showState (DLList L);

int main (void)
{
	printf("\n>> Importing from stdin\n");
	DLList myList = getDLList (stdin);
	printf("\n>> Please check your inputs: \n");
	putDLList (stdout, myList);
	assert (validDLList (myList));
	printf("\n============================================================\n");

	printf("\n>> Jumping over the boudary\n");
	showState(myList);
	printf("\n>> Move to certain line\n");
	DLListMoveTo(myList, 10000);
    showState(myList);
	printf("\n>> Backward\n");
	DLListMove(myList, -15000);
    showState(myList);
	printf("\n>> Forward\n");
	DLListMove(myList, 20000);
    showState(myList);
	printf("\n============================================================\n");

	printf("\n>> Inserting 7 lines after the current line\n");
	showState(myList);
	for (int i = 10; i < 71; i+=10) {
		char str[20];
		sprintf(str, "I'm line %d", i);
		DLListAfter(myList, str);
	}
	printf("\n>> Previewing your list after insertion: \n\n");
	putDLList(stdout, myList);
	showState(myList);
	printf("\n============================================================\n");

	printf("\n>> Moving current pointer to the middle line\n");
	DLListMoveTo(myList, (myList->nitems + 1)/2);
	showState(myList);
	printf("\n>> Previewing your list: \n\n");
	putDLList(stdout, myList);
	printf("\n============================================================\n");

	printf("\n>> Inserting 5 lines before the current(middle) line\n");
	showState(myList);
	for (int i = 5; i > 0; i--) {
		char str[20];
		sprintf(str, "I'm line %d", i);
		DLListBefore(myList, str);
	}
	printf("\n>> Previewing your list after insertion: \n\n");
	putDLList(stdout, myList);
	showState(myList);
	printf("\n============================================================\n");

	printf("\n>> Deleting 3 lines\n");
	showState(myList);
	for (int i = 0; i < 3; i++) DLListDelete(myList);
	printf("\n>> Previewing your list: \n\n");
	putDLList(stdout, myList);
	showState(myList);
	printf("\n============================================================\n");
	
	freeDLList (myList);
	return EXIT_SUCCESS;
}

void showState (DLList L)
{
	if (validDLList(L)) {
		printf("\n	~~~ You have a valid list, %zu items were detected\n", DLListLength(L));
		if (DLListLength(L) != 0) {
			printf("	~~~ Your first line is: \n");
			printf("		%s\n", L->first->value);
			printf("	~~~ Your last line is: \n");
			printf("		%s\n", L->last->value);
			printf("	~~~ Your current line is: \n");
			printf("		%s\n\n", L->curr->value);
		}
	}
}
