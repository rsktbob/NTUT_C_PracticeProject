#include <stdio.h> 

int main() 
{    
    int n,m;

    while(scanf("%d %d", &n, &m)!=-1) 
    {
        int array[502][502] = {0};
        int CurrentX, CurrentY;
        int x, y;
        int i, j;

        scanf("%d %d", &CurrentX, &CurrentY);

        m-=1;
        while(m--)
        {
            scanf("%d %d", &x, &y);

            while(CurrentX != x || CurrentY != y) 
            {
                array[CurrentX][CurrentY] = 1;

                if(CurrentX < x) CurrentX++;
                if(CurrentX > x) CurrentX--;
                if(CurrentY < y) CurrentY++;
                if(CurrentY > y) CurrentY--;
            }

            array[CurrentX][CurrentY] = 1;
        }

        for(i=0; i<n+2; i++)
            putchar('-');

        printf("\n");

        for(i=1; i<=n; i++) 
        {
            putchar('|');

            for(j=1; j<=n; j++)
                printf("%c", (array[i][j])? '*' : ' ');

            putchar('|');
            printf("\n");
        }        

        for(i=0; i<n+2; i++)
            putchar('-');

        printf("\n");

        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                array[i][j]=0;

    }
    return 0;
}