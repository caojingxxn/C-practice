//
//  main.c
//  顺序表_数据结构_01
//
//  Created by admin on 17/12/1.
//  Copyright © 2017年 Amon. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include "SeqList.h"

void SeqList_Init(SeqList *L)//初始化
{
    assert(L);
    L->length = 0;
    
}


void SeqList_Push_Back(SeqList *L, ElemType c)//尾插
{
    assert(L);
    if (L->length >= MaxSizeSeqList) {
        printf("插入失败！\n");
        return;
    }
    L->data[L->length] = c;
    L->length++;
    
}

void SeqList_Pop_Back(SeqList *L)//尾删
{
    assert(L);
    
    if (L->length == 0) {
        printf("删除失败！\n");
        return;
    }
    
    L->length--;
    
}

void SeqList_Push_Front(SeqList *L,ElemType c)//头插
{
    assert(L);
    int i;
    if (L->length >= MaxSizeSeqList) {
        printf("插入失败！\n");
        return;
    }
    for (i = L->length; i > 0; i--) {
        L->data[i] = L->data[i-1];
    }
    L->data[0] = c;
    L->length++;
    
}

void SeqList_Pop_Front(SeqList *L)//头删
{
    assert(L);
    int i = 0;
    
    if (L->length == 0) {
        printf("删除失败！\n");
        return;
    }
    
    for ( ; i < L->length-1; i++) {
        
        L->data[i] = L->data[i+1];
        
    }
    
    L->length--;
    
}

ElemType SeqList_Getchar(SeqList *L,int Position)//读任意位置元素
{
    assert(L);
    if (Position >= L->length) {
        printf("读取失败！\n");
        return -1;
    }
    
    return L->data[Position];

    
}


void SeqList_Revise(SeqList *L,int Position,ElemType c)//修改任意位置元素
{
    assert(L);
    
    if (Position >= L->length) {
        printf("修改失败！\n");
    }
    else
        L->data[Position] = c;
    
    
}

void SeqList_Search(SeqList *L,ElemType a)//查找指定元素值的下标
{
    assert(L);
    int i = 0;
    int flag = 0;
    for (; i < L->length; i++) {
        if (L->data[i] == a) {
            printf("%c的下标为：%-3d",a,i);
            flag = 1;
        }
    }
    
    if (flag == 0) {
        printf("%c:没有此元素！\n",a);
    }
    else
        printf("\n");
    
}


void SeqListInsert(SeqList *L,int Position,ElemType c)//在任意位置插入元素
{
    assert(L);
    if (Position > L->length) {
        printf("插入失败！\n");
    }
    
    else{
        int i = L->length;
        for (; i > Position; i--) {
            L->data[i] = L->data[i-1];
        }
        L->data[Position] = c;
        
        L->length++;
    }
    
    
}


//////////////////////////////////////////////////
//                以下为测试代码                   //
//////////////////////////////////////////////////

void DispListSeqList(SeqList *L)//输出
{
    int i;
    for (i=0; i<L->length; i++) {
        printf("data[%d]:%-3c [地址:]%p\n",i,L->data[i],&L->data[i]);
    }
    printf("length:%d\n\n",L->length);
}

void Test_Init(SeqList *L)//初始化测试
{
    TEST_HEADER;
    SeqList_Init(L);
    printf("length:%d\n",L->length);
    
}


void Test_Push_Back(SeqList *L)//尾插法测试
{
    TEST_HEADER;
    SeqList_Push_Back(L, 'a');
    SeqList_Push_Back(L, 'b');
    SeqList_Push_Back(L, 'c');
    SeqList_Push_Back(L, 'd');
    
    DispListSeqList(L);
}


void Test_Pop_Back(SeqList *L)//尾删法测试
{
    TEST_HEADER;
    SeqList_Pop_Back(L);
    SeqList_Pop_Back(L);
    
    DispListSeqList(L);
    
    SeqList_Pop_Back(L);
    SeqList_Pop_Back(L);
    SeqList_Pop_Back(L);

}

void Test_Push_Front(SeqList *L)//头插法测试
{
    TEST_HEADER;
    SeqList_Push_Front(L,'m');
    SeqList_Push_Front(L,'n');
    DispListSeqList(L);
    
}


void Test_Pop_Front(SeqList *L)//头删法测试
{
    TEST_HEADER;
    SeqList_Pop_Front(L);
    DispListSeqList(L);
    SeqList_Pop_Front(L);
    SeqList_Pop_Front(L);
    DispListSeqList(L);
    
}

void Test_Get_char(SeqList *L)
{
    TEST_HEADER;
    int a;
    SeqList_Push_Back(L, 'k');
    a = SeqList_Getchar(L, 0);
    if (a != -1) {
        printf("%c\n",a);
    }
    a = SeqList_Getchar(L, 1);
    if (a != -1) {
        printf("%c\n",a);
    }
    
}

void Test_Revise(SeqList *L)
{
    TEST_HEADER;
    SeqList_Push_Front(L,'a');
    SeqList_Push_Front(L,'b');
    SeqList_Push_Front(L,'c');
    DispListSeqList(L);
    SeqList_Revise(L, 1, 'v');
    
    DispListSeqList(L);
    SeqList_Revise(L, 4, 'm');
}

void Test_Search(SeqList *L)//查找下标测试
{
    TEST_HEADER;
    SeqList_Search(L, 'k');
    SeqList_Search(L, 'a');
    SeqList_Search(L, 'm');
    
}



void TestInsert(SeqList *L)
{
    TEST_HEADER;
    SeqListInsert(L, 3, 'w');
    DispListSeqList(L);
    SeqListInsert(L, 5, 'p');
    DispListSeqList(L);
    SeqListInsert(L, 7, 'o');
}

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    SeqList L;
    Test_Init(&L);
    Test_Push_Back(&L);
    Test_Pop_Back(&L);
    Test_Push_Front(&L);
    Test_Pop_Front(&L);
    Test_Get_char(&L);
    Test_Revise(&L);
    Test_Search(&L);
    TestInsert(&L);
    return 0;
}
