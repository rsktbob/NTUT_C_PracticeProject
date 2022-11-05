#include <stdio.h>
#include <stdlib.h>

int lcm(int x1,int x2)
{
    int multiple;
    x1=abs(x1); 
    x2=abs(x2);
    if (x1 == 0)
    {
        return 0;
    }
    if(x1 < x2)
    {
        while(x1!=0)
        {
            multiple=x1;
            x1=x2%x1;
            x2=multiple;
        }
    }
    else
    {
        while(x2!=0)
        {
            multiple=x2;
            x2=x1%x2;
            x1=multiple;
        }
    }
    return multiple;
}

void aboutminute(int *num1,int *multiple)
{
    int key;
    key=lcm(*num1,*multiple);
    *num1=*num1/key;
    *multiple=*multiple/key;
}

void calculate(int num1,int num2,int multiple,int times,char key,int *array)
{
    switch (key)
    {
        case '+': num1=num1+num2; break;
        case '-': num1=num1-num2; break;
        case '*': num1=num1*num2; multiple=multiple*multiple; break;
        case '/': 
            multiple=num2;
            if(multiple<0)
            {
                multiple=-multiple;
                num1=-num1;
                break;
            }
            else if(multiple==0)
            {
                multiple=-1;
                num1=-1;
            }
    }
    if(num1!=0)
    {
        aboutminute(&num1,&multiple);
    }
    array[times]=num1;
    array[times+1]=multiple;
}

void array_out(int *array,int times)
{
    for(int i=0;i<=times;i=i+2)
    {
        if(array[i]==-1 && array[i+1]==-1)
        {
            printf("ERROR\n");
        }
        else
        {
            if(array[i]==0)
            {
                printf("%d\n",0);
            }
            else
            {
                if(abs(array[i])>array[i+1] && abs(array[i])%array[i+1]!=0)
                {
                    printf("%d(%d/%d)\n",array[i]/array[i+1],abs(array[i])%array[i+1],array[i+1]);
                }
                else if(abs(array[i])%array[i+1]==0)
                {
                    printf("%d\n",array[i]/array[i+1]);
                }
                else if(abs(array[i])<array[i+1])
                {
                    printf("%d/%d\n",array[i],array[i+1]);
                }
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
    int multiple;
    int times=0;
    int array[80];
    char key;
    char x3;
    while(1)
    {
        scanf(" %d", &num1);
        scanf(" %d", &x1);
        scanf(" %d", &num2);
        scanf(" %d", &x2);
        scanf(" %c", &key);
        scanf(" %c", &x3);
        if(x1==0 || x2==0)
        {
            array[times]=-1;
            array[times+1]=-1;
        }
        else
        {
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
            multiple=lcm(x1,x2);
            multiple=(x1/multiple)*(x2/multiple)*multiple;
            num1=num1*(multiple/x1);
            num2=num2*(multiple/x2);
            calculate(num1,num2,multiple,times,key,&array[0]);
        }
        if(x3 == 'f')
        {
            break;
        }
        times=times+2;
    }
    array_out(&array[0],times);
}