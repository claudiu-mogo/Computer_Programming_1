#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int factorial(int x)
{
    if(x>2)
        return x*factorial(x-1);
    return 2;
}

int main()
{
    int n,i;
    double tnumere=1, teps=1, snumere=0, seps=0, x, eps;
    scanf("%lf%d%lf",&x,&n,&eps);
    //suma normala
    for(i=0;i<n;i++)
    {
        snumere+=tnumere;
        tnumere=tnumere*x/(i+1);
    }
    //suma pana la epsilon
    i=0;
    while(teps>eps)
    {
        seps+=teps;
        teps=teps*x/(++i);
    }
    printf("%lf %lf %lf %lf",snumere,seps,exp(x),pow(2.718,x));

    return 0;
}
