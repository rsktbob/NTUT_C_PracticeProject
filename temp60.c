#include <stdio.h>

void load(int *num1,char *x1,int *key1,int *c1)
{
    int t1;
    for(int i=0;x1[i]!='\0';i++)
    {
        t1=i;
    }
    for(int i=t1,k=159;i>=0;i--,k--)
    {
        if(x1[i]=='-')
        {
            *key1=1;
            break;
        }
        if(x1[i]=='.')
        {
            *c1=159-k;
            i--;
        }
        num1[k]=x1[i]-'0';
    }
}

int array_len(int *num1)
{
    int t1=1;
    for(int i=0;i<160;i++)
    {
        if(num1[i]!=0)
        {
            t1=160-i;
            break;
        }
    }
    return t1;
}

void shift(int *num1,int k1)
{
    int num2[160]={0};
    if(k1>0)
    {
        for(int i=0;i<160-k1;i++)
        {
            num2[i]=num1[i+k1];
        }
    }
    if(k1<0)
    {
        for(int i=159;i>=-k1;i--)
        {
            num2[i]=num1[i+k1];
        }
    }
    for(int i=0;i<160;i++)
    {
        num1[i]=num2[i];
    }
}

void align(int *num1,int *num2,int *c1,int *c2)
{
    printf("%d\n",*c1);
    printf("%d\n",*c2);
    if(*c1>*c2)
    {
        shift(&num2[0],*c1-*c2);
        *c2=*c1;
    }
    if(*c2>*c1)
    {
        shift(&num1[0],*c2-*c1);
        *c1=*c2;
    }
}

void add(int *num1,int *num2,int *k1)
{
    int sum;
    int carry=0;
    for(int i=159;i>=0;i--)
    {
        sum=num1[i]+num2[i]+carry;
        carry=0;
        if(sum>9)
        {
            sum=sum-10;
            carry=1;
        }
        k1[i]=sum;
    }
}

void sub(int *num1,int *num2,int *k1)
{
    int deffreence;
    int borrow=0;
    for(int i=159;i>=0;i--)
    {
        deffreence=num1[i]-num2[i]-borrow;
        borrow=0;
        if(deffreence<0)
        {
            deffreence=deffreence+10;
            borrow=1;
        }
        k1[i]=deffreence;
    }
}

void mul(int *num1,int *num2,int *k1)
{
    int t1=array_len(&num2[0]);
    for(int i=159;i>159-t1;i--)
    {
        for(int j=0;j<num2[i];j++)
        {
            add(&num1[0],&k1[0],&k1[0]);
        }
        shift(&num1[0],1);
    }
}

void array_out(int *k1,int c1)
{
    int key=160;
    for(int i=0;i<160;i++)
    {
        if(k1[i]!=0)
        {
            key=i;
            break;
        }
    }
    if(key==160)
    {
        printf("%d\n",0);
        return;
    }
    for(int i=159;i>159-c1;i--)
    {
        if(k1[i]!=0)
        {
            break;
        }
        k1[i]=-1;
    }
    for(int i=key;i<160;i++)
    {
        if(i==160-c1 && k1[i]!=-1)
        {
            printf(".");
        }
        if(k1[i]!=-1)
        {
            printf("%d",k1[i]);
        }
    }
    printf("\n");
}

int main()
{
    char x1[160]={};
    char x2[160]={};
    int num1[160]={0};
    int num2[160]={0};
    int k1[160]={0};
    int k2[160]={0};
    int k3[160]={0};
    int key1=0;
    int key2=0;
    int c1=0;
    int c2=0;
    scanf("%s",x1);
    scanf("%s",x2);
    load(&num1[0],&x1[0],&key1,&c1);
    load(&num2[0],&x2[0],&key2,&c2);
    align(&num1[0],&num2[0],&c1,&c2);
    add(&num1[0],&num2[0],&k1[0]);
    sub(&num1[0],&num2[0],&k2[0]);
    mul(&num1[0],&num2[0],&k3[0]);
    array_out(&k1[0],c1);
    array_out(&k2[0],c1);
    array_out(&k3[0],c1*2);
}
