#include <stdio.h>

void triangle_right(int length)
{
    int key = length/2;
    for(int i = 0; i < key+1; i++)
    {
        for(int j = 0; j < i+1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(int i = 0 ;i < key; i++)
    {
        for(int j = 0; j < key-i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void triangle_left(int length)
{
    int key = length/2;
    for(int i = 0; i < key+1; i++)
    {
        for(int j = 0; j < key-i; j++)
        {
            printf(".");
        }
        for(int j = 0; j < i+1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(int i = 0; i < key; i++)
    {
        for(int j = 0; j < i+1; j++)
        {
            printf(".");
        }
        for(int j = 0; j < key-i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void shombus(int length)
{
    int key = length/2;
    int x1=0;
    for(int i = 0; i < key+1; i++)
    {
        for(int j = 0; j < key-i; j++)
        {
            printf(".");
        }
        for(int j = 0; j < i+1; j++)
        {
            printf("*");
        }
        for(int i = 0; i < x1; i++)
        {
            printf("*");
        }
        x1+=1;
        printf("\n");
    }
    x1-=1;
    for(int i = 0; i < key; i++)
    {
        x1-=1;
        for(int j = 0; j < i+1; j++)
        {
            printf(".");
        }
        for(int j = 0; j < key-i; j++)
        {
            printf("*");
        }
        for(int i = 0; i < x1; i++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int num1;
    int length;
    scanf(" %d", &num1);
    scanf(" %d", &length);
    if(num1 == 1)
    {
        triangle_right(length);
    }
    else if(num1 == 2)
    {
        triangle_left(length);
    }
    else if(num1 == 3)
    {
        shombus(length);
    }
}