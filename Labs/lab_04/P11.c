#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,v[101];
    double x,s;
    scanf("%lf%d",&x,&n);
    for(i=0;i<=n;i++)
    {
        scanf("%d",&v[i]);
    }
    s=v[0];
    for(i=1;i<=n;i++)
    {
        s=x*s+v[i];
    }
    printf("%.2lf",s);
    return 0;
}
