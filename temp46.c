#include <stdio.h>
#include <string.h>

void replace_array(char (*x1)[40][80],char *t1,char *t2)
{
    for(int i=0;(*x1)[i][0]!='\0';i++)
    {
        if(strcmp((*x1)[i],t1)==0)
        {
            strcpy((*x1)[i],t2);
        }
    }
}

void insert_array(char (*x1)[40][80],char *t1,char *t2)
{
    int times;
    for(int i=0;(*x1)[i][0]!='\0';i++)
    {
        if(strcmp((*x1)[i],t1)==0)
        {
            times=i;
            while((*x1)[times][0]!='\0')
            {
                times++;
            }
            for(int j=times;j>=i+1;j--)
            {
                strcpy((*x1)[j],(*x1)[j-1]);
            }
            strcpy((*x1)[i],t2);
            i++;
        }
    }
}

void delete_array(char (*x1)[40][80],char *t1)
{
    int times;
    int num1;
    for(int i=0;(*x1)[i][0]!='\0';i++)
    {
        if(strcmp((*x1)[i],t1)==0)
        {
            times=i;
            while((*x1)[times][0]!='\0')
            {
                strcpy((*x1)[times],(*x1)[times+1]);
                times++;
            }
            i--;
        }
    }
}

void set_array(char (*x1)[40][80],char (*x2)[40][80])
{
    int key=1;
    int times=0;
    for(int i=0;(*x2)[i][0]!='\0';i++)
    {
        key=1;
        for(int j=0;(*x1)[j][0]!='\0';j++)
        {
            if(strcmp((*x1)[j],(*x2)[i])==0)
            {
                key=0;
                break;
            }
        }
        if(key==1)
        {
            times=0;
            while((*x1)[times][0]!='\0')
            {
                times++;
            }
            strcpy((*x1)[times],(*x2)[i]);
        }
    }
}

void sort_array(char (*x1)[40][80],char (*x2)[40][80])
{
    int num1[40]={0};
    int times=0;
    int k1;
    char k2[40];
    for(int i=0;(*x1)[i][0]!='\0';i++)
    {
        for(int j=0;(*x2)[j][0]!='\0';j++)
        {
            if(strcmp((*x1)[i],(*x2)[j])==0)
            {
                num1[i]++;
            }
        }
        times=i+1;
    }
    for(int i=1;i<times;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(num1[j]>num1[j-1])
            {
                k1=num1[j];
                num1[j]=num1[j-1];
                num1[j-1]=k1;
                strcpy(k2,(*x1)[j]);
                strcpy((*x1)[j],(*x1)[j-1]);
                strcpy((*x1)[j-1],k2);
            }         
            else if(num1[j]==num1[j-1])
            {
                if(strlen((*x1)[j])<strlen((*x1)[j-1]) || (strlen((*x1)[j])==strlen((*x1)[j-1]) && strcmp((*x1)[j],(*x1)[j-1])<0))
                {
                    k1=num1[j];
                    num1[j]=num1[j-1];
                    num1[j-1]=k1;
                    strcpy(k2,(*x1)[j]);
                    strcpy((*x1)[j],(*x1)[j-1]);
                    strcpy((*x1)[j-1],k2);
                }
                else
                {
                    break;
                }
            }
            else if(num1[j]<num1[j-1])
            {
                break;
            }
        }
    }
    for(int i=0;(*x1)[i][0]!='\0';i++)
    {
        printf("%s %d\n",(*x1)[i],num1[i]);
    }
}

void out_array(char (*x1)[40][80])
{
    for(int i=0;(*x1)[i][0]!='\0';i++)
    {
        printf("%s ",(*x1)[i]);
    }
    printf("\n");
}

int main()
{
    char x1[140]={};
    char x2[40][80]={};
    char x3[40][80]={};
    char k1[40][80]={};
    char k2[40][80]={};
    char k3[40][80]={};
    char *t1;
    char t2[40];
    char t3[40];
    gets(x1);
    scanf(" %s",t2);
    scanf(" %s",t3);
    t1=strtok(x1," ");
    for(int i=0;t1!=NULL;i++)
    {
        strcpy(x2[i],t1);
        strcpy(x3[i],t1);
        strcpy(k1[i],t1);
        strcpy(k2[i],t1);
        t1=strtok(NULL," ");
    }
    set_array(&k3,&x3);
    replace_array(&x2,&t2[0],&t3[0]);
    insert_array(&k1,&t2[0],&t3[0]);
    delete_array(&k2,&t2[0]);
    out_array(&x2);
    out_array(&k1);
    out_array(&k2);
    sort_array(&k3,&x3);
}