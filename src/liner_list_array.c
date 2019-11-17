#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	char name[8];
} UserInfo;

int MAX_LEN = 10;

typedef struct {
	UserInfo data[10];
	int length;
} SeqList;

SeqList L;

void Initiate() {
	L.data[0] = (UserInfo ) { 1, "a" };
	L.data[1] = (UserInfo ) { 2, "b" };
	L.data[2] = (UserInfo ) { 3, "c" };
	L.data[3] = (UserInfo ) { 4, "d" };
	L.length = 4;
}

void PrintList(SeqList L) {
	printf("length => %d \n", L.length);

	for (int i = 0; i < L.length; i++) {
		printf("index=> %d , UserInfo.id => %d , UserInfo.name=> %s \n", i,
				L.data[i].id, L.data[i].name);
	}
}

void Insert(SeqList *L, UserInfo u, int i) {
	if (L->length == MAX_LEN) {
		printf("满了");
		exit(-1);
	}

	if (!(i > 0 && i <= L->length + 1)) {
		printf("位置参数非法,当前长度为=>%d", L->length);
		exit(-1);
	}

	for (int j = L->length; j >= i; j--) { //从最后一个开始，都往后移一个位置
		L->data[j] = L->data[j - 1]; // 往后移动
	}
	L->data[i - 1] = u;
	L->length++;
}

int Locate(SeqList L, UserInfo u) {
	int location = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i].id == u.id) {
			location = i + 1;
			break;
		}
	}
	return location;
}

void Delete(SeqList *L, int i) {
	if (!(i > 0 && i <= L->length)) {
		printf("位置参数非法,当前长度为=>%d", L->length);
		exit(-1);
	}

	for (int j = i; j < L->length; j++) {
		L->data[j - 1] = L->data[j]; //依次左移
	}
	L->length--;
}

int main(void) {
	Initiate();
	PrintList(L);

	printf("************************Insert*********************** \n");
	UserInfo u5 = { 5, "e" };
	Insert(&L, u5, 5);
	PrintList(L);

	printf("************************Delete*********************** \n");
	Delete(&L, 1);
	PrintList(L);

	printf("************************Location*********************** \n");
	printf("location of e is=>%d", Locate(L, (UserInfo ) { 5, "e" }));
	return EXIT_SUCCESS;
}
