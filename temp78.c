#include <stdio.h>
#include <string.h>
#include <math.h>

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
void add(char x1[])
{
    printf("%s\n", x1);
    for (int i = 0; i < 6; i++)
    {
        x1[i] = 't';
    }
}

int main() {
    int x1 = 3;
    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", i);
    }
}

