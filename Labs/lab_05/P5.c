#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    int p=1;
    for(int i=2;i<=n;i++)
        p*=i;
    return p;
}

double putere(double x, int n)
{
    double rez=1;
    for(int i=1;i<=n;i++)
        rez*=x;
    return rez;
}

double taylor(double x, int n)
{
    double s=1.0;
    for(int i=1;i<=n;i++)
    {
        s+=(putere(x,i)/factorial(i));
    }
    return s;
}

int main()
{
    int n;
    double x;
    scanf("%lf%d",&x,&n);
    //printf("%lf",putere(x,n));
    printf("%.4lf",taylor(x,n));
    return 0;
}
