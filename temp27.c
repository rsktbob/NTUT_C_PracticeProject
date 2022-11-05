#include <stdio.h>
#include <string.h>

void load(char *x1,int *num1,int key)
{
    int times=1;
    for(int i=79;i>79-key;i--)
    {
        num1[i]=x1[key-times]-'0';
        times++;
    }
}

void add(int *num1,int *num2)
{
    int sum;
    int carry=0;
    for(int i=79;i>-1;i--)
    {
        sum=num1[i]+num2[i]+carry;
        if(sum>=10)
        {
            carry=1;
            sum=sum-10;
        }
        else
        {
            carry=0;
        }
        num1[i]=sum;
    }
}

void sub(int *num1,int *num2)
{
    int difference;
    int borrow=0;
    for(int i=79;i>-1;i--)
    {
        difference=num1[i]-num2[i]-borrow;
        if(difference<0)
        {
            borrow=1;
            difference=difference+10;
        }
        else
        {
            borrow=0;
        }
        num1[i]=difference;
    }
}

void out_number(int *num1)
{
    int key;
    for(int i=0;i<80;i++)
    {
        if(num1[i]!=0)
        {
            key=i;
            break;
        }
    }
    for(int i=key;i<80;i++)
    {
        printf("%d",num1[i]);
    }
}

int main()
{
    char x1[80];
    char x2[80];
    int num1[80]={0};
    int num2[80]={0};
    scanf(" %s", x1);
    scanf(" %s", x2);
    int num1_length=strlen(x1);
    int num2_length=strlen(x2);
    load(&x1[0],&num1[0],num1_length);
    load(&x2[0],&num2[0],num2_length);
    sub(&num1[0],&num2[0]);
    out_number(&num1[0]);
}