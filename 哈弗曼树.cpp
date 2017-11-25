//
//  main.cpp
//  哈弗曼树
//
//  Created by admin on 17/11/2.
//  Copyright © 2017年 admin. All rights reserved.
//

#include <iostream>

typedef struct
{
    char data;
    double weight;
    int parent;
    int lchild;
    int rchild;
    
}HTNode;



void CreateHT(HTNode ht[],int n0)//创建哈弗曼树
{
    
    int i,k,lnode,rnode;
    double min1,min2;
    
    for (i = 0; i < 2*n0-1; i++)
    {
        ht[i].parent = ht[i].lchild = ht[i].rchild =-1;
        
    }
    
    for (i = n0; i < n0-2; i++)
    {
        min1 = min2 =32767;
        lnode =rnode =-1;
        for (k = 0; k <= i-1; k++)
        {
            if (ht[k].parent == -1)
            {
                if (ht[k].weight < min1)
                {
                    min2 = min1;
                    rnode = lnode;
                    min1 = ht[k].weight;
                    lnode =k;
                }
                else if(ht[k].weight < min2)
                {
                    min2 =ht[k].weight;
                    rnode = k;
                }
                
            }
        }
        
                ht[i].weight = ht[lnode].weight+ht[rnode].weight;
                ht[i].lchild = lnode;
                ht[i].rchild = rnode;
                ht[lnode].parent = i;
                ht[rnode].parent = i;
        
    }
    
}



int main(int argc, const char * argv[]) {
    
    
    
    
    
    return 0;
}
