#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double trapez_sin(double x)
{
    return sin(x);
}

double trapez_cos(double x)
{
    return cos(x);
}

double integrala(double (*func) (double x), double a, double b, int n)
{
    double h,s=0,i;
    h=(b-a)/n;
    for(i=a;i<=b;i=i+h)
    {
        s=s+func(i)+func(i+h);
    }
    s=s*h/2;
    return s;
}

int main()
{
    int n,nr;
    double a,b,suma;
    double(*funcs[2])(double)={trapez_sin,trapez_cos};
    scanf("%d%lf%lf%d",&nr,&a,&b,&n);
    suma=integrala(funcs[nr],a,b,n);
    printf("%lf",suma);
    return 0;
}
