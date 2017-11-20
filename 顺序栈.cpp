
//  main.c
//  顺序栈
//
//  Created by admin on 17/10/9.
//  Copyright © 2017年 admin. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdbool.h>

#define Maxsize 100
#define TRUE 1
#define FALSE 0

typedef int ElemType;

typedef struct
{
    ElemType data[Maxsize];
    int top;
}SqStack;


void InitStack(SqStack *&s) //初始化
{
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
    
}


void DestroyStack(SqStack *&s)//销毁
{
    free(s);
    
}


bool StackEmpty(SqStack *s)//判断
{
    return (s->top==-1);
    
}


bool Push(SqStack *&s,ElemType e)//进栈
{
    if (s->top==Maxsize-1) {
        return FALSE;
    }
    
    s->top++;
    s->data[s->top]=e;
    
    return TRUE;
    
}


bool Pop(SqStack *&s,ElemType &e)//出栈
{
    if (s->top==-1) {
        return FALSE;
    }
    
    e=s->data[s->top];
    s->top--;
    return TRUE;
    
}


bool GetTop(SqStack *&s,ElemType &e)//求栈顶元素
{
    if (s->top==-1) {
        return FALSE;
    }
    
    e=s->data[s->top];
    return TRUE;
    
}

bool symmetry(char str[])//判断回文
{
    ElemType e;
    SqStack *s;
    InitStack(s);
    int i;
    for (i=0; str[i]!='\0'; i++)
    {
        Push(s, str[i]);
    }
    
    for (i=0; str[i]!='\0'; i++)
    {
        Pop(s, e);
        if (e!=str[i])
        {
            DestroyStack(s);
            return FALSE;
        }
    }
    DestroyStack(s);
    return TRUE;
}


int main(int argc, const char * argv[]) {
    SqStack *s;
    ElemType e;
    InitStack(s);
    printf("%d\n",StackEmpty(s));
    
    Push(s,1);Push(s,2);Push(s,3);Push(s,4);
    GetTop(s,e);
    printf("%d\n",e);
    
    Pop(s, e);
    printf("%d\n",e);
    
    DestroyStack(s);
    
    char a[]="12345654321";
    printf("%d\n",symmetry(a));
    
    return 0;
}







