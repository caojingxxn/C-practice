//
//  main.cpp
//  链式基数排序
//
//  Created by admin on 17/11/22.
//  Copyright © 2017年 Amon. All rights reserved.
//

#include <iostream>

#define MAXR 8 //关键字基数（十进制时）

typedef int KeyType;

typedef struct node{
    
    char data[8];
    KeyType Key;
    struct node *next;
}RecType1;

void RadixSort(RecType1 *&p,int r,int d)
{
    RecType1 *head[MAXR], *tail[MAXR];
    RecType1 *t;
    
    int i,j,k;
    
    for (i = 0; i < d; i++) {
        
        for (j = 0; j < r; j++) {
            head[j] = tail[j] = NULL;
        }
        
        while (p != NULL) {
            k = p->data[i] - '0';
            
            
            
        }
        
        
        
        
        
        
        
        
        
        
    }
    
    
    
}

int main(int argc, const char * argv[]) {
    
    RecType1 R[5];
    R[0].Key = 8;
    R[1].Key = 7;
    R[2].Key = 2;
    R[3].Key = 9;
    R[4].Key = 3;
    
    //InsertSort(R, 5);
    int i;
    
    for (i = 0; i < 5; i++) {
        
        printf("%d  ",R[i].Key);
        
    }
    
    return 0;
}
