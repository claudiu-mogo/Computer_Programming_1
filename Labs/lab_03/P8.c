#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x,eps,r1,r2;
    scanf("%lf%lf",&x,&eps);
    r1=x;
    r2=x/2.0;
    while(fabs(r1-r2)>=eps)
    {
        r1=r2;
        r2=(r1+x/r1)/2;

    }
    printf("%lf %lf",r2,sqrt(x));

    return 0;
}
