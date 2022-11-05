#include <stdio.h>

void check(int (*course_list)[20][18],int *course_size,int times_list)
{
    for(int i = 0; i < times_list; i++)
    {
        for(int j = 1; j < course_size[i]+1; j++)
        {
            for(int k = i+1; k < times_list; k++)
            {
                for(int t = 1; t < course_size[k]+1; t++)
                {
                    if((*course_list)[i][j] == (*course_list)[k][t])
                    {
                        printf("%d and %d conflict on %d\n",(*course_list)[i][0],(*course_list)[k][0],(*course_list)[i][j]);
                    }
                }
            }
        }
    }

}
int main()
{
    int times;
    int times_list;
    int course;
    int course_list[20][18];
    int course_size[18];
    scanf(" %d", &times_list);
    for(int i=0; i<times_list;i++)
    {
        scanf(" %d",&course);
        scanf(" %d",&times);
        course_list[i][0] = course;
        course_size[i] = times;
        for(int j=1; j<times+1;j++)
        {
            scanf(" %d",&course_list[i][j]);
        }
    }
    check(&course_list,&course_size[0],times_list);
}