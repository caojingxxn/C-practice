//
//  main.c
//  折半插入排序
//
//  Created by admin on 17/11/15.
//  Copyright © 2017年 Amon. All rights reserved.
//

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
    int left,right,mid;
    
    for (i = 1; i < n; i++) {
        
      
        if (R[i].Key < R[i-1].Key) {
            
            tmp = R[i];
            
            left = 0;
            right = i-1;
            mid = (left+right)/2;
            
            while ( left <= right && left >= 0 && right >= 0) {
                
                if (R[mid].Key < tmp.Key) {
                    left = mid + 1;
                    
                }
                else{
                    
                    right = mid -1;
                    
                }
                mid = (left+right)/2;
                
            }
            
            for(j = i;j > right;j-- ){
                
                R[j] = R[j-1];
            }
            
            R[j+1] = tmp;
            
            
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



