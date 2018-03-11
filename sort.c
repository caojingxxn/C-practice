#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "../SeqStack/SeqStack.h"

typedef int ElemType;

void Swap(ElemType* a, ElemType* b) {
	ElemType tmp = *a;
	*a = *b;
	*b = tmp;
}

/////////////////////////////
// 冒泡排序
/////////////////////////////
void BubbleSort(ElemType data[], size_t size) {
	if (size == 1) {
		return;
	}
	size_t bound = 1;
	for (; bound < size; ++bound) {
		size_t i = size - 1;
		for (; i >= bound; --i) {
			if (data[i] < data[i-1]) {
				Swap(&data[i], &data[i-1]);
			}
		}
	}
}

/////////////////////////////
//选择排序
/////////////////////////////
void SeleteSort(ElemType data[], size_t size) {
	size_t bound = 0;
	for (; bound < size; ++bound) {
		size_t i = bound + 1;
		for (; i < size; ++i) {
			if (data[bound] > data[i]) {
				Swap(&data[bound], &data[i]);
			}
		}
	}
}

/////////////////////////////
// 插入排序
/////////////////////////////
void InsertSort(ElemType data[], size_t size) {
	if (size == 1) {
		return;
	}
	size_t bound = 1;
	for (; bound < size; ++bound) {
		ElemType value = data[bound];
		size_t i = bound;
		for (; i > 0; --i) {
			if (data[i-1] > value) {
				data[i] = data[i-1];
			} else {
				break;
			}
		}
		data[i] = value;
	}
}

/////////////////////////////
// 堆排序
/////////////////////////////
void AdjustDown(ElemType data[], size_t size, size_t index) {
	size_t parent = index;
	size_t child = index * 2 + 1;
	while (child < size) {
		if (child + 1 < size && data[child] < data[child+1]) {
				++child;
		}
		if (data[parent] < data[child]) {
			Swap(&data[parent], &data[child]);
		} else {
			break;
		}
		parent = child;
		child = parent * 2 + 1;
	}
}

void CreateHeap(ElemType data[], size_t size) {
	size_t offset = (size - 1 - 1) / 2;
	for (; offset > 0; --offset) {
		AdjustDown(data, size, offset);
	}
	AdjustDown(data, size, 0);
}

void RemoveRoot(ElemType data[], size_t size){
	Swap(&data[0], &data[size-1]);
	AdjustDown(data, size-1, 0);
}

void HeapSort(ElemType data[], size_t size) {
	if (size == 1) {
		return;
	}
	// 1.插入元素，创建堆
	CreateHeap(data, size);
	// 2.依次删除元素
	size_t i = 0;
	for (; i < size; ++i) {
		RemoveRoot(data, size-i);
	}
}

/////////////////////////////
// 希尔排序
/////////////////////////////
void ShellSort(ElemType data[], size_t size) {
	if (size == 1) {
		return;
	}
	size_t d = size / 2;
	for (; d >= 1; d /= 2) {
		size_t i = d;
		for (; i < size; ++i) {
			ElemType tmp = data[i];
			int j = i - d;
			while(tmp < data[j] && j >= 0) {
				data[j+d] = data[j];	
				j -= d;
			}
			data[j+d] = tmp;
		}
	}
}

/////////////////////////////
// 归并排序(循环)
/////////////////////////////
// 1.[beg, mid)
// 2.[mid, end)
void Merge(ElemType data[], size_t beg, size_t mid, size_t end, 
		ElemType tmp[]) {
	if (end <= beg) {
		return;
	}
	size_t i = 0;
	size_t beg1 = beg;
	size_t beg2 = mid;
	while (beg1 < mid && beg2 < end) {
		if (data[beg1] < data[beg2]) {
			tmp[i++] = data[beg1++];
		} else {
			tmp[i++] = data[beg2++];
		}
	}
	while (beg1 < mid) {
		tmp[i++] = data[beg1++];
	}
	while (beg2 < end) {
		tmp[i++] = data[beg2++];
	}
	memcpy(data + beg, tmp, sizeof(ElemType) * (end - beg));
}

void MergeSortByLoop(ElemType data[], size_t size) {
	if (size == 1) {
		return;
	}
	ElemType* tmp = (ElemType*)malloc(sizeof(ElemType) * size);
	size_t d = 1;
	for (; d <= size; d *= 2) {
		size_t beg = 0;
		size_t mid = beg + d;
		size_t end = mid + d;
		for (; beg < size; beg += 2 * d, mid = beg + d, end = mid + d) {
			if (mid >= size) {
				mid = size;
			}
			if (end >= size) {
				end = size;
			}
			Merge(data, beg, mid, end, tmp);
		}
	}
	free(tmp);
}

/////////////////////////////
// 冒泡排序(递归)
/////////////////////////////
void _MergeSort(ElemType data[], size_t beg, 
			size_t mid, size_t end, ElemType tmp[]) {
	if ( mid <= beg || end <= mid ) {
		return;
	}
	size_t mid1 = beg + (mid - beg) / 2;
	size_t mid2 = mid + (end - mid) / 2;
	_MergeSort(data, beg, mid1, mid, tmp);
	_MergeSort(data, mid, mid2, end, tmp);
	Merge(data, beg, mid, end, tmp);
}

void MergeSort(ElemType data[], size_t size) {
	if (size == 1) {
		return;
	}
	ElemType* tmp = (ElemType*)malloc(sizeof(ElemType) * size);
	_MergeSort(data, 0, size / 2, size, tmp);
	free(tmp);
}

/////////////////////////////
// 快速排序
/////////////////////////////
int64_t Sort_quick1(ElemType data[], int64_t beg, int64_t end) {
	int64_t left = beg;
	int64_t right = end - 1;
	while (left < right) {
		while (left < right && data[left] <= data[end - 1]) {
			// 到了第一个比 tmp 大， 或到了 tmp 的位置
			++left;
		}
		while (left < right && data[right] >= data[end - 1]) {
			// 如果 left 已经在 tmp 的位置， 则 left == right， 直接退出
			// 如果不是，则 right 到了一个比 tmp 小的位置，
			//						  或者直接到了 left 的位置
			//						  这个位置上， data 值 比 tmp 大
			--right;
		}
		if (left < right) {
			// 不能直接left++ 和 right--
			// 当 left 与 right 相差 2 时， 会出错
			Swap(&data[left], &data[right]);
		}
	}
	Swap(&data[left], &data[end-1]);
	return left;
}

int64_t Sort_quick2(ElemType data[], int64_t beg, int64_t end) {
	int64_t left = beg;
	int64_t right = end - 1;
	ElemType tmp = data[right];
	while (left < right) {
		while (left < right && data[left] < data[end - 1]) {
			++left;
		}
		data[right] = data[left];
		while (left < right && data[right] >= data[end - 1]) {
			--right;
		}
		data[left] = data[right];
	}
	data[left] = tmp;
	return left;
}

int64_t Sort_quick3(ElemType data[], int64_t beg, int64_t end) {
	int64_t pre = beg - 1;
	int64_t next = beg;
	// pre 和 next 中夹着的值为小于 data[end-1] 的值
	while (next < end - 1) {
		if (data[next] < data[end - 1] && ++pre != next) {
			Swap(&data[pre], &data[next]);
		}
		++next;
	}
	if (data[++pre] != data[end - 1]) {
		Swap(&data[pre], &data[end - 1]);
	}
	return pre;
}

void _QuickSort(ElemType data[], int64_t beg, int64_t end) {
	if (end - beg <= 1) {
		return;
	}
	int64_t mid = Sort_quick1(data, beg, end);
	_QuickSort(data, beg, mid);
	_QuickSort(data, mid + 1, end);
}

void QuickSort(ElemType data[], int64_t size) {
	if (size <= 1) {
		return;
	}
	_QuickSort(data, 0, size);
}

/////////////////////////////
// 冒泡排序(循环)
/////////////////////////////
typedef struct QuickNode {
	int64_t beg;
	int64_t end;
} QuickNode;

void QuickSortByLoop(ElemType data[], int64_t size) {
	if (size <= 1) {
		return;
	}
	SeqStack stack;
	SeqStackInit(&stack);
	QuickNode* q = (QuickNode*)malloc(sizeof(QuickNode));
	q->beg = 0;
	q->end = size;
	SeqStackPush(&stack, q);

	while (SeqStackTop(stack, &q)) {
		int64_t mid = Sort_quick3(data, q->beg, q->end);
		QuickNode* q1 = (QuickNode*)malloc(sizeof(QuickNode));
		q1->beg = q->beg;
		q1->end = mid;

		QuickNode* q2 = (QuickNode*)malloc(sizeof(QuickNode));
		q2->beg = mid + 1;
		q2->end = q->end;

		SeqStackPop(&stack);
		free(q);
		if (q1->end - q1->beg > 1 && q1->beg >= 0) {
			SeqStackPush(&stack, q1);
		}
		if (q2->end - q2->beg > 1 && q2->end <= size) {
			SeqStackPush(&stack, q2);
		}
	}
}


/////////////////////////////////
// 以下为测试代码
/////////////////////////////////
#if 1

void Print(ElemType data[], size_t size) {
	size_t i = 0;
	for (; i < size; ++i) {
		printf("%d ", data[i]);
	}
	printf("\n");
}

int main() {
	system("clear");
	ElemType data[] = {4, 6, 10, 7, 2, 0, 5, 9, 1, 8};
	// BubbleSort(data, 10);
	// SeleteSort(data, 10);
	// InsertSort(data, 10);
	// HeapSort(data, 10);
	// ShellSort(data, 10);
	// MergeSort(data, 10);
	// MergeSortByLoop(data, 10);
	// QuickSort(data, 10);
	QuickSortByLoop(data, 10);
	Print(data, 10);
}

#endif


