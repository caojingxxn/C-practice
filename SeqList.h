//
//  SeqList.h
//  顺序表_数据结构_01
//
//  Created by admin on 17/12/1.
//  Copyright © 2017年 Amon. All rights reserved.
//

#ifndef SeqList_h
#define SeqList_h

#define MaxSizeSeqList 100
#define TEST_HEADER printf("\n %s \n",__FUNCTION__) //打印函数名

typedef int ElemType;

typedef struct SeqList
{
    ElemType data[MaxSizeSeqList];
    int length;
    
}SeqList;

void SeqListInit(SeqList *L);
//初始化

void SeqListPushBack(SeqList *L, ElemType c);
//尾插

void SeqList_Pop_Back(SeqList *L);
//尾删

void SeqList_Push_Front(SeqList *L,ElemType c);
//头插

void SeqList_Pop_Front(SeqList *L);
//头删

ElemType SeqList_Getchar(SeqList *L,int Position);
//读任意位置元素

void SeqList_Revise(SeqList *L,int Position,ElemType c);
//修改任意位置元素

void SeqList_Search(SeqList *L,ElemType a);
//查找指定元素值的下标

void SeqListInsert(SeqList *L,int Position,ElemType c);
//在任意位置插入元素

#endif /* SeqList_h */
