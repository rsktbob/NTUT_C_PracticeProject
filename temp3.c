#include <stdio.h>

int main()
{
	float x1;
	float x2;
	float t1;
	float t2;
	scanf("%f",&x1);
	scanf("%f",&x2);
	scanf("%f",&t1);
	scanf("%f",&t2);
	printf("%.1f\n",(x1+x2)*t1*0.92-t2*0.05);
	printf("%.1f\n",t2*0.05);
	printf("%.1f\n",(x1+x2)*t1*0.08);
}
