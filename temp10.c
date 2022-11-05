#include <stdio.h>

int main()
{
    int seconds[5]={0,0,0,0,0};
    float consume[3]={0,0,0};
    int key;
    float rentConsume[3][5]={{0.08 ,0.1393 ,0.1349 ,1.1287 ,1.4803},{0.07 ,0.1304  ,0.1217 ,1.1127 ,1.2458},{0.06 ,0.1087 ,0.1018 ,0.9572 ,1.1243}};
    for(int i = 0; i < 5; i++)
    {
        scanf(" %d", &key);
        seconds[i]=key;
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            consume[i]=consume[i]+seconds[j]*rentConsume[i][j];
        }
    }
    if(consume[0]<183)
    {
        consume[0]=183;
    }
    if(consume[1]<383)
    {
        consume[1]=383;
    }
    if(consume[2]<983)
    {
        consume[2]=983;
    }
    float min=consume[0];
    key=0;
    for(int i = 1; i < 3; i++)
    {
        if(min>consume[i])
        {
            min=consume[i];
            key=i;
        }
    }
    if(key==0)
    {
        printf("%d\n",183);
    }
    else if(key==1)
    {
        printf("%d\n",383);
    }
    else if(key==2)
    {
        printf("%d\n",983);
    }
}