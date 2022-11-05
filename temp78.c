#include <stdio.h>
#include <string.h>

typedef struct student_s {
    int data;
    char name[8];
    double centimeter;
} student_t;

int fib(int num1,int num2[]) {
    if(num2[num1]) {
        return num2[num1];
    }
    else if(num2[num1-1] && num2[num1-2]){
        num2[num1]=num2[num1-1]+num2[num1-2];
    }
    return fib(num1-1,num2)+fib(num1-2,num2);
}

int main() {
    student_t x1;
    int num1[6][6];
    memset(num1,0,sizeof(num1));
    num1[0][1] = 1;
    num1[1][0] = 1;
    num1[1][2] = 1;
    num1[2][1] = 1;
    num1[3][0] = 1;
    num1[0][3] = 1;
    num1[4][5] = 1;
    num1[5][4] = 1;
    num1[3][5] = 1;
    num1[5][3] = 1;
}
