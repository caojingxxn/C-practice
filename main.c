//
//  main.c
//  ACM_day1_结构体+sort
//
//  Created by admin on 18/1/19.
//  Copyright © 2018年 Amon. All rights reserved.
//
//
//

#include <stdio.h>


//B
//int main(int argc, const char * argv[]) {
//
//    int T;
//    scanf("%d",&T);
//    int i = 1;
//    for ( ; i <= T; i++) {
//        int N;
//        scanf("%d", &N);
//        int j = 0;
//        int a[1001] = {0};
//        for ( ; j < N; j++) {
//            scanf("%d", &a[j]);
//        }
//        for (j = 0; j < N; j++) {
//            int k = 0;
//            for ( ; k < N-j-1; k++) {
//                if (a[k] > a[k+1]) {
//                    int tmp = a[k];
//                    a[k] = a[k+1];
//                    a[k+1] = tmp;
//                }
//            }
//        }
//        
//        for (j = 0; j < N-1; j++) {
//            printf("%d ", a[j]);
//        }
//        printf("%d\n",a[j]);
//    }
//}



//205543 A
//
//鸽巢原理：有N个苹果，N+1个抽屉，无论怎样放，总有一个抽屉里至少有两个苹果

//#include <stdio.h>
//
//int main(int argc, const char * argv[]) {
//    int N;
//    while ( scanf("%d",&N) != EOF ) {
//        int spec_n = 0;//记录栈底数
//        int appear = 0;//记录栈中数量
//        int n;//记录每次手动输入的数
//        while (N--) {
//            scanf("%d", &n);
//            if (appear == 0) {//相当于栈空，直接入栈
//                appear = 1;//记录当前栈中有多少个数
//                spec_n = n;//记录栈底的数
//            }
//            else {//此时栈中一定有数
//                if (n != spec_n) {
//                    appear--;
//                }
//                else {//此次读到的数与栈底的数相同
//                    appear++;
//                }
//            }
//        }
//        printf("%d\n", spec_n);//最后在栈底的数
//    }
//}
//

//#include <stdio.h>
//
//int main(int argc, const char * argv[]) {
//
//    int N;
//    while ( scanf("%d",&N) != EOF ) {
//        int a[32768] = {0};
//        int i = 0;
//        int r = 0;
//        for (; i < N; i++) {
//            int n;
//            scanf("%d", &n);
//            if (a[n] >= N/2) {
//                r = n;
//            }
//                a[n]++;
//        }
//        printf("%d\n", r);
//    }
//}

//
//#include <stdio.h>
//#include <stdlib.h>
//
//int a[1000000];
//
//int cmp(const void* a, const void* b) {
//    return ( *(int *)a - *(int *)b );
//}
//
//int main(int argc, const char * argv[]) {
//    
//    int N;
//    while ( scanf("%d",&N) != EOF ) {
//        int i = 0;
//        for ( ; i < N; i++) {
//            scanf("%d", &a[i]);
//        }
//        qsort(a, N, sizeof(int), cmp);
//        
//        printf("%d\n",a[N/2]);
//    }
//    return 0;
//}
