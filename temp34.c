#include <stdio.h>

int main()
{
    int num1;
    int num2;
    scanf(" %d", &num1);
    scanf(" %d", &num2);
    int x1=num2/2+1;
    if(num1==1)
    {
        for(int i=0; i<x1; i++)
        {
            for(int j=0; j<i+1; j++)
            {
                printf("*");
            }
            printf("\n");
        }
         for(int i=x1-1; i>0; i--)
        {
            for(int j=0; j<i; j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    else if(num1==2)
    {
        for(int i=0; i<x1; i++)
        {
            for(int j=0; j<x1-i-1; j++)
            {
                printf(" ");
            }
            for(int j=i+1; j>0; j--)
            {
                printf("*");
            }
            printf("\n");
        }
        for(int i=x1-1; i>0; i--)
        {
            for(int j=0; j<x1-i; j++)
            {
                printf(" ");
            }
            for(int j=i; j>0; j--)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    else if(num1==3)
    {
        for(int i=0; i<x1; i++)
        {
            for(int j=0; j<x1-i-1;j++)
            {
                printf(" ");
            }
            printf("*");
            for(int j=0;j<i;j++)
            {
                printf("**");
            }
            printf("\n");
        }
        for(int i=x1-1; i>0;i--)
        {
            for(int j=0; j<x1-i;j++)
            {
                printf(" ");
            }
            printf("*");
            for(int j=0;j<i-1;j++)
            {
                printf("**");
            }
            printf("\n");
        }
    }
}