//
//  main.c
//  14周ACM
//
//  Created by admin on 17/12/6.
//  Copyright © 2017年 Amon. All rights reserved.
//

#include <stdio.h>


int main ()
{
    int n,i,k;
    int a[1001],b[1001];
    
    while (~scanf("%d",&n)) {
        
        for (i = 0; i < n; i++) {
            int j = 0;
            int count = 0;
            while(~scanf("%d",&k))
            {
                a[j] = k;
                j++;
                if (k == ' ') {
                    count = j;
                }
            }
            
            j = 0;
            while (<#condition#>) {
                <#statements#>
            }
            
            
            
            
            
          
            
        }
            
    }
        
        
        
        
        
    
        for (i = 0; i < 1000; i++) {
            printf("%d",a[i]);
            if (a[i] == ' ') {
                break;
            }
        }
        
        for (i = 0; i < 1000; i++) {
            printf("%d",a[i]);
            if (b[i] == ' ') {
                break;
            }
        }
    }
    
    
    
    return 0;
}//B大数相加










///*
// 
//1 1*3 1
//2 2*3 12/13
//3 2*3 123/132
//4 3*2*3 1212/1213/1232
//5 4*2*3  12123/12132/12312/12323/
//*/
//int main ()
//{
//    
//    
//    3*2*2*2....*2*1
//    3*2*2*2*1
//    3*2*2*1
//
//    
//    
//    return 0;
//    
//}//P














//1 1 1
//2 2 1(母)+1(2)
//3 3 1(母)+1(2)+1(3)
//4 4 1(母)+1(2)+1(3)+1(4)
//5 6 1(母)+1(母)+1(3)+1(4)+2(5)
//6 9 1(母)+1(母)+1(母)+1(4)+2(5)+3(6)
//7 13 1(母)+1(母)+1(母)+1(母)+2(5)+3(6)+4(7)
//8 19 1(母)+1(母)+1(母)+1(母)+2(母)+3(6)+4(7)+6(8)
//
//long long int k[56] = {0,1,2,3,4};
//
//long long int CountCow(int m)
//{
//
//    if (k[m] == 0) {
//        k[m] = CountCow(m-1) + CountCow(m-3);
//    }
//    return k[m];
//    
//}
//
//int main ()
//{
//    int n;
//    CountCow(55);
//    while ( ~scanf("%d",&n) && n != 0) {
//
//
//        printf("%lld\n",k[n]);
//
//
//    }
//    return 0;
//
//
//}//S
//



//
//long long int k[51] = {0,1,2,3};
//
//long long int Count (int m)
//{
//    if (k[m] == 0) {
//        k[m] = Count(m-1)+Count(m-2);
//    }
//    return k[m];
//}
//
//int main ()
//{
//    int n;
//    Count(50);
//
//    while ( scanf("%d",&n) != EOF && n != 0) {
//
//        printf("%lld\n",k[n]);
//        
//
//    }
//    return 0;
//
//}//Q



//
//long long int k[51] = {0,1,2};
//
//long long int Count (int m)
//{
//    
//    if (k[m] == 0) {
//        k[m] = Count(m-1)+Count(m-2);
//    }
//    return k[m];
//}
//
//int main ()
//{
//    int n,i,a,b;
//    Count(50);
//    
//    while ( ~scanf("%d",&n) && n != 0) {
//        
//        for (i = 0; i < n; i++) {
//            scanf("%d %d",&a,&b);
//            printf("%lld\n",k[b-a]);
//            
//        }
//        
//    }
//    return 0;
//    
//}//O






//int a[41] = {0,1,1};
//
//int Count (int k)
//{
//    if (k <= 2) {
//        return 1;
//    }
//    if (a[k] == 0) {
//        a[k] = Count(k-1)+Count(k-2);
//    }
//    return a[k];
//}
//
//int main ()
//{
//    int n,j,i;
//    
//    Count(40);
//    
//    while ( ~scanf("%d",&n) && n != 0) {
//    
//        for (i = 0; i < n; i++) {
//            
//            scanf("%d",&j);
//            printf("%d\n",a[j]);
//            
//        }
//      
//    }
//    return 0;
//    
//}//N









//int Count_Peach (int day)
//{
//    if (day-1) {
//        return 2*(Count_Peach(day-1)+1);
//    }
//    else
//        return 1;
//}
//
//
//
//int main()
//{
//    
//    int n;
//    while ( ~scanf("%d",&n) && n != 0) {
//        
//            printf("%d\n",Count_Peach(n));
//    }
//    
//    
//    return 0;
//}//M






//int k;
//
//int Count(int count)
//{
//    if (count) {
//        return 2*(Count(count-1)-1);
//    }
//    else
//        return 3;
//}
//
//int main ()
//{
//    int n,i;
//    while ( ~scanf("%d",&n) && n != 0) {
//        
//        int a[31] = {0};
//        
//        for (i = 0; i < n; i++) {
//            scanf("%d",&a[i]);
//            
//            printf("%d\n",Count(a[i]));
//        }
//
//        
//        
//    }
//    return 0;
//    
//    
//}//R







//int main(int argc, const char * argv[]) {
//    
//    printf("Hello World!");
//    return 0;
//}
