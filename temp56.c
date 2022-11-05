#include <stdio.h>
#include <string.h>

typedef struct data_s {
    int x1[20];
} data_t;

int check_data(data_t k1, data_t k2,int num1)
{
    if(num1==0)
    {
        return 1;
    }
    for (int i = num1-1; i >= 0; i--)
    {
        if(k1.x1[i]!=k2.x1[i])
        {
            return 0;
        }
    }
    return 1;
}

void cmp_data(data_t *k1, data_t *k2,int num1)
{
    int key;
    for(int i=0; i<num1; i++)
    {
        key=k1->x1[i];
        k1->x1[i]=k2->x1[i];
        k2->x1[i]=key;
    }
}

void insert_sort(data_t *data,int num1,int num2)
{
    for(int i = 0; i < num2; i++)
    {
        for(int j = 1; j <= num1-1; j++)
        {
            for(int k = j; k > 0; k--)
            {
                if(data[k].x1[i] >= data[k-1].x1[i])
                {
                    break;
                }
                if(check_data(data[k], data[k-1],i)==1)
                {
                    cmp_data(&data[k],&data[k-1],num2);
                }
            }
        }
    }
}

void array_out(data_t *data,int num1,int num2)
{
    for(int i = 0;i < num1; i++)
    {
        for(int j=0; ; j++)
        {
            printf("%d",data[i].x1[j]);
            if(j==num2-1)
            {
                break;
            }
            printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    int num1;
    int num2;
    int num3;
    scanf("%d %d", &num1, &num2);
    data_t data[num1];
    for(int i = 0; i < num1; i++)
    {
        memset(data[i].x1,0,sizeof(data[i].x1));
    }
    for(int i = 0; i < num1; i++)
    {
        for(int j = 0; j < num2; j++)
        {
            scanf("%d", &data[i].x1[j]);      
        }
    }
    insert_sort(&data[0],num1,num2);
    array_out(&data[0],num1,num2);
}