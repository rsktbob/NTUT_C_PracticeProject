#include <stdio.h>
#include <string.h>

void init(char *x1)
{
    for(int i=0;i<30;i++)
    {
        x1[i]='a';
    }
}

int check(char *x1,char x2,int  num1)
{
    int key=1;
    for(int i=0;i<num1;i++)
    {
        if(x2==x1[i])
        {
            key=0;
            break;
        }
    }
    return key;
}

int get_length(int num1,int  num2,char *x1)
{
    char x2[30]={};
    int key;
    int times=0;
    for(int i=0;i<num2-num1+1;i++)
    {
        key=1;
        init(&x2[0]);
        for(int j=0;j<num1;j++)
        {
            if(check(&x2[0],x1[i+j],num1)==0)
            {
                key=0;
                break;
            }
            x2[j]=x1[i+j];
        }
        if(key==1)
        {
            times++;
        }
    }
    return times; 
}

int main()
{
    char x1[30]={};
    int num1;
    int num2;
    int times;
    scanf(" %s", x1);
    scanf(" %d",&num1);
    num2=strlen(x1);
    times=get_length(num1,num2,&x1[0]);
    printf("%d\n",times);
}