#pragma once
#include <stddef.h>

#define SeqQueueMaxSize 1000

typedef char QueueType;

typedef struct SeqQueue {
	QueueType data[SeqQueueMaxSize];
	int head;
	int tail;
	size_t size;
}SeqQueue;

void SeqQueueInit(SeqQueue* queue);

void SeqQueuePush(SeqQueue* queue, QueueType value);

void SeqQueuePop(SeqQueue* queue);

int SeqQueueFront(SeqQueue* queue, QueueType* value);

int SeqQueueBack(SeqQueue* queue, QueueType* value);

size_t SeqQueueSize(SeqQueue* queue);

