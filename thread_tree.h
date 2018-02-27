#pragma once
#include <stddef.h>

typedef char ThreadType;
typedef enum Flag {
	CHILD,
	THREAD,
} Flag;

typedef struct ThreadNode {
	ThreadType data;
	struct ThreadNode* left;
	struct ThreadNode* right;
	Flag lflag;
	Flag rflag;
} ThreadNode;

ThreadNode* ThreadTreeCreate(ThreadType arr[], size_t size, ThreadType invalid);

void PreThreading(ThreadNode* root);

void PreOrderByThreading(ThreadNode* root);

void InThreading(ThreadNode* root);

void InOrderByThreading(ThreadNode* root);

void PostThreading(ThreadNode* root);

void PostOrderByThreading(ThreadNode* root);


