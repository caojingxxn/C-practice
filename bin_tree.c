#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bin_tree.h"
#include "../queue/SeqQueue.h"
#include "../SeqStack/SeqStack.h"

void TreeInit(TreeNode** root) {
	if (root == NULL) {
		return;
	}
	*root = NULL;
}

void PreOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%c ", root->data);
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}

void InOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	InOrder(root->lchild);
	printf("%c ", root->data);
	InOrder(root->rchild);
}

void PostOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	printf("%c ", root->data);
}

void LevelOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	SeqQueue q;
	SeqQueueInit(&q);
	SeqQueuePush(&q, root);
	TreeNode* cur;
	while(SeqQueueFront(&q, &cur)) {
		printf("%c ", cur->data);
		SeqQueuePop(&q);
		if (cur->lchild != NULL) {
			SeqQueuePush(&q, cur->lchild);
		}
		if (cur->rchild != NULL) {
			SeqQueuePush(&q, cur->rchild);
		}
	}
	printf("\n");
}

TreeNode* CreateNode(TreeNodeType value) {
	TreeNode* NewNode = (TreeNode*)malloc(sizeof(TreeNode));
	NewNode->data = value;
	NewNode->lchild = NULL;
	NewNode->rchild = NULL;
	return NewNode;
}

void _TreeCreate(TreeNode** root, TreeNodeType arr[], 
						 size_t* index, size_t size, TreeNodeType flag) {
	if (*index >= size) {
			return;
	}
	if (arr[*index] == flag) {
		++(*index);
		return;
	}
	*root = CreateNode(arr[*index]);
	++(*index);
	_TreeCreate(&((*root)->lchild), arr, index, size, flag);
	_TreeCreate(&((*root)->rchild), arr, index, size, flag);
}

TreeNode* TreeCreate(TreeNodeType arr[], 
									size_t size, TreeNodeType flag) {
	if (size == 0) {
		return;
	}
	size_t index = 0;
	TreeNode* root;
	_TreeCreate(&root, arr, &index, size, flag);
	return root;
}

TreeNode* _Clone(TreeNode** new_node, TreeNode* node) {
	if (node == NULL) {
		return NULL;
	}
	*new_node = CreateNode(node->data);
	_Clone(&(*new_node)->lchild, node->lchild);
	_Clone(&(*new_node)->rchild, node->rchild);
}

TreeNode* Clone(TreeNode* root) {
	if (root == NULL) {
		return NULL;
	}
	TreeNode* new_root = CreateNode(root->data);
	_Clone(&new_root->lchild, root->lchild);
	_Clone(&new_root->rchild, root->rchild);
	return new_root;
}

size_t TreeSize(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + TreeSize(root->lchild) + TreeSize(root->rchild); 
}

size_t TreeLeavesSize(TreeNode* root){
	if (root == NULL) {
		return 0;
	}
	if (root->lchild == NULL && root->rchild == NULL) {
		return 1;
	}
	return TreeLeavesSize(root->lchild) + TreeLeavesSize(root->rchild); 
}

size_t TreeKSize(TreeNode* root, int K) {
	if (root == NULL || K < 1) {
		return 0;
	}
	if (K == 1) {
		return 1;
	}
	return TreeKSize(root->lchild, K-1) + TreeKSize(root->rchild, K-1); 
}

void DestroyNode(TreeNode** root) {
	free(*root);
	*root = NULL;
}

void TreeDestroy(TreeNode** root) {
	if (root == NULL) {
		return;
	}
	if (*root == NULL) {
		return;
	}
	TreeDestroy(&(*root)->lchild);
	TreeDestroy(&(*root)->rchild);
	DestroyNode(root);
}

TreeNode* lchild(TreeNode* node) {
	if (node == NULL) {
		return NULL;
	}
	return node->lchild;
}

TreeNode* rchild(TreeNode* node) {
	if (node == NULL) {
		return NULL;
	}
	return node->rchild;
}

TreeNode* Parent(TreeNode* root, TreeNode* node) {
	if (root == NULL || node == NULL) {
		return NULL;
	}
	if (root->lchild == node || root->rchild == node) {
		return root;
	}
	TreeNode* lresult = Parent(root->lchild, node);
	TreeNode* rresult = Parent(root->rchild, node);
	return lresult != NULL ? lresult :rresult; 
}

size_t TreeHeight(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	size_t lresult = TreeHeight(root->lchild);
	size_t rresult = TreeHeight(root->rchild);
	return 1 + (lresult > rresult ? lresult :rresult); 
}

TreeNode* TreeFind(TreeNode* root, TreeNodeType value) {
	if (root == NULL) {
		return NULL;
	}
	if (root->data == value) {
		return root;
	}
	TreeNode* lresult = TreeFind(root->lchild, value);
	TreeNode* rresult = TreeFind(root->rchild, value);
	return lresult != NULL ? lresult : rresult;
}

void TreeMirror(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	TreeNode* tmp = root->lchild;
	root->lchild = root->rchild;
	root->rchild = tmp;
	TreeMirror(root->lchild);
	TreeMirror(root->rchild);
}
/*
void PreOrderByLoop(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	SeqStack stack;
	SeqStackInit(&stack);
	SeqStackPush(&stack, root);
	TreeNode* cur = NULL;
	while (SeqStackTop(stack, &cur)) {
		printf("%c ", cur->data);
		SeqStackPop(&stack);
		if (cur->rchild != NULL) {
			SeqStackPush(&stack, cur->rchild);
		}
		if (cur->lchild != NULL) {
			SeqStackPush(&stack, cur->lchild);
		}
	}
	printf("\n");
}
*/

void PreOrderByLoop(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	SeqStack stack;
	SeqStackInit(&stack);
	TreeNode* cur = root;
	while (cur || SeqStackSize(stack)) {
		while (cur != NULL) {
			printf("%c ", cur->data);
			SeqStackPush(&stack, cur);	
			cur = cur->lchild;
		}
		SeqStackTop(stack, &cur);
		SeqStackPop(&stack);
		cur = cur->rchild;
	}
	printf("\n");
}

void InOrderByLoop(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	SeqStack stack;
	SeqStackInit(&stack);
	TreeNode* cur = root;
	// cur为空并且栈内无元素时，已处理完
	// 不能单独判断栈是否为空，
	// 例如根节点还有右子树时，取出根节点来处理，此时栈空，但cur不为NULL
	while (cur || SeqStackSize(stack)) { 
		while (cur != NULL) {
			SeqStackPush(&stack, cur);
			cur = cur->lchild;
		}
		SeqStackTop(stack, &cur); 
		SeqStackPop(&stack);
		printf("%c ", cur->data);
		cur = cur->rchild;
	}
	printf("\n");
}

void PostOrderByLoop(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	SeqStack stack;
	SeqStackInit(&stack);
	TreeNode* cur = root;
	TreeNode* pre = NULL;
	while (cur || SeqStackSize(stack)) {
		while (cur != NULL) {
			SeqStackPush(&stack, cur);
			cur = cur->lchild;
		}
		TreeNode* top = NULL;
		SeqStackTop(stack, &top); 
		if (top->rchild == NULL || pre == top->rchild) {
			SeqStackPop(&stack);
			printf("%c ", top->data);
			pre = top;
		} else {
			cur = top->rchild;
		}
	}
	printf("\n");
}

int IsCompleteTree(TreeNode* root) {
	if (root == NULL) {
		return 1;
	}
	SeqQueue q;
	SeqQueueInit(&q);
	SeqQueuePush(&q, root);
	TreeNode* cur = NULL;
	int check_comp_flag = 0;
	while(SeqQueueFront(&q, &cur)) {
		if (check_comp_flag == 0) {
			if (cur->lchild != NULL && cur->rchild != NULL) {
				SeqQueuePush(&q, cur->lchild);
				SeqQueuePush(&q, cur->rchild);
			} else if (cur->lchild == NULL && cur->rchild == NULL) {
				check_comp_flag = 1;
			} else if (cur->lchild == NULL && cur->rchild != NULL) {
				return 0;
			} else if (cur->lchild != NULL && cur->rchild == NULL) {
				check_comp_flag = 1;
				SeqQueuePush(&q, cur->lchild);
			}
		} else {

			if (cur->lchild != NULL || cur->rchild != NULL) {
				return 0;
			}
		}
		SeqQueuePop(&q);
	}
	return 1;
}

///////////////////////////////////////
//  以下为测试代码
///////////////////////////////////////
#if 1
#define TEST_HEADER printf("\n===========%s===========\n",__FUNCTION__)

void TestInit() {
	TEST_HEADER;
	TreeNode* root;
	TreeInit(&root);
	printf("root expect:NULL actual:%p\n",root);
}

void TestOrder() {
	TEST_HEADER;
	TreeNode* root;
	TreeInit(&root);
	root = CreateNode('a');
	TreeNode* b = CreateNode('b');
	TreeNode* c = CreateNode('c');
	TreeNode* d = CreateNode('d');
	TreeNode* e = CreateNode('e');
	TreeNode* f = CreateNode('f');
	TreeNode* g = CreateNode('g');
	root->lchild = b;
	root->rchild = c;
	b->lchild = d;
	b->rchild = e;
	c->rchild = f;
	e->lchild = g;

	printf("先序遍历:\n");
	PreOrder(root);

	printf("\n中序遍历:\n");
	InOrder(root);

	printf("\n后序遍历:\n");
	PostOrder(root);

	printf("\n层次遍历:\n");
	LevelOrder(root);
}

void TestCreate() {
	TEST_HEADER;
	TreeNodeType arr[] = "abd##eg###c#f##";
	TreeNode* root = TreeCreate(arr, strlen(arr), '#');

	printf("先序遍历:\n");
	PreOrder(root);

	printf("\n中序遍历:\n");
	InOrder(root);

	printf("\n后序遍历:\n");
	PostOrder(root);

	printf("\n层次遍历:\n");
	LevelOrder(root);
}

void TestSize() {
	TEST_HEADER;
	TreeNodeType arr[] = "abd##eg###c#f##";
	TreeNode* root = TreeCreate(arr, strlen(arr), '#');
	printf("size expert:7 actual:%d\n", TreeSize(root));
}

void TestLeavesSize() {
	TEST_HEADER;
	TreeNodeType arr[] = "abd##eg###c#f##";
	TreeNode* root = TreeCreate(arr, strlen(arr), '#');
	printf("size expert:3 actual:%d\n", TreeLeavesSize(root));
}

void TestKSize() {
	TEST_HEADER;
	TreeNodeType arr[] = "abd##eg###c#f##";
	TreeNode* root = TreeCreate(arr, strlen(arr), '#');
	printf("2th size  expert:2 actual:%d\n", TreeKSize(root, 2));
	printf("3th size  expert:3 actual:%d\n", TreeKSize(root, 3));
	printf("4th size  expert:1 actual:%d\n", TreeKSize(root, 4));
}

void TestClone() {
	TEST_HEADER;
	TreeNodeType arr[] = "abd##eg###c#f##";
	TreeNode* root = TreeCreate(arr, strlen(arr), '#');
	TreeNode* new_root = Clone(root);
	
	printf("先序遍历:\n");
	PreOrder(new_root);

	printf("\n中序遍历:\n");
	InOrder(new_root);

	printf("\n后序遍历:\n");
	PostOrder(new_root);

	printf("\n层次遍历:\n");
	LevelOrder(new_root);
}

void TestDestroy() {
	TEST_HEADER;
	TreeNodeType arr[] = "abd##eg###c#f##";
	TreeNode* root = TreeCreate(arr, strlen(arr), '#');
	TreeDestroy(&root);
	printf("root expert:NULL actual:%p\n", root);
}

void TestHeight() {
	TEST_HEADER;
	TreeNodeType arr[] = "abd##eg###c#f##";
	TreeNode* root = TreeCreate(arr, strlen(arr), '#');
	printf("height expert:4 actual:%lu\n", TreeHeight(root));
}

void TestFind() {
	TEST_HEADER;
	TreeNodeType arr[] = "abd##eg###c#f##";
	TreeNode* root = TreeCreate(arr, strlen(arr), '#');
	printf("c expert:%p actual:%p\n", root->rchild, TreeFind(root, 'c'));
}

void TestMirror() {
	TEST_HEADER;
	TreeNodeType arr[] = "abd##eg###c#f##";
	TreeNode* root = TreeCreate(arr, strlen(arr), '#');
	TreeMirror(root);
	printf("\n层次遍历:\n");
	LevelOrder(root);
}

void TestOrderByLoop() {
	TEST_HEADER;
	TreeNodeType arr[] = "abd##eg###c#f##";
	TreeNode* root = TreeCreate(arr, strlen(arr), '#');

	printf("先序遍历:\n");
	PreOrderByLoop(root);

	printf("中序遍历:\n");
	InOrderByLoop(root);

	printf("后序遍历:\n");
	PostOrderByLoop(root);
}

void TestIsComplete() {
	TEST_HEADER;
	TreeNodeType arr1[] = "abd##e##c##";
	TreeNode* root1 = TreeCreate(arr1, strlen(arr1), '#');
	TreeNodeType arr2[] = "abd##e##cf###";
	TreeNode* root2 = TreeCreate(arr2, strlen(arr2), '#');
	TreeNodeType arr3[] = "abd##e##c#f##";
	TreeNode* root3 = TreeCreate(arr3, strlen(arr3), '#');
	TreeNodeType arr4[] = "abd##ef###c##";
	TreeNode* root4 = TreeCreate(arr4, strlen(arr4), '#');

	printf("complete\n"
			"expert:1 actual:%d\n"
			"expert:1 actual:%d\n"
			"expert:0 actual:%d\n"
			"expert:0 actual:%d\n", 
			IsCompleteTree(root1),
			IsCompleteTree(root2),
			IsCompleteTree(root3),
			IsCompleteTree(root4));
}


int main() {
	system("clear");
	TestInit();
	TestOrder();
	TestCreate();
	TestSize();
	TestLeavesSize();
	TestKSize();
	TestClone();
	TestDestroy();
	TestHeight();
	TestFind();
	TestMirror();
	TestOrderByLoop();
	TestIsComplete();
	return 0;
}
#endif

