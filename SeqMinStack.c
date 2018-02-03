#include "SeqStack.h"
// 方法一：两个栈
#if 0
typedef struct {
	SeqStack data;
	SeqStack min;
}SeqMinStack;

void SeqMinStackInit(SeqMinStack* stack) {
	if (stack == NULL) {
		return;
	}
	SeqStackInit(&stack->data);
	SeqStackInit(&stack->min);
}

void SeqMinStackPush(SeqMinStack* stack, SeqType value) {
	if (stack == NULL) {
		return;
	}
	SeqType tmp;
	int ret = SeqStackTop(stack->min, &tmp);
	if (ret == 0) {
		SeqStackPush(&stack->data, value);
		SeqStackPush(&stack->min, value);
	} else {
		tmp = tmp < value ? tmp :value;
		SeqStackPush(&stack->data, value);
		SeqStackPush(&stack->min, tmp);
	}
}

void SeqMinStackPop(SeqMinStack* stack) {
	if (stack == NULL) {
		return;
	}
	SeqStackPop(&stack->data);
	SeqStackPop(&stack->min);
}

int SeqMinStackMinTop(SeqMinStack* stack, SeqType* value) {
	if (stack == NULL || value == NULL) {
		return 0;
	}
	return SeqStackTop(stack->min, value);
}
#endif

// 方法二：一个栈

typedef struct SeqMinStack{
	SeqStack data;
}SeqMinStack;

void SeqMinStackInit(SeqMinStack* stack) {
	if (stack == NULL) {
		return;
	}
	SeqStackInit(&stack->data);
}

void SeqMinStackPush(SeqMinStack* stack, SeqType value) {
	if (stack == NULL) {
		return;
	}
	SeqType tmp;
	int ret = SeqStackTop(stack->data, &tmp);
	if (ret == 0) {
		SeqStackPush(&stack->data, value);
		SeqStackPush(&stack->data, value);
	} else {
		tmp = tmp < value ? tmp :value;
		SeqStackPush(&stack->data, value);
		SeqStackPush(&stack->data, tmp);
	}
}

void SeqMinStackPop(SeqMinStack* stack) {
	if (stack == NULL) {
		return;
	}
	SeqStackPop(&stack->data);
	SeqStackPop(&stack->data);
}

int SeqMinStackMinTop(SeqMinStack* stack, SeqType* value) {
	if (stack == NULL || value == NULL) {
		return 0;
	}
	return SeqStackTop(stack->data, value);
}

//////////////////////////////////
//	  以下为测试代码
//////////////////////////////////

void Test() {
	SeqMinStack stack;
	SeqMinStackInit(&stack);
	SeqMinStackPush(&stack, 'b');
	SeqMinStackPush(&stack, 'c');
	SeqMinStackPush(&stack, 'd');
	SeqMinStackPush(&stack, 'a');

	SeqType value;
	int ret = SeqMinStackMinTop(&stack, &value);
	printf("ret expect:1 actual:%d\n", ret);
	printf("value expect:a actual:%c\n", value);
	SeqMinStackPop(&stack);

	ret = SeqMinStackMinTop(&stack, &value);
	printf("ret expect:1 actual:%d\n", ret);
	printf("value expect:b actual:%c\n", value);
	SeqMinStackPop(&stack);
   
	ret = SeqMinStackMinTop(&stack, &value);
	printf("ret expect:1 actual:%d\n", ret);
	printf("value expect:b actual:%c\n", value);
	SeqMinStackPop(&stack);

	ret = SeqMinStackMinTop(&stack, &value);
	printf("ret expect:1 actual:%d\n", ret);
	printf("value expect:b actual:%c\n", value);
	SeqMinStackPop(&stack);

	ret = SeqMinStackMinTop(&stack, &value);
	printf("ret expect:0 actual:%d\n", ret);
}

int main() {
	Test();
	return 0;
}
