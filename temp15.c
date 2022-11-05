#include <stdio.h>
#include <stdlib.h>

const int x3=14;
int num1=6;

void f(int x1)
{
    num1=num1*2;
}

int main()
{
    int x1=18;
    int x2[]={1,2,3,4,5,6};
    int *num1;
    int (*num2)[6];
    num2=&x2;
    (*num2)[0]=3;
    (*num2)[1]=6;
    num1=malloc(sizeof(int)*148);
    printf("%p\n",num1);
    for(int i=0; i<148; i++)
    {
        num1[i]=i+1;
    }
    for(int i=0; i<148; i++)
    {
        printf("%p %d\n",num1[i],num1[i]);
    }
    for(int i=0; i<148; i++)
    {
        printf("%p %d\n",&num1[i],num1[i]);
    }
    for (int i=0; i<6; i++)
    {
        printf("%d\n",x2[i]);
        printf("%d\n",(*num2)[i]);
    }
}