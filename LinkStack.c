#include "LinkStack.h"

void LinkStackInit(LinkStack* stack) {
	if (stack == NULL) {
		return;
	}
	stack->head.data = '\0';
	stack->head.next = NULL;
}

LinkNode* CreateNode(LinkType value) {
	LinkNode* ptr = (LinkNode*)malloc (sizeof(LinkNode));
	ptr->data = value;
	ptr->next = NULL;
	return ptr;
}

void LinkStackPush(LinkStack* stack, LinkType value) {
	if (stack == NULL) {
		return;
	}
	LinkNode* cur = CreateNode(value);
	cur->next = stack->head.next;
	stack->head.next = cur;
}

void Destroy(LinkNode* cur) {
	free(cur);
}

void LinkStackPop(LinkStack* stack) {
	if (stack == NULL) {
		return;
	}
	if (stack->head.next == NULL) {
		return;
	}
	LinkNode* to_delete = stack->head.next;
	stack->head.next = to_delete->next;
	Destroy(to_delete);
	to_delete = NULL;
}

int LinkStackTop(LinkStack stack, LinkType* value) {
	if (stack.head.next == NULL) {
		return 0;
	}
	*value = stack.head.next->data;
	return 1;
}

void LinkStackDestroy(LinkStack* stack) {
	if (stack == NULL) {
		return;
	}
	while (stack->head.next != NULL) {
		LinkStackPop(stack);
	}
}

///////////////////////////////////////////////////
//   以下为测试代码
///////////////////////////////////////////////////
#if 1
#define TEST_HEADER \
	printf("\n================%s===============\n",__FUNCTION__)

void LinkStackPrintChar(LinkStack stack, const char* msg) {
	printf("%s\n",msg);
	printf("[栈顶] ");
	LinkNode* cur = stack.head.next;
	while(cur != NULL) {
		printf(" [%c %p] ",cur->data,cur);
		cur = cur->next;
	}
	printf(" NULL ");
	printf("[栈底]\n");
}

void TestInit() {
	TEST_HEADER;
	LinkStack stack;
	LinkStackInit(&stack);
	LinkStackPrintChar(stack,"初始化链栈");	
}

void TestPush() {
	TEST_HEADER;
	LinkStack stack;
	LinkStackInit(&stack);
	LinkStackPush(&stack, 'a');
  LinkStackPush(&stack, 'b');
  LinkStackPush(&stack, 'c');
  LinkStackPush(&stack, 'd');
	LinkStackPrintChar(stack,"头插四个元素");	
}

void TestPop() {
	TEST_HEADER;
	LinkStack stack;
	LinkStackInit(&stack);
	LinkStackPush(&stack, 'a');
  LinkStackPush(&stack, 'b');
  LinkStackPush(&stack, 'c');
  LinkStackPush(&stack, 'd');
	LinkStackPrintChar(stack,"头插四个元素");	
	LinkStackPop(&stack);
	LinkStackPop(&stack);
	LinkStackPrintChar(stack,"出栈两个元素");	
	LinkStackPop(&stack);
	LinkStackPop(&stack);
	LinkStackPrintChar(stack,"再出栈两个元素");	
	LinkStackPop(&stack);
	LinkStackPrintChar(stack,"尝试对空栈出栈");	
}

void TestTop() {
	TEST_HEADER;
	LinkStack stack;
	LinkStackInit(&stack);
	LinkType value = '\0';
	int ret = LinkStackTop(stack, &value);
	printf("ret expert:0 actual:%d, value expert:0 actual:%c\n", ret, value);
	LinkStackPush(&stack, 'a');
  LinkStackPush(&stack, 'b');
  LinkStackPush(&stack, 'c');
  LinkStackPush(&stack, 'd');
	LinkStackPrintChar(stack,"头插四个元素");	
	ret = LinkStackTop(stack, &value);
	printf("ret expert:1 actual:%d, value expert:d actual:%c\n", ret, value);
}

void TestDestroy() {
	TEST_HEADER;
	LinkStack stack;
	LinkStackInit(&stack);
	LinkStackPush(&stack, 'a');
  LinkStackPush(&stack, 'b');
  LinkStackPush(&stack, 'c');
  LinkStackPush(&stack, 'd');
	LinkStackPrintChar(stack,"头插四个元素");	
	LinkStackDestroy(&stack);
	LinkStackPrintChar(stack,"销毁链栈");	
}

int main() {

//	while (1) {

	TestInit();
	TestPush();
	TestPop();
	TestTop();
	TestDestroy();

//	}
	return 0;
}


#endif
