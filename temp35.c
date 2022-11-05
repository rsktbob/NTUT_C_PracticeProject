#include <stdio.h>

int main()
{
    int num1;
    int num2;
    scanf(" %d", &num1);
    scanf(" %d", &num2);
    if(num1==1)
    {
        for(int i=1; i<num2+1; i++)
        {
            for(int j=1; j<=i; j++)
            {
                printf("%d",j);
            }
            printf("\n");
        }
        for(int i=num2-1; i>0;i--)
        {
            for(int j=1; j<=i;j++)
            {
                printf("%d",j);
            }
            printf("\n");
        }
    }
    else if(num1==2)
    {
        for(int i=1; i<num2+1; i++)
        {
            for(int j=0; j<num2-i;j++)
            {
                printf(" ");
            }
            for(int j=1; j<=i; j++)
            {
                printf("%d",j);
            }
            printf("\n");
        }
        for(int i=num2-1; i>0;i--)
        {
            for(int j=0; j<num2-i;j++)
            {
                printf(" ");
            }
            for(int j=1; j<=i;j++)
            {
                printf("%d",j);
            }
            printf("\n");
        }
    }
    else if(num1==3)
    {
        for(int i=1; i<num2+1; i++)
        {
            for(int j=0; j<num2-i;j++)
            {
                printf(" ");
            }
            for(int j=1; j<=i; j++)
            {
                printf("%d",j);
            }
            for(int j=i-1; j>0; j--)
            {
                printf("%d",j);
            }
            printf("\n");
        }
        for(int i=num2-1; i>0;i--)
        {
            for(int j=0; j<num2-i;j++)
            {
                printf(" ");
            }
            for(int j=1; j<=i;j++)
            {
                printf("%d",j);
            }
            for(int j=i-1; j>0; j--)
            {
                printf("%d",j);
            }
            printf("\n");
        }
    }
}
