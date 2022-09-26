#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,a[101],i,j,ok=1,counter,c[101]={0};
    float x[101];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%f",&x[i]);
    scanf("%d",&m);
    for(i=0;i<m;i++)
        scanf("%d",&a[i]);
    for(i=0;i<m-1&&ok;i++)
    {
        if(a[i]>=a[i+1])
            ok=0;
        else
        {
            counter=0;
            for(j=0;j<n;j++)
            {
                if(x[j]>a[i]&&x[j]<a[i+1])
                    counter++;
            }
            c[i]=counter;
        }
    }
    if(!ok)
        printf("Error");
    else
    {
        for(i=0;i<m-1;i++)
            printf("%d ",c[i]);
    }
    return 0;
}
