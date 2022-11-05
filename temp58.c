#include <stdio.h>
#include <string.h>

int move_end(char *x1)
{
    int k;
    for(int i=0;x1[i]!='\0';i++)
    {
        k=i+1;
    }
    return k;
}

void insert(char *x1,int k,char t1)
{
    for(int i=159;i>k;i--)
    {
        x1[i]=x1[i-1];
    }
    if(t1=='\0')
    {
        t1=' ';
    }
    x1[k]=t1;
}

void delete(char *x1,int k)
{
    for(int i=k;x1[i]!='\0';i++)
    {
        x1[i]=x1[i+1];
    }
}

int main()
{
    char x1[160];
    char x2[160];
    char x3;
    int k=0;
    int t=0;
    gets(x1);
    gets(x2);
    for(int i=0;x2[i]!='\0';i++)
    {
        switch(x2[i])
        {
            case '0': 
                k=0; 
                break;
            case '$': 
                k=move_end(x1);
                break;
            case 'x':
                delete(x1,k);
                break;
            case 's':
                t=move_end(x1);
                if(t!=k && t!=k+1)
                {
                    x3=x1[k];
                    x1[k]=x1[k+1];
                    x1[k+1]=x3;
                }
                break;
            case 'i': 
                insert(&x1[0],k,x2[++i]); 
                k++;
                break;
            case 'u':
                if(x1[k]>=97 || x1[k]<=122)
                {
                    x1[k]=x1[k]-32;
                }
                k++;
                break;
            case '+':
                k++;
                break;
            case '-':
                k--;
        }
    }
    printf("%s\n",x1);
}
