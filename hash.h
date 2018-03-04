#pragma once
#include <stddef.h>
#define HashMaxSize 1000

typedef enum Stat {
	Empty,
	Valid,
	Invalid
} Stat;

typedef int KeyType;
typedef int ValType;

typedef size_t (*HashFunc)(KeyType key);

typedef struct HashElem {
	KeyType key;
	ValType value;
	Stat stat;
} HashElem;

typedef struct HashTable {
	HashElem data[HashMaxSize];
	size_t size;
	HashFunc func;
} HashTable;

void HashInit(HashTable* ht, HashFunc func);

void HashInsert(HashTable* ht, KeyType key, ValType value);

int HashFind(HashTable* ht, KeyType key, ValType* value);

void HashRemove(HashTable* ht, KeyType key);

int HashEmpty(HashTable* ht);

size_t HashSize(HashTable* ht);

void HashDestroy(HashTable* ht);

