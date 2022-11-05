#include <stdio.h>

void check(int (*array)[8][20],int *num3,int *x1,int num1)
{
    for(int i = 0; i < num1-1; i++)
    {
        for(int j = 0; j < num3[i]; j++)
        {
            for(int k = i+1; k < num1; k++)
            {
                for(int t = 0; t < num3[k]; t++)
                {
                    if((*array)[i][j]==(*array)[k][t])
                    {
                        printf("%d and %d conflict on %d\n",x1[i],x1[k],(*array)[i][j]);
                    }
                }
            }
        }
    }
}

int main()
{
    int num1;
    int num2;
    int x1;
    int x2[8];
    int num3[8];
    int array[8][20];
    scanf(" %d", &num1);
    for (int i = 0; i <num1; i++)
    {
        scanf(" %d", &x1);
        scanf(" %d", &num2);
        x2[i] = x1;
        num3[i] = num2;
        for (int j = 0; j < num2; j++)
        {
            scanf(" %d", &array[i][j]);
        }
    }
    check(&array,&num3[0],&x2[0],num1);
}