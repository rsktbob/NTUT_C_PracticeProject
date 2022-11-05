#include <stdio.h>
#include <stdlib.h>

int gcm(int num1,int num2)
{
    num1=abs(num1);
    num2=abs(num2);
    int num3;
    if(num1<num2)
    {
        while(num1!=0)
        {
            num3=num1;
            num1=num2%num1;
            num2=num3;
        }
    }
    else
    {
        while(num2!=0)
        {
            num3=num2;
            num2=num1%num2;
            num1=num3;
        }
    }
    return num3;
}

void aboutminutes(int *num1,int *num2)
{
    int key;
    key=gcm(*num1,*num2);
    *num1=*num1/key;
    *num2=*num2/key;
}

void calculate(int num1,int x1,int num2,int x2,int times,int *array,char key)
{
    int multiplie;
    int t1;
    int t2;
    multiplie=gcm(x1,x2);
    t1=x2/multiplie;
    t2=x1/multiplie;
    num1=num1*t1;
    num2=num2*t2;
    x1=x1*t1;
    x2=x2*t2;
    switch (key)
    {
        case '+': num1=num1+num2; break;
        case '-': num1=num1-num2; break;
        case '*': num1=num1*num2; x1=x1*x1; break;
        case '/': x1=num2; break;
    }
    if(x1<0)
    {
        x1=-x1;
        num1=-num1;
    }
    if(x2<0)
    {
        x2=-x2;
        num2=-num2;
    }
    aboutminutes(&num1,&x1);
    array[times]=num1;
    array[times+1]=x1;
}

void array_out(int *array,int times)
{
    for(int i=0;i<=times;i=i+2)
    {
        if(array[i]==-1 && array[i+1]==-1)
        {
            printf("ERROR\n");
        }
        else if(array[i]==0)
        {
            printf("%d\n",0);
        }
        else
        {
            if(abs(array[i])>=array[i+1])
            {
                if(abs(array[i])%array[i+1]>0)
                {
                    printf("%d(%d/%d)\n",array[i]/array[i+1],abs(array[i]%array[i+1]),array[i+1]);
                }
                else
                {
                    printf("%d\n",array[i]/array[i+1]);
                }
            }
            else
            {
                printf("%d/%d\n",array[i],array[i+1]);
            }
        }
    }
}

int main()
{
    int num1;
    int x1;
    int num2;
    int x2;
    int times=0;
    int array[80];
    char key;
    char x3;
    while(1)
    {
        scanf(" %d/%d", &num1, &x1);
        scanf(" %d/%d", &num2, &x2);
        scanf(" %c", &key);
        if(x1==0 || x2==0)
        {
            array[times]=-1;
            array[times+1]=-1;
        }
        else
        {
            calculate(num1,x1,num2,x2,times,&array[0],key);
        }
        scanf(" %c", &x3);
        if(x3=='n')
        {
            break;
        }
        times=times+2;
    }
    array_out(&array[0],times);
}