#include <stdio.h>
#include <stdlib.h>

int common_factor(int num1, int num2)
{
    int key;
    if(num1>=num2)
    {
        while(num2!=0)
        {
            key=num2;
            num2=num1%num2;
            num1=key;
        }
    }
    else if(num1<num2)
    {
        while(num1!=0)
        {
            key=num1;
            num1=num2%num1;
            num2=key;
        } 
    }
    key=abs(key);
    return key;
}

int common_multiple(int num1,int num2)
{
    int key;
    key=common_factor(num1, num2);
    key=(num1/key)*(num2/key)*key;
    return key;
}

void about_minutes(int *num1,int *num2)
{
    if(*num1!=0)
    {
        int key=common_factor(*num1,*num2);
        *num1=*num1/key;
        *num2=*num2/key;
    }
}

int commpute(int num1,int num2,int x1,int x2,int key,int multiple,int times,int *array)
{
    int t1;
    num1=num1*(multiple/num2); 
    x1=x1*(multiple/x2); 
    switch(key)
    {
        case '+': t1=num1+x1; break; 
        case '-': t1=num1-x1; break; 
        case '*': t1=num1*x1; multiple=multiple*multiple; break; 
        case '/': 
            if(x1<0)
            {
                t1=-num1; multiple=-x1;
            }
            else
            {
                t1=num1; multiple=x1; break;
            }
    }
    about_minutes(&t1,&multiple);
    array[times]=t1;
    array[times+1]=multiple;
}

int array_out(int num1,int num2)
{
    if(num1==-1 && num2==-1)
    {
        printf("ERROR");
        return 0;
    }
    else if(num1==0)
    {
        printf("%d",0);
        return 0;
    }
    int num3=num1/num2;
    num1=num1%num2;
    if(num1==0)
    {
        printf("%d",num3);
        return 0;
    }
    else if(num3==0)
    {
        printf("%d",num1);
        printf("/");
        printf("%d",num2);
        return 0;
    }
    else if(num3<0)
    {
        printf("%d",num3);
        printf("(");
        printf("%d",-num1);
        printf("/");
        printf("%d",num2);
        printf(")");
        return 0;
    }
    else if(num3>0)
    {
        printf("%d",num3);
        printf("(");
        printf("%d",num1);
        printf("/");
        printf("%d",num2);
        printf(")");
        return 0;
    }
}

int main()
{
    int num1;
    int num2;
    int x1;
    int x2;
    int multiple;
    int times=0;
    int array[26]={0};
    char key;
    char continuous='y';
    while(continuous=='y')
    {
        scanf(" %d/%d",&num1,&num2);
        scanf(" %d/%d",&x1,&x2);
        scanf(" %c",&key);
        if(num2!=0 && x2!=0)
        {
            multiple=common_multiple(num2,x2);
            commpute(num1,num2,x1,x2,key,multiple,times,&array[0]);
        }
        else
        {
            array[times]=-1;
            array[times+1]=-1;
        }
        scanf(" %c",&continuous);
        times=times+2;
    }
    for(int i=0;i<times;i=i+2)
    {
        array_out(array[i],array[i+1]);
        printf("\n");
    }
}