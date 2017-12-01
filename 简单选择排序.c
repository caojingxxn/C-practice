//
//  main.c
//  简单选择排序
//
//  Created by admin on 17/11/16.
//  Copyright © 2017年 Amon. All rights reserved.
//

#include <stdio.h>


typedef int KeyType;
typedef int InfoType;

typedef struct{
    
    KeyType Key;
    InfoType data;
    
}RecType;


int Min(RecType R[],int n,int i)//从R[0...n-1]中选出最小数下标
{
    int j;
    int tmp = i;
    for (j = i+1; j < n; j++) {
        
        if (R[tmp].Key > R[j].Key) {
            tmp = j;
        }
        
    }
    
    return tmp;
}


void SelectSort(RecType R[],int n)
{
    
    int i,k;
    RecType tmp;
    
    for (i = 0; i < n; i++) {
    
        k = Min(R, n, i);
        
        if (k != i) {
            tmp = R[i];
            R[i] = R[k];
            R[k] = tmp;
            
        }
    }
}

int main(int argc, const char * argv[]) {
    
    RecType R[5];
    R[0].Key = 8;
    R[1].Key = 7;
    R[2].Key = 2;
    R[3].Key = 9;
    R[4].Key = 3;
    
    SelectSort(R, 5);
    int i;
    
    for (i = 0; i < 5; i++) {
        
        printf("%d  ",R[i].Key);
        
    }
    return 0;
}
