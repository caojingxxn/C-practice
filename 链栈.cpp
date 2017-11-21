//
//  main.cpp
//  链栈
//
//  Created by admin on 17/10/9.
//  Copyright © 2017年 admin. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Maxsize 100
#define TRUE 1
#define FALSE 0

typedef int ElemType;

typedef struct LinkStack
{
    ElemType data;
    struct LinkStack *next;
}LinkStNode;


void InitStack(LinkStNode *&s) //初始化
{
    s=(LinkStNode *)malloc(sizeof(LinkStNode));
    s->next=NULL;
    
}


void DestroyStack(LinkStNode *s)//销毁
{   LinkStNode *pre,*p;
    pre=s;
    p=pre->next;
    while (p) {
        free(pre);
        pre=p;
        p=pre->next;
    }
    free(p);
}


bool StackEmpty(LinkStNode *s)//判断
{
    return (s->next==NULL);
}


void Push(LinkStNode *&s,ElemType e)//进栈
{
    LinkStNode *p;
    p=(LinkStNode *)malloc(sizeof(LinkStNode));
    p->data=e;
    p->next=s->next;
    s->next=p;
    
}



bool Pop(LinkStNode *s,char &e)//出栈
{
    LinkStNode *p;
    p=s->next;
    if (s->next==NULL) {
        return FALSE;
    }
    
    e=p->data;
    s->next=p->next;
    free(p);
    return TRUE;
    
}


bool GetTop(LinkStNode *s,char &e)//求栈顶元素
{
    if (s->next==NULL) {
        return FALSE;
    }
    
    e=s->next->data;
    return TRUE;
    
}


bool Match1(char exp[])//判断（）是否匹配/啊我写的
{
    LinkStNode *s;
    InitStack(s);
    int i;
    char e;
    for (i=0; exp[i]!='\0'; i++)
    {
        if (exp[i]=='(')
            Push(s, 1);
        
        
        if (exp[i]==')')
        {
            if (StackEmpty(s)==1)
                return FALSE;
            
            Pop(s, e);
            
        }
    }
    if (StackEmpty(s)!=1)
        return FALSE;
    
    return TRUE;
}


bool Match2(char exp[],int n)
{
    int i=0;
    char e;
    bool match=TRUE;
    LinkStNode *st;
    InitStack(st);
    while (i<n && match)
    {
        if (exp[i]=='(')
            Push(st, exp[i]);
        
        else if(exp[i]==')')
        {
            if (GetTop(st,e)==TRUE)
            {
                if (e!='(')//这步干嘛用的啊。。
                    match=FALSE;
                
                else
                    Pop(st,e);
            }
            else
                match=FALSE;
        }
        
        i++;
    }
    if (!StackEmpty(st))
        match=FALSE;
    
    DestroyStack(st);
    return match;
    
}










int main(int argc, const char * argv[]) {
//    char a;
//    LinkStNode *s;
//    
//    InitStack(s);
//    printf("%d\n",StackEmpty(s));
//    
//    Push(s,1);
//    Push(s,3);
//    Push(s,8);
//    Push(s,4);
//    
//    GetTop(s,a);
//    printf("%d\n",a);
//    
//    Pop(s, a);
//    printf("%d\n",a);
//    
//    DestroyStack(s);
//    
    char m[]="()()";
    printf("%d\n",Match2(m,4));
    
    return 0;
}


