//
//  main.cpp
//  二叉树
//
//  Created by admin on 17/10/29.
//  Copyright © 2017年 admin. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

#define MaxSize 100

typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *lchild,*rchild;
    
}BTNode;


void CreateBTree(BTNode *&b,char *str)//建立
{
    BTNode *st[MaxSize],*p=NULL;
    int top=-1,j=0,k=1;
    char ch;
    ch=str[j];
    
    b=NULL;

    while (ch!='\0')
    {
        switch (ch)
        {
            case '(':
                k=1;
                top++;
                st[top]=p;
                break;
                
            case ')':
                top--;
                break;
                
            case ',':
                k=2;
                break;
                
            default:
                p=(BTNode *)malloc(sizeof(BTNode));
                p->data=ch;
                p->lchild=p->rchild=NULL;
                
                if (b==NULL)
                    b=p;
                
                else
                {
                    switch (k)
                    {
                        case 1:
                            st[top]->lchild=p;
                            break;
                            
                        case 2:
                            st[top]->rchild=p;
                            break;
                    }
                    
                }
                
                break;
        }
        j++;ch=str[j];
    }
    
    
}



void DestroyBTree(BTNode *&b)//销毁
{
    if (b) {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
    }
    
}



BTNode *FindNode(BTNode *b,ElemType e)//查找结点
{
    BTNode *p;
    
    if (b==NULL)
        return NULL;
    
    else if(b->data != e)
        return b;
    
    else
    {
        p=FindNode(b->lchild, e);
        if (p)
            return p;
        else
        return FindNode(b->rchild, e);

    }
}




BTNode *LchildNode(BTNode *b)//找左孩子结点
{
    return b->lchild;
}


BTNode *RchildNode(BTNode *b)//找右孩子结点
{
    return b->rchild;
}



int BTHeight(BTNode *b)//求高度
{
    int lchilddep,rchilddep;
    if (b==NULL)
        return 0;
    
    else
    {
        lchilddep = BTHeight(b->lchild);
        rchilddep = BTHeight(b->rchild);
      
        return ((lchilddep>rchilddep)?(lchilddep+1):(rchilddep+1));
    }
    
}



void DispBTNode(BTNode *b)//输出
{
    if (b)
    {
        printf("%c",b->data);
        
        if (b->lchild||b->rchild)
        {
            printf("(");
            
            DispBTNode(b->lchild);
            
            if (b->rchild)
                printf(",");
            
            DispBTNode(b->rchild);
            
            printf(")");
            
        }
    }
    
}



void PreOreder(BTNode *b)//先根遍历
{
    if (b)
    {
        printf("%c",b->data);
        PreOreder(b->lchild);
        PreOreder(b->rchild);
    }
}


void InOreder(BTNode *b)//中序遍历
{
    if (b)
    {
        PreOreder(b->lchild);
        printf("%c",b->data);
        PreOreder(b->rchild);
    }
}


void PostOreder(BTNode *b)//后根遍历
{
    if (b)
    {
        PreOreder(b->lchild);
        PreOreder(b->rchild);
        printf("%c",b->data);
    }
}


int Nodes(BTNode *b)//求结点个数
{
    if (!b)
        return 0;
    else
        return Nodes(b->lchild)+Nodes(b->rchild)+1;
    
}


void DispLeaf(BTNode *b)//输出叶子结点
{
    if (b)
    {
        if (b->lchild==NULL&&b->rchild==NULL)
            printf("%c",b->data);
        
        DispLeaf(b->lchild);
        DispLeaf(b->rchild);
    }
}


int Level(BTNode *b,ElemType x,int h)//求值为x的结点的层次（结点唯一）
{
    int l;
    if (b==NULL)
        return 0;
    
    if (b->data==x)
        return h;
    
    else
    {
        
        l=Level(b->lchild, x, h+1);
        if (l!=0)
            return l;
        
        else
            return Level(b->rchild, x, h+1);
        
    }
    
}



void Lnodenum(BTNode *b,int h,int k,int &n)//求k层结点个数
{
    if (b)
    {
        if (h==k)
            n++;
        
        
        else if (h<k)
        {
            Lnodenum(b->lchild, h+1, k, n);
            Lnodenum(b->rchild, h+1, k, n);
        }
    }
    
}



bool Like(BTNode *b1,BTNode *b2)//判断两树是否相似
{
    bool like1=0,like2=0;
    
    if (b1==NULL&&b2==NULL)
        return 1;
    
    else if (b1==NULL||b2==NULL)
        return 0;
    
    else
    {
        like1=Like(b1->lchild,b2->lchild);
        like2=Like(b1->rchild,b2->rchild);
        return (like1&&like2);
    }
    
}




int main(int argc, const char * argv[])
{
    BTNode *b;
    char str[17]="(A(B(D(,F),E),C)";
    
    CreateBTree(b, str);
    
    DispBTNode(b);
    printf("\n");
    
    int i;
    i=Level(b, 'E', 1);
    printf("%d\n",i);
    return 0;
}
