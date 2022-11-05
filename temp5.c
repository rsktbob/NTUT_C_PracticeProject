#include <stdio.h>

int function1(int *x1,int num1,int num2,int num3)
{
	for(int i=num3; i>num1; i--)
	{
		x1[i]=x1[i-1];
	}
	x1[num1]=num2;
}
int function2(int num1,int num2)

{
	int num3;
	while(num2!=0)
	{
		num3=num1%num2;
		num1=num2;
		num2=num3;
	}
	return num1;
}

void function3(int *x1,int num1,int num2)
{
	if(num1<num2)
	{
		int i=num1;
		int j=num2;
		int node=num1;
		int t;
		while(i<j)
		{
			while(x1[j]>=x1[node] && i<j)
			{
				j--;
			}
			while(x1[i]<=x1[node] && i<j)
			{
				i++;
			}
			t=x1[i];
			x1[i]=x1[j];
			x1[j]=t;
		}
		t=x1[i];
		x1[i]=x1[node];
		x1[node]=t;
		function3(x1,num1,i-1);
		function3(x1,i+1,num2);
	}
}

int function4(int x1[],int num1,int num2)
{
	int t=0;
	printf("the length %d\n%d\n",num1,num2);
	for(int i=0;i<num1;i++)
	{	
		if(x1[i]==num2)
		{
			t=1;
			break;
		}
	}
	return t;
}

int function6(int x1[][3],int num1,int num2)
{
	for(int i=0;i<num1;i++)
	{
		for(int j=0;j<num2;j++)
		{
			printf("%d\n",x1[i][j]);
		}
	}
}
int main()
{
	int x1[7][6]={{1,2,3},{4,5,6},{5,8,14}};
	int *x2;
	int x3[6]={3,6,14,8,5,18};
	int num1=3;
	int num2=6;
	x2=x3;
	char t1[]="skfpatuifhttk";
	printf("%c\n",t1[0]);
	printf("%d\n",x1[1][2]);
	printf("%d\n",num1);
	function6(x1,3,2);
	function3(x2,0,5);
	for(int i=0;i<6;i++)
	{
		printf("%d\n",x2[i]);
	}
}
