#include "SeqStack.h"

void SeqStackInit(SeqStack* stack) {
	if (stack == NULL) {
		return;
	}
	stack->size = 0;
}

void SeqStackPush(SeqStack* stack, SeqType value) {
	if (stack == NULL) {
		return;
	}
	stack->data[stack->size++] = value;
}

void SeqStackPop(SeqStack* stack) {
	if (stack == NULL) {
		return;
	}
	if (stack->size == 0) {
		return;
	}
	--stack->size;
}

int SeqStackTop(SeqStack stack, SeqType* value) {
	if (stack.size == 0) {
		return 0;
	}
	*value = stack.data[stack.size-1];
	 return 1;
}

void SeqStackDestroy(SeqStack* stack) {
	if (stack == NULL) {
		return;
	}
	stack->size = 0;
}

#ifdef __MAZE
void SeqStackPrintChar(SeqStack stack, char* msg) {
	printf("%s\n",msg);
	printf("[栈底] ");
	size_t count = 0;
	for (; count < stack.size; ++count) {
		printf("[%d %d] ",stack.data[count].row, stack.data[count].col);
	}
	printf("[栈顶]\n");
}
#endif

size_t SeqStackSize(SeqStack stack) {
	return stack.size;
}

//////////////////////////////////////////////
//  以下为测试代码
//////////////////////////////////////////////
#if 0

#define TEST_HEADER \
	printf("\n================%s==============\n",__FUNCTION__)

void SeqStackPrintChar(SeqStack stack, char* msg) {
	printf("%s\n",msg);
	printf("[栈底] ");
	size_t count = 0;
	for (; count < stack.size; ++count) {
		printf("[%c] ",stack.data[count]);
	}
	printf("[栈顶]\n");
}

void TestInit() {
	TEST_HEADER;
	SeqStack stack;
	SeqStackInit(&stack);
	SeqStackPrintChar(stack, "初始化栈");
}

void TestPush() {
	TEST_HEADER;
	SeqStack stack;
	SeqStackInit(&stack);
	SeqStackPush(&stack,'a');
	SeqStackPush(&stack,'b');
	SeqStackPush(&stack,'c');
	SeqStackPush(&stack,'d');
	SeqStackPrintChar(stack, "尾插四个元素");
}

void TestPop() {
	TEST_HEADER;
	SeqStack stack;
	SeqStackInit(&stack);
	SeqStackPush(&stack,'a');
	SeqStackPush(&stack,'b');
	SeqStackPush(&stack,'c');
	SeqStackPush(&stack,'d');
	SeqStackPrintChar(stack, "尾插四个元素");
	SeqStackPop(&stack);
	SeqStackPop(&stack);
	SeqStackPrintChar(stack, "出栈两个元素");
	SeqStackPop(&stack);
	SeqStackPop(&stack);
	SeqStackPrintChar(stack, "再出栈两个元素");
	SeqStackPop(&stack);
	SeqStackPrintChar(stack, "尝试对空栈出栈");
}

void TestTop() {
	TEST_HEADER;
	SeqStack stack;
	SeqStackInit(&stack);
	SeqType value = '\0';
	int ret = SeqStackTop(stack, &value);
	printf("ret expert:0 actual:%d, value expert:0 actual %c\n", ret, value);
	SeqStackPush(&stack,'a');
	SeqStackPush(&stack,'b');
	SeqStackPush(&stack,'c');
	SeqStackPush(&stack,'d');
	SeqStackPrintChar(stack, "尾插四个元素");
	ret = SeqStackTop(stack, &value);
	printf("ret expert:1 actual:%d, value expert:d actual %c\n", ret, value);
}

void TestDestroy() {
	TEST_HEADER;
	SeqStack stack;
	SeqStackInit(&stack);
	SeqStackPush(&stack,'a');
	SeqStackPush(&stack,'b');
	SeqStackPush(&stack,'c');
	SeqStackPush(&stack,'d');
	SeqStackPrintChar(stack, "尾插四个元素");
	SeqStackDestroy(&stack);
	SeqStackPrintChar(stack, "销毁栈");
}

int main() {
	TestInit();
	TestPush();
	TestPop();
	TestTop();
	TestDestroy();
	return 0;
}
#endif
