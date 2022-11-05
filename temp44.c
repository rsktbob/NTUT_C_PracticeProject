#include <stdio.h>

void xor(int *num1,int *num2)
{
    for(int i=0;i<4;i++)
    {
        if(num1[i]==num2[i])
            num1[i]=0;
        else
            num1[i]=1;
    }
}

void binary(int *num1,int num2)
{
    int times=3;
    while(num2!=0)
    {
        num1[times]=num2%2;
        num2=num2/2;
        times--;
    }
    for(int i=times;i>=0;i--)
    {
        num1[i]=0;
    }
}

int main()
{
    char x1[12]={};
    int num1[4]={0},num2[4]={0};
    scanf("%s", x1);
    for(int i=0;i<12;i++)
    {
        if(x1[i]=='1')
        {
            binary(&num1[0],i+1);
            xor(&num2[0],&num1[0]);
        }
    }
    for(int i=0;i<4;i++)
    {
        printf("%d",num2[i]);
    }
}