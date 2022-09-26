#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v[101],nrpoz=0, nrneg=0,i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }
    for(i=0;i<n;i++)
    {
        if(v[i]<0)
            nrneg++;
        else
            nrpoz++;
    }
    printf("%d %d",nrneg,nrpoz);
    return 0;
}
