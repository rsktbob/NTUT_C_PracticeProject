#include <stdio.h>

int check_courses(int (*courseSpace)[3],int *courseName)
{
    for(int i = 0; i < 3; i++)
    {
        if(courseSpace[0][i]==0)
        {
            continue;
        }
        for(int j = 0; j < 3; j++)
        {
            if(courseSpace[0][i]==courseSpace[1][j])
            {
                printf("%d and %d conflict on %d\n",courseName[0],courseName[1],courseSpace[0][i]);
                break;
            }
        }
    }
    for(int i = 0; i < 3; i++)
    {
        if(courseSpace[1][i]==0)
        {
            continue;
        }
        for(int j = 0; j < 3; j++)
        {
            if(courseSpace[1][i]==courseSpace[2][j])
            {
                printf("%d and %d conflict on %d\n",courseName[1],courseName[2],courseSpace[1][i]);
                break;
            }
        }
    }
    for(int i = 0; i < 3; i++)
    {
        if(courseSpace[0][i]==0)
        {
            continue;
        }
        for(int j = 0; j < 3; j++)
        {
            if(courseSpace[0][i]==courseSpace[2][j])
            {
                printf("%d and %d conflict on %d\n",courseName[0],courseName[2],courseSpace[0][i]);
                break;
            }
        }
    }
}
int main()
{
    int courseName[3];
    int courseTimes;
    int courseSpace[3][3];
    int course;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            courseSpace[i][j]=0;
        }
    }
    for(int i=0; i<3; i++)
    {
        scanf(" %d", &courseName[i]);
        scanf(" %d", &courseTimes);
        for(int j=0; j<courseTimes; j++)
        {
            scanf(" %d", &course);
            courseSpace[i][j] = course;
        }
    }
    check_courses(&courseSpace[0],&courseName[0]);
}