#include <stdio.h>
#include <string.h>

int function1(char num1[])
{
	int num2;
	if(strcmp(num1,"1")==0)
	{
		num2=1;
	}
	else if(strcmp(num1,"2")==0)
	{
		num2=2;
	}
	else if(strcmp(num1,"3")==0)
	{
		num2=3;
	}
	else
	{
		num2=0;
	}
	return num2;
}
int main()
{
	char num1[]="1";
	int num2;
	int num3=0;
	int t1;
	for(int i=0;i<5;i++)
	{
		scanf("%s",&num1);
		num2=function1(num1);
		for(int k=0;k<num2;k++)
		{
			num3=num3*10;
		}
		if(num2==1)
		{
			num3=num3+1;
		}
		else if(num2==2)
		{
			num3=num3+10;
		}
		else if(num2==3)
		{
			num3=num3+100;
		}
	}
	for(int i=0;i<3;i++)
	{
		t1=num3%10;
		num3=num3/10;
		printf("%d\n",t1);
	}
}
