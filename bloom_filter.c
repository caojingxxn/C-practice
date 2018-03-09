#include "bloom_filter.h"
#include <stdio.h>
size_t HashFunc0(const char* str) {
	unsigned int hash = 1315423911;
  while (*str) {
  	hash ^= ((hash << 5) + (*str++) + (hash >> 2));
  }
	return (hash & 0x7FFFFFFF);
}

size_t HashFunc1(const char* str) {
	unsigned int hash = 0;
	while (*str) {
    hash = (*str++) + (hash << 6) + (hash << 16) - hash;
  }
  return (hash & 0x7FFFFFFF);
}

void BloomFilterInit(BloomFilter* bf) {
	if (bf == NULL) {
		return;
	}
	size_t i = 0;
	bf->hashfunc[0] = HashFunc0;
	bf->hashfunc[1] = HashFunc1;
	BitMapInit(&bf->bm, BitMapCapacity);
}

void BloomFilterInsert(BloomFilter* bf, const char* str) {
	if (bf == NULL) {
		return;
	}
	size_t i = 0;
	for (; i < HashFuncMaxSize; ++i) {
		size_t ret = bf->hashfunc[i](str) % BitMapCapacity;
		BitMapSet(&bf->bm, ret);
	}
}

int BloomFilterExist(BloomFilter* bf, const char* str) {
	if (bf == NULL) {
		return 0;
	}
	size_t i = 0;
	for (; i < HashFuncMaxSize; ++i) {
		size_t ret = bf->hashfunc[i](str) % BitMapCapacity;
		if (BitMapTest(&bf->bm, ret) == 0) {
			return 0;
		}
	}
	return 1;
}

void BloomFilterDestroy(BloomFilter* bf) {
	if (bf == NULL) {
		return;
	}
	BitMapDestroy(&bf->bm);
	size_t i = 0;
	for (; i < HashFuncMaxSize; ++i) {
		bf->hashfunc[i] = NULL;
	}
}

//////////////////////////
// 以下为测试代码
//////////////////////////
#if 1
#include <stdio.h>
#define TEST_HEADER printf("\n==========%s==========\n", __FUNCTION__)

void Test() {
	TEST_HEADER;
	BloomFilter bf;
	BloomFilterInit(&bf);
	int ret = BloomFilterExist(&bf, "hello");
	printf("ret expert 0, actual %d\n", ret);

	BloomFilterInsert(&bf, "hello");
	ret = BloomFilterExist(&bf, "hello");
	printf("ret expert 1, actual %d\n", ret);
}

int main() {
	system("clear");
	Test();
	return 0;
}



#endif



