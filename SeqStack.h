#pragma once
#include <stdio.h>
#include <stddef.h>

#define SEQ_MAX 100

#define __MAZE
#ifdef __MAZE

typedef struct Point {
	int row;
	int col;
}Point;

typedef Point SeqType;

#else
typedef char SeqType;
#endif

typedef struct SeqStack {
	SeqType data[SEQ_MAX];
	size_t size;	
}SeqStack;

void SeqStackInit(SeqStack* stack);

void SeqStackDestroy(SeqStack* stack);

void SeqStackPush(SeqStack* stack, SeqType value);

void SeqStackPop(SeqStack* stack);

int SeqStackTop(SeqStack stack, SeqType* value);

void SeqStackPrintChar(SeqStack stack, char* msg);

size_t SeqStackSize(SeqStack stack);
