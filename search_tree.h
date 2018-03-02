#pragma once

typedef char SearchTreeType;

typedef struct SearchTreeNode {
	SearchTreeType key;
	struct SearchTreeNode* lchild;
	struct SearchTreeNode* rchild;
} SearchTreeNode;

void SearchTreeInit(SearchTreeNode** root);

void SearchTreeInsert(SearchTreeNode** root, SearchTreeType key);

SearchTreeNode* SearchTreeFind(SearchTreeNode* root, 
								SearchTreeType key);

void SearchTreeRemove(SearchTreeNode** root, SearchTreeType key);

void SearchTreeInsertByLoop(SearchTreeNode** root, SearchTreeType key);

SearchTreeNode* SearchTreeFindByLoop(SearchTreeNode* root, 
								SearchTreeType key);

void SearchTreeRemoveByLoop(SearchTreeNode** root, SearchTreeType key);

