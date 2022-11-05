#include <stdio.h>

int main()
{
    int num1=3;
    int num2=18;
    int num3[6]={1,2,3,4,5,6};
    int *x1;
    int t1[6]={3,6,14,8,32,18};
    x1=&num3[0];
    int *x2;
    x2=&t1[0];
    int *x3[3]={x1,x2,x1};
    for(int i=0; i<6; i++)
    {
        printf("%d\n",x3[0][i]);
        printf("%d\n",x3[1][i]);
    }
}