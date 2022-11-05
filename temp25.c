#include <stdio.h>
#include <string.h>

void load(char *x1,int *num1,int key1)
{
    int times=0;
    for(int i=80-key1;i<80;i++)
    {
        num1[i]=x1[times]-'0';
        times++;
    }
}

void init(int *num1)
{
    for(int i=0;i<80;i++) 
    {
        num1[i]=0;
    }
}

int get_bit(int *num1)
{
    int times=0;
    while(num1[times]==0)
    {
        times++;
    }
    times=80-times;
    return times;
}

void copy(int *num1,int *num2)
{
    for(int i=0;i<80;i++)
    {
        num1[i]=num2[i];
    }
}

int compare(int *num1,int*num2)
{
    int key=0;
    int times=79;
    for(int i=0;i<80;i++)
    {
        if(num1[i]!=num2[i])
        {
            times=i;
            break;
        }
    }
    if(num1[times]>num2[times] || (num1[times]==num2[times] && times==79))
    {
        key=1;
    }
    return key;
}

void shift(int *num1,int key)
{
    for(int i=0;i<80-key;i++)
    {
        num1[i]=num1[i+key];
    }
    for(int i=79;i>79-key;i--)
    {
        num1[i]=0;
    }
}

void add(int *num1,int *num2)
{
    int sum;
    int carry=0;
    for(int i=79;i>-1;i--)
    {
        sum=num1[i]+num2[i]+carry;
        carry=sum/10;
        sum=sum%10;
        num1[i]=sum;
    }
}

void sub(int *num1,int *num2)
{
    int times;
    for(int i=79;i>0;i--)
    {
        if(num1[i]<num2[i])
        {
            times=i-1;
            while(num1[times]==0)
            {
                num1[times]=9;
                times=times-1;
            }
            num1[times]=num1[times]-1;
            num1[i]=num1[i]+10;
        }
        num1[i]=num1[i]-num2[i];
    }
}

void mult(int *num1,int key)
{
    int num2[80]={0};
    copy(&num2[0],&num1[0]);
    if(key==0)
    {
        init(&num1[0]);
    }
    for(int i=0;i<key-1;i++)
    {
        add(&num1[0],&num2[0]);
    }
}


void divide(int *num1,int *num2,int *num3)
{
    int times=0;
    int key1=get_bit(&num1[0]);
    int key2=get_bit(&num2[0]);
    int array1[80]={0};
    int array2[80]={0};
    int key3=key1-key2;
    copy(&array1[0],&num2[0]);
    for(int i=key3;i>-1;i--)
    {
        copy(&num2[0],&array1[0]);
        shift(&num2[0],i);
        copy(&array2[0],&num2[0]);
        for(int j=0;j<11;j++)
        {
            copy(&num2[0],&array2[0]);
            mult(&num2[0],j);
            if(compare(&num1[0],&num2[0])==0)
            {            
                copy(&num2[0],&array2[0]);
                mult(&num2[0],j-1);
                sub(&num1[0],&num2[0]);
                num3[key3-i]=j-1;
                break;
            }
        }
    }
}

int main()
{
    char x1[80];
    char x2[80];
    int num1[80]={0};
    int num2[80]={0};
    int num3[20]={0};
    int key1;
    int key2;
    int times=0;
    scanf(" %s", x1);
    scanf(" %s", x2);
    key1=strlen(x1);
    key2=strlen(x2);
    load(&x1[0],&num1[0],key1);
    load(&x2[0],&num2[0],key2);
    divide(&num1[0],&num2[0],&num3[0]);
    while(num3[times]==0)
    {
        times++;
    }
    for(int i=times; i<key1-key2+1; i++)
    {
        printf("%d",num3[i]);
    }
}