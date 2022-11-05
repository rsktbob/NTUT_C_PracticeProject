#include <stdio.h>
#include <string.h>

void init(int *t1)
{
    for(int i=0; i<80; i++)
    {
        t1[i]=0;
    }
}

void shift(int *t1, int num1)
{
    for(int i=0; i<79; i++)
    {
        t1[i]=t1[i+num1];
    }
    for(int i=79; i>79-num1; i--)
    {
        t1[i]=0;
    }
}

void add(int *t1,int *t2,int *t3)
{
    int sum;
    int carry=0;
    for(int i=79;i>-1;i--)
    {
        sum=t1[i]+t2[i]+carry;
        carry=sum/10;
        sum=sum%10;
        t3[i]=sum;
    }
}

int sub(int *t1,int *t2,int *t3,int num1,int num2)
{
    int times;
    int negation=0;
    if(num1<num2)
    {
        negation=1;
    }
    else if(num1==num2)
    {
        for(int i=80-num1;i<80;i++)
        {
            if(t1[i]<t2[i])
            {
                negation=1;
                break;
            }
        }
    }
    if(negation==0)
    {
        for(int i=79;i>-1;i--)
        {
            if(t1[i]<t2[i])
            {
                t1[i]=t1[i]+10;
                times=i-1;
                while(t1[times]==0)
                {
                    t1[times]=9;
                    times--;
                }
                t1[times]=t1[times]-1;
            }
            t3[i]=t1[i]-t2[i];
        }
    }
    else
    {
        for(int i=79;i>-1;i--)
        {
            if(t2[i]<t1[i])
            {
                t2[i]=t2[i]+10;
                times=i-1;
                while(t2[times]==0)
                {
                    t2[times]=9;
                    times--;
                }
                t2[times]=t2[times]-1;
            }
            t3[i]=t2[i]-t1[i];
        }
    }
    return negation;
}

void mult(int *t1, int *t2, int *t3,int *k1,int num1)
{
    int times=0;
    for(int i=79;i>79-num1;i--)
    {
        for(int j=0;j<t2[i];j++)
        {
            add(&k1[0],&t1[0],&k1[0]);
        }
        shift(&k1[0],times);
        add(&k1[0],&t3[0],&t3[0]);
        init(&k1[0]);
        times++;
    }
}

int compute(char *x1, char *x2,int key)
{
    int num1=strlen(x1);
    int num2=strlen(x2);
    int t1[80]={0};
    int t2[80]={0};
    int t3[80]={0};
    int k1[80]={0};
    int k2=80;
    int negation=0;
    int times=0;
    for (int i=num1-1; i>-1; i--)
    {
        k2--;
        t1[k2]=x1[i]-'0';
    }
    k2=80;
    for (int i=num2-1; i>-1; i--)
    {
        k2--;
        t2[k2]=x2[i]-'0';
    }
    if(key==1)
    {
        add(&t1[0],&t2[0],&t3[0]);
    }
    else if(key==2)
    {
        negation=sub(&t1[0],&t2[0],&t3[0],num1,num2);
    }
    else if(key==3)
    {
        mult(&t1[0],&t2[0],&t3[0],&k1[0],num2);
    }
    while(t3[times]==0)
    {
        times++;
        if(times==79)
        {
            break;
        }
    }
    if(negation==1)
    {
        printf("-");
    }
    for(int i=times;i<80;i++)
    {
        printf("%d",t3[i]);
    }
}
int main()
{
    char x1[80];
    char x2[80];
    int key;
    scanf(" %d", &key);
    scanf(" %s", x1);
    scanf(" %s", x2);
    compute(&x1[0],&x2[0],key);
}