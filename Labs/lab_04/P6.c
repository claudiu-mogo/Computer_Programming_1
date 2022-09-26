#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,mat[101][101],n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&mat[i][j]);
    for(j=1;j<n;j++)
    {
        for(i=1;i<n;i++)
        {
            if(i+j>n-1)
                printf("%d ",mat[i][j]);
        }
    }
    return 0;
}
