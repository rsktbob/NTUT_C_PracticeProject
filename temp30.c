#include <stdio.h>
#include <string.h> 

void init(int *k1)
{
    for(int i=0;i<530;i++)
    {
        k1[i]=-1;
    }
}

void shift(int *k1,int num1)
{
    for(int i=517;i>num1-1;i--)
    {
        k1[i+12]=k1[i];
    }
}

void out_array(int *k1,int num1)
{
    for(int i=0;i<num1;i++)
    {
        for(int j=0;j<num1;j++)
        {
            for(int k=0;k<530;k=k+2)
            {
                if(k1[k]==i && k1[k+1]==j)
                {
                    printf("%d,%d\n",i,j);
                    break;
                }
            }
        }
    }
}


void check_lon(int num1,int num2,char *x1)
{
    int k1[530];
    int k2[530];
    init(&k1[0]);
    init(&k2[0]);
    k1[0]=0;
    k1[1]=0;
    k1[2]=num1;
    int t1;
    int t2;
    int times=0;
    int size;
    for(int i=0;i<num2;i++)
    {
        if(x1[i]=='2')
        {
            t1=k1[i*3];
            t2=k1[i*3+1];
            size=k1[i*3+2]/2;
            shift(&k1[0],i*3);
            k1[(i+1)*3]=t1;
            k1[(i+1)*3+1]=t2;
            k1[(i+1)*3+2]=size;
            k1[(i+2)*3]=t1+size;
            k1[(i+2)*3+1]=t2;
            k1[(i+2)*3+2]=size;
            k1[(i+3)*3]=t1;
            k1[(i+3)*3+1]=t2+size;
            k1[(i+3)*3+2]=size;
            k1[(i+4)*3]=t1+size;
            k1[(i+4)*3+1]=t2+size;
            k1[(i+4)*3+2]=size;
        }
        else if(x1[i]=='1')
        {
            for(int j=k1[i*3];j<k1[i*3]+k1[i*3+2];j++)
            {
                for(int k=k1[i*3+1];k<k1[i*3+1]+k1[i*3+2];k++)
                {
                    k2[times]=k;
                    k2[times+1]=j;
                    times=times+2;
                }
            }
        }
    }
    out_array(&k2[0],num1);
}

int main()
{
    char x1[160];
    int num1;
    int num2;
    scanf(" %s", x1);
    scanf(" %d",&num1);
    num2=strlen(x1);
    if(num2==1 && x1[0]=='0')
    {
        printf("all white");
    }
    else
    {
        check_lon(num1,num2,&x1[0]);
    }
}



