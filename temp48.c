#include <stdio.h>

void operation_grath(int (*num1)[6][9], int num2)
{
    int num3;
    int x1[9];
    switch(num2)
    {
        case 10:
            for(int i=0;i<3;i++)
            {
                num3=(*num1)[0][i];
                (*num1)[0][i]=(*num1)[3][i];
                (*num1)[3][i]=(*num1)[1][i];
                (*num1)[1][i]=(*num1)[2][i];
                (*num1)[2][i]=num3;
            }
            for(int i=0;i<9;i++)
            {
                x1[i]=(*num1)[4][i];
            }
            (*num1)[4][0]=x1[6];
            (*num1)[4][1]=x1[3];
            (*num1)[4][2]=x1[0];
            (*num1)[4][3]=x1[7];
            (*num1)[4][5]=x1[1];
            (*num1)[4][6]=x1[8];
            (*num1)[4][7]=x1[5];
            (*num1)[4][8]=x1[2];
            break;
        case 11:
            for(int i=3;i<6;i++)
            {
                num3=(*num1)[0][i];
                (*num1)[0][i]=(*num1)[3][i];
                (*num1)[3][i]=(*num1)[1][i];
                (*num1)[1][i]=(*num1)[2][i];
                (*num1)[2][i]=num3;
            }
            break;
        case 12:
            for(int i=6;i<9;i++)
            {
                num3=(*num1)[0][i];
                (*num1)[0][i]=(*num1)[3][i];
                (*num1)[3][i]=(*num1)[1][i];
                (*num1)[1][i]=(*num1)[2][i];
                (*num1)[2][i]=num3;
            }
            for(int i=0;i<9;i++)
            {
                x1[i]=(*num1)[5][i];
            }
            (*num1)[5][0]=x1[6];
            (*num1)[5][1]=x1[3];
            (*num1)[5][2]=x1[0];
            (*num1)[5][3]=x1[7];
            (*num1)[5][5]=x1[1];
            (*num1)[5][6]=x1[8];
            (*num1)[5][7]=x1[5];
            (*num1)[5][8]=x1[2];
            break;
        case 20:
            for(int i=0;i<=6;i=i+3)
            {
                num3=(*num1)[3][i];
                (*num1)[3][i]=(*num1)[5][i];
                (*num1)[5][i]=(*num1)[2][i];
                (*num1)[2][i]=(*num1)[4][i];
                (*num1)[4][i]=num3;
            }
            for(int i=0;i<9;i++)
            {
                x1[i]=(*num1)[0][i];
            }
            (*num1)[0][0]=x1[2];
            (*num1)[0][1]=x1[5];
            (*num1)[0][2]=x1[8];
            (*num1)[0][3]=x1[1];
            (*num1)[0][5]=x1[7];
            (*num1)[0][6]=x1[0];
            (*num1)[0][7]=x1[3];
            (*num1)[0][8]=x1[6];
            break;
        case 21:
            for(int i=1;i<=7;i=i+3)
            {
                num3=(*num1)[3][i];
                (*num1)[3][i]=(*num1)[5][i];
                (*num1)[5][i]=(*num1)[2][i];
                (*num1)[2][i]=(*num1)[4][i];
                (*num1)[4][i]=num3;
            }
            break;
        case 22:
            for(int i=2;i<=8;i=i+3)
            {
                num3=(*num1)[3][i];
                (*num1)[3][i]=(*num1)[5][i];
                (*num1)[5][i]=(*num1)[2][i];
                (*num1)[2][i]=(*num1)[4][i];
                (*num1)[4][i]=num3;
            }
            for(int i=0;i<9;i++)
            {
                x1[i]=(*num1)[1][i];
            }
            (*num1)[1][0]=x1[2];
            (*num1)[1][1]=x1[5];
            (*num1)[1][2]=x1[8];
            (*num1)[1][3]=x1[1];
            (*num1)[1][5]=x1[7];
            (*num1)[1][6]=x1[0];
            (*num1)[1][7]=x1[3];
            (*num1)[1][8]=x1[6];
            break;
    }
}

void out_array(int (*num1)[6][9])
{
    int times;
    for(int i=0;i<3;i++)
    {
        times=i;
        for(int j=0;j<3;j++)
        {
            printf("%d ",(*num1)[0][times]);
            times=times+3;
        }
        printf("\n");
    }
}

int main()
{
    int num1[6][9]={{1,1,1,1,1,1,1,1,1},{6,6,6,6,6,6,6,6,6},{3,3,3,3,3,3,3,3,3},{4,4,4,4,4,4,4,4,4},{5,5,5,5,5,5,5,5,5},{2,2,2,2,2,2,2,2,2}};
    int num2;
    int num3;
    scanf(" %d",&num2);
    for(int i=0; i<num2;i++)
    {
        scanf(" %d",&num3);
        operation_grath(&num1, num3);
    }
    out_array(&num1);
}