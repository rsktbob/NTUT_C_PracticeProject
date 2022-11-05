#include <stdio.h>
#include <math.h>

double f1(double a,double x)
{
    return fabs(sqrt(a-pow(x,2)));
}

double f2(double a,double x)
{
    return fabs((a*pow(x,3))+x*7)/sqrt(a+x);
}

double calculate_area(double (*fct)(double,double),double a,double p,double q,int n)
{
    double h,l;
    h=(*fct)(a,p)+(*fct)(a,q);
    l=(q-p)/n;
    for(double i=p+l; i<=q-l; i=i+l)
    {
        h=h+(*fct)(a,i)*2;
    }
    return l/2*h;
}

double integral(double (*fct)(double,double),double a,double p,double q,double err)
{
    double previous_area,now_area,gap;
    now_area=0;
    previous_area=-1;
    gap=1/pow(10,err);
    for(int i=1; ;i=i*2)
    {        
        now_area=calculate_area(fct,a,p,q,i);
        if(fabs(now_area-previous_area)<gap)
        {
            break;
        }
        previous_area=now_area;
    }
    return now_area;
}

int main()
{
    int n;
    double a,p,q,err;
    double (*fct)(double,double);
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
        {
            break;
        }
        else if(n==1)
        {
            fct=&f1;
        }
        else if(n==2)
        {
            fct=&f2;
        }
        scanf("%lf",&a);
        scanf("%lf",&p);
        scanf("%lf",&q);
        scanf("%lf",&err);
        printf("%.12lf\n",integral(fct,a,p,q,err));
    }
}