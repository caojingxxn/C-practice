//
//  main.cpp
//  直接插入排序
//
//  Created by admin on 17/11/15.
//  Copyright © 2017年 Amon. All rights reserved.
//  从小到达排序

#include <stdio.h>

typedef int KeyType;
typedef int InfoType;

typedef struct{
    
    KeyType Key;
    InfoType data;
    
}RecType;


void InsertSort(RecType R[],int n)
{
    
    int i,j;
    RecType tmp;
    
    for (i = 1; i < n; i++) {
        if (R[i].Key < R[i-1].Key) {
            
            tmp = R[i];
            j = i;
            
            while ( (tmp.Key < R[j-1].Key) && j > 0) {
                R[j] = R[j-1];
                j--;
            }
            
            R[j] = tmp;

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
    
    InsertSort(R, 5);
    int i;
    
    for (i = 0; i < 5; i++) {
        
        printf("%d  ",R[i].Key);
        
    }
    return 0;
}
