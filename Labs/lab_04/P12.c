#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, b, e, val, v[10001]={0}, i, j, s=0;
    scanf("%d%d",&n,&m);
    for (i = 0;i < m;i++)
    {
        scanf("%d%d%d",&b,&e,&val);
        v[b]+=val;
        v[e+1]-=val;
    }
    for(i=0;i<n;i++)
    {
        s+=v[i];
        v[i]=s;
    }
    for(i=0;i<n;i++)
        printf("%d ",v[i]);
    return 0;
}
