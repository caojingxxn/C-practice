//
//  main.cpp
//  二维数组中的查找
//
//  Created by admin on 17/10/29.
//  Copyright © 2017年 admin. All rights reserved.
//
//在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样一个二维数组和一个整数，判断数组中是否含有该整数。

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int a,b=0,i,j;
    
    scanf("%d,%d",&i,&j);
    int k[i][j];
    
    for (a=0; a<i; a++)
        for (b=0; b<j; b++)
            scanf("%d",&k[a][b]);
    
    for (a=0; a<i; a++)
        {
            for (b=0; b<j; b++)
                printf("%3d",k[a][b]);
            printf("\n");
        }
    
    int m;
    scanf("%d",&m);
    
 /*-------------------------------------------------------------------*/
 
    a=0;
    b=j-1;
    while (a<=i&&b>=0)
    {
        if (k[a][b]>m)
            b--;
        
        else if (k[a][b]<m)
            a++;
        
        else
        {
            printf("存在\n");
            return 1;
        }
    }
    printf("不存在\n");
    return 0;
}

