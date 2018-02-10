#include "SeqQueue.h"

void SeqQueueInit(SeqQueue* queue) {
	if (queue == NULL) {
		return;
	}
	queue->head = 0;
	queue->tail = 0;
	queue->size = 0;
}

void SeqQueuePush(SeqQueue* queue, QueueType value) {
	if (queue == NULL) {
		return;
	}
	if (queue->size == SeqQueueMaxSize) {
		return;
	}
	queue->data[queue->tail++] = value; 
	queue->tail %= SeqQueueMaxSize;
	queue->size++;
}

void SeqQueuePop(SeqQueue* queue) {
	if (queue == NULL) {
		return;
	}
	if (queue->size == 0) {
		return;
	}
	queue->head++;
	queue->head %= SeqQueueMaxSize;
	queue->size--;
}

int SeqQueueFront(SeqQueue* queue, QueueType* value) {
	if (queue == NULL || value == NULL) {
		return 0;
	}
	if (queue->size == 0) {
		return 0;
	}
	*value = queue->data[queue->head];
	return 1;
}

int SeqQueueBack(SeqQueue* queue, QueueType* value) {
	if (queue == NULL || value == NULL) {
		return 0;
	}
	if (queue->size == 0) {
		return 0;
	}
	*value = queue->data[queue->tail-1];
	return 1;
}

size_t SeqQueueSize(SeqQueue* queue) {
	if (queue == NULL) {
		return (size_t)-1;
	}
	return queue->size;
}

//////////////////////////////////////
//   以下是测试代码
//////////////////////////////////////
#if 0
#include <stdio.h>

void Test() {
	SeqQueue q;
	SeqQueueInit(&q);
	SeqQueuePush(&q, 'a');
	SeqQueuePush(&q, 'b');
	SeqQueuePush(&q, 'c');
	SeqQueuePush(&q, 'd');

	QueueType value_F;
	QueueType value_B;
	int ret_F = SeqQueueFront(&q, &value_F);
	int ret_B = SeqQueueBack(&q, &value_B);
	printf("ret_F  expect:1 actual:%d\n", ret_F);
	printf("ret_B  expect:1 actual:%d\n", ret_B);
	printf("value_F  expect:a actual:%c\n", value_F);
	printf("value_B  expect:d actual:%c\n\n", value_B);
	SeqQueuePop(&q);

	ret_F = SeqQueueFront(&q, &value_F);
	ret_B = SeqQueueBack(&q, &value_B);
	printf("ret_F  expect:1 actual:%d\n", ret_F);
	printf("ret_B  expect:1 actual:%d\n", ret_B);
	printf("value_F  expect:b actual:%c\n", value_F);
	printf("value_B  expect:d actual:%c\n\n", value_B);
	SeqQueuePop(&q);

	ret_F = SeqQueueFront(&q, &value_F);
	ret_B = SeqQueueBack(&q, &value_B);
	printf("ret_F  expect:1 actual:%d\n", ret_F);
	printf("ret_B  expect:1 actual:%d\n", ret_B);
	printf("value_F  expect:c actual:%c\n", value_F);
	printf("value_B  expect:d actual:%c\n\n", value_B);
	SeqQueuePop(&q);

	ret_F = SeqQueueFront(&q, &value_F);
	ret_B = SeqQueueBack(&q, &value_B);
	printf("ret_F  expect:1 actual:%d\n", ret_F);
	printf("ret_B  expect:1 actual:%d\n", ret_B);
	printf("value_F  expect:d actual:%c\n", value_F);
	printf("value_B  expect:d actual:%c\n\n", value_B);
	SeqQueuePop(&q);

	ret_F = SeqQueueFront(&q, &value_F);
	ret_B = SeqQueueBack(&q, &value_B);
	printf("ret_F  expect:0 actual:%d\n", ret_F);
	printf("ret_B  expect:0 actual:%d\n\n", ret_B);

	SeqQueuePush(&q, 'e');
	ret_F = SeqQueueFront(&q, &value_F);
	ret_B = SeqQueueBack(&q, &value_B);
	printf("ret_F  expect:1 actual:%d\n", ret_F);
	printf("ret_B  expect:1 actual:%d\n", ret_B);
	printf("value_F  expect:e actual:%c\n", value_F);
	printf("value_B  expect:e actual:%c\n\n", value_B);
}

int main() {
	system("clear");
	Test();
}
#endif



