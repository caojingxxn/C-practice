#pragma once
#include <stddef.h>

#define HeapMaxSize 1000

typedef int HeapType;
typedef int (*compare)(HeapType a, HeapType b);

typedef struct Heap {
	HeapType data[HeapMaxSize];
	size_t size;
	compare cmp;
} Heap;

int cmp(HeapType a, HeapType b) {
	return a < b;
}

void HeapInit(Heap* heap, compare cmp);

void HeapInsert(Heap* heap, HeapType value);

int HeapRoot(Heap* heap, HeapType* value);

void HeapErase(Heap* heap);

int HeapEmpty(Heap* heap);

size_t HeapSize(Heap* heap);

void HeapDestory(Heap* heap);

void HeapSort(HeapType arr[], size_t size);




