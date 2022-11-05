#include <stdio.h>

int singleNumber(int *nums,int size)
{
    int key;
    int count;
    for(int i = 0; i < size; i++)
    {
        count=0;
        for(int j = 0; j < size; j++)
        {
            if(nums[i]==nums[j])
            {
                count++;
            }
            if(count==2)
            {
                break;
            }
        }
        if(count==1)
        {
            return nums[i];
        }
    }
}
int main()
{
    int nums[6]={0};
    int size;
    int x1;
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        scanf("%d",&nums[i]);
    }
    x1=singleNumber(nums,size);
    printf("%d\n",x1);
}  