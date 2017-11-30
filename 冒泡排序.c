//
//  main.c
//  冒泡排序
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


void BubbleSort(RecType R[],int n)
{
    
    int i,j;
    RecType tmp;
    int flag = 0;
    
    for (i = 0; i < n; i++) {
        
        for (j = 0; j < n-i-1; j++) {
            
            if (R[j].Key > R[j+1].Key) {
                tmp = R[j+1];
                R[j+1] = R[j];
                R[j] = tmp;
                flag = 1;
            }
        }
        
        if (flag == 0) {
            break;
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
    
    BubbleSort(R, 5);
    int i;
    
    for (i = 0; i < 5; i++) {
        
        printf("%d  ",R[i].Key);
        
    }
    return 0;
}
