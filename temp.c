#include <stdio.h>
#include <math.h>

int main()
{
    double a;
    double b;
    double c;
    scanf("%lf",&a);
    scanf("%lf",&b);
    scanf("%lf",&c);
    double x1=(-b+sqrt(b*b-a*c*4))/(2*a);
    double x2=(-b-sqrt(b*b-a*c*4))/(2*a);
	if(x1==0)
	{
		printf("%.1f\n",0);
	}
    else
    {
    	printf("%.1f\n",x1);
    }
	if(x2==0)
	{
		printf("%.1f\n",0);
	}
    else
    {
    	printf("%.1f\n",x2);
	}
}
