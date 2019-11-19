#include <stdio.h>

typedef struct node {
	int a;
	struct node * next;
} Node, *LinkList;

LinkList InitLinkList() {
	LinkList head = malloc(sizeof(Node));
	head->next = NULL;
	return head;
}

void PrintLinkList(LinkList head) {
	if (NULL == head->next) {
		printf("空链表 \n");
	} else {
		LinkList temp = head; //保存当前运算的节点指针
		while (NULL != temp->next) { // 如果下一个节点有值
			printf("%d \n", temp->next->a); //就把下一个节点的值打印出来
			temp = temp->next; //将下一个节点的指针赋给temp指针
		}
		free(temp);
	}
}

int LengthLinkList(LinkList head) {
	int len = 0;
	if (NULL != head->next) {
		LinkList temp = head; //保存当前运算的节点指针
		while (NULL != temp->next) { // 如果下一个节点有值
			len++;
			temp = temp->next; //将下一个节点的指针赋给temp指针
		}
		free(temp);
	}
	return len;
}

