#pragma once

#include <stdint.h>
#include <stddef.h>

typedef struct BitMap {
	uint64_t* data;
	size_t capacity;
} BitMap;

void BitMapInit(BitMap* bm, size_t capacity);

void BitMapSet(BitMap* bm, size_t index);

void BitMapUnset(BitMap* bm, size_t index);

int BitMapTest(BitMap* bm, size_t index);

void BitMapFill(BitMap* bm);

void BitMapClear(BitMap* bm);

void BitMapDestrpy(BitMap* bm);


