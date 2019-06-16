// testList.c - testing DLList data type
// Written by John Shepherd, March 2013

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "DLList.h"
static void test_DLListBefore(DLList L);
static void test_DLListAfter(DLList L);
static void test_delete(DLList L);
int main (void)
{
	DLList myList = getDLList (stdin);
	putDLList (stdout, myList);
	assert (validDLList (myList));
	//initial state
	printf("-------Initial Condition\n");
	printf("Curr line:%s\nNumbers of line:%zu\n",DLListCurrent(myList),DLListLength(myList));
	test_DLListBefore(myList);
	// TODO: more tests needed here
	test_DLListAfter(myList);
	test_delete(myList);
	freeDLList (myList);
	return EXIT_SUCCESS;
}

static void test_DLListBefore(DLList L){
	printf("---test_DLListBefore---\n");
	printf("--current condition--\n");
	printf("Curr line:%s\n",DLListCurrent(L));
	printf("Add string to the first line\n");
	DLListBefore(L,"AddBefore1");
	printf("show the result:\n");
	printf("---------------|\n");
	putDLList(stdout,L);
	printf("---------------|\n");
	printf("Add string to the last line\n");
 	DLListMoveTo(L,DLListLength(L));
	DLListBefore(L,"AddBefore2");
 	printf("show the result\n");
	printf("---------------|\n");
	putDLList(stdout,L);
	printf("---------------|\n");
	printf("Add string to the middle line\n");
	DLListMove(L,-1);
	DLListBefore(L,"AddBefore3");
	
	printf("show the result\n");
	printf("---------------|\n");
	putDLList(stdout,L);
	printf("---------------|\n");
	assert(validDLList(L));
	printf("----passed----\n");


}
static void test_DLListAfter(DLList L){
	DLListMoveTo(L,1);
	printf("---test_DLListBefore---\n");
	printf("--current condition--\n");
	printf("Curr line:%s\n",DLListCurrent(L));
	printf("Add string to the first line\n");
	DLListAfter(L,"AddAfter1");
	printf("show the result:\n");
	printf("---------------|\n");
	putDLList(stdout,L);
	printf("---------------|\n");
	printf("Add string to the last line\n");
 	DLListMoveTo(L,DLListLength(L));
	DLListAfter(L,"AddAfter2");
 	printf("show the result\n");
	printf("---------------|\n");
	putDLList(stdout,L);
	printf("---------------|\n");
	printf("Add string to the middle line\n");
	DLListMove(L,-1);
	DLListAfter(L,"AddAfter3");
	
	printf("show the result\n");
	printf("---------------|\n");
	putDLList(stdout,L);
	printf("---------------|\n");
	assert(validDLList(L));
	printf("----passed----\n");
}
static void test_delete(DLList L){
	DLListMoveTo(L,1);
	printf("delete the first line\n");
	DLListDelete(L);
	
	printf("---------------|\n");
	putDLList(stdout,L);
	printf("---------------|\n");
	
	printf("delete the last line\n");
	DLListMoveTo(L,DLListLength(L));
	DLListDelete(L);

	printf("---------------|\n");
	putDLList(stdout,L);
	printf("---------------|\n");
	assert(validDLList(L));
	printf("----passed----\n");

}