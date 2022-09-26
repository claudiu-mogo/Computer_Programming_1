#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int *v,cap=5,n=0,x,i;
    v=(int *)calloc(cap,sizeof(int));
    scanf("%d",&x);
    while(x!=0)
    {
        v[n++]=x;
        if(cap==n)
            cap*=2;
        v=(int *)realloc(v,cap*sizeof(int));
        scanf("%d",&x);
    }
    for(i=0;i<n;i++)
        printf("%d ",v[i]);
    return 0;
}
