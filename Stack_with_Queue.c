#include "SeqQueue.h"

typedef struct Stack_with_queue {
	SeqQueue entry;
	SeqQueue exit;
}SwQueue;

void SwQueueInit(SwQueue* q) {
	if (q == NULL) {
		return;
	}
	SeqQueueInit(&q->entry);
	SeqQueueInit(&q->exit);
}

void SwQueuePush(SwQueue* q, QueueType value) {
	if (q == NULL) {
		return;
	}
	if (SeqQueueSize(&q->exit) == 0) {
		SeqQueuePush(&q->entry, value);
	} else {
		SeqQueuePush(&q->exit, value);
	}
}

void SwQueuePop(SwQueue* q) {
	if (q == NULL) {
		return;
	}
	QueueType value;
	size_t size1 = SeqQueueSize(&q->entry);
	SeqQueue* non_empty = size1 > 0 ? &q->entry : &q->exit;
	SeqQueue* empty = size1 == 0 ? &q->entry : &q->exit;

	while (SeqQueueSize(non_empty) > 1) {
		SeqQueueFront(non_empty, &value);
		SeqQueuePop(non_empty);
		SeqQueuePush(empty, value);
	}
	SeqQueuePop(non_empty);
}

int SwQueueTop(SwQueue* q, QueueType* value) {
	if (q == NULL || value == NULL) {
		return 0;
	}
	if (SeqQueueSize(&q->entry) == 0) {
		return SeqQueueBack(&q->exit, value);
	} else {
		return SeqQueueBack(&q->entry, value);
	}
}

//////////////////////////////////
// 以下为测试代码
//////////////////////////////////
#if 1
#include <stdio.h>

void Test() {
	SwQueue q;
	SwQueueInit(&q);
	SwQueuePush(&q, 'a');
	SwQueuePush(&q, 'b');
	SwQueuePush(&q, 'c');
	SwQueuePush(&q, 'd');
	
	QueueType value;
	int ret = SwQueueTop(&q, &value);
	printf("ret expect:1 actual:%d\n", ret);
	printf("value expect:d actual:%c\n\n", value);
	SwQueuePop(&q);

	ret = SwQueueTop(&q, &value);
	printf("ret expect:1 actual:%d\n", ret);
	printf("value expect:c actual:%c\n\n", value);
	SwQueuePop(&q);

	ret = SwQueueTop(&q, &value);
	printf("ret expect:1 actual:%d\n", ret);
	printf("value expect:b actual:%c\n\n", value);
	SwQueuePop(&q);

	ret = SwQueueTop(&q, &value);
	printf("ret expect:1 actual:%d\n", ret);
	printf("value expect:a actual:%c\n\n", value);
	SwQueuePop(&q);

	ret = SwQueueTop(&q, &value);
	printf("ret expect:0 actual:%d\n\n", ret);
}

int main() {
	Test();
	return 0;
}

#endif
