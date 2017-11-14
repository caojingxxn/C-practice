
#include <iostream>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LinkNode;


void CreateList1(LinkNode **L,ElemType a[],int n)//建立（头插法）
{   LinkNode *s;
    int i;
    *L=(LinkNode *)malloc(sizeof(LinkNode));
    (*L)->next=NULL;
    for (i=0; i<n; i++) {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];
        s->next=(*L)->next;
        (*L)->next=s;
    }
}

void CreateList2(LinkNode **L,ElemType a[],int n)//建立（尾插法）
{
    LinkNode *s;LinkNode *p;
    int i;
    *L=(LinkNode *)malloc(sizeof(LinkNode));
    p=*L;
    for (i=0; i<n; i++) {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];
        p->next=s;
        p=s;
        
    }
    
}



void DispList(LinkNode *L)//输出
{
    LinkNode *p=L->next;
    while (p!=NULL) {
        printf("%3d",p->data);
        p=p->next;
    }
    printf("\n");
}



void DelMaxNode(LinkNode *L)//删除链表中最大值

{
    LinkNode *p=L->next;
    LinkNode *pre=L;
    LinkNode *max=p;
    LinkNode *premax=L;
    while (p!=NULL) {
        if (max->data<p->data) {
            premax=pre;
            max=p;
        }
        pre=p;
        p=p->next;
    }
    premax->next=max->next;
    free(max);
}


void Reverse(LinkNode *L)//倒序
{   LinkNode *p=L->next,*q;
    L->next=NULL;
    while (p!=NULL) {
        q=p->next;
        p->next=L->next;
        L->next=p;
        p=q;
    }
}



int ListInsert(LinkNode *L,int i,ElemType e)//第i-1个结点后插入元素e
{   LinkNode *p,*s;
    int j=1;
    p=L;
    s=(LinkNode *)malloc(sizeof(LinkNode));
    s->data=e;
    while(p->next!=0&&j<i)
    {
        p=p->next;
        j++;
    }
    if (p==NULL) {
        return 0;
    }
    else
    {s->next=p->next;
        p->next=s;
        return 1;}
    
}




void ArrangeList(LinkNode *L)//从小到大排序
{
    LinkNode *p,*q,*tail;
    ElemType tmp;
    tail=L->next;
    while (tail!=NULL) {
        tail=tail->next;
    }
    
    while (L->next!=tail)
    {
        p=L->next;
        q=p->next;
        while (q!=tail) {
            
            if (p->data>q->data) {
                tmp=p->data;
                p->data=q->data;
                q->data=tmp;
            }
            else
            {   p=q;
                q=q->next;}
        }
        tail=p;
    }
}


ElemType MiddleList(LinkNode *L)//找中间结点
{   LinkNode *p,*q;
    p=L->next;
    q=p;
    while (q->next!=NULL && q->next->next) {
        p=p->next;
        q=q->next->next;
    }
    return p->data;
}




void UnionSet(LinkNode* L1,LinkNode* L2)//找相同元素
{   LinkNode *p,*q;
    p=L1->next;
    q=L2->next;
    if (p->data>p->next->data)
        Reverse(L1);
    if (q->data>q->next->data)
        Reverse(L2);
    p=L1->next;
    q=L2->next;
    while (p&&q) {
        if (p->data<q->data)
            p=p->next;
        
        else if (p->data>q->data)
            q=q->next;
        
        else
        {   printf("%3d",p->data);
            p=p->next;
            q=q->next;}
    }
    printf("\n");

}



void duplicate(LinkNode *L)//找重复元素
{
    LinkNode *p=L->next;
    
    while (p)
    {
        LinkNode *q=p;
        int i=1;
        
        while (q->next)
        {
            if (p->data==q->next->data)
            {
                q->next=q->next->next;
                i++;
            }
            q=q->next;
        }
    
        if (i-1)
        {
            printf("%d %d\n",p->data,i);
        }
        p=p->next;
    }
    
}











//
//void UnionList1(LinkNode *L1,LinkNode *L2)//合并两个有序链表合并后依然有序
//{   LinkNode *p,*q,*r;
//    p=L1->next;
//    q=L2->next;
//    r=q->next;
//    while (p&&q)
//    {
//        if (p->data<q->data)
//        {
//            while (p->next&&p->next->data<q->data)
//            {
//                p=p->next;
//            }
//            
//        }
//        
//        if (L1->next==p)
//        {
//            q->next=L1->next;
//            L1->next=q;
//        }
//        else
//        {
//            q->next=p->next;
//            p->next=q;
//        }
//        
//        q=r;
//        r=r->next;
//        p=p->next->next;
//    }
//    
//    while (q) {
//        p->next=q;
//    }
//    
//}
//

//
//void UnionList2(LinkNode *L1,LinkNode *L2,LinkNode *&L3)//合并两个有序链表合并后依然有序
//{   L3=(LinkNode *)malloc(sizeof(LinkNode));
//    LinkNode *p=L1->next,*q=L2->next,*r=L3,*s;
//    while (p&&q) {
//        s=(LinkNode *)malloc(sizeof(LinkNode));
//        if (p->data<q->data) {
//            s->data=p->data;
//            p=p->next;
//        }
//        else{
//            s->data=q->data;
//            q=q->next;
//        }
//        r->next=s;
//        r=r->next;
//    }
//    while (p) {
//        s=(LinkNode *)malloc(sizeof(LinkNode));
//        s->data=p->data;
//        r->next=s;
//        r=r->next;
//        p=p->next;
//    }
//    
//    while (q) {
//        s=(LinkNode *)malloc(sizeof(LinkNode));
//        s->data=q->data;
//        r->next=s;
//        r=r->next;
//        q=q->next;
//    }
//    
//    r->next=NULL;
//    
//}
//

LinkNode *CycleCheck(LinkNode *L)//判断有无环
{
    LinkNode *p=L,*q=L;
    
    p=p->next;
    q=q->next->next;
    
    while (p!=q)
    {
        p=p->next;
        q=q->next->next;
        if (q->next==NULL||q->next->next==NULL)
        {
            return NULL;
        }
    }
    
    return p;
    
}








int main(int argc, const char * argv[]) {
    
    LinkNode *L1;//,*L2;
    ElemType a[10]={8,5,12,7,5,7,3,4,9,0};
    //ElemType b[5]={16,5,3,9,12};
    CreateList1(&L1,a,10);
    //CreateList1(&L2,b,5);
    //DelMaxNode(L1);
    //Reverse(L1);
//    ListInsert(L1,5,2);
//    ArrangeList(L1);
    //-------------------------------------------------------
    printf("L1:");DispList(L1);
    
    //ArrangeList(L2);
    //Reverse(L2);
    
    //printf("L2:");DispList(L2);
    
   
    //UnionSet(L1,L2);
    
    //UnionList1(L1,L2);
    //printf("合并:\n");DispList(L1);
    
    //
    //    UnionList2(L1,L2,&L3);
    //    printf("合并:\n");DispList(L3);
    
    //CycleCheck(L1);
    //printf("%d\n",t);
    
    duplicate(L1);
    return 0;
}

