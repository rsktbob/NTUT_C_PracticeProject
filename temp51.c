#include<stdio.h>

void init(int *e,int num1)
{
    for(int i=0; i<num1; i++)
    {
        e[i]=0;
    }
}

void init_2d(int (*e)[180][20])
{
    for(int i=0; i<180; i++)
    {
        for(int j=0; j<20; j++)
        {
            (*e)[i][j]=0;
        }
    }
}

int check_array(int *e)
{
    for(int i=0;i<180;i++)
    {
        if(e[i]!=0)
        {
            return 1;
        }
    }
    return 0;
}

int delete_array(int (*e)[180][20],int num1)
{
    for(int i=0; i<180; i++)
    {
        for(int j=0; j<20; j++)
        {
            if((*e)[i][j]==num1)
            {
                (*e)[i][j]=0;
            }
        }
    }
}

int main()
{
    int p;
    int q;
    int x1[20]={0};
    int x2[20]={0};
    int times=0;
    struct data
    {
        int t[180];
        int e[180][20];
    } work;
    init(&work.t[0],180);
    init_2d(&work.e);
    scanf(" %d", &p);
    for(int i=0;i<p;i++)
    {
        scanf(" %d", &q);
        for(int j=0;j<q;j++)
        {
            init(&x1[0],20);
            times=0;
            do
            {
                scanf("%d", &x1[times]);
                times++;
            }while(getchar()!='\n');
            work.t[j]=x1[0];
            for(int k=2;k<2+x1[1];k++)
            {
                work.e[j][k-2]=x1[k];
            }
        }
        while(check_array(&work.t[0])!=0)
        {
            x2[i]++;
            for(int k=0;k<q;k++)
            {
                if(check_array(&work.e[k][0])==0 && work.t[k]>0)
                {
                    work.t[k]--;
                    if(work.t[k]==0)
                    {
                        delete_array(&work.e,k+1);
                    }
                }
            }
        }
        init(&work.t[0],180);
        init_2d(&work.e);
    }
    for(int i=0;i<p;i++)
    {
        printf("%d\n",x2[i]);
    }
}