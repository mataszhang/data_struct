#include <stdio.h>

typedef struct node {
	int data;
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
		Node* p = head; //保存当前运算的节点指针
		while (NULL != p->next) { // 如果下一个节点有值
			printf("%d \n", p->next->data); //就把下一个节点的值打印出来
			p = p->next; //将下一个节点的指针赋给temp指针
		}
	}
}

/**
 * T(n) =O(n)
 */
int LengthLinkList(LinkList head) {
	int len = 0;
	if (NULL != head->next) {
		Node* p = head; //保存当前运算的节点指针
		while (NULL != p->next) { // 如果下一个节点有值
			len++;
			p = p->next; //将下一个节点的指针赋给temp指针
		}
	}
	return len;
}

/**
 * T(n) =O(n)
 */
Node * GetLinkList(LinkList head, int position) {
	Node* p;
	p = head->next; //p指向首节点
	int j = 1; //由于p指向首节点，所以从1开始计数
	while (p != NULL && j < position) {
		p = p->next;
		j++;
	}

	if (position == j) {
		return p;
	} else {
		return NULL;
	}
}

/**
 * T(n) =O(n)
 */
int LocateLinkList(LinkList head, int target) {
	Node* p = head->next; //首节点
	int position = 1;
	while (p != NULL && p->data != target) {
		p = p->next;
		position++;
	}

	if (p != NULL) {
		return position;
	}
	return -1;
}

/**
 * T(n) =O(n)
 */
void InsertLinkList(LinkList head, int data, int position) {
	Node *prev; // 在position位置插入节点，首先获取position位置的前驱节点
	Node *curr; //要插入的节点

	if (position == 1) {
		prev = head; // 前驱节点为头节点
	} else {
		prev = GetLinkList(head, position - 1);
	}

	if (prev == NULL) {
		printf("前驱节点不存在");
		exit(-1);
	}

	curr = malloc(sizeof(Node));
	curr->data = data;

	curr->next = prev->next; //首先将前驱节点指向的next节点地址赋给curr节点的next指针
	prev->next = curr; //然后将前驱节点的next指针指向curr节点
}

/**
 * T(n) =O(n)
 */
void DeleteLinkList(LinkList head, int position) {
	if (position < 1 || position > LengthLinkList(head)) {
		printf("位置有误");
		exit(-1);
	}

	Node *prev, *del; //前驱节点，要删除的节点
	if (position == 1) {
		prev = head; //如果要删除第一个，前驱节点则为头结点
	} else {
		prev = GetLinkList(head, position - 1);
	}
	
	if (prev == NULL || prev->next == NULL) {
		printf("找不到要删除的节点");
		exit(-1);
	}

	del = prev->next;
	prev->next = del->next;
	free(del);
}

