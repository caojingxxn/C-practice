#include <stdio.h>
#include <stdlib.h>

#include "DLinkNode.h"

DLinkNode* CreateDNode(DLinkType value) {
	DLinkNode* ptr = (DLinkNode*)malloc(sizeof(DLinkNode));
	ptr->data = value;
	ptr->next = ptr;
	ptr->prev = ptr;
	return ptr;
}

void Destroy(DLinkNode* ptr) {
	free(ptr);
}

void DLinkListInit(DLinkNode** head) {
	if (head == NULL) {
		return;
	}
	*head = CreateDNode(0);
}

DLinkNode* DLinkListPushBack(DLinkNode* head, DLinkType value) {
	if (head == NULL) {
		return NULL;
	}
	DLinkNode* cur = CreateDNode(value);
	DLinkNode* cur_next = head;
	DLinkNode* cur_prev = head->prev;

	cur->next = cur_next;
	cur_next->prev = cur;
	cur->prev = cur_prev;
	cur_prev->next = cur;
	return cur;
}

void DLinkListPopBack(DLinkNode* head) {
	if (head == NULL) {
		return;
	}
	if (head->next == head) {
		return;
	}
	DLinkNode* to_delete = head->prev;
	DLinkNode* to_delete_prev = to_delete->prev;
	DLinkNode* to_delete_next = head;

	to_delete_prev->next = to_delete_next;
	to_delete_next->prev = to_delete_prev;
	Destroy(to_delete);
}

void DLinkListPushFront(DLinkNode* head, DLinkType value) {
	if (head == NULL) {
		return;
	}
	DLinkNode* cur =CreateDNode(value);
	DLinkNode* cur_prev = head;
	DLinkNode* cur_next = head->next;
	
	cur_prev->next = cur;
	cur->prev = cur_prev;
	cur_next->prev = cur;
	cur->next = cur_next;
}

void DLinkListPopFront(DLinkNode* head) {
	if (head == NULL) {
		return;
	}
	if (head->next == head) {
		return;
	}
	DLinkNode* cur = head->next;
	DLinkNode* cur_prev = head;
	DLinkNode* cur_next = cur->next;

	cur_prev->next = cur_next;
	cur_next->prev = cur_prev;
	Destroy(cur);
}

DLinkNode* DLinkListFind(DLinkNode* head,	DLinkType to_find) {
	if (head == NULL) {
		return NULL;
	}
	DLinkNode* cur = head->next;
	for (; cur != head; cur = cur->next) {
		if (cur->data == to_find) {
			return cur;
		}
	}
	return NULL;
}

void DLinkListInsert(DLinkNode* pos, DLinkType value) {
	if (pos == NULL) {
		return;
	}
	DLinkNode* to_insert = CreateDNode(value);
	DLinkNode* to_insert_prev = pos->prev;
	DLinkNode* to_insert_next = pos;
	
	to_insert->next = to_insert_next;
	to_insert_next->prev = to_insert;
	to_insert->prev = to_insert_prev;
	to_insert_prev->next = to_insert;
}

void DLinkListInsertAfter(DLinkNode* pos, DLinkType value) {
	if (pos == NULL) {
		return;
	}
	DLinkNode* to_insert = CreateDNode(value);
	DLinkNode* to_insert_prev = pos;
	DLinkNode* to_insert_next = pos->next;

	to_insert->next = to_insert_next;
	to_insert_next->prev = to_insert;
	to_insert->prev = to_insert_prev;
	to_insert_prev->next = to_insert;
}


/////////////////////////////////////////
//					以下为测试代码
/////////////////////////////////////////
#if 1

void DLinkListPrint(DLinkNode* head, char* str) {
	printf("%s\n",str);
	printf("[head]");
	DLinkNode* cur = head->next;
	for(; cur != head; cur = cur->next) {
		printf(" -> [%c-%p]", cur->data, cur);
	}
	printf("\n[head]");
	for(cur = head->prev; cur != head; cur = cur->prev) {
		printf(" <- [%c-%p]", cur->data, cur);
	}
	printf("\n");
}

void TestPushBack() {
	TEST_HEADER;
	DLinkNode* head;
	DLinkListInit(&head);
	DLinkListPushBack(head, 'a');
	DLinkListPushBack(head, 'b');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'd');
	DLinkListPrint(head,"尾插四个元素");
}

void TestPopBack() {
	TEST_HEADER;
	DLinkNode* head;
	DLinkListInit(&head);
	DLinkListPushBack(head, 'a');
	DLinkListPushBack(head, 'b');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'd');
	DLinkListPrint(head,"尾插四个元素");
	DLinkListPopBack(head);
	DLinkListPopBack(head);
	DLinkListPrint(head,"尾删两个元素");
	DLinkListPopBack(head);
	DLinkListPopBack(head);
	DLinkListPrint(head,"再尾删两个元素");
	DLinkListPopBack(head);
	DLinkListPrint(head,"尝试对空链表尾删");
}

void TestPushFront() {
	TEST_HEADER;
	DLinkNode* head;
	DLinkListInit(&head);
	DLinkListPushFront(head, 'a');
	DLinkListPushFront(head, 'b');
	DLinkListPushFront(head, 'c');
	DLinkListPushFront(head, 'd');
	DLinkListPrint(head,"头插四个元素");
}

void TestPopFront() {
	TEST_HEADER;
	DLinkNode* head;
	DLinkListInit(&head);
	DLinkListPushBack(head, 'a');
	DLinkListPushBack(head, 'b');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'd');
	DLinkListPrint(head,"尾插四个元素");
	DLinkListPopFront(head);
	DLinkListPopFront(head);
	DLinkListPrint(head,"头删两个元素");
	DLinkListPopFront(head);
	DLinkListPopFront(head);
	DLinkListPrint(head,"再头删两个元素");
	DLinkListPopFront(head);
	DLinkListPopFront(head);
	DLinkListPrint(head,"尝试对空链表头删");
}

void TestFind() {
	TEST_HEADER;
	DLinkNode* head;
	DLinkListInit(&head);
	DLinkListPushBack(head, 'a');
	DLinkNode* pos_b = DLinkListPushBack(head, 'b');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'd');
	DLinkListPrint(head,"尾插四个元素");
	DLinkNode* ptr = DLinkListFind(head, 'x');
	printf("查找不存在的元素 expert:NULL actual:%p\n", ptr);
	ptr = DLinkListFind(head, 'b');
	printf("查找b expert:%p actual:%p\n", pos_b, ptr);
}

void TestInsert() {
	TEST_HEADER;
	DLinkNode* head;
	DLinkListInit(&head);
	DLinkListPushBack(head, 'a');
	DLinkNode* pos_b = DLinkListPushBack(head, 'b');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'd');
	DLinkListPrint(head,"尾插四个元素");
	DLinkListInsert(pos_b, 'x');
	DLinkListPrint(head,"在b前面插入x");
}

void TestInsertAfter() {
	TEST_HEADER;
	DLinkNode* head;
	DLinkListInit(&head);
	DLinkListPushBack(head, 'a');
	DLinkNode* pos_b = DLinkListPushBack(head, 'b');
	DLinkListPushBack(head, 'c');
	DLinkListPushBack(head, 'd');
	DLinkListPrint(head,"尾插四个元素");
	DLinkListInsertAfter(pos_b, 'x');
	DLinkListPrint(head,"在b后面插入x");
}

int main() {
	system("clear");
	TestPushBack();
	TestPopBack();
	TestPushFront();
	TestPopFront();
	TestFind();
	TestInsert();
	TestInsertAfter();
	return 0;
}
#endif
