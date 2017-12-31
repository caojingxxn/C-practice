#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define FOOD " 💗 "
#define SIZE 0.04
#define TIME 100000

void SetPos(int x, int y) {
    printf("\033[%d;%dH", y, x);
    printf("\033[0m");
}

void printlove() {
    double x = 0;
    double y1 = 0;
    double y2 = 0;
    SetPos (30,25);
    printf(FOOD);
    SetPos (29,13);
    printf(FOOD);
    x += SIZE;
    while ( x <= 1 ) {
        y1= sqrt(1-pow(x,2))+pow(x,(double)2/3);
        SetPos (x*20+29,-y1*6+20);
        printf(FOOD);
        SetPos (-x*20+30,-y1*6+20);
        printf(FOOD);
        y2= -sqrt(1-pow(x,2))+pow(x,(double)2/3);
        SetPos (x*20+29,-y2*6+20);
        printf(FOOD);
        SetPos (-x*20+30,-y2*6+20);
        printf(FOOD);
        usleep(TIME);
        x += SIZE;
        fflush(stdout);
  	}
    //下面的几句可以省略...为了好看所以又写了几句
  	SetPos (x*20+29,-y1*6+21);
  	printf(FOOD);
  	SetPos (-x*20+30,-y1*6+21);
  	printf(FOOD);
    usleep(TIME);
    fflush(stdout);
    
    SetPos (25,17);
    printf("元旦快乐啦");
    usleep(TIME);
    fflush(stdout);
    usleep(TIME*13);
    
}

int main() 
{
    system("clear");
    printlove();
    system("clear");
    SetPos (40,30);
    return 0;
}
