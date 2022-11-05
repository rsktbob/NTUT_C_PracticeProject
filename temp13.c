#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void init(int *x1)
{
    int num1=0;
    while(1)
    {
        if(x1[num1]==-1 || num1==25)
        {
            break;
        }
        x1[num1] = -1;
        num1++;
    }
}

void binary_array(int num1,int *x1)
{
    int num2;
    int key=0;
    while(1)
    {
        num2=num1%2;
        num1=num1/2;
        x1[key]=num2;
        key++;
        if(num1==0)
        {
            break;
        }
    }
}

int power(int num1,int num2)
{
    if(num2==0)
    {
        return 1;
    }
    return num1*power(num1,num2-1);
}

int decimal(int num1)
{
    int num2;
    int key=0;
    int count=0;
    while(1)
    {
        num2=num1%2;
        num1=num1/2;
        count=count+num2*power(10,key);
        key++;
        if(num1==0)
        {
            break;
        }
    }
    return count;
}

int gray(int *x1)
{
    int count=0;
    int key=0;
    while(1)
    {
        if(x1[key+1]==-1)
        {
            count=count+x1[key]*power(2,key);
            break;
        }
        count=count+(x1[key]^x1[key+1])*power(2,key);
        key++;
    }
    return count;
}

int main()
{
    int num1;
    int num2;
    int num3;
    int x1[26];
    int x2[26];
    int x3[26];
    int t1=0;
    int t2=0;
    while(t1==0)
    {
        scanf(" %d %d",&num1,&num2);
        init(&x1[0]);
        binary_array(num2,&x1[0]);
        num3=gray(&x1[0]);
        x2[t2]=num1;
        x3[t2]=num3;
        scanf(" %d",&t1);
        t2++;
    }
    num1=0;
    num2=0;
    for(int i=0 ;i<t2 ;i++)
    {
        num1=x3[i];
        num2=0;
        do
        {
            num1=num1/2;
            num2++;
        } while (num1!=0);
        for(int j=0 ;j<x2[i]-num2 ;j++)
        {
            printf("%d",0);
        }
        num2=decimal(x3[i]);
        printf("%d\n",num2);
    }
}