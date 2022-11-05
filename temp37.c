#include <stdio.h>

int calculate(int *array)
{
    int x1[4]={0};
    int x2[2];
    int times=0;
    for(int i=0;i<4;i++)
    {
        if(array[0]==array[i])
        {
            x1[0]++;
        }
        if(array[1]==array[i])
        {
            x1[1]++;
        }
        if(array[2]==array[i])
        {
            x1[2]++;
        }
        if(array[3]==array[i])
        {
            x1[3]++;
        }
    }
    if(x1[0]==4 || x1[1]==4 || x1[2]==4 || x1[3]==4)
    {
        return 18;
    }
    else
    {
        if(x1[0]==2 || x1[1]==2 || x1[2]==2 || x1[3]==2)
        {
            if(x1[0]==2 && x1[1]==2 && x1[2]==2 && x1[3]==2)
            {
                x2[0]=array[0];
                for(int i=1;i<4;i++)
                {
                    if(x2[0]<array[i])
                    {
                        x2[0]=array[i];
                    }
                }
                return x2[0]+x2[0];
            }
            else
            {
                for(int i=0;i<4;i++)
                {
                    if(x1[i]==1)
                    {
                        x2[times]=array[i];
                        times++;
                    }
                }
                return x2[0]+x2[1];
            }
        }
        else
        {
            return 0;
        }
    }
}
void dice_lon(int num1,int *dice1)
{
    int x1[6]={0};
    for(int i=0;i<6;i++)
    {
        x1[i]=dice1[i];
    }
    if(num1==1)
    {
        dice1[0]=x1[2];
        dice1[1]=x1[3];
        dice1[2]=x1[1];
        dice1[3]=x1[0];
    }
    else if(num1==2)
    {
        dice1[0]=x1[3];
        dice1[1]=x1[2];
        dice1[2]=x1[0];
        dice1[3]=x1[1];
    }
    else if(num1==3)
    {
        dice1[0]=x1[4];
        dice1[1]=x1[5];
        dice1[4]=x1[1];
        dice1[5]=x1[0];
    }
    else if(num1==4)
    {
        dice1[0]=x1[5];
        dice1[1]=x1[4];
        dice1[4]=x1[0];
        dice1[5]=x1[1];
    }
}

int main()
{
    int times;
    int num1;
    int num2;
    int x1;
    int x2;
    int x3;
    int dice1[6]={1,6,4,3,5,2};
    int dice2[6]={1,6,4,3,5,2};
    int dice3[6]={1,6,4,3,5,2};
    int dice4[6]={1,6,4,3,5,2};
    int array[4]={0};
    scanf(" %d",&times);
    for(int i=0; i<times; i++)
    {
        scanf(" %d %d %d %d",&num1,&num2,&x1,&x2);
        dice_lon(num1,&dice1[0]);
        dice_lon(num2,&dice2[0]);
        dice_lon(x1,&dice3[0]);
        dice_lon(x2,&dice4[0]);
    }
    array[0]=dice1[0];
    array[1]=dice2[0];
    array[2]=dice3[0];
    array[3]=dice4[0];
    x3=calculate(&array[0]);
    printf("%d\n",x3);
}