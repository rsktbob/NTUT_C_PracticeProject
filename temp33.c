#include <stdio.h>

int main()
{
    int num1;
    scanf(" %d", &num1);
    for(int i=0; i<num1; i++)
    {
        for(int j=1; j<i+2; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }
    for(int i=num1-1; i>0; i--)
    {
        for(int j=1; j<i+1; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }
}