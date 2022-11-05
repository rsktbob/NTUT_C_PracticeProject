#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int function1(int (*x1)[2][6])
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            printf("%d\n",x1[i][j]);
        }
    }
}
int main()
{
    int (*x1)[6];
    int x2[2][6]={{3,5,14,6,8,18},{1,2,3,4,5,6}};
    x1=&x2;
    function1(x1);
}

