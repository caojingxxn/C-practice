//
//  main.cpp
//  二叉排序树
//
//  Created by admin on 17/11/12.
//  Copyright © 2017年 Amon. All rights reserved.
//

#include <iostream>

typedef int KeyType;

typedef struct node
{
    KeyType key;
    
    struct node *lchild,*rchild;
    
}BSTNode;


int InsertBST(BSTNode *&p,KeyType k)//插入结点
{
    
    if ( p == NULL ) {
        p = (BSTNode *)malloc(sizeof(BSTNode));
        p -> lchild = NULL;
        p -> rchild = NULL;
        p -> key = k;
        return 1;
    }
    else if (p->key == k){
        return 0;
    }
    else if (p->key > k){
        return InsertBST(p->lchild, k);
    }
    else
        return InsertBST(p->rchild, k);
}



BSTNode *CreateBST(KeyType A[],int n)//创建二叉排序树
{
    BSTNode *bt = NULL;
    int i;
    for (i = 0; i < n; i++) {
        InsertBST(bt, A[i]);
    }
    
    return bt;
    
}

BSTNode *SearchBST(BSTNode *p,KeyType k)//二叉排序树的查找
{
    if ( p->key == k || p == NULL ) {
        return p;
    }
    
    else if(p->key < k){
        return SearchBST(p->lchild,k);
    }
    else
        return SearchBST(p->rchild,k);

}

//----------------------------------------------------------------
void deletep(BSTNode *&p)//删除结点，仅有右子树
{
    BSTNode *q = p;
    p = p->rchild;
    free(q);
    
}

int deletekr(BSTNode *&p,KeyType k)//删除结点，仅有右子树，用其右子树代替
{
    if (p != NULL) {
        
        if(p->key == k){
            deletep(p);//删除p，用其右子树代替
            return 1;
        }
        
        else if(p->key > k){
            return deletekr(p->lchild, k);
        }
        
        else{
            return deletekr(p->rchild, k);
        }
        
    }
    
    else
        return 0;

}

//--------------------------------------------------------------------
int dele(BSTNode *&p,KeyType k)
{
    if ( (p->lchild->key == k) && (p->lchild->lchild == NULL) && (p->lchild->rchild == NULL) ) {
        
        BSTNode *q = p;
        q = q->lchild;
        free(q);
        p -> lchild = NULL;
        return 1;

    }
    
    else if ( (p->rchild->key == k) && (p->rchild->lchild == NULL) && (p->rchild->rchild == NULL) ) {
        
        BSTNode *q = p;
        q = q->rchild;
        free(q);
        p -> rchild = NULL;
        return 1;

    }
    
    else
        return 0;
}




int main(int argc, const char * argv[]) {
    
    BSTNode *p;
    int A[] = {1,3,5,6,8};
    
    p = CreateBST(A, 5);
    
    InsertBST(p,7);
    
    return 0;
}
