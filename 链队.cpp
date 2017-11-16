//
//  main.cpp
//  链队
//
//  Created by admin on 17/10/12.
//  Copyright © 2017年 admin. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int ElemType;

typedef struct qnode
{
    ElemType data;
    struct qnode *next;
    
}DataNode;


typedef struct
{
    DataNode *front;
    DataNode *rear;
    
}LinkQuNode;


void InitQueue(LinkQuNode *&q)//初始化
{
    q=(LinkQuNode *)malloc(sizeof(LinkQuNode));
    q->front=q->rear=NULL;
    
}


void DestroyQueue(LinkQuNode *&q)//销毁
{
    
    DataNode *p=q->front,*r;
    if (p)
    {
        r=p->next;
        while (r)
        {
            free(p);
            p=r;
            r=r->next;
        }
    }
    free(p);
    free(q);
    
}


bool QueueEmpty(LinkQuNode *q)//判空
{
    return (q->front==NULL);
    
}


void EnQueue(LinkQuNode *&q,ElemType e)//进队
{
    DataNode *p;
    p=(DataNode *)malloc(sizeof(DataNode));
    p->data=e;
    p->next=NULL;
    if (q->rear==NULL)
    {
        q->rear=q->front=p;
    }
    else
    {q->rear->next=p;
        q->rear=p;
    }
}


bool DeQuquq(LinkQuNode *&q,ElemType &e)//出队
{
    if (q->rear) {
        return FALSE;
    }
    
    DataNode *pre;
    pre=q->front;
    
    if (q->rear==q->front)
        q->rear=q->front=NULL;
    
    else
        q->front=q->front->next;
    
    e=pre->data;
    free(pre);
    return TRUE;
    
}







int main(int argc, const char * argv[]) {
    LinkQuNode *q;
    InitQueue(q);
    
    ElemType e;
    ElemType m[]={1,2,3,4,5,6,7,8};
    
    int i;
    for (i=0; i<8; i++)
        EnQueue(q, m[i]);
    
    for (i=0; i<8; i++) {
        if (m[i]%2==0)
        {
            DeQuquq(q, e);
            m[i]=e;
        }
    
        else
        {
            DeQuquq(q, e);
            EnQueue(q, e);
            
        }
    
    }
    
    
    

    return 0;
}
