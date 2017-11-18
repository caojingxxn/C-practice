//
//  main.cpp
//  链串
//
//  Created by admin on 17/10/16.
//  Copyright © 2017年 admin. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Snode
{
    char data;
    struct Snode *next;
    
}LinkStrNode;

void StrAssgin(LinkStrNode *&s,char cstr[])//生成，赋值
{
    int i;
    s=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    
    LinkStrNode *p,*pre=s;
    
    for (i=0; cstr[i]!='\0'; i++) {
        p=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        p->data=cstr[i];
        pre->next=p;
        pre=p;
    }
    pre->next=NULL;
}


void DestroyStr(LinkStrNode *&s)//销毁
{
    LinkStrNode *p=s->next;
    
    while (p) {
        s->next=p->next;
        free(p);
        p=s->next;
    }
    free(s);
    
}


void DispStr(LinkStrNode *s)//输出
{
    LinkStrNode *p=s->next;
    while (p) {
        printf("%c",p->data);
        p=p->next;
    }
    
    printf("\n");
}



void StrCopy(LinkStrNode *&s,LinkStrNode *&t)//t复制给s
{
    LinkStrNode *r=s,*q,*p=t->next;
    s=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    
    while (p) {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
        
    }
    r->next=NULL;
    
}


int StrLength(LinkStrNode *s)//判串长
{
    int i=0;
    LinkStrNode *p=s->next;
    while (p) {
        p=p->next;
        i++;
    }
    
    return i;
}


LinkStrNode *SubStr(LinkStrNode *s,int i,int j)//求子串
{
    int k;
    LinkStrNode *str,*p=s->next,*q,*r;
    str=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    str->next=NULL;
    r=str;
    
    if (i<=0||i>StrLength(s)||i+j-1>StrLength(s)) {
        return str;
    }
    
    for (k=0; k<i-1; k++)
        p=p->next;
    
    for (k=1; k<=j; k++) {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    
    r->next=NULL;
    return str;
    
}


bool StrEqual(LinkStrNode *s,LinkStrNode *t)//判相等
{
    LinkStrNode *q=s->next,*p=t->next;
    
    while (p&&q&&(p->data==q->data)) {
        p=p->next;
        q=q->next;
    }
    
    if (p==NULL&&q==NULL) {
        return TRUE;
    }
    
    else
        return FALSE;
}



LinkStrNode *DelStr(LinkStrNode *&s,int i,int j)//删除子串
{
    int k;
    LinkStrNode *str,*p=s->next,*q,*r;
    str=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    str->next=NULL;
    r=str;
    
    if (i<0||i>StrLength(s)||i+j-1>StrLength(s)) {
        return str;
    }
    
    for (k=0; k<i-1; k++) {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    
    for (k=0; k<j; k++) {
        p=p->next;
    }
    
    while (p) {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    
    r->next=NULL;
    return str;
    
}


LinkStrNode *InsStr(LinkStrNode *&s,int i,LinkStrNode *t)//串插入
{
    int k;
    LinkStrNode *str,*q,*p=s->next,*r,*p1=t->next;
    str=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    str->next=NULL;
    r=str;
    
    if (i<=0||i>StrLength(s)+1)
        return str;
    
    for (k=0; k<i-1; k++)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    
    while (p1)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p1->data;
        r->next=q;
        r=q;
        p1=p1->next;
    }
    
    while (p)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    
    r->next=NULL;
    return str;
}


LinkStrNode *RepStr(LinkStrNode *s,int i,int j,LinkStrNode *t)//串替换
{
    int k;
    LinkStrNode *str,*r,*p=s->next,*q,*p1=t->next;
    str=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    str->next=NULL;
    r=str;
    
    if (i<0||i>StrLength(s)||i+j-1>StrLength(s)) {
        return str;
    }
    
    for (k=0; k<i-1; k++) {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    
    while (p1) {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p1->data;
        r->next=q;
        r=q;
        p1=p1->next;
    }
    
    for (k=0; k<j; k++) {
        p=p->next;
    }
    
    while (p) {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    
    r->next=NULL;
    return str;
    
}


bool Strcmp(LinkStrNode *s,LinkStrNode *t)//比较s和t的大小（上机作业）
{
    int sl,tl,min;
    LinkStrNode *sp=s->next,*tp=t->next;
    sl=StrLength(s);
    tl=StrLength(t);
    if (sl<=tl)
        min=sl;
    else
        min=tl;
    
    while (min)
    {
        if (sp->data>tp->data)
            return TRUE;
        else if(sp->data<tp->data)
            return FALSE;
        else
        {
            sp=sp->next;
            tp=tp->next;
            min--;
            
        }
    }
    
    if (sp->next==NULL) {
        return FALSE;
    }
    
    else
        return TRUE;
    
}





void homework(LinkStrNode *s,char cstr1[],char cstr2[])//把最先出现的cstr1换成cstr2
{
    LinkStrNode *m1,*m2;
    int i=1;
    
    while(cstr1[i]!='\0')
        i++;
    
    StrAssgin(m1, cstr1);
    StrAssgin(m2, cstr2);
    
    int k=1;
    
    while(StrEqual(SubStr(s, k, i),m1)==FALSE)
        k++;
    
    DispStr(RepStr(s, k, i, m2));
    
}


int main(int argc, const char * argv[]) {
    
    LinkStrNode *s,*m,*p;
    char cstr[]="fajleabdmsal";
    char c1[]="ab";
    //char c2[]="xyz";
    StrAssgin(m, c1);
    StrAssgin(s, cstr);
    //homework(s, c1, c2);
    LinkStrNode *t=RepStr(s, 2, 2, m);
    
    StrCopy(p,t);
    DispStr(RepStr(s, 2, 2, m));
    
    printf("%d",Strcmp(m, s));
    return 0;
}


