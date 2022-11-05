#include <stdio.h>
#include <string.h>

int power(int num1,int num2)
{
    if(num2==0)
    {
        return 1;
    }
    return power(num1,num2-1)*num1;
}

int check(char *num1,int num2)
{
    int key=0;
    for(int i=0;i<num2;i++)
    {
        if(num1[i]-'0'>1)
        {
            printf("ERROR");
            key=1;
            break;
        }
    }
    return key;
}

int decimal(char *num1,int num2)
{
    int sum=0;
    for(int i=0;i<num2;i++)
    {
        sum=sum+(num1[i]-'0')*power(2,num2-i-1);
    }
    return sum;
}

int heptad(int num1)
{
    int arrray[20]={0};
    int times=19;
    int x1;
    while(num1>=7)
    {
       x1=num1%7;
       arrray[times]=x1;
       num1=num1/7;
       times--;
    }
    arrray[times]=num1;
    for(int i=times;i<20;i++)
    {
        printf("%d",arrray[i]);
    }
}

int main()
{
    char num1[20];
    int num2;
    int key;
    int sum;
    scanf(" %s", &num1);
    num2=strlen(num1);
    key=check(&num1[0],num2);
    if(key==0)
    {
        sum=decimal(&num1[0],num2);
        heptad(sum);
    }
}