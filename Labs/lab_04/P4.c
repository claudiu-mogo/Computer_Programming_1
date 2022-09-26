#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,p,q,a[101][101],b[101][101],i,j,k;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    scanf("%d%d",&p,&q);
    for(i=0;i<p;i++)
        for(j=0;j<q;j++)
            scanf("%d",&b[i][j]);
    if(n!=p)
        printf("imposibil");
    else
    {
        printf("%d %d \n",m,q);
        for(i=0;i<m;i++)
        {
            for(k=0;k<q;k++)
            {
                int s=0;
                for(j=0;j<n;j++)
                {
                    s+=a[i][j]*b[j][k];
                }
                printf("%d ",s);
            }
            printf("\n");
        }
    }
    return 0;
}
