#include <stdio.h>
#include <stdlib.h>

void count(int n, int *v, int *zero, int *poz, int *neg)
{
    int i;
    *zero=*poz=*neg=0;
    for(i=0;i<n;i++)
    {
        if(!v[i])
            (*zero)++;
        else
            if(v[i]>0)
                (*poz)++;
            else
                (*neg)++;
    }
}

int main()
{
    int n,a,b,c,v[101],i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&v[i]);
    count(n,v,&a,&b,&c);
    printf("nule: %d\npozitive: %d\nnegative: %d",a,b,c);
    return 0;
}
