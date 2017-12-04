//
//  main.c
//  归并排序
//
//  Created by admin on 17/11/20.
//  Copyright © 2017年 Amon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int InfoType;

typedef struct{
    
    KeyType Key;
    InfoType data;
    
}RecType;


void Merge(RecType R[], int low, int mid, int high)//二路归并
{
    int i = low,j = mid+1;
    RecType *R1;
    R1 = (RecType *)malloc((high-low+1)*sizeof(RecType));
    int k = 0;
    
    
    while (i <= mid && j <= high) {
        
        if (R[i].Key < R[j].Key) {
            R1[k] = R[i];
            i++,k++;
        }
        else{
            R1[k] = R[j];
            j++,k++;
        }
    }
    
    
    while (i <= mid) {
        R1[k] = R[i];
        i++,k++;
    }
    
    while (j <= high) {
        R1[k] = R[j];
        j++,k++;
    }
    
    i = low;
    k = 0;
    
    while ( i <= high ) {
        R[i] = R1[k];
        i++,k++;
    }
    
    free(R1);
    
}



void MergePass(RecType R[], int length, int n)//一趟二路归并
{
    int i = 0;
    
    while ( (i+2*length-1) < n ) {
        Merge(R, i, length+i-1, i+2*length-1);
        i += 2*length;
    }
    
    if ( i+length-1 < n-1 ) {
        Merge(R, i, length+i-1, n-1);
    }
    
}


void MergeSort(RecType R[],int n)//二路归并排序
{
    
    int length = 1;
    while (length < n) {
        
        MergePass(R, length, n);
        
        length *= 2;
    }
    
}



int main(int argc, const char * argv[]) {
    
    
    RecType R[5];
    R[0].Key = 8;
    R[1].Key = 7;
    R[2].Key = 2;
    R[3].Key = 9;
    R[4].Key = 3;
    
    MergeSort(R, 5);
    int i;
    
    for (i = 0; i < 5; i++) {
        
        printf("%d  ",R[i].Key);
        
    }
    
    return 0;
}
