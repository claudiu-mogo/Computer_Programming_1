#include <stdio.h>
#include <stdlib.h>

void transform(int v[], int n, int x)
{
    int i=0,j=n-1,aux;
    while(i<j)
    {
        while(v[j]>=x&&i<j)
            j--;
        while(v[i]<x&&i<j)
            i++;
        if(i<j)
        {
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            i++;
            j--;
        }
    }
}

int main()
{
    int v[101],n,x,i;
    scanf("%d%d",&n,&x);
    for(i=0;i<n;i++)
        scanf("%d",&v[i]);
    transform(v,n,x);
    for(i=0;i<n;i++)
        printf("%d ",v[i]);
    return 0;
}
