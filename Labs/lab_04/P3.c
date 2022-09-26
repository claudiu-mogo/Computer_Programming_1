#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,maxlin,minovr,mat[101][101],i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&mat[i][j]);
    maxlin=mat[0][0];
    for(j=1;j<n;j++)
    {
        if(mat[0][j]>maxlin)
            maxlin=mat[0][j];
    }
    minovr=maxlin;
    for(i=1;i<n;i++)
    {
        maxlin=mat[i][0];
        for(j=1;j<n;j++)
        {
            if(mat[i][j]>maxlin)
                maxlin=mat[i][j];
        }
        if(maxlin<minovr)
            minovr=maxlin;
    }
    printf("%d",minovr);
    return 0;
}
