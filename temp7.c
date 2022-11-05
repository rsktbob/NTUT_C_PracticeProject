#include <stdio.h>

int information(int **x1,int height,int widtht)
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<widtht;j++)
        {
            x1[i][j]=x1[i][j]*2;
            printf("%d\n",x1[i][j]);
        }
    }
}

int main()
{
    int course1,course2,course3;
    int x1[2][6]={{1,2,3,4,5,6},{3,2,3,4,5,6}};
    int *x2[2][3]={{&x1[0][0],&x1[1][0],&x1[0][0]},{&x1[1][0],&x1[0][0],&x1[0][0]}};
    int *x3;
    int *num1[2]={&x1[0],&x1[1]};
    int num2=3;
    int (*num3)[3];
    x3=num1[0];
    printf("%p\n",&x1[0][1]);
    printf("%p\n",&x3[1]);
    printf("%d\n",num1[0][2]);
    printf("%d\n",x1[0]);
    information(&num1[0],2,6);
}