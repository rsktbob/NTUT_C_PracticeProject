#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy_array(char (*x1)[18][40],char *t1)
{
    int times=0;
    int key=1;
    while((*x1)[times][0]!='\0')
    {
        if(strcmp((*x1)[times],t1)==0)
        {
            key=0;
            break;
        }
        times++;
    }
    if(key==1)
    {
        strcpy((*x1)[times],t1);      
    }
}

int check_array(char (*x1)[18][40],char (*x2)[18][40])
{
    for(int i=0;(*x1)[i][0]!='\0';i++)
    {
        for(int j=0;(*x2)[j][0]!='\0';j++)
        {
            if(strcmp((*x1)[i],(*x2)[j])==0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int same_array(char (*x1)[18][40],char (*k1)[18][40],char (*k2)[18][40])
{
    int t1=0;
    int t2=0;
    int num1=0;
    int num2=0;
    int times=0;
    while((*x1)[times][0]!='\0')
    {
        times++;
    }
    while((*k1)[num1][0]!='\0')
    {
        num1++;
    }
    while((*k2)[num2][0]!='\0')
    {
        num2++;
    }
    for(int i=0;(*x1)[i][0]!='\0';i++)
    {
        for(int j=0;(*k1)[j][0]!='\0';j++)
        {
            if(strcmp((*x1)[i],(*k1)[j])==0)
            {
                t1++;
            }
        }
    }
    for(int i=0;(*x1)[i][0]!='\0';i++)
    {
        for(int j=0;(*k2)[j][0]!='\0';j++)
        {
            if(strcmp((*x1)[i],(*k2)[j])==0)
            {
                t2++;
            }
        }
    }
    if(times==t1+t2 && t1==num1 && t2==num2)
    {
        return 1;
    }
    return 0;
}

int main()
{
    char x1[140]={};
    char x2[18][40]={};
    char *t1;
    char k1[140]={};
    char k2[8][18][40]={};
    int num1;
    int times=0;
    gets(x1);
    scanf(" %d",&num1);
    getchar();
    t1=strtok(x1," ");
    while(t1!=NULL)
    {
        copy_array(&x2,&t1[0]);
        t1=strtok(NULL," ");
    }
    for(int i=0;i<num1;i++)
    {
        gets(k1);
        t1=strtok(k1," ");
        while(t1!=NULL)
        {
            copy_array(&k2[i],&t1[0]);
            t1=strtok(NULL," ");
        }
    }
    for(int i=0;k2[i][0][0]!='\0';i++)
    {
        for(int j=i+1;k2[j][0][0]!='\0';j++)
        {
            if(check_array(&k2[i],&k2[j])==1 &same_array(&x2,&k2[i],&k2[j])==1)
            {
                times++;
            }
        }
    }
    printf("%d\n",times);
}