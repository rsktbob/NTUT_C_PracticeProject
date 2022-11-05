#include <stdio.h>

void init(int *num1)
{
    for(int i=0;i<159;i++)
    {
        num1[i]=0;
    }
    num1[159]=-2;
}

void load(int *num1,int *key1,char *x1)
{
    int len=0;
    for(int i=0;x1[i]!='\0';i++)
    {
        len++;
    }
    for(int i=160-len,k=0;x1[k]!='\0';i++,k++)
    {
        num1[i]=x1[k]-'0';
    }
    if(num1[160-len]==-3)
    {
        *key1=1;
        num1[160-len]=0;
    }
}

void shift(int *num1)
{
    if(num1[159]==-2)
    {
        for(int i=0;i<158;i++)
        {
            num1[i]=num1[i+1];
        }
        num1[158]=0;
        return;
    }
    for(int i=0;i<160;i++)
    {
        if(num1[i]==-2)
        {
            num1[i]=num1[i+1];
            num1[i+1]=-2;
            return;
        }
    }
}

int point_loc(int *num1)
{
    for(int i=159;i>=0;i--)
    {
        if(num1[i]==-2)
        {
            i=159-i;
            return i;
        }    
    }
}

void array_shift(int *num1,int k1)
{
    int num2[160]={0};
    for(int i=0;i<160-k1;i++)
    {
        num2[i]=num1[i+k1];
    }
    for(int i=0;i<160;i++)
    {
        num1[i]=num2[i];
    }
}

int array_len(int *num1)
{
    int key=0;
    for(int i=0;i<160;i++)
    {
        if(num1[i]!=0 && num1[i]!=-2)
        {
            key=160-i;
            break;
        }      
    }
    return key;
}

int equal(int *num1,int *num2)
{
    int key=0;
    for(int i=0;i<160;i++)
    {
        if(num1[i]>num2[i])
        {
            key=1;
            break;
        }
        if(num1[i]<num2[i])
        {
            key=-1;
            break;
        }
    }
    return key;
}

void add_point(int *num1)
{
    int k1=0;
    for(int i=159;i>=0;i--)
    {
        if(num1[i]==-2)
        {
            k1=1;
            break;
        }
    }
    if(k1==0)
    {
        for(int i=0;i<159;i++)
        {
            num1[i]=num1[i+1];
        }
        num1[159]=-2;
    }
}

void align(int *num1,int *num2)
{
    int k1;
    int k2;
    for(int i=159;i>=0;i--)
    {
        if(num1[i]==-2)
        {
            k1=159-i;
            break;
        }
    }
    for(int i=159;i>=0;i--)
    {
        if(num2[i]==-2)
        {
            k2=159-i;
            break;
        }
    }
    if(k1>k2)
    {
        array_shift(&num2[0],k1-k2);
    }
    if(k1<k2)
    {
        array_shift(&num1[0],k2-k1);
    }
}

void add(int *num1,int *num2,int *num3)
{
    int sum;
    int carry=0;
    for(int i=159;i>=0;i--)
    {
        if(num1[i]==-2)
        {
            num3[i]=-2;
            i--;
        }
        sum=num1[i]+num2[i]+carry;
        carry=0;
        if(sum>9)
        {
            sum=sum-10;
            carry=1;
        }
        num3[i]=sum;
    }
}

void sub(int *num1,int *num2,int *num3)
{
    int difference;
    int borrow=0;
    for(int i=159;i>=0;i--)
    {
        if(num1[i]==-2)
        {
            num3[i]=-2;
            i--;
        }
        difference=num1[i]-num2[i]-borrow;
        borrow=0;
        if(difference<0)
        {
            difference=difference+10;
            borrow=1;
        }
        num3[i]=difference;
    }
}

void array_out(int *num1,int x1)
{
    int key1=0;
    int key2=0;
    int key3=0;
    for(int i=0;i<160;i++)
    {
        key1=i;
        if(num1[i]!=0 && num1[i]!=-2)
        {
            break;
        }
    }
    if(key1==159)
    {
        printf("%d\n",0);
        return;
    }
    if(x1==1)
    {
        printf("-");
    }
    for(int i=0;num1[i]==0;i++)
    {
        key2=i;
    }
    for(int i=key2+1;i<160;i++)
    {
        if(num1[i]==-2)
        {
            if(i!=159)
            {
                printf(".");
                for(int j=159;num1[j]==0;j--)
                {
                    num1[j]=-1;
                    key3=j;
                }
            }
        }
        else if(num1[i]!=-1)
        {
            printf("%d",num1[i]);
        }
    }
    printf("\n");
}

void mul(int *num1,int *num2,int *num3,int c1,int c2)
{
    int k1=array_len(&num2[0]);
    int k2;
    int k3;
    int t1[160]={0};
    for(int i=0;i<160;i++)
    {
        t1[i]=num1[i];
    }
    for(int i=159;i>159-k1;i--)
    {
        if(num2[i]!=-2)
        {
            for(int j=0;j<num2[i];j++)
            {
                align(&num1[0],&num3[0]);
                add(&num1[0],&num3[0],&num3[0]);
            }
            shift(&num1[0]);
        }
    }
    for(int i=0;i<160;i++)
    {
        num1[i]=t1[i];
    }
    k2=c1+c2;
    k3=159-point_loc(&num3[0]);
    for(int i=k3;i>159-k2;i--)
    {
        num3[i]=num3[i-1];
        num3[i-1]=-2;
    }
}

int main()
{
    char x1[160]={};
    char x2[160]={};
    int num1[160]={0};
    int num2[160]={0};
    int k1[160]={0};
    int k2[160]={0};
    int k3[160]={0};
    int key1=0;
    int key2=0;
    int t1=0;
    int t2=0;
    int t3=0;
    int c1=0;
    int c2=0;
    init(&k3[0]);
    scanf("%s",x1);
    scanf("%s",x2);
    load(&num1[0],&key1,&x1[0]);
    load(&num2[0],&key2,&x2[0]);
    add_point(&num1[0]);
    add_point(&num2[0]);
    c1=point_loc(&num1[0]);
    c2=point_loc(&num2[0]);
    mul(&num1[0],&num2[0],&k3[0],c1,c2);
    align(&num1[0],&num2[0]);
    if(key1==0 && key2==0)
    {
        add(&num1[0],&num2[0],&k1[0]);
        if(equal(&num1[0],&num2[0])==-1)
        {
            t2=1;
            sub(&num2[0],&num1[0],&k2[0]);           
        }
        else
        {
            sub(&num1[0],&num2[0],&k2[0]); 
        }
    }
    else if(key1==0 && key2==1)
    {
        t3=1;
        if(equal(&num1[0],&num2[0])==-1)
        {
            t1=1;
            sub(&num2[0],&num1[0],&k1[0]);
        }
        else
        {
            sub(&num1[0],&num1[0],&k1[0]);
        }
        add(&num1[0],&num2[0],&k2[0]);
    }
    else if(key1==1 && key2==0)
    {
        t3=1;
        if(equal(&num1[0],&num2[0])==1)
        {
            t1=1;
            sub(&num1[0],&num2[0],&k1[0]);
        }
        else
        {
            sub(&num2[0],&num1[0],&k1[0]);
        }
        t2=1;
        add(&num1[0],&num2[0],&k2[0]);
    }
    else if(key1==1 && key2==1)
    {
        t1=1;
        add(&num1[0],&num2[0],&k1[0]);
        if(equal(&num1[0],&num2[0])==1)
        {
            t2=1;
            sub(&num1[0],&num2[0],&k2[0]);
        }
        else
        {
            sub(&num2[0],&num1[0],&k2[0]);
        }
    }
    array_out(&k1[0],t1);
    array_out(&k2[0],t2);
    array_out(&k3[0],t3);
}