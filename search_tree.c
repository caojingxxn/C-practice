#include "search_tree.h"
#include <stdlib.h>


void SearchTreeInit(SearchTreeNode** root) {
	if (root == NULL) {
		return;
	}
	*root = NULL;
}

SearchTreeNode* CreateSearchNode(SearchTreeType key) {
	SearchTreeNode* new_node = 
		(SearchTreeNode*)malloc(sizeof(SearchTreeNode));
	new_node->key = key;
	new_node->lchild = NULL;
	new_node->rchild = NULL;
	return new_node;
}

void SearchTreeInsert(SearchTreeNode** root, SearchTreeType key) {
	if (root == NULL) {
		return;
	}
	if (*root == NULL) {
		*root = CreateSearchNode(key);
		return;
	}
	if (key < (*root)->key) {
		SearchTreeInsert(&(*root)->lchild, key);
	} else if (key > (*root)->key) {
		SearchTreeInsert(&(*root)->rchild, key);
	} else {
		return;
	}
}

SearchTreeNode* SearchTreeFind(SearchTreeNode* root, 
								SearchTreeType key) {
	if (root == NULL) {
		return NULL;
	}
	if (key < root->key) {
		return SearchTreeFind(root->lchild, key);
	} else if (key > root->key) {
		return SearchTreeFind(root->rchild, key);
	} else {
		return root;
	}
}

void DestroySearchNode(SearchTreeNode* root) {
	free(root);
}

void SearchTreeRemove(SearchTreeNode** root, SearchTreeType key) {
	if (root == NULL) {
		return;
	}
	if (*root == NULL) {
		return;
	}
	if (key < (*root)->key) {
		SearchTreeRemove(&(*root)->lchild, key);
	} else if (key > (*root)->key) {
		SearchTreeRemove(&(*root)->rchild, key);
	} else {
		// 找到了
		SearchTreeNode* to_remove = *root;
		if ((*root)->lchild == NULL && (*root)->rchild == NULL) {
			*root = NULL;
			DestroySearchNode(to_remove);
		} else if ((*root)->lchild != NULL && (*root)->rchild == NULL) {
			*root = (*root)->lchild;
			DestroySearchNode(to_remove);
		} else if ((*root)->lchild == NULL && (*root)->rchild != NULL) {
			*root = (*root)->rchild;
			DestroySearchNode(to_remove);
		} else {
			SearchTreeNode* min = (*root)->rchild;
			while (min->lchild) {
				min = min->lchild;
			}
			(*root)->key = min->key;
			SearchTreeRemove(&to_remove->rchild, min->key);
		}
	}
}

void SearchTreeInsertByLoop(SearchTreeNode** root, SearchTreeType key) {
	if (root == NULL) {
		return;
	}
	if (*root == NULL) {
		*root = CreateSearchNode(key);
	}
	SearchTreeNode* child = *root;
	SearchTreeNode* parent = *root;
	while (child) {
		if (key < child->key) {
			parent = child;
			child = child->lchild;
		} else if (key > child->key) {
			parent = child;
			child = child->rchild;
		} else {
			// 找到相同的
			return;
		}
	}
	if (parent->key > key) {
		child = CreateSearchNode(key);
		parent->lchild = child;
	} else {
		child = CreateSearchNode(key);
		parent->rchild = child;
	}
}

SearchTreeNode* SearchTreeFindByLoop(SearchTreeNode* root, 
								SearchTreeType key) {
	if (root == NULL) {
		return NULL;
	}
	SearchTreeNode* cur = root;
	while (cur) {
		if (key < cur->key) {
			cur = cur->lchild;
		} else if (key > cur->key) {
			cur = cur->rchild;
		} else {
			return cur;
		}
	}
	return NULL;
}

void SearchTreeRemoveByLoop(SearchTreeNode** root, SearchTreeType key) {
	if (root == NULL) {
		return;
	}
	if (*root == NULL) {
		return;
	}
	SearchTreeNode* cur = *root;
	SearchTreeNode* parent = *root;
	while (cur) {
		if (key < cur->key) {
			parent = cur;
			cur = cur->lchild;
		} else if (key > cur->key) {
			parent = cur;
			cur = cur->rchild;
		} else {
			// 找到了...
			if (cur->lchild == NULL && cur->rchild == NULL) {
				if (key < parent->key) {
					parent->lchild = NULL;
				} else {
					parent->rchild = NULL;
				}
				DestroySearchNode(cur);
			} else if (cur->lchild == NULL && cur->rchild != NULL) {
				// 用右子树代替自己
				if (key < parent->key) {
					parent->lchild = cur->rchild;
				} else {
					parent->rchild = cur->rchild;
				}
				DestroySearchNode(cur);
			} else if (cur->lchild != NULL && cur->rchild == NULL) {
				if (key < parent->key) {
					parent->lchild = cur->lchild;
				} else {
					parent->rchild = cur->lchild;
				}
				DestroySearchNode(cur);
			} else {
				SearchTreeNode* min = cur->rchild;
				SearchTreeNode* min_parent = cur;
				while(min->lchild) {
					min_parent = min;
					min = min->lchild;
				}
				cur->key = min->key;
				// 删除min
				if (min->key < min_parent->key) {
					min_parent->lchild = min->rchild;
				} else {
					min_parent->rchild = cur->rchild;
				}
				DestroySearchNode(min);
			}
		}
	}
}




///////////////////////
// 以下为测试代码
///////////////////////
#if 1
#include <stdio.h>
#include <stddef.h>
#define TEST_HEADER printf("\n=======%s=======\n", __FUNCTION__)

void TestInit() {
	TEST_HEADER;
	SearchTreeNode* root;
	SearchTreeInit(&root);
	printf("root expert:NULL actual:%p\n", root);
}

void PreOrder(SearchTreeNode* root) {
	if (root == NULL) {
		return;
	}
	printf("[%c ]", root->key);
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}

void InOrder(SearchTreeNode* root) {
	if (root == NULL) {
		return;
	}
	InOrder(root->lchild);
	printf("[%c ]", root->key);
	InOrder(root->rchild);
}

void TestInsert() {
	TEST_HEADER;
	SearchTreeNode* root;
	SearchTreeInit(&root);
	SearchTreeInsert(&root, 'd');
	SearchTreeInsert(&root, 'b');
	SearchTreeInsert(&root, 'f');
	SearchTreeInsert(&root, 'g');
	SearchTreeInsert(&root, 'a');
	SearchTreeInsert(&root, 'c');
	printf("先序遍历：");
	PreOrder(root);
	printf("\n中序遍历：");
	InOrder(root);
	printf("\n");
}

void TestFind() {
	TEST_HEADER;
	SearchTreeNode* root;
	SearchTreeInit(&root);
	SearchTreeInsert(&root, 'd');
	SearchTreeInsert(&root, 'b');
	SearchTreeInsert(&root, 'f');
	SearchTreeInsert(&root, 'g');
	SearchTreeInsert(&root, 'a');
	SearchTreeInsert(&root, 'c');
	SearchTreeNode* ret1 = SearchTreeFind(root, 'g');
	SearchTreeNode* ret2 = SearchTreeFind(root, 'e');
	printf("ret1 expert: %p actual: %p\n", root->rchild->rchild, ret1);
	printf("ret2 expert: NULL actual: %p\n", ret2);
}

void TestRemove() {
	TEST_HEADER;
	SearchTreeNode* root;
	SearchTreeInit(&root);
	SearchTreeInsert(&root, 'd');
	SearchTreeInsert(&root, 'b');
	SearchTreeInsert(&root, 'f');
	SearchTreeInsert(&root, 'g');
	SearchTreeInsert(&root, 'a');
	SearchTreeInsert(&root, 'c');
	SearchTreeInsert(&root, 'e');

	SearchTreeRemove(&root, 'c');
	printf("删除'c'后 先序遍历：");
	PreOrder(root);
	printf("\n中序遍历：");
	InOrder(root);
	printf("\n");

	SearchTreeRemove(&root, 'b');
	printf("删除'b'后 先序遍历：");
	PreOrder(root);
	printf("\n中序遍历：");
	InOrder(root);
	printf("\n");

	SearchTreeRemove(&root, 'd');
	printf("删除'd'后 先序遍历：");
	PreOrder(root);
	printf("\n中序遍历：");
	InOrder(root);
	printf("\n");
}

void TestInsertByLoop() {
	TEST_HEADER;
	SearchTreeNode* root;
	SearchTreeInit(&root);
	SearchTreeInsertByLoop(&root, 'd');
	SearchTreeInsertByLoop(&root, 'b');
	SearchTreeInsertByLoop(&root, 'f');
	SearchTreeInsertByLoop(&root, 'g');
	SearchTreeInsertByLoop(&root, 'a');
	SearchTreeInsertByLoop(&root, 'c');
	printf("先序遍历：");
	PreOrder(root);
	printf("\n中序遍历：");
	InOrder(root);
	printf("\n");
}

void TestFindByLoop() {
	TEST_HEADER;
	SearchTreeNode* root;
	SearchTreeInit(&root);
	SearchTreeInsertByLoop(&root, 'd');
	SearchTreeInsertByLoop(&root, 'b');
	SearchTreeInsertByLoop(&root, 'f');
	SearchTreeInsertByLoop(&root, 'g');
	SearchTreeInsertByLoop(&root, 'a');
	SearchTreeInsertByLoop(&root, 'c');
	SearchTreeNode* ret1 = SearchTreeFindByLoop(root, 'g');
	SearchTreeNode* ret2 = SearchTreeFindByLoop(root, 'e');
	printf("ret1 expert: %p actual: %p\n", root->rchild->rchild, ret1);
	printf("ret2 expert: NULL actual: %p\n", ret2);
}

void TestRemoveByLoop() {
	TEST_HEADER;
	SearchTreeNode* root;
	SearchTreeInit(&root);
	SearchTreeInsertByLoop(&root, 'd');
	SearchTreeInsertByLoop(&root, 'b');
	SearchTreeInsertByLoop(&root, 'f');
	SearchTreeInsertByLoop(&root, 'g');
	SearchTreeInsertByLoop(&root, 'a');
	SearchTreeInsertByLoop(&root, 'c');
	SearchTreeInsertByLoop(&root, 'e');

	SearchTreeRemoveByLoop(&root, 'c');
	printf("删除'c'后 先序遍历：");
	PreOrder(root);
	printf("\n中序遍历：");
	InOrder(root);
	printf("\n");

	SearchTreeRemoveByLoop(&root, 'b');
	printf("删除'b'后 先序遍历：");
	PreOrder(root);
	printf("\n中序遍历：");
	InOrder(root);
	printf("\n");

	SearchTreeRemoveByLoop(&root, 'd');
	printf("删除'd'后 先序遍历：");
	PreOrder(root);
	printf("\n中序遍历：");
	InOrder(root);
	printf("\n");
}

int main() {
	system("clear");
	TestInit();
	TestInsert();
	TestInsertByLoop();
	TestFind();
	TestFindByLoop();
	TestRemove();
	TestRemoveByLoop();
	return 0;
}
#endif







