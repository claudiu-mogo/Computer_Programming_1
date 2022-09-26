#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,j,nr=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<=(n-1)/m;i++)
    {
        for(j=0;j<m&&nr<n;j++)
        {
            printf("%4d",++nr);
        }
        printf("\n");
        if((i+1)%24==0)
            printf("\n");
    }
    fflush(stdin);
    getchar();
    return 0;
}
