#include <stdio.h>
#include <math.h>

int circuit_get(int num1,int num2)  
{
    if(num1==1 || num1==0)
    {
        return num2;
    }
    else if(num1%2==1)
    {
        num1=num1+1;
        num1=num1/2;
        return circuit_get(num1,num2+1);
    }
    else if(num1%2==0)
    {
        num1=num1/2;
        return circuit_get(num1,num2+1);
    }
}

int circuit_sum(int num1,int num2) 
{
    for(int i=0;i<num1+1;i++)
    {
        num2=num2+circuit_get(i,0);
    }
    return num2;
}

long long power(int num1,int num2)
{
    long long num3=num1;
    if(num2==0)
    {
        return 1;
    }
    else if(num2==1)
    {
        return num1;
    }
    for(int i=0;i<num2-1;i++)
    {
        num3=num3*num1;
    }
    return num3;
}

int decimal(int num1)
{
    int num2;
    int num3=0;
    int key=0;
    if(num1==0)
    {
        return 0;
    }
    else if(num1==1)
    {
        return 1;
    }
    while(num1!=1)
    {
        num2=num1%10;
        num1=num1/10;
        num3=num3+num2*power(2,key);
        key++;
    }
    num3=num3+power(2,key);
    return num3;
}

long long binary(int num1)
{
    int num2;
    long long num3=0;
    int key=0;
    if(num1==0)
    {
        return 0;
    }
    else if(num1==1)
    {
        return 1;
    }
    while(num1!=1)
    {
        num2=num1%2;
        num1=num1/2;
        num3=num3+num2*power(10,key);
        key++;
    }
    num3=num3+power(10,key);
    return num3;
}

int main()
{
    long long num1;
    long long num2[18];
    int num3=0;
    int key=0;
    while(num3==0)
    {
        scanf(" %d",&num1);
        num2[key]=decimal(num1);    
        num2[key]=circuit_sum(num2[key],0);
        num2[key]=binary(num2[key]);
        scanf(" %d",&num3);
        key++;
    }
    for(int i=0;i<key;i++)
    {
        printf("%011lld\n",num2[i]);
    }
}