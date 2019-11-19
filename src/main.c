#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "liner_list_link.h"
#include "liner_list_seq.h"

void test_array() {
	InitiateSeq();
	PrintSeq(L);

	printf("************************Insert*********************** \n");
	UserInfo u5 = { 5, "e" };
	InsertSeq(&L, u5, 2);
	PrintSeq(L);

	printf("************************Delete*********************** \n");
	DeleteSeq(&L, 1);
	PrintSeq(L);

	printf("************************Location*********************** \n");
	printf("location of e is=>%d", LocateSeq(L, (UserInfo ) { 5, "e" }));
}

void test_link() {
	LinkList list =InitLinkList();

	Node node1;
	node1.a=10;
	node1.next=NULL;
	list->next = &node1;

	PrintLinkList(list);

	printf("length of LinkList => %d" , LengthLinkList(list));
}

int main(void) {
	//test_array();
	test_link();
	return EXIT_SUCCESS;
}
