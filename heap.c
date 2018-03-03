#include "heap.h"
void HeapInit(Heap* heap, compare cmp) {
	heap->size = 0;
	heap->cmp = cmp;
}

void Swap(HeapType* a, HeapType* b) {
	HeapType tmp = *a;
	*a = *b;
	*b = tmp;
}

void AdjustUp(HeapType* data, size_t size, compare cmp, size_t index) {
	size_t child = index;
	size_t parent;
	while (child > 0) {
		parent = (child - 1) / 2;
		if (cmp(data[child], data[parent])) {
			Swap(&data[child], &data[parent]);
		} else {
			break;
		}
		child = parent;
	}
}

void HeapInsert(Heap* heap, HeapType value) {
	if (heap == NULL) {
		return;
	}
	if (heap->size >= HeapMaxSize) {
		return;
	}
	heap->data[heap->size++] = value;
	AdjustUp(heap->data, heap->size, heap->cmp, heap->size - 1);
}

int HeapRoot(Heap* heap, HeapType* value) {
	if (heap == NULL || value == NULL) {
		return 0;
	}
	if (heap->size == 0) {
		return 0;
	}
	*value =  heap->data[0];
	return 1;
}

void AdjustDown(HeapType* data, size_t size, compare cmp, size_t index) {
	size_t parent = index;
	size_t child = parent*2 + 1;
	while (child < size) {
		if (child+1 < size && cmp(data[child+1], data[child])) {
			++child;
		}
		if (cmp(data[child], data[parent])) {
			Swap(&data[child], &data[parent]);
		} else {
			break;
		}
		parent = child;
		child = parent*2 + 1;
	}
}

void HeapErase(Heap* heap) {
	if (heap == NULL) {
		return;
	}
	if (heap->size == 0) {
		return;
	}
	if (heap->size == 1) {
		heap->size = 0;
		return;
	}
	Swap(&heap->data[0], &heap->data[heap->size-1]);
	--heap->size;
	AdjustDown(heap->data, heap->size, heap->cmp, 0);
}

int HeapEmpty(Heap* heap) {
	if (heap == NULL) {
		return 0;
	}
	return (heap->size == 0);
}

size_t HeapSize(Heap* heap) {
	if (heap == NULL) {
		return 0;
	}
	return heap->size;
}

void HeapDestory(Heap* heap) {
	heap->size = 0;
}

#if 0
void HeapSort(HeapType arr[], size_t size) {
	if (size <= 1) {
		return;
	}
	Heap heap;
	HeapInit(&heap, cmp);
	size_t i = 0;
	for (; i < size; ++i) {
		HeapInsert(&heap, arr[i]);
	}
  for (i = 0; i < size; ++i) {
  	HeapRoot(&heap, &arr[i]);
  	HeapErase(&heap);
  }
}
#else

void HeapSort(HeapType arr[], size_t size) {
	if (size <= 1) {
		return;
	}
	size_t parent = (size-1-1) / 2;
	for (; parent > 0; --parent) {
		AdjustDown(arr, size, cmp, parent);
	}
	AdjustDown(arr, size, cmp, 0);
	size_t heap_size = size;
	while (heap_size > 0) {
		Swap(&arr[0], &arr[heap_size-1]);
		--heap_size;
		AdjustDown(arr, heap_size, cmp, 0);
	}
}

#endif

////////////////////////
// 以下是测试代码
////////////////////////
#if 1
#include <stdio.h>
#define TEST_HEADER printf("\n==========%s==========\n", __FUNCTION__)

void HeapPrintChar(Heap* heap, HeapType* msg) {
	printf("%s\n", msg);
	size_t i = 0;
	for (; i < heap->size; ++i) {
		printf("%d ", heap->data[i]);
	}
	printf("\n");
}

void TestInit() {
	TEST_HEADER;
	Heap heap;
	HeapInit(&heap, cmp);
	printf("heap.size expert:0 actual:%lu\n", heap.size);
	printf("heap.cmp expert:%p actual:%p\n", cmp, heap.cmp);
}

void TestInsert() {
	TEST_HEADER;
	Heap heap;
	HeapInit(&heap, cmp);
	HeapInsert(&heap, 9);
	HeapInsert(&heap, 15);
	HeapInsert(&heap, 27);
	HeapInsert(&heap, 6);
	HeapInsert(&heap, 14);
	HeapInsert(&heap, 22);
	HeapPrintChar(&heap, "插入六个元素");
}

void TestRoot() {
	TEST_HEADER;
	Heap heap;
	HeapInit(&heap, cmp);
	HeapInsert(&heap, 9);
	HeapInsert(&heap, 15);
	HeapInsert(&heap, 27);
	HeapInsert(&heap, 6);
	HeapInsert(&heap, 14);
	HeapInsert(&heap, 22);
	HeapType value;
	int ret = HeapRoot(&heap, &value);
	printf("ret expert:1 actual:%d\n", ret);
	printf("Root expert:6 actual:%d\n", value);
}

void TestEraseandSize() {
	TEST_HEADER;
	Heap heap;
	HeapInit(&heap, cmp);
	HeapInsert(&heap, 15);
	HeapInsert(&heap, 4);
	HeapInsert(&heap, 6);
	HeapInsert(&heap, 19);
	HeapInsert(&heap, 3);
	HeapInsert(&heap, 9);
	HeapInsert(&heap, 18);
	HeapPrintChar(&heap, "尾插");
	printf("size expert:6 actual:%lu\n", HeapSize(&heap));
	HeapErase(&heap);
	HeapPrintChar(&heap, "删去最小元素");
	HeapErase(&heap);
	HeapPrintChar(&heap, "删去最小元素");
	HeapErase(&heap);
	HeapPrintChar(&heap, "删去最小元素");
	HeapErase(&heap);
	HeapPrintChar(&heap, "删去最小元素");
	HeapErase(&heap);
	HeapPrintChar(&heap, "删去最小元素");
}

void TestEmpty() {
	TEST_HEADER;
	Heap heap;
	HeapInit(&heap, cmp);
	HeapInsert(&heap, 9);
	HeapErase(&heap);
	printf("empty expert:1 actual:%d\n", HeapEmpty(&heap));
}

void TestSort() {
	TEST_HEADER;
	HeapType arr[] = {15, 4, 6, 19, 3, 9, 18};
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	size_t i = 0;
  for (; i < sizeof(arr) / sizeof(arr[0]); ++i) {
  	printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
	system("clear");
	TestInit();
	TestInsert();
	TestRoot();
	TestEraseandSize();
	TestEmpty();
	TestSort();
	return 0;
}

#endif

