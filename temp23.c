#include <stdio.h>
#include <string.h>

int main()
{
    char num1[8];
    char array[9][8]={};
    int times=0;
    while(times<9)
    {
        scanf(" %s",num1);
        for(int i=0; i<strlen(num1); i++)
        {
            array[times][i-1]=num1[i];
        }
        times++;
    }
    for(int i=0; i<9; i++)
    {
        printf("%s\n",array[i]);
    }
}

void add(int *t1,int *t2,int *t3,int size)
{
    int sum;
    int carry=0;
    for(int i=size;i>-1;i--)
    {
        sum=t1[i]+t2[i]+carry;
        carry=sum/10;
        sum=sum%10;
        t3[i]=sum;
    }
}
