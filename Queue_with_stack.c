#include "SeqStack.h"

typedef struct queue_with_stack {
	SeqStack entry;
	SeqStack exit;
}QwStack;

void QwStackInit(QwStack* q) {
	if (q == NULL) {
		return;
	}
	SeqStackInit(&q->entry);
	SeqStackInit(&q->exit);
}

void QwStackPush(QwStack* q, SeqType value) {
	if (q == NULL) {
		return;
	}
	SeqType tmp;
	while (SeqStackTop(q->exit, &tmp)) {
		SeqStackPop(&q->exit);
		SeqStackPush(&q->entry, tmp);
	}
	SeqStackPush(&q->entry, value);
}

void QwStackPop(QwStack* q) {
	if (q == NULL) {
		return;
	}
	SeqType value;
	while (SeqStackTop(q->entry, &value)) {
		SeqStackPop(&q->entry);
		SeqStackPush(&q->exit, value);
	}
	SeqStackPop(&q->exit);
}

int QwStackFront(QwStack* q, SeqType* value) {
	if (q == NULL || value == NULL) {
		return 0;
	}
	SeqType tmp;
	while (SeqStackTop(q->entry, &tmp)) {
		SeqStackPop(&q->entry);
		SeqStackPush(&q->exit, tmp);
	}
	return SeqStackTop(q->exit, value);
}

////////////////////////////////
// 以下为测试代码
////////////////////////////////
#include <stdio.h>

void Test() {
	QwStack q;
	QwStackInit(&q);
	QwStackPush(&q, 'a');
	QwStackPush(&q, 'b');
	QwStackPush(&q, 'c');
	QwStackPush(&q, 'd');

	SeqType value;
	int ret = QwStackFront(&q, &value);
	printf("ret expect:1 actual:%d\n", ret);
	printf("value expect:a actual:%c\n", value);
	QwStackPop(&q);

	ret = QwStackFront(&q, &value);
	printf("ret expect:1 actual:%d\n", ret);
	printf("value expect:b actual:%c\n", value);
	QwStackPop(&q);

	ret = QwStackFront(&q, &value);
	printf("ret expect:1 actual:%d\n", ret);
	printf("value expect:c actual:%c\n", value);
	QwStackPop(&q);

	QwStackPush(&q, 'e');

	ret = QwStackFront(&q, &value);
	printf("ret expect:1 actual:%d\n", ret);
	printf("value expect:d actual:%c\n", value);
	QwStackPop(&q);

	ret = QwStackFront(&q, &value);
	printf("ret expect:1 actual:%d\n", ret);
	printf("value expect:e actual:%c\n", value);
	QwStackPop(&q);
	
	ret = QwStackFront(&q, &value);
	printf("ret expect:0 actual:%d\n", ret);
}

int main() {
	system("clear");
	Test();
	return 0;
}
