#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k,*vim,*vi,*aux,lungime=2,i,j;
    scanf("%d%d",&n,&k);
    vim=(int *)malloc(lungime*sizeof(int));
    vim[0]=vim[1]=1;
    vi=(int *)malloc(lungime*sizeof(int));
    for(i=2;i<=n;i++)
    {
        lungime++;
        vi=(int *)realloc(vi,lungime*sizeof(int));
        vi[0]=vi[lungime-1]=1;
        printf("%d ",vi[0]);
        for(j=1;j<lungime-1;j++)
        {
            vi[j]=vim[j-1]+vim[j];
            printf("%d ",vi[j]);
        }
        printf("%d ",vi[lungime-1]);
        printf("\n");
        vim=(int *)realloc(vim,lungime*sizeof(int));
        aux=vi;
        vi=vim;
        vim=aux;
    }
    printf("%d",vim[k]);
    return 0;
}
