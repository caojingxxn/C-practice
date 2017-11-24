//
//  main.cpp
//  线索二叉树
//
//  Created by admin on 17/11/2.
//  Copyright © 2017年 admin. All rights reserved.
//

#include <iostream>

typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *lchild,*rchild;
    int Ltag,Rtag;

}TBTNode;

TBTNode *pre;//全局变量

void Thread(TBTNode *&p)//对二叉树中序线索化
{
    if(p!=NULL)
    {
        Thread(p->lchild);
        if (p->lchild==NULL)
        {
            p->lchild=pre;
            p->Ltag=1;
        }
        else
        {
            p->Ltag=0;
        }
        
        
        if (pre->rchild==NULL)
        {
            pre->rchild=p;
            pre->Rtag=1;
        }
        else
        {
            pre->Rtag=0;
        }
        pre=p;
        
        
        Thread(p->rchild);
        
    }
    
}



TBTNode *CreatThread(TBTNode *b)
{
    TBTNode *root;
    root=(TBTNode *)malloc(sizeof(TBTNode));
    
    root->Ltag=0;
    root->Rtag=1;
    root->rchild=b;
    
    if (b==NULL)
    {
        root->lchild=root;
    }
    
    else
    {
        root->lchild=b;
        pre=root;
        
        Thread(b);//中序线索化
        
        pre->rchild=root;
        pre->Rtag=1;//感觉这条不需要。。

        root->rchild=pre;
        
    }

    return root;
    
}


void ThInOrder(TBTNode *tb)//遍历
{
    TBTNode *p=tb->lchild;
    while (p!=tb)
    {
        while ( p->Ltag == 0)
        {
            p=p->lchild;
        }
        
        printf("%c",p->data);
        
        while ((p->Rtag == 1) && (p->rchild != tb))
        {
            p=p->rchild;
            printf("%c",p->data);
        }
        p=p->rchild;
    }
    
}



int main(int argc, const char * argv[])
{
    TBTNode *b,*tb;
   
    tb=CreatThread(b);
    
    ThInOrder(tb);
    
    return 0;
}
