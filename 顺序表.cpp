#include <stdio.h>
#include <stdlib.h>

#define N 100
#define TRUE 1
#define FALSE 0

typedef int ElemType;

typedef struct {
    ElemType data[N];
    int length;
}SqList;

void CreateList(SqList *&L,ElemType a[],int n)//创建
{
    int i;
    L=(SqList *)malloc(sizeof(SqList));
    for (i=0; i<n; i++)
        L->data[i]=a[i];
    L->length=n;
    
}

void DispList(SqList *L)//输出
{   int i;
    for (i=0; i<L->length; i++) {
        printf("%3d",L->data[i]);
    }
    printf("\n");
}


void Move(SqList *L)//交换奇偶
{   int i=0,j=L->length-1;
    ElemType tmp;
    while (i<j)
    {
        while ((L->data[i]%2)!=0&&i<j) {
            i++;
        }
        while ((L->data[j]%2)==0&&i<j) {
            j--;
        }
        tmp=L->data[i];
        L->data[i]=L->data[j];
        L->data[j]=tmp;
    }
}


void DestroyList(SqList *L)//销毁
{
    free(L);
    L=NULL;
    
}


int main(int argc, const char * argv[]) {
    SqList *L;
    ElemType a[]={1,2,3,4,5,6,7,8,9,10};
    CreateList(L,a,10);
    DispList(L);
    Move(L);
    DispList(L);
    DestroyList(L);
    
    return 0;
}
