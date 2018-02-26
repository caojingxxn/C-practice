#pragma once
#include <stddef.h>

typedef char TreeNodeType;

typedef struct Tree_Node{
	TreeNodeType data;
	struct Tree_Node* lchild;
	struct Tree_Node* rchild;
}TreeNode;

void TreeInit(TreeNode** root);

void PreOrder(TreeNode* root);

void InOrder(TreeNode* root);

void PostOrder(TreeNode* root);

void LevelOrder(TreeNode* root);

TreeNode* TreeCreate(TreeNodeType arr[], size_t size, TreeNodeType flag);

size_t TreeSize(TreeNode* root);

size_t TreeLeavesSize(TreeNode* root);

size_t TreeKSize(TreeNode* root, int K);

TreeNode* Clone(TreeNode* root);

void TreeDestroy(TreeNode** root);

TreeNode* lchild(TreeNode* node);

TreeNode* rchild(TreeNode* node);

TreeNode* Parent(TreeNode* root, TreeNode* node);

size_t TreeHeight(TreeNode* root);

TreeNode* TreeFind(TreeNode* root, TreeNodeType value);

void TreeMirror(TreeNode* root);

void PreOrderByLoop(TreeNode* root);

void InOrderByLoop(TreeNode* root);

void PostOrderByLoop(TreeNode* root);

int IsCompleteTree(TreeNode* root);


