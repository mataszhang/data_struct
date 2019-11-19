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
	printf("location of e is=>%d", LocateSeq(L, (UserInfo )
			{ 5, "e" }));
}

void test_link() {
	LinkList list = InitLinkList();
	InsertLinkList(list, 10, 1);
	InsertLinkList(list, 20, 2);
	InsertLinkList(list, 30, 3);
	InsertLinkList(list, 40, 4);
	InsertLinkList(list, 50, 5);

	InsertLinkList(list, 52, 2);

	printf("***********************Print**************************** \n");
	PrintLinkList(list);

	printf("***********************Get**************************** \n");
	int position = 4;
	Node* find = GetLinkList(list, position);
	printf("data at position %d => %d \n", position,
			find == NULL ? -1 : find->data);

	printf("***********************Locate**************************** \n");
	int data = 20;
	printf("data %d at position=> %d \n", data, LocateLinkList(list, data));

	printf("***********************Length**************************** \n");
	printf("length of LinkList => %d \n", LengthLinkList(list));

	printf("***********************Delete**************************** \n");
	position = 5;
	DeleteLinkList(list, position);
	printf("print list after delete position => %d \n", position);
	PrintLinkList(list);
}

int main(void) {
	//test_array();
	test_link();
	return EXIT_SUCCESS;
}
