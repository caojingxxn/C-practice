#include "SeqStack.h"

int judge_stack_string(SeqType input[], 
			size_t size1,	SeqType output[], size_t size2) {
	SeqStack s;
	SeqStackInit(&s);
	size_t out_p = 0;
	size_t in_p = 0;
	for (; in_p < size1; in_p++) {
		SeqStackPush(&s,input[in_p]);
		SeqType value;
		while (SeqStackTop(s, &value) && out_p < size2) {
			if (value == output[out_p]) {
				out_p++;
				SeqStackPop(&s);
			} else {
				break;
			}
		}
	}
	if (in_p == out_p && SeqStackSize(s) == 0) {
		return 1;
	}
	return 0;
}

//////////////////////////////
// 以下为测试代码
//////////////////////////////
#if 1
void Test() {
	SeqType input[] = { 'a', 'b', 'c', 'd', 'e'};
	SeqType output1[] = { 'a', 'b', 'e', 'd', 'c'};
	SeqType output2[] = { 'a', 'b', 'e', 'c', 'd'};
	int ret1 = judge_stack_string(input, sizeof(input)/sizeof(input[0]),
							output1, sizeof(output1)/sizeof(output1[0]));
	int ret2 = judge_stack_string(input, sizeof(input)/sizeof(input[0]),
							output2, sizeof(output2)/sizeof(output2[0]));
	printf("ret1 expert:1 actual:%d\n", ret1);
	printf("ret2 expert:0 actual:%d\n", ret2);
}

int main() {
	Test();
	return 0;
}

#endif
