#include "hash.h"

size_t HashFuncDefault(KeyType key) {
	return key % HashMaxSize;
}

void HashInit(HashTable* ht, HashFunc func) {
	if (ht == NULL) {
		return;
	}
	ht->size = 0;
	ht->func = func;
	size_t i = 0;
	for (; i < HashMaxSize; ++i) {
		ht->data[i].stat = Empty;
	}
}

void HashInsert(HashTable* ht, KeyType key, ValType value) {
	if (ht == NULL) {
		return;
	}
	size_t offset = ht->func(key);
	while (ht->data[offset].stat == Valid) {
		if (ht->data[offset].key == key) {
			// 存在相同的数
			return;
		}
		offset = (offset + 1) % HashMaxSize;
	}
	ht->data[offset].stat = Valid;
	ht->data[offset].key = key;
	ht->data[offset].value = value;
	++ht->size;
}

int HashFind(HashTable* ht, KeyType key, ValType* value) {
	if (ht == NULL) {
		return 0;
	}
	size_t offset = ht->func(key);
	while (ht->data[offset].stat != Empty) {
		if (ht->data[offset].stat == Valid && ht->data[offset].key == key) {
			*value = ht->data[offset].value;
			return 1;
		}
		offset = (offset + 1) % HashMaxSize;
	}
	return 0;
}

void HashRemove(HashTable* ht, KeyType key) {
	if (ht == NULL) {
		return;
	}
	size_t offset = ht->func(key);
	while (ht->data[offset].stat != Empty) {
		if (ht->data[offset].stat == Valid && ht->data[offset].key == key) {
			ht->data[offset].stat = Invalid;
			--ht->size;
			break;
		}
		offset = (offset + 1) % HashMaxSize;
	}
}

int HashEmpty(HashTable* ht) {
	if (ht == NULL) {
		return 1;
	}
	return (ht->size == 0);
}

size_t HashSize(HashTable* ht) {
	if (ht == NULL) {
		return (size_t)-1;
	}
	return ht->size;
}

void HashDestroy(HashTable* ht) {
	if (ht == NULL) {
		return;
	}
	size_t i = 0;
	for (; i < HashMaxSize; ++i) {
		ht->data[i].stat = Empty;
	}
	ht->size = 0;
	ht->func = NULL;
}

/////////////////////////
// 以下为测试代码
/////////////////////////
#if 1
#include <stdio.h>
#define TEST_HEADER printf("\n=======%s=======\n", __FUNCTION__)

void HashPrintInt(HashTable* ht, char* msg) {
	printf("%s\n" , msg);
	size_t i = 0;
	for (; i < HashMaxSize; ++i) {
		if (ht->data[i].stat != Empty) {
			printf("%lu  %d  %d  %d\n",
					i, ht->data[i].key, ht->data[i].value, ht->data[i].stat);
		}
	}
}

void TestInit() {
	TEST_HEADER;
	HashTable ht;
	HashInit(&ht, HashFuncDefault);
	printf("size expert 0, actual %lu\n", ht.size);
	printf("cmp expert %p, actual %p\n", HashFuncDefault, ht.func);
}

void TestInsert() {
	TEST_HEADER;
	HashTable ht;
	HashInit(&ht, HashFuncDefault);
	HashInsert(&ht, 1, 100);
	HashInsert(&ht, 2, 200);
	HashInsert(&ht, 1001, 300);
	HashInsert(&ht, 1002, 400);
	HashPrintInt(&ht, "插入四个元素");
}

void TestFind() {
	TEST_HEADER;
	HashTable ht;
	HashInit(&ht, HashFuncDefault);
	HashInsert(&ht, 1, 100);
	HashInsert(&ht, 2, 200);
	HashInsert(&ht, 1001, 300);
	HashInsert(&ht, 1002, 400);
	ValType value = 0;
	int ret = HashFind(&ht, 1, &value);
	printf("ret expert 1, actual %d\n", ret);
	printf("value expert 100, actual %d\n", value);

	ret = HashFind(&ht, 1001, &value);
	printf("ret expert 1, actual %d\n", ret);
	printf("value expert 300, actual %d\n", value);

	ret = HashFind(&ht, 3, &value);
	printf("ret expert 0, actual %d\n", ret);
}

void TestRemove() {
	TEST_HEADER;
	HashTable ht;
	HashInit(&ht, HashFuncDefault);
	HashInsert(&ht, 1, 100);
	HashInsert(&ht, 2, 200);
	HashInsert(&ht, 1001, 300);
	HashInsert(&ht, 1002, 400);
	HashRemove(&ht, 1);
	HashPrintInt(&ht, "删除1");
	
	ValType value = 0;
	int ret = HashFind(&ht, 1001, &value);
	printf("ret expert 1, actual %d\n", ret);
	printf("value expert 300, actual %d\n", value);

	HashInsert(&ht, 11001, 500);
	HashPrintInt(&ht, "插入11001");
}

void TestEmpty() {
	TEST_HEADER;
	HashTable ht;
	HashInit(&ht, HashFuncDefault);
	int ret = HashEmpty(&ht);
	printf("empty expert 1, actual %d\n", ret);
}

void TestSize() {
	TEST_HEADER;
	HashTable ht;
	HashInit(&ht, HashFuncDefault);
	HashInsert(&ht, 1, 100);
	HashInsert(&ht, 2, 200);
	HashInsert(&ht, 1001, 300);
	HashInsert(&ht, 1002, 400);
	int ret = HashSize(&ht);
	printf("empty expert 4, actual %lu\n", ret);
}

void TestDestroy() {
	TEST_HEADER;
	HashTable ht;
	HashInit(&ht, HashFuncDefault);
	HashInsert(&ht, 1, 100);
	HashInsert(&ht, 2, 200);
	HashInsert(&ht, 1001, 300);
	HashInsert(&ht, 1002, 400);
	HashDestroy(&ht);
	printf("size expert 0, actual %lu\n", ht.size);
	printf("cmp expert NULL, actual %p\n", ht.func);
	size_t i = 0;
	for (; i < HashMaxSize; ++i) {
		if (ht.data[i].stat != Empty) {
			printf("%lu error\n", i);
		}
	}
}

int main() {
	TestInit();
	TestInsert();
	TestFind();
	TestRemove();
	TestEmpty();
	TestSize();
	TestDestroy();
	return 0;
}

#endif


