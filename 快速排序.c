//
//  main.c
//  快速排序
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

void Q_Sort(RecType R[],int s,int t)//一次
{
    
    if (s < t) {
        
        int i = s;
        int j = t;
        RecType tmp = R[i];;
        
        while (i < j) {
            
            if (i < j && tmp.Key <= R[j].Key) {
                j--;
            }
            
            R[i] = R[j];
            
            if (i < j && tmp.Key >= R[i].Key) {
                i++;
            }
            
            R[j] = R[i];
            
        }
        
        R[i] = tmp;
        Q_Sort(R, s, i-1);//递归多次
        Q_Sort(R, i+1, t);//递归多次

    }
}




int main(int argc, const char * argv[]) {
    
    RecType R[5];
    R[0].Key = 8;
    R[1].Key = 7;
    R[2].Key = 2;
    R[3].Key = 9;
    R[4].Key = 3;
    
    Q_Sort(R, 0, 4);
    int i;
    
    for (i = 0; i < 5; i++) {
        
        printf("%d  ",R[i].Key);
        
    }
    return 0;
}
