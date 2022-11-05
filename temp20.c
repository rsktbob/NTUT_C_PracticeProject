#include <stdio.h>
#include <stdlib.h>

int greatest_common_fraction(int num1,int num2)
{
    if(num1==0)
    {
        return 1;
    }
    else
    {
        int key;
        if(num1>num2)
        {
            while(num2!=0)
            {
                key=num2;
                num2=num1%num2;
                num1=key;
            }
            return num1;
        }
        else if(num1==num2)
        {
            return num1;
        }
        else if(num1<num2)
        {
            while(num1!=0)
            {
                key=num1;
                num1=num2%num1;
                num2=key;
            }
            return num2;
        }
    }
}
void compute_slope_intercept(int x1, int x2, int y1, int y2, int *num1)
{
    int slope_num1=x2-y2;
    int slope_num2=x1-y1;
    int intercept_num1=(x2*slope_num2)-(x1*slope_num1);
    int intercept_num2=x1-y1;
    int common_fraction1=greatest_common_fraction(slope_num1,slope_num2);
    int common_fraction2=greatest_common_fraction(intercept_num1,slope_num2);
    slope_num1=slope_num1/common_fraction1;
    slope_num2=slope_num2/common_fraction1;
    intercept_num1=intercept_num1/common_fraction2;
    intercept_num2=intercept_num2/common_fraction2;  
    if(slope_num2<0)
    {
        slope_num1=-slope_num1;
        slope_num2=-slope_num2;
    }
    if(intercept_num2<0)
    {
        intercept_num1=-intercept_num1;
        intercept_num2=-intercept_num2;
    }
    num1[0]=slope_num1;
    num1[1]=slope_num2;
    num1[2]=intercept_num1;
    num1[3]=intercept_num2;
}

void compute(int *num1)
{
    int key=0;
    printf("y=");
    if(num1[0]!=0)
    {
        if(abs(num1[0])>=num1[1])
        {
            if(abs(num1[0])%num1[1]!=0)
            {
                key=1;
                printf("%d(%d/%d)x",num1[0]/num1[1],abs(num1[0]%num1[1]),num1[1]);
            }
            else
            {
                key=1;
                if(abs(num1[0])/num1[1]!=1)
                {
                    printf("%dx",num1[0]/num1[1]);
                }
                else
                {
                    if(num1[0]==1)
                    {
                        printf("x");
                    }
                    else if(num1[0]==-1)
                    {
                        printf("-x");
                    }
                }
            }
        }
        else
        {
            key=1;
            printf("%d/%dx",num1[0],num1[1]);
        }
    }
    if(key==1 && num1[2]>0)
    {
        printf("+");
    }
    if(num1[2]!=0)
    {
        if(abs(num1[2])>=num1[3])
        {
            if(abs(num1[2])%num1[3]!=0)
            {
                printf("%d(%d/%d)",num1[2]/num1[3],abs(num1[2]%num1[3]),num1[3]);
            }
            else
            {
                printf("%d",num1[2]/num1[3]);
            }
        }
        else
        {
            printf("%d/%d",num1[2],num1[3]);
        }
    }
    if(key==0 && num1[2]==0)
    {
        printf("%d",0);
    }
}

int main()
{
    int x1;
    int x2;
    int y1;
    int y2;
    int num1[4]={0};
    scanf(" %d,%d",&x1,&x2);
    scanf(" %d,%d",&y1,&y2);
    compute_slope_intercept(x1,x2,y1,y2,&num1[0]);
    compute(&num1[0]);
}