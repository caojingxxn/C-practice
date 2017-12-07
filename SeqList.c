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

void SeqListInit(SeqList* seq)//初始化
{
    assert(seq);
    seq->length = 0;
    
}


void SeqListPushBack(SeqList* seq, SeqType value)//尾插
{
    assert(seq);
    if (seq->length >= SeqListMaxSize) {
        return;
    }
    seq->data[seq->length] = value;
    seq->length++;
    
}



void SeqListPopBack(SeqList* seq)//尾删
{
    assert(seq);
    
    if (seq->length == 0) {
        return;
    }
    
    seq->length--;
    
}



void SeqListPushFront(SeqList* seq, SeqType value)//头插
{
    assert(seq);
    size_t i;
    if (seq->length >= SeqListMaxSize) {
        return;
    }
    
    for (i = seq->length; i > 0; i--) {
        seq->data[i] = seq->data[i-1];
    }
    seq->data[0] = value;
    seq->length++;
    
}



void SeqListPopFront(SeqList* seq)//头删
{
    assert(seq);
    if (seq->length == 0) {
        return;
    }
    
    size_t i = 0;
    for ( ; i < seq->length-1; i++) {
        seq->data[i] = seq->data[i+1];
    }
    
    seq->length--;
    
}



SeqType SeqListGet(SeqList* seq, size_t pos, SeqType default_value)//取顺序表中任意位置的一个元素
{
    assert(seq);
    if (pos >= seq->length) {
        return default_value;
    }
    
    return seq->data[pos];

    
}


void SeqListSet(SeqList* seq, size_t pos,SeqType value)//修改任意位置元素

{
    assert(seq);
    
    if (pos >= seq->length) {
        return;
    }
    else
        seq->data[pos] = value;
    
    
}



size_t SeqListFind(SeqList* seq, SeqType value)//查找指定元素值的下标
{
    assert(seq);
    size_t i = 0;
    
    for (; i < seq->length; i++) {
        if (seq->data[i] == value) {
            return i;
        }
    }
    
    return (size_t)-1;
        
        
}


void SeqListInsert(SeqList* seq, size_t pos,SeqType value)//在任意位置插入元素
{
    assert(seq);
    if (pos > seq->length) {
        ;
    }
    
    else{
        size_t i = seq->length;
        for (; i > pos; i--) {
            seq->data[i] = seq->data[i-1];
        }
        seq->data[pos] = value;
        
        seq->length++;
    }
    
    
}


void SeqListErase(SeqList* seq, size_t pos)//删除指定位置的值
{
    assert(seq);
    if (pos >= seq->length) {
        return;
    }
    
    size_t i;
    for ( i = pos; i < seq->length-1; i++) {
        
        seq->data[i] = seq->data[i+1];
        
    }
    
    seq->length--;
    
  
}


void SeqListRemove(SeqList* seq, SeqType to_delete)//删除第一个指定元素的值
{
    
    assert(seq);
    size_t i = SeqListFind(seq, to_delete);
    
    if (seq->data[i] == to_delete) {
        SeqListErase(seq, i);
    }
    
}



void SeqListRemoveAll(SeqList* seq, SeqType to_delete)//删除顺序表中所有的指定的值
{
    assert(seq);
    size_t count = 0;
    size_t i = 0;
    
    for ( ; i < seq->length; i++) {
        if (seq->data[i] == to_delete) {
            count++;
        }
    }
    
    while (count--) {
        SeqListRemove(seq, to_delete);
    }
    
}

void SeqListRemoveAllEx(SeqList* seq, SeqType to_delete)//删除顺序表中所有的指定的值,时间复杂度O(n)
{
    
    size_t cur = 0;
    size_t count = 0;
    
    for ( ; count < seq->length; count++) {
        
        if (seq->data[count] != to_delete) {
            seq->data[cur] = seq->data[count];
            cur++;
        }

    }
    
    seq->length = cur;
    
}


size_t SeqListSize(SeqList* seq)//获取顺序表元素个数
{
    return seq->length;
    
}


int SeqListEmpty(SeqList* seq)//判定顺序表是否为空
{
    if (seq->length == 0) {
        return 1;
    }
    else
        return 0;
}

void SeqListBubbleSort(SeqList* seq)//冒泡排序
{
    size_t count,cur;
    for (count = 0; count < seq->length-1; count++) {
        for (cur = 0; cur < seq->length-count-1; cur++) {
            if (seq->data[cur] > seq->data[cur+1]) {
                
                seq->data[cur] ^= seq->data[cur+1];
                seq->data[cur+1] ^= seq->data[cur];
                seq->data[cur] ^= seq->data[cur+1];

            }
        }
    }
 
    
}


int cmp(SType a, SType b)
{
    if (a < b) {
        return 1;
    }
    else
        return 0;
    
}


void SeqListBubbleSortEx(SeqList* seq, int (*cmp)(SType , SType))
{
    
    size_t count,cur;
    
    for (count = 0; count < seq->length-1; count++) {
        for (cur = 0; cur < seq->length-count-1; cur++) {
            if (cmp(seq->data[cur],seq->data[cur+1])) {
                
                seq->data[cur] ^= seq->data[cur+1];
                seq->data[cur+1] ^= seq->data[cur];
                seq->data[cur] ^= seq->data[cur+1];
                
            }
        }
    }
    
    
    
    
    
    
}

//////////////////////////////////////////////////
//                以下为测试代码                   //
//////////////////////////////////////////////////




void DispListSeqList(SeqList *L, char *str)//输出
{
    size_t i;
    printf("[%s]  ",str);
    printf("length:%zu\n",L->length);
    
    for (i=0; i<L->length; i++) {
        printf("data[%zu]:%-3c [地址:]%p\n",i,L->data[i],&L->data[i]);
    }
    printf("\n");

}

void Test_Init()//初始化测试
{
    TEST_HEADER;
    SeqList L;
    SeqListInit(&L);
    DispListSeqList(&L,"初始化为空表:");
    
}


void Test_Push_Back()//尾插法测试
{
    TEST_HEADER;
    SeqList L;
    SeqListInit(&L);

    SeqListPushBack(&L, 'a');
    SeqListPushBack(&L, 'b');
    SeqListPushBack(&L, 'c');
    SeqListPushBack(&L, 'd');
    
    DispListSeqList(&L,"尾插 a,b,c,d:");
}


void Test_Pop_Back()//尾删法测试
{
    TEST_HEADER;
    SeqList L;
    SeqListInit(&L);
    SeqListPopBack(&L);
    DispListSeqList(&L,"尾删空表:");
    
    SeqListPushBack(&L, 'a');
    SeqListPushBack(&L, 'b');
    SeqListPushBack(&L, 'c');
    SeqListPushBack(&L, 'd');
    
    DispListSeqList(&L,"尾插 a,b,c,d:");
    
    SeqListPopBack(&L);
    SeqListPopBack(&L);
    DispListSeqList(&L,"尾删两个元素:");

}

void Test_Push_Front()//头插法测试
{
    TEST_HEADER;
    SeqList L;
    SeqListInit(&L);
    
    SeqListPushFront(&L,'m');
    SeqListPushFront(&L,'n');
    DispListSeqList(&L,"头插 m,n:");
    
    SeqListPushFront(&L,'a');
    SeqListPushFront(&L,'b');
    DispListSeqList(&L,"头插 a,b:");
    
}


void Test_Pop_Front()//头删法测试
{
    TEST_HEADER;
    SeqList L;
    SeqListInit(&L);
    SeqListPopFront(&L);
    DispListSeqList(&L,"头删空表:");
    
    SeqListPushBack(&L, 'a');
    SeqListPushBack(&L, 'b');
    SeqListPushBack(&L, 'c');
    SeqListPushBack(&L, 'd');
    DispListSeqList(&L,"尾插 a,b,c,d:");
    
    
    SeqListPopFront(&L);
    SeqListPopFront(&L);
    DispListSeqList(&L,"头删两个元素:");
    
    
}


void Test_Get()
{
    TEST_HEADER;
    SeqList L;
    SeqListInit(&L);
    
    SeqListPushBack(&L, 'a');
    SeqListPushBack(&L, 'b');
    SeqListPushBack(&L, 'c');
    SeqListPushBack(&L, 'd');
    
    SeqType a = SeqListGet(&L, 10, -1);
    DispListSeqList(&L,"尾插 a,b,c,d:");
    printf("取下标为10元素的值[actual:]%c\n",a);
    
    SeqType b = SeqListGet(&L, 2, -1);
    printf("取下标为2元素的值[expect:]c [actual:]%c\n",b);

}


void Test_Set()
{
    TEST_HEADER;
    SeqList L;
    SeqListInit(&L);
    SeqListSet(&L, 2, 'm');
    DispListSeqList(&L, "对空表下标为2的元素修改为'm':");
    SeqListPushBack(&L, 'a');
    SeqListPushBack(&L, 'b');
    SeqListPushBack(&L, 'c');
    SeqListPushBack(&L, 'd');
    SeqListSet(&L, 2, 'm');
    DispListSeqList(&L, "尾插a,b,c,f,对下标为2的元素修改为'm':");

}



void Test_Find()//查找下标测试
{
    TEST_HEADER;
    SeqList L;
    SeqListInit(&L);
    
    SeqListPushBack(&L, 'a');
    SeqListPushBack(&L, 'b');
    SeqListPushBack(&L, 'c');
    SeqListPushBack(&L, 'd');
    DispListSeqList(&L,"尾插 a,b,c,d:");
    
    size_t k = SeqListFind(&L, 'm');
    printf("查找'm' [actual:]%zu\n",k);
    
    size_t t = SeqListFind(&L, 'b');
    printf("查找'b' [expect:]1  [actual:]%zu\n",t);
    
    
}



void Test_Insert()
{
    TEST_HEADER;
    SeqList L;
    SeqListInit(&L);
    
    SeqListPushBack(&L, 'a');
    SeqListPushBack(&L, 'b');
    SeqListPushBack(&L, 'c');
    SeqListPushBack(&L, 'd');
    DispListSeqList(&L,"尾插 a,b,c,d:");
    
    SeqListInsert(&L, 4, 'l');
    DispListSeqList(&L,"在末尾插入'l':");
    
    SeqListInsert(&L, 0, 'i');
    DispListSeqList(&L,"在开头插入'i':");
    
    SeqListInsert(&L, 2, 'n');
    DispListSeqList(&L,"在下标为2插入'n':");
}



void Tset_Erase()
{
    TEST_HEADER;
    SeqList L;
    SeqListInit(&L);
    SeqListErase(&L, 1);
    DispListSeqList(&L, "在空表删除下标为1的元素:");
    
    SeqListPushBack(&L, 'a');
    SeqListPushBack(&L, 'b');
    SeqListPushBack(&L, 'c');
    SeqListPushBack(&L, 'a');
    SeqListPushBack(&L, 'd');
    SeqListPushBack(&L, 'a');
    DispListSeqList(&L,"尾插 a,b,c,a,d,a:");
    
    SeqListErase(&L, 6);
    DispListSeqList(&L,"删除下标为6的元素(无此元素):");
    
    SeqListErase(&L, 3);
    DispListSeqList(&L,"删除下标为3的元素:");
    
    SeqListErase(&L, 0);
    DispListSeqList(&L,"删除下标为0的元素:");
    

}


void Test_Remove()
{
    
    TEST_HEADER;
    SeqList L;
    SeqListInit(&L);
    SeqListRemove(&L, 'a');
    DispListSeqList(&L, "在空表删除'a':");
    
    SeqListPushBack(&L, 'a');
    SeqListPushBack(&L, 'b');
    SeqListPushBack(&L, 'c');
    SeqListPushBack(&L, 'a');
    SeqListPushBack(&L, 'd');
    SeqListPushBack(&L, 'a');
    DispListSeqList(&L,"尾插 a,b,c,a,d,a:");
    
    SeqListRemove(&L, 'a');
    DispListSeqList(&L,"删除第一个'a':");
    
}


void Test_RemoveAll()
{
    TEST_HEADER;
    SeqList L;
    SeqListInit(&L);
    
    SeqListPushBack(&L, 'a');
    SeqListPushBack(&L, 'b');
    SeqListPushBack(&L, 'c');
    SeqListPushBack(&L, 'a');
    SeqListPushBack(&L, 'd');
    SeqListPushBack(&L, 'a');
    DispListSeqList(&L,"尾插 a,b,c,a,d,a:");
    
    SeqListRemoveAll(&L, 'a');
    DispListSeqList(&L,"删除所有'a':");

}

void Test_RemoveAllEx()
{
    TEST_HEADER;
    SeqList L;
    SeqListInit(&L);
    
    SeqListPushBack(&L, 'a');
    SeqListPushBack(&L, 'b');
    SeqListPushBack(&L, 'c');
    SeqListPushBack(&L, 'a');
    SeqListPushBack(&L, 'd');
    SeqListPushBack(&L, 'a');
    DispListSeqList(&L,"尾插 a,b,c,a,d,a:");
    
    SeqListRemoveAllEx(&L, 'a');
    DispListSeqList(&L,"删除所有'a':");
    
}


void Test_Empty()
{
    TEST_HEADER;
    SeqList L;
    SeqListInit(&L);
    int a = SeqListEmpty(&L);
    printf("[判定空表是否为空:][expect:]1 [actual:]%d\n",a);
    
    SeqListPushBack(&L, 'm');
    SeqListPushBack(&L, 'n');
    DispListSeqList(&L, "尾插m,n:");
    int b = SeqListEmpty(&L);
    printf("[判定是否为空:][expect:]0 [actual:]%d\n",b);
}

void Test_Bubble()
{
    TEST_HEADER;
    SeqList L;
    SeqListInit(&L);
    SeqListPushBack(&L, 'c');
    SeqListPushBack(&L, 'a');
    SeqListPushBack(&L, 'm');
    SeqListPushBack(&L, 'd');
    SeqListPushBack(&L, 'i');
    DispListSeqList(&L,"尾插 c,a,m,d,i:");
    
    SeqListBubbleSort(&L);
    DispListSeqList(&L,"进行冒泡排序:");
    
    
}


void Test_BubbleEx()
{
    TEST_HEADER;
    SeqList L;
    SeqListInit(&L);
    SeqListPushBack(&L, 'c');
    SeqListPushBack(&L, 'a');
    SeqListPushBack(&L, 'm');
    SeqListPushBack(&L, 'd');
    SeqListPushBack(&L, 'i');
    DispListSeqList(&L,"尾插 c,a,m,d,i:");
    
    SeqListBubbleSortEx(&L,&cmp);
    DispListSeqList(&L,"进行优化的冒泡排序:");
    

}

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    Test_Init();
    Test_Push_Back();
    Test_Pop_Back();
    Test_Push_Front();
    Test_Pop_Front();
    Test_Get();
    Test_Set();
    Test_Find();
    Test_Insert();
    Tset_Erase();
    Test_Remove();
    Test_RemoveAll();//删除所有
    Test_RemoveAllEx();//优化时间复杂度
    Test_Empty();
    Test_Bubble();
    Test_BubbleEx();
    return 0;
}
