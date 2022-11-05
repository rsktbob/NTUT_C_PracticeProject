#include <stdio.h>
#include <string.h>
#include <math.h>

typedef enum scoreType_s {G,GPA,S} scoreType_t;
typedef enum grade_s{AP, A, AM, BP, B, BM, CP, C, CM, F} grade_t;
typedef union score_s{int score;grade_t grade;} score_t;

int average_score(int num1,score_t *array)
{
    float sum=0;
    for(int i = 0; i < num1; i++)
    {
        switch (array[i].grade)
        {
            case AP: array[i].score=95; break;
            case A: array[i].score=87; break;
            case AM: array[i].score=82; break;
            case BP: array[i].score=78; break;
            case B: array[i].score=75; break;
            case BM: array[i].score=70; break;
            case CP: array[i].score=68; break;
            case C: array[i].score=65; break;
            case CM: array[i].score=60; break;
            case F: array[i].score=50; break;
        }
        sum=sum+array[i].score;
    }
    sum=sum/num1;
    sum=round(sum);
    return sum;
}

void insert_sort(int num1,char (*student)[18][20],int *sum_score)
{
    int key;
    char x1[20];
    for(int i=1;i<=num1;i++)
    {
        for(int j=i;j>=1;j--)
        {
            if(sum_score[j]>sum_score[j-1])
            {
                key=sum_score[j-1];
                sum_score[j-1]=sum_score[j];
                sum_score[j]=key;
                strcpy(x1,(*student)[j-1]);
                strcpy((*student)[j-1],(*student)[j]);
                strcpy((*student)[j],x1);
            }
            else
            {
                break;
            }               
        }
    }
    for(int i=0;i<3;i++)
    {
        printf("%s\n",(*student)[i]);
        printf("%d\n",sum_score[i]);
    }
}

int main() 
{
    int num1;
    int num2;
    char score[4];
    char grade[8];
    char score_c[3][4]={"G","GPA","S"};
    char x1[10][3]={"A+", "A", "A-", "B+","B", "B-", "C+", "C", "C-","F"};
    char x2[10][4]={"4.3","4.0","3.7","3.3","3.0","2.7","2.3","2.0","1.7","0"};
    char x3[10][8]={"90-100","85-89","80-84","77-79","73-76","70-72","67-69","63-66","60-62","0-59"};
    scoreType_t t1[20]={0};
    grade_t t2[18][20]={0};
    score_t array[20];
    char student[18][20]={};
    int sum_score[20]={0};
    scanf(" %d",&num1);
    for(int i = 0; i <num1;i++) 
    {
        scanf(" %s",&score);
        for(int j = G; j <= S; j++)
        {
            if(strcmp(score,score_c[j])==0)
            {
                t1[i]=j;
            }
        }
    }
    scanf(" %d",&num2);
    for(int i = 0; i < num2;i++)
    {
        scanf(" %s",&student[i]);
        for(int j = 0; j < num1; j++)
        {
            scanf(" %s",&grade);
            if(t1[j]==G)
            {
                for(int k=AP;k<=F;k++)
                {
                    if(strcmp(grade,x1[k])==0)
                    {
                        array[j].grade=k;
                        break;
                    }
                }
            }
            else if(t1[j]==GPA)
            {
                for(int k=AP;k<=F;k++)
                {
                    if(strcmp(grade,x2[k])==0)
                    {
                        array[j].grade=k;
                        break;
                    }
                } 
            }
            else if(t1[j]==S)
            {
                for(int k=AP;k<=F;k++)
                {
                    if(strcmp(grade,x3[k])==0)
                    {
                        array[j].grade=k;
                        break;
                    }
                } 
            }
        }
        sum_score[i]=average_score(num1,&array[0]);
    }
    insert_sort(num2,&student,&sum_score[0]);
}