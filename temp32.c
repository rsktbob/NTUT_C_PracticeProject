#include <stdio.h>

int main()
{
    int num1;
    scanf(" %d",&num1);
    for(int i=1; i<(num1+1)/2+1; i++)
    {
        for(int j=1; j<i+1; j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }
    for(int i=num1/2; i>0;i--)
    {
        for(int j=1; j<i+1; j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }
}