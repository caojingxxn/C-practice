//
//  main.c
//  acm_13_贪心算法
//
//  Created by admin on 17/11/30.
//  Copyright © 2017年 Amon. All rights reserved.
//
//

#include <stdio.h>

long int k[1000000] = {0};

int main()
{
    long int n,i,d,count;
    
    
    while (scanf("%ld",&n) != EOF) {
        
        count = 0;
        for ( i = 0; i < n; i++) {
            scanf("%ld",&d);
            k[d]++;
        }
  
        
        for (i = 1; i < 1000000; i++) {
            if (k[i]%2 == 0) {
                count += k[i]/2;
            }
            
            else if (k[i]%2 == 1 && k[i+1]%2 == 1 && k[i+2] > 0) {
                
                count += (1 + k[i]/2 + k[i+1]/2 );
                k[i+2]--;
                i++;
                
            }
            else {
                count += (k[i]/2 + k[i+1]/2);
                i++;
            }
            
        }
        
        printf("%ld\n",count);
        for (i = 1; i < 1000000; i++) {
            k[i] = 0;
        }
        
    }
    return 0;
}//K



















//
//struct DNA {
//    long int start;
//    long int end;
//    int count;
//}DNA[1001];
//
//int main()
//{
//    int n,i,j;
//    struct DNA tmp;
//    
//    while ( (~scanf("%d",&n)) && n != 0) {
//        
//        for ( i = 0; i < n; i++) {
//            scanf("%ld %ld",&DNA[i].start,&DNA[i].end);
//            DNA[i].count = i+1;
//        }
//        
//        for ( i =0; i < n-1; i++) {
//            for (j = 0; j < n-i-1; j++) {
//                if (DNA[j].end > DNA[j+1].end) {
//                    
//                    tmp = DNA[j];
//                    DNA[j] = DNA[j+1];
//                    DNA[j+1] = tmp;
//                    
//                }
//            }
//        }
//        
//        long int END = DNA[0].end;
//        printf("%d",DNA[0].count);
//        
//        for (i = 1; i < n; i++) {
//            
//            if (END < DNA[i].start) {
//                
//                printf(" %d",DNA[i].count);
//        
//                END = DNA[i].end;
//                
//            }
//            
//        }
//        printf("\n");
//  
//    }
//    return 0;
//}//I
//
//340 500
//220 470
//100 300
//880 943
//525 556
//612 776




//
//#include <stdlib.h>
//#include <math.h>
//int main()
//{
//
//    int n,i;
//    int a[100000] = {0};
//
//    while (scanf("%d",&n) != EOF && n != 0) {
//
//        long long int sum = 0;
//        
//        for (i = 0; i < n; i++) {
//
//            scanf("%d",&a[i]);
//
//        }
//
//
//        for (i = 0; i < n; i++) {
//            
//            a[i+1] += a[i];
//            sum += (long long int)(abs(a[i]));
//       
//        }
//
//        printf("%lld\n",sum);
//
//    }
//
//    return 0;
//}//G
//
//
//
//

//int main()
//{
//    int n,i,j,tmp,count;
//    int a[100] = {0};
//    int flag = 0;
//    int flag1 = 0,flag2 = 0;
//    while (scanf("%d",&n) != EOF) {
//        flag = 0;
//        flag1 = 0;
//        flag2 = 0;
//        
//        for ( i = 0; i < n; i++) {
//            scanf("%d",&a[i]);
//            
//        }
//
//        
//        for (i = 0; i < n; i++) {
//            if (a[i] % 2 == 1) {
//                flag1++;
//            }
//        }
//        
//        for (i = 0; i < n; i++) {
//            if (a[i] != 0) {
//                flag2++;
//            }
//        }
//        
//        if ((flag1 == 1 && flag2 == 1 && n != 1) || (flag1 == 0)) {
//            printf("-1\n");
//            continue;
//
//        }
//       
//        
//        tmp = 10;
//        count = 0;
//        flag = 0;
//        for (i = 0; i < n; i++) {
//            if ( (a[i] % 2 == 1) && (a[i] < tmp) ) {
//                
//                tmp = a[i];
//                count = i;
//                flag = 1;
//            }
//        }
//        
//        
//        if (flag == 1) {
//           
//            a[count] = a[n-1];
//            a[n-1] = tmp;
//        
//        }
//        
//        for (i = 0; i < (n-2); i++) {
//            for (j = 0; j < (n-2-i); j++) {
//                if (a[j] < a[j+1]) {
//                    
//                    tmp = a[j];
//                    a[j] = a[j+1];
//                    a[j+1] = tmp;
//                   
//                }
//                
//                
//            }
//        }
//
//        for (i = 0; i < n; i++) {
//
//            printf("%d",a[i]);
//        }
//        printf("\n");
//    
//    }
//    
//    
//    return 0;
//}//J




//
//int main()
//{
//    int n,i,j,tmp;
//    int dps[30] = {0};
//    int hp[30] = {0};
//    while (scanf("%d",&n) != EOF) {
// 
//        for ( i = 0; i < n; i++) {
//            scanf("%d %d",&dps[i],&hp[i]);
//            
//        }
//
//        
//        for (i = 0; i < (n-1); i++) {
//            for (j = 0; j < (n-1-i); j++) {
//                if (dps[j]*hp[j+1] < dps[j+1]*hp[j]) {
//                    
//                    tmp = dps[j];
//                    dps[j] = dps[j+1];
//                    dps[j+1] = tmp;
//                    
//                    tmp = hp[j];
//                    hp[j] = hp[j+1];
//                    hp[j+1] = tmp;
//                    
//                }
//                
//                
//            }
//        }
//
//        long long int sum = 0;
//        int ret = hp[0];
//        
//        for ( i = 0; i < n; i++) {
//            sum += (long long int)(ret*dps[i]);
//            ret += hp[i+1];
//        }
//        
//        printf("%lld\n",sum);
//        
//    }
//    
//    
//    return 0;
//}//M




//
//
//int main()
//{
//    int a[1000000] = {0};
//    long int i;
//    
//    for (i = 0; i < 1000000; i++) {
//        
//        long int m = i,k = i;
//        
//        while (m) {
//            if (m%10 == 4) {
//                a[i] = 1;
//                break;
//            }
//            
//            m /= 10;
//            
//        }
//        
//        while (k) {
//            
//            if (k%100 == 62) {
//                a[i] = 1;
//                break;
//            }
//            
//            k /= 10;
//            
//        }
// 
//    }
//    
//    long int w,r;
//    
//    while (scanf("%ld %ld",&w,&r) != EOF && ( w != 0 || r != 0) ) {
//        long int count = 0;
//
//        for (i = w; i <= r; i++) {
//            if (a[i] == 0) {
//                count++;
//            }
//        }
//        
//        printf("%ld\n",count);
// 
//    }
//
//    return 0;
//}








//int main()
//{
//    int n,i;
//    int money;
//    
//    while (scanf("%d",&n) != EOF && n != 0) {
//        
//        int count = 0;
//        
//        for (i = 0; i < n; i++) {
//
//            scanf("%d",&money);
//            
//            while (money) {
//                count += money/100;
//                money %= 100;
//                
//                count += money/50;
//                money %= 50;
//                
//                count += money/10;
//                money %= 10;
//                
//                count += money/5;
//                money %= 5;
//                
//                count += money/2;
//                money %= 2;
//                
//                count += money/1;
//                money %= 1;
//            }
//            
//            
//        }
//        
//        
//        printf("%d\n",count);
// 
//        
//    }
//    
//    
//    return 0;
//}B











//struct _homework{
//    
//    int deadline;
//    int scorce;
//    
//};
//
//
//int main()
//{
//    struct _homework homew[1000];
//    struct _homework tmp;
//    int T,N;
//    int i,j,k;
//    int m;
//    
//    scanf("%d",&T);
//    
//    for (m = 0; m < T; m++) {
//        
//        ////////////////////////////////////////////////////////////////
//        scanf("%d",&N);
//        for (j = 0; j < N; j++)
//            scanf("%d",&homew[j].deadline);
//
//        for (j = 0; j < N; j++)
//            scanf("%d",&homew[j].scorce);
//        
//        for (j = 0; j < N-1; j++) {
//            for (k = 0; k < N-1-j; k++) {
//                if (homew[k].scorce < homew[k+1].scorce) {
//                    tmp = homew[k];
//                    homew[k] = homew[k+1];
//                    homew[k+1] = tmp;
//                    
//                }
//                
//                else if (homew[j].scorce == homew[j+1].scorce) {
//                    
//                    if (homew[j].deadline > homew[j+1].deadline) {
//                        
//                        tmp = homew[j];
//                        homew[j] = homew[j+1];
//                        homew[j+1] = tmp;
//                    }
//                }
//            }
//        }
//        
//
//        int a[1001] = {0};
//        
//        int sum = 0;
//        
//        for (i = 0; i < N; i++) {
//            
//            if ( a[homew[i].deadline] == 0 )
//                a[homew[i].deadline] = 1;
//            
//            else{
//                int flag = 0;
//                j = homew[i].deadline - 1;
//                for (; j >= 1; j--) {
//                        
//                    if (a[j] == 0)
//                    {
//                        a[j] = 1;
//                        flag = 1;
//                        break;
//                    }
//                    
//                }
//                if (flag == 0) {
//                    sum = sum + homew[i].scorce;
//                }
//                
//            }
//            
//        }
//
//        printf("%d\n",sum);
//  
//    }
//    
//    
//    
//    return 0;
//}H
//
//



















//
//int main()
//{
//    int n,s,i;
//    long long int sum = 0;
//    
//    int ret = 0;
//    
//    while (scanf("%d %d",&n,&s) != EOF) {
//        
//        int C[10000] = {0};
//        int Y[10000] = {0};
//        
//        for (i = 0; i < n; i++) {
//        
//            scanf("%d %d",&C[i],&Y[i]);
//            
//        }
//        
//        ret = C[0];
//        sum = ret*Y[0];
//        
//        for (i = 0; i < (n-1); i++) {
//            
//            if (C[i+1] > (ret+s) )
//                ret += s;
//            
//            else
//                ret = C[i+1];
//            
//            
//            sum += ret*Y[i+1];
//        }
//        
//        printf("%lld\n",sum);
//        
//    }
//    
//    return 0;
//}
//
//
//
//






//
//struct a
//{
//    double j;
//    double f;
//    double k;
//    
//};
//
//int main()
//{
//    int m,n,i,j;
//    struct a tmp;
//    struct a tr[10000];
//    
//    while (scanf("%d %d",&m,&n) != EOF && m != -1 && n != -1) {
//        
//        
//        for (i = 0; i < n; i++) {
//            
//            scanf("%lf %lf",&tr[i].j,&tr[i].f);
//            tr[i].k = tr[i].j/tr[i].f;
//        }
//        
//        for (i = 0; i < (n-1); i++) {
//            for (j = 0; j < (n-1-i); j++) {
//                if (tr[j].k < tr[j+1].k) {
//                    
//                    tmp = tr[j];
//                    tr[j] = tr[j+1];
//                    tr[j+1] = tmp;
//                    
//                }
//            }
//        }
//
//        double sum = 0;
//        
//        for (i = 0; i < n; i++) {
//            
//            
//            if ( (m - tr[i].f) > 0) {
//                
//                sum += tr[i].j;
//                m -= tr[i].f;
//                
//            }
//            
//            else{
//                
//                sum += ((double)m/tr[i].f)*tr[i].j;
//                break;
//            }
//            
//            
//        }
//        printf("%0.3f\n",sum);
//        
//    }
//
//    return 0;
//}//javabean catfood








//int main()
//{
//    int v,n,i,j;
//    int tmp;
//    
//    while (scanf("%d",&v) != EOF && v != 0) {
//        
//        scanf("%d",&n);
//        int sum = 0;
//        int price[100] = {0};
//        int volume[100] = {0};
//        
//        for (i = 0; i < n; i++) {
//            
//            scanf("%d %d",&price[i],&volume[i]);
//    
//        }
//        
//        for (i = 0; i < (n-1); i++) {
//            for (j = 0; j < (n-1-i); j++) {
//                if (price[j] < price[j+1]) {
//                    
//                    tmp = price[j];
//                    price[j] = price[j+1];
//                    price[j+1] = tmp;
//    
//                    tmp = volume[j];
//                    volume[j] = volume[j+1];
//                    volume[j+1] = tmp;
//                        
//                }
//            }
//        }
//        
//        
//        
//        for (i = 0; i < n; i++) {
//            
//            if ( (v-volume[i]) > 0) {
//                
//                sum += (price[i]*volume[i]);
//                v -=volume[i];
//                
//            }
//            
//            else{
//                
//                sum += (price[i]*v);
//                break;
//            }
//            
//            
//        }
//        printf("%d\n",sum);
//        
//        
//        
//    }
//    
//    
//    return 0;
//}






//
//int main(int argc, const char * argv[]) {
//    
//    int i,n,j;
//    
//    int tmp;
//    
//    while (scanf("%d",&n) != EOF && n != 0) {
//        
//        int count = 1;
//        int a[100] = {0};
//        int b[100] = {0};
//        for (i = 0; i < n; i++) {
//            
//            scanf("%d %d",&a[i],&b[i]);
//            
//        }
//        
//        for (i = 0; i < (n-1); i++) {
//            for (j = 0; j < (n-1-i); j++) {
//                if (b[j] > b[j+1]) {
//                    
//                    tmp = a[j];
//                    a[j] = a[j+1];
//                    a[j+1] = tmp;
//                    
//                    tmp = b[j];
//                    b[j] = b[j+1];
//                    b[j+1] = tmp;
//                    
//                }
//            }
//        }
//        
//        i = 0;
//        
//        for (j = 1; j < n; j++) {
//            
//            if (a[j] >= b [i]){
//                i = j;
//                count++;
//            }
//        }
//        printf("%d\n",count);
//        
//    }
//    
//    return 0;
//    
//}

//12
//1 3
//3 4
//0 7
//3 8
//15 19
//15 20
//10 15
//8 18
//6 12
//5 10
//4 14
//2 9
//0
//


//1 3
//3 4
//0 7
//3 8
//2 9
//5 10
//6 12
//4 14
//10 15
//8 18
//15 19
//15 20



//int main(int argc, const char * argv[]) {
//    
//    printf("Hello World!");
//    return 0;
//}
