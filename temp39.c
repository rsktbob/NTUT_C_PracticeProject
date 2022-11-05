#include <stdio.h>
#include <string.h>

void init(int *num1)
{
    for (int i = 0; i < 80; i++)
    {
        num1[i]=0;
    }
}

void load(int *num1,char *x1,int t1)
{
    int times=t1-1;
    for(int i=79;i>79-t1;i--)
    {
        num1[i]=x1[times]-'0';
        times--;
    }
}

void copy(int *num1, int *num2)
{
    for (int i = 0; i < 80; i++)
    {
        num1[i]=num2[i];
    }
}

void shift(int *num1,int k1)
{
    int num2[80]={0};
    if(k1>=0)
    {
        for(int i = 0; i < 80-k1; i++)
        {
            num2[i]=num1[i+k1];
        }
    }
    else
    {
        for(int i=79;i>-1-k1;i--)
        {
            num2[i]=num1[i+k1];
        }
    }
    copy(&num1[0],&num2[0]);
}

int judge(int *num1, int *num2)
{
    for(int i=0; i < 80; i++)
    {
        if(num1[i]>num2[i] || (i==79 && num1[i]==num2[i]))
        {
            return 1;
        }
        if(num1[i]<num2[i])
        {
            return 0;
        }
    }
}

void array_out(int *num1)
{
    int times=0;
    while(num1[times]==0)
    {
        times++;
    }
    for(int i=times;i<80;i++)
    {
        printf("%d",num1[i]);
    }
}

void add(int *num1, int *num2)
{
    int sum;
    int carry=0;
    for(int i=79;i>-1;i--)
    {
        sum=num1[i]+num2[i]+carry;
        carry=0;
        if(sum>=10)
        {
            sum=sum-10;
            carry=1;
        }
        num1[i]=sum;
    }
}

void sub(int *num1, int *num2)
{
    int difference;
    int borrow=0;
    for(int i=79;i>-1;i--)
    {
        difference=num1[i]-num2[i]-borrow;
        borrow=0;
        if(difference<0)
        {
            difference=difference+10;
            borrow=1;
        }
        num1[i]=difference;
    }
}

void mul(int *num1, int *num2,int t1)
{
    int times=0;
    int x1[80]={0};
    int x2[80]={0};
    for(int i=79;i>79-t1;i--)
    {
        for(int j=0;j<num2[i];j++)
        {
            add(&x1[0],&num1[0]);
        }
        shift(&x1[0],times);
        add(&x2[0],&x1[0]);
        init(&x1[0]);
        times++;
    }
    copy(&num1[0],&x2[0]);
}

void div(int *num1, int *num2,int t1,int t2)
{
    int t3=t1-t2;
    int x1[80]={0};
    shift(&num2[0],t3+1);
    for(int i=t3;i>=0;i--)
    {
        shift(&num2[0],-1);
        for(int j=1;j<10;j++)
        {
            if(judge(&num1[0],&num2[0])==1)
            {
                sub(&num1[0],&num2[0]);
                x1[79-i]=j;
            }
            else
            {
                break;
            }
        }
    }
    copy(&num1[0],&x1[0]);
}

int main()
{
    char x1[80]={};
    char x2[80]={};
    int num1[80]={0};
    int num2[80]={0};
    int t1;
    int t2;
    char key;
    scanf(" %s",x1);
    scanf(" %s",x2);
    scanf(" %c",&key);
    t1=strlen(x1);
    t2=strlen(x2);
    load(&num1[0],&x1[0],t1);
    load(&num2[0],&x2[0],t2);
    if(key=='+')
    {
        add(&num1[0],&num2[0]);
    }
    else if(key=='-')
    {
        sub(&num1[0],&num2[0]);
    }
    else if(key=='*')
    {
        mul(&num1[0],&num2[0],t2);
    }
    else if(key=='/')
    {
        div(&num1[0],&num2[0],t1,t2);
    }
    array_out(&num1[0]);
}