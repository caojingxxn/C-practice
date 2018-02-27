#include "thread_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ThreadNode* ThreadNodeCreate(ThreadType value) {
	ThreadNode* new_node= (ThreadNode*)malloc(sizeof(ThreadNode));
	new_node->data = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->lflag = CHILD;
	new_node->rflag = CHILD;
	return new_node;
}

ThreadNode* _ThreadTreeCreate(ThreadType arr[], size_t size, size_t* index,
															ThreadType invalid) {
	if (index == NULL || *index >= size) {
		return NULL;
	}
	ThreadNode* root = ThreadNodeCreate(arr[*index]);
	if (arr[*index] == invalid) {
		return NULL;
	}
	++(*index);
	root->left = _ThreadTreeCreate(arr, size, index, invalid);
	++(*index);
	root->right = _ThreadTreeCreate(arr, size, index, invalid);
	return root;
}

ThreadNode* ThreadTreeCreate(ThreadType arr[], size_t size, ThreadType invalid) {
	size_t index = 0;
	return _ThreadTreeCreate(arr, size, &index, invalid);
}

void _PreThreading(ThreadNode* root, ThreadNode** prev) {
	if (root == NULL || prev == NULL) {
		return;
	}
	// 根节点
	// 1.左子树为空，置为prev
	// 2.prev的右子树为空，指向当前结点
	if (root->left == NULL) {
		root->left = *prev;
		root->lflag = THREAD;
	}
	if (*prev != NULL && (*prev)->right == NULL) {
		(*prev)->right = root;
		(*prev)->rflag = THREAD;
	}
	*prev = root;
	// 左子树
	if (root->lflag == CHILD) {
		_PreThreading(root->left, prev);
	}
	// 右子树
	if (root->rflag == CHILD) {
		_PreThreading(root->right, prev);
	}
}

void PreThreading(ThreadNode* root) {
	if (root == NULL) {
		return;
	}
	ThreadNode* prev = NULL;
	_PreThreading(root, &prev);
}

void PreOrderByThreading(ThreadNode* root) {
	if (root == NULL) {
		return;
	}
	ThreadNode* cur = root;
	while (cur) {
		while (cur->lflag == CHILD && cur->left != NULL) {
			printf("%c ", cur->data);
			cur = cur->left;
		}
		printf("%c ", cur->data);
		cur = cur->right;
	}
	printf("\n");
}

void _InThreading(ThreadNode* root, ThreadNode** prev) {
	if (root == NULL || prev == NULL) {
		return;
	}
	// 左子树
	if (root->lflag == CHILD) {
		_InThreading(root->left, prev);
	}
	// 根结点
	if (root->left == NULL) {
		root->left = *prev;
		root->lflag = THREAD;
	}
	if (*prev != NULL && (*prev)->right == NULL) {
		(*prev)->right = root;
		(*prev)->rflag = THREAD;
	}
	*prev = root;
	// 右子树
	if (root->rflag == CHILD) {
		_InThreading(root->right, prev);
	}
}

void InThreading(ThreadNode* root) {
	if (root == NULL) {
		return;
	}
	ThreadNode* prev = NULL;
	_InThreading(root, &prev);
}

void InOrderByThreading(ThreadNode* root) {
	if (root == NULL) {
		return;
	}
	ThreadNode* cur = root;
	while (cur->lflag == CHILD) {
		cur = cur->left;
	}
	while (cur) {
		printf("%c ", cur->data);
		if (cur->rflag == CHILD) {
			cur = cur->right;
			while (cur && cur->lflag == CHILD) {
				cur = cur->left;
			}
		} else {
			cur = cur->right;
		}
	}
	printf("\n");
}

void _PostThreading(ThreadNode* root, ThreadNode** prev) {
	if (root == NULL || prev == NULL) {
		return;
	}
	// 左子树
	if (root->lflag == CHILD) {
		_PostThreading(root->left, prev);
	}
	// 右子树
	if (root->rflag == CHILD) {
		_PostThreading(root->right, prev);
	}
	// 根节点
	if (root->left == NULL) {
		root->left = *prev;
		root->lflag = THREAD;
	}
	if (*prev && (*prev)->right == NULL) {
		(*prev)->right = root;
		(*prev)->rflag = THREAD;
	}
	*prev = root;
}

void PostThreading(ThreadNode* root) {
	if (root == NULL) {
		return;
	}
	ThreadNode* pre = NULL;
	_PostThreading(root, &pre);
}


///////////////////////
// 以下为测试代码
///////////////////////
#if 1
#define TEST_HEADER printf("\n===========%s===========\n", __FUNCTION__)

void TestPre() {
	TEST_HEADER;
	ThreadType arr[] = "abd##eg###c#f##";
	ThreadNode* root = ThreadTreeCreate(arr, strlen(arr), '#');
	PreThreading(root);
	PreOrderByThreading(root);
}

void TestIn() {
	TEST_HEADER;
	ThreadType arr[] = "abd##eg###c#f##";
	ThreadNode* root = ThreadTreeCreate(arr, strlen(arr), '#');
	InThreading(root);
	InOrderByThreading(root);
}

void TestPost() {
	TEST_HEADER;
	ThreadType arr[] = "abd##eg###c#f##";
	ThreadNode* root = ThreadTreeCreate(arr, strlen(arr), '#');
	PostThreading(root);
}

int main() {
	system("clear");
	TestPre();
	TestIn();
	TestPost();
	return 0;
}

#endif





