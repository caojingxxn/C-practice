#include "BitMap.h"
#include <stdlib.h>
#include <string.h>

size_t Calculate(size_t capacity) {
	return capacity / (sizeof(uint64_t) * 8) + 1;
}

void BitMapInit(BitMap* bm, size_t capacity) {
	if (bm == NULL) {
		return;
	}
	bm->capacity = capacity;
	bm->data = (uint64_t*)malloc(Calculate(capacity) * 8);
}

void BitMapSet(BitMap* bm, size_t index) {
	if (bm == NULL) {
		return;
	}
	size_t n = index / (sizeof(uint64_t) * 8);
	size_t offset = index % (sizeof(uint64_t) * 8);
	bm->data[n] |= 1ul << offset;
}

void BitMapUnset(BitMap* bm, size_t index) {
	if (bm == NULL) {
		return;
	}
	size_t n = index / (sizeof(uint64_t) * 8);
	size_t offset = index % (sizeof(uint64_t) * 8);
	bm->data[n] &= ~(1ul << offset);
}

int BitMapTest(BitMap* bm, size_t index) {
	if (bm == NULL) {
		return 0;
	}
	size_t n = index / (sizeof(uint64_t) * 8);
	size_t offset = index % (sizeof(uint64_t) * 8);
	uint64_t ret = bm->data[n] & (1ul << offset);
	return ret > 0;
}

void BitMapFill(BitMap* bm) {
	if (bm == NULL) {
		return;
	}
	memset(bm->data, 0xff, (Calculate(bm->capacity)) * 8);
}

void BitMapClear(BitMap* bm) {
	if (bm == NULL) {
		return;
	}
	memset(bm->data, 0, (Calculate(bm->capacity)) * 8);
}

void BitMapDestroy(BitMap* bm) {
	bm->capacity = 0;
	free(bm->data);
}


/////////////////////////////
// 以下为测试代码
/////////////////////////////
#if 0
#define TEST_HEADER printf("\n=======%s=======\n", __FUNCTION__)
#include <stdio.h>

void TestInit() {
	TEST_HEADER;
	BitMap bm;
	BitMapInit(&bm, 63);
	printf("capacity expert 63, actual %lu\n", bm.capacity);
}

void TestSet() {
	TEST_HEADER;
	BitMap bm;
	BitMapInit(&bm, 300);
	BitMapSet(&bm, 280);
	size_t i = 0;
	for (; i < bm.capacity / (sizeof(uint64_t) * 8) + 1; ++i) {
		printf("[%lu: %lx] ", i, bm.data[i]);
	}
}

void TestUnset() {
	TEST_HEADER;
	BitMap bm;
	BitMapInit(&bm, 300);
	BitMapSet(&bm, 280);
	BitMapUnset(&bm, 280);
	size_t i = 0;
	for (; i < bm.capacity / (sizeof(uint64_t) * 8) + 1; ++i) {
		printf("[%lu: %lx] ", i, bm.data[i]);
	}
}

void TestTest() {
	TEST_HEADER;
	BitMap bm;
	BitMapInit(&bm, 300);
	BitMapSet(&bm, 290);
	int ret = BitMapTest(&bm, 290);
	printf("ret expert 1, actual %d\n", ret);
	BitMapUnset(&bm, 290);
	ret = BitMapTest(&bm, 290);
	printf("ret expert 0, actual %d\n", ret);
}

void TestFill() {
	TEST_HEADER;
	BitMap bm;
	BitMapInit(&bm, 64);
	BitMapFill(&bm);
	size_t i = 0;
	for (; i < bm.capacity / (sizeof(uint64_t) * 8) + 1; ++i) {
		printf("[%lu: %lx] ", i, bm.data[i]);
	}
}

void TestClear() {
	TEST_HEADER;
	BitMap bm;
	BitMapInit(&bm, 64);
	BitMapSet(&bm, 60);
	BitMapClear(&bm);
	size_t i = 0;
	for (; i < bm.capacity / (sizeof(uint64_t) * 8) + 1; ++i) {
		printf("[%lu: %lx] ", i, bm.data[i]);
	}
}


int main() {
	system("clear");
	TestInit();
	TestSet();
	TestUnset();
	TestTest();
	TestFill();
	TestClear();
	return 0;
}

#endif


