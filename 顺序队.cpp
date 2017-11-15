//
//  main.cpp
//  顺序队
//
//  Created by admin on 17/10/13.
//  Copyright © 2017年 admin. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MaxSize 100

typedef int ElemType;

typedef struct SqQueue
{
    ElemType data[MaxSize];
    ElemType front;
    ElemType count;
    
}SqQueue;

void InitQueue(SqQueue *&q)//初始化
{
    q=(SqQueue *)malloc(sizeof(SqQueue));
    q->front=0;
    q->count=0;
    
}


void DestroyQueue(SqQueue *&q)//销毁
{
    free(q);
    
}


bool QueueEmpty(SqQueue *q)//判空
{
    return (q->count==0);
}


bool EnQueue(SqQueue *&q,ElemType e)//进队
{
    if (q->count==MaxSize-1) {
        return FALSE;
    }
    
    q->data[(q->front+q->count)%MaxSize]=e;
    q->count++;
    return TRUE;
}


bool DeQueue(SqQueue *&q,ElemType &e)//出队
{
    if (q->count==0)
    {
        return FALSE;
    }
    
    e=q->data[q->front%MaxSize];
    q->count--;
    q->front++;
    return TRUE;
    
}

void homework(SqQueue *&q,ElemType m[],int n)
{
    InitQueue(q);
    ElemType e;
    int i;
    
    for (i=0; i<n; i++)
    {
        EnQueue(q, m[i]);
    }
    
    i=0;
    while (i!=n)
    {
        DeQueue(q, e);
        if ((q->front)%2==1)
        {
            m[i]=e;
            i++;
        }
        
        else
        
        {
            EnQueue(q, e);
        }
    }

}





int main(int argc, const char * argv[]) {
    SqQueue *q;
    
    ElemType m[]={1,2,3,4,5,6,7,8};
    homework(q,m,8);
   
    int  i;
    for (i=0; i<8; i++) {
        printf("%d",m[i]);
    }
    printf("\n");
    return 0;
}
