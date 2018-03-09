#pragma once
#include <stddef.h>
#include "BitMap.h"

#define HashFuncMaxSize 2
#define BitMapCapacity 1024

typedef size_t (*HashFunc)(const char*);

typedef struct BloomFilter {
	BitMap bm;
	HashFunc hashfunc[HashFuncMaxSize];
} BloomFilter;

void BloomFilterInit(BloomFilter* bf);

void BloomFilterInsert(BloomFilter* bf, const char* str);

int BloomFilterExist(BloomFilter* bf, const char* str);

void BloomFilterDestroy(BloomFilter* bf);




