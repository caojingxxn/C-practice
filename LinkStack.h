#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef char LinkType;

typedef struct LinkNode {
	LinkType data;
	struct LinkNode* next;
}LinkNode;

typedef struct LinkStack {
	LinkNode head; //带头结点的链栈
}LinkStack;

void LinkStcakInit(LinkStack* stack);

void LinkStackDestroy(LinkStack* stack);

void LinkStackPush(LinkStack* stack, LinkType value);

void LinkStackPop(LinkStack* stack);

int LinkStackTop(LinkStack stack, LinkType* value);
