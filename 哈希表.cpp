//
//  main.cpp
//  哈希表
//
//  Created by admin on 17/11/12.
//  Copyright © 2017年 Amon. All rights reserved.
//
//编写一个程序实现哈希表的相关运算，并完成以下功能：
//1.建立关键字序列（16，74，60，43，54，90，46，31，29，88，77）对应的哈希表A[0...12]，哈希函数为h(k)=k%p，并采用开放地址法中的线性探测法解决冲突
//2.在上述哈希表中查找关键字为29的记录
//3.在上述哈希表中删除关键字为77的记录
//


#include <iostream>

typedef int ElemType;
typedef int KeyType;

typedef struct
{
    KeyType key;

}HashTable[13];

void InsertHash(HashTable Ha,KeyType k,int p)//插入关键字
{
    int adr;
    adr = k % p;
    
    if (Ha[adr].key == -1) {
        Ha[adr].key = k;
    }
    
    else{
        do {
            adr = (adr + 1) % p;
            
        }while (Ha[adr].key != -1);
        
        Ha[adr].key = k;
        
    }
    
}


void CreateHash(HashTable Ha,int A[],int n,int p)//建立哈希表
{
    int i = 0;
    
    for (i = 0; i < p; i++) {
        Ha[i].key = -1;
    }
    for (i = 0; i < n; i++) {
        
        InsertHash(Ha, A[i], p);
    }
    
    
}



int SearchHash(HashTable Ha,KeyType k,int p)//查找关键字k
{
    int adr = k % p;
    
    while ( (Ha[adr].key != -1) && (Ha[adr].key != k) ) {

        adr = (adr + 1) % p;
        
    }
    
    if (Ha[adr].key == k) {
        return adr;
    }
    
    else
        return -1;
}


void deletek(HashTable Ha,KeyType k,int p)//删除关键字为k的记录
{
    int adr = SearchHash(Ha, k, p);
  
    if (Ha[adr].key != -1) {
        Ha[adr].key = -1;
    }
}




int main(int argc, const char * argv[]) {
    
    int a[] = {16,74,60,43,54,90,46,31,29,88,77};
    HashTable Ha;

    CreateHash(Ha,a, 11 ,13);
    int m = SearchHash(Ha, 29 ,13);
    printf("%d\n",m);

    deletek(Ha, 77, 13);
    printf("%d\n",Ha[0].key);
    
    
    
    return 0;
}




