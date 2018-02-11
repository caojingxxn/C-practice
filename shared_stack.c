#include <stddef.h>
#define SharedStackMaxSize 5

typedef char SeqType;
typedef struct SharedStack {
	SeqType data[SharedStackMaxSize];	
	size_t top1;
	size_t top2;
}SharedStack;

void SharedStackInit(SharedStack* s) {
	if (s == NULL) {
		return;
	}
	s->top1 = 0;
	s->top2 = SharedStackMaxSize - 1;
}

void SharedStackPush1(SharedStack* s, SeqType value) {
	if (s == NULL) {
		return;
	}
	if (s->top1 >= s->top2) {
		return;
	}
	s->data[s->top1++] = value;
}

void SharedStackPop1(SharedStack* s) {
	if (s == NULL) {
		return;
	}
	if (s->top1 == 0) {
		return;
	}
	--s->top1;
}

int SharedStackTop1(SharedStack* s, SeqType* value) {
	if (s == NULL || value == NULL) {
		return 0;
	}
	if (s->top1 == 0) {
		return 0;
	}
	*value = s->data[s->top1-1];
	return 1;
}

void SharedStackPush2(SharedStack* s, SeqType value) {
	if (s == NULL) {
		return;
	}
	if (s->top1 >= s->top2) {
		return;
	}
	s->data[s->top2--] = value;
}

void SharedStackPop2(SharedStack* s) {
	if (s == NULL) {
		return;
	}
	if (s->top2 == SharedStackMaxSize - 1) {
		return;
	}
	++s->top2;
}

int SharedStackTop2(SharedStack* s, SeqType* value) {
	if (s == NULL || value == NULL) {
		return 0;
	}
	if (s->top2 == SharedStackMaxSize - 1) {
		return 0;
	}
	*value = s->data[s->top2+1];
	return 1;
}

//////////////////////////////
// 以下为测试代码
//////////////////////////////
#if 1
#include <stdio.h>
// a b   d c
void Test() {
	SharedStack s;
	SharedStackInit(&s);
	SharedStackPush1(&s, 'a');
	SharedStackPush1(&s, 'b');
	SharedStackPush2(&s, 'c');
	SharedStackPush2(&s, 'd');

	SeqType value;
	int ret = SharedStackTop1(&s, &value);
	printf("ret expect:1 actual:%d\n", ret);
	printf("value expect:b actual:%c\n", value);

	ret = SharedStackTop2(&s, &value);
	printf("ret expect:1 actual:%d\n", ret);
	printf("value expect:d actual:%c\n", value);

	SharedStackPop1(&s);
	SharedStackPop2(&s);
	ret = SharedStackTop1(&s, &value);
	printf("ret expect:1 actual:%d\n", ret);
	printf("value expect:a actual:%c\n", value);

	ret = SharedStackTop2(&s, &value);
	printf("ret expect:1 actual:%d\n", ret);
	printf("value expect:c actual:%c\n", value);

	SharedStackPop1(&s);
	SharedStackPop2(&s);
	ret = SharedStackTop1(&s, &value);
	printf("ret expect:0 actual:%d\n", ret);

	ret = SharedStackTop2(&s, &value);
	printf("ret expect:0 actual:%d\n", ret);
}

int main() {
	Test();
	return 0;
}

#endif
