#include <stdio.h>

typedef struct hitter_s
{
    int hits;
    int score;
    int loc;
} hitter_t;

void get_score(hitter_t *hitter,char x1,int num1)
{
    int num2;
    switch(x1)
    {
        case '1': num2 = 1; break;
        case '2': num2 = 2; break;
        case '3': num2 = 3; break;
        case 'H': num2 = 4; break; 
    }
    for(int i=0;i<9;i++)
    {
        if(hitter[i].loc>0)
        {
            hitter[i].loc=hitter[i].loc+num2;
        }
    }
    hitter[num1].hits++;
    hitter[num1].loc=num2;
    for(int i=0; i<9; i++)
    {
        if(hitter[i].loc>=4)
        {
            hitter[i].score++;
            hitter[i].loc=0;
        }
    }
}

int main()
{
    hitter_t hitter[9]={0,0,0};
    char grath[9][20]={};
    int x1;
    int x2=0;
    int x3;
    int out_hitter=0;
    int out_score=0;
    int key=0;
    for(int i=0; i<9; i++)
    {
        scanf(" %d",&x1);
        if(x1>x2)
        {
            x2=x1;
        }
        for(int j=0; j<x1; j++)
        {
            scanf(" %c",&grath[i][j]);
        }
    }
    scanf(" %d",&x3);
    for(int i=0;i<x2; i++)
    {
        for(int j=0;j<9; j++)
        {
            if(grath[j][i]=='\n')
            {
                key=1;
                break;
            }
            else if(grath[j][i]=='O')
            {
                out_hitter++;
                if(out_hitter%3==0)
                {
                    for(int i=0; i<9; i++)
                    {
                        hitter[i].loc=0;
                    }
                }
                if(out_hitter==x3)
                {
                    key=1;
                    break;
                }
            }
            else
            {
                get_score(&hitter[0],grath[j][i],j);
            }
        }
        if(key==1)
        {
            break;
        }
    }
    for(int i=0;i<9;i++)
    {
        out_score=out_score+hitter[i].score;
    }
    printf("%d\n",out_score);
    for(int i=0; i<9; i++)
    {
        printf("%d %d %d\n",i+1,hitter[i].hits,hitter[i].score);
    }
}