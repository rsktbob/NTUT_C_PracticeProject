#include <stdio.h>

int main()
{
    int x1[6]={1,2,3,4,5,6};
    char x2[]={'a', 'b', 'c', 'd', 'e','t','\0'};
    char *x3;
    x2[0]='t';
    x3="sdojljuoghfustsadfanlt";
    x3="sdojljufmast";
    int **num1;
    int *num2[2]={&x1[0],&x1[0]};
    num1=&num2[0];
    for(int i=0; i<2;i++)
    {
        for(int j=0; j<6;j++)
        {
            printf("%d\n",num1[i][j]);
        }
    }
    int (*num3)[6];
    num3=&x1;
    for(int i=0; i<6;i++)
    {
        printf("%d\n",(*num3)[i]);
    }
    printf("%d\n",x1[0]);
    printf("%p\n",x3);
    x3=&x2[0];
    printf("%p\n",x3);
    x3[0]='r';
    x3="edmflwjft";
    printf("%p\n",x2);
    printf("%p\n",x3);
    printf("%s\n",x2);
    printf("%s\n",x3);
}