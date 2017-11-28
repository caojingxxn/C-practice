//
//  main.c
//  希尔排序
//
//  Created by admin on 17/11/15.
//  Copyright © 2017年 Amon. All rights reserved.

/*

思路：
 1.分组d=n/2；
 2.将排序序列分为d组，组内进行直接插入排序；
 3.递减d=d/2，重复至d=1。
 
 */

#include <stdio.h>

typedef int KeyType;
typedef int InfoType;

typedef struct{
    
    KeyType Key;
    InfoType data;
    
}RecType;


void ShellSort(RecType R[],int n)
{
    int i,j;
    int d = n/2;
    RecType tmp;
    
    while (d > 0) {
     
        for (i = d; i < n; i++) {
                
                tmp = R[i];
                j = i;
                
                while ( (tmp.Key < R[j-d].Key) && j > 0) {
                    R[j] = R[j-d];
                    j -= d;
                }
                
                R[j] = tmp;
                
        }
        
        d = d/2;
    }
    
}


int main(int argc, const char * argv[]) {
    
    RecType R[5];
    R[0].Key = 8;
    R[1].Key = 7;
    R[2].Key = 2;
    R[3].Key = 9;
    R[4].Key = 3;
    
    ShellSort(R, 5);
    int i;
    
    for (i = 0; i < 5; i++) {
        
        printf("%d  ",R[i].Key);
        
    }
    return 0;
}


