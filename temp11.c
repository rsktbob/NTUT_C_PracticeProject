#include <stdio.h>

float convert(char *key)
{
    float value;
    switch(*key)
    {
        case 'A':
           value = 1;
           break;
        case '2':
           value = 2;
           break;
        case '3':
           value = 3;
           break;
        case '4':
           value = 4;
           break;
        case '5':
           value = 5;
           break;
        case '6':
           value = 6;
           break;
        case '7':
           value = 7;
           break;
        case '8':
           value = 8;
           break;
        case '9':
           value = 9;
           break;
        case 'J':
           value = 0.5;
           break;
        case 'Q':
           value = 0.5;
           break;
        case 'K':
           value = 0.5;
           break;
         default:
           value = 10;
    }
   return value;
}
int main()
{
    float player1=0;
    float player2=0;
    char key[2];
    float value;
    for(int i = 0; i < 3; i++)
    {
        scanf(" %s", key);
        value=convert(key);
        player1+=value;
    }
    for(int i = 0; i < 3; i++)
    {
        scanf(" %s", key);
        value=convert(key);
        player2+=value;
    }
    if(player1>10.5)
    {
        player1=0;
    }
    if(player2>10.5)
    {
        player2=0;
    }
    printf("%.1f\n%.1f\n",player1,player2);
    if(player1>player2)
    {
        printf("A wins.");
    }
    else if(player1<player2)
    {
        printf("B wins.");
    }
    else if(player1==player2)
    {
        printf("It's a tie.");
    }
}