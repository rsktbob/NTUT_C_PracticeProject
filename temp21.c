#include <stdio.h>

int judge_correct(int *x1,int *x2)
{
    int num1=0;
    int num2=0;
    int key=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(x2[i]==x1[j])
            {
                num2++;
                break;
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        if(x1[i]==x2[i])
        {
            num1++;
        }
    }
    num2=num2-num1;
    if(num1==4)
    {
        key=1;
        return key;
    }
    printf("%dA%dB\n",num1,num2);
    return key;
}

int main()
{
    int num1;
    int num2;
    int x1[4]={0};
    int x2[4]={0};
    int key;
    scanf("%d",&num1);
    for (int i=0;i<4;i++)
    {
        key=num1%10;
        num1=num1/10;
        x1[i]=key;
    }
    for(int i=0;i<6;i++)
    {
        scanf("%d",&num1);
        for (int i=0;i<4;i++)
        {
            key=num1%10;
            num1=num1/10;
            x2[i]=key;
        }
        key=judge_correct(&x1[0],&x2[0]);
        if(key==1)
        {
            printf("win");
            break;
        }
    }
}