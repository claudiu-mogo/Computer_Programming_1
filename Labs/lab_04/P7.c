#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,v[101],prim=0,primrel=0,lmax=0,l=0,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&v[i]);
    for(i=1;i<n;i++)
    {
        if(v[i]>=v[i-1])
        {
            l++;
        }
        else
        {
            if(l>lmax)
            {
                lmax=l;
                prim=primrel;
            }
            primrel=i;
            l=0;
        }
    }
    for(i=prim;i<=prim+lmax;i++)
        printf("%d ",v[i]);
    return 0;
}
