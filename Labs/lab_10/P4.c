#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int n,m;
    int **a;
}MATRICE;

MATRICE* creeaza_MATRICE(int n, int m)
{
    MATRICE* ma;
    ma=(MATRICE *)malloc(sizeof(MATRICE));
    ma->n=n;
    ma->m=m;
    ma->a=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
    {
        ma->a[i]=(int *)malloc(m*sizeof(int));
    }
    return ma;
}

MATRICE* citeste_MATRICE(MATRICE* ma)
{
    int i,j;
    for(i=0;i<ma->n;i++)
    {
        for(j=0;j<ma->m;j++)
            scanf("%d",&ma->a[i][j]);
    }
    return ma;
}

void scrie_MATRICE(MATRICE* ma)
{
    int i,j;
    for(i=0;i<ma->n;i++)
    {
        for(j=0;j<ma->m;j++)
            printf("%d ",ma->a[i][j]);
        printf("\n");
    }
}

MATRICE* aduna_MATRICE(MATRICE* ma, MATRICE* mb)
{
    MATRICE *ms;
    int i,j;
    if(ma->m!=mb->m||ma->n!=mb->n)
        return NULL;
    else
    {
        ms=(MATRICE *)malloc(sizeof(MATRICE));
        ms->a=(int **)malloc((ma->n)*sizeof(int *));
        for(i=0;i<ma->n;i++)
        {
            ms->a[i]=(int *)malloc((ma->m)*sizeof(int));
        }
        ms->n=ma->n;
        ms->m=ma->m;
        for(i=0;i<ma->n;i++)
        {
            for(j=0;j<ma->m;j++)
            {
                ms->a[i][j]=ma->a[i][j]+mb->a[i][j];
            }
        }
        return ms;
    }
}

MATRICE* inmulteste_MATRICE(MATRICE* ma, MATRICE* mb)
{
    int i,j,k;
    MATRICE *mp;
    if(ma->m!=mb->n)
        return NULL;
    mp=(MATRICE *)malloc(sizeof(MATRICE));
    mp->a=(int **)malloc((ma->n)*sizeof(int *));
    mp->n=ma->n;
    mp->m=mb->m;
    for(i=0;i<ma->n;i++)
    {
        mp->a[i]=(int *)malloc((mb->m)*sizeof(int));
    }
    for(i=0;i<ma->n;i++)
    {
        for(j=0;j<mb->m;j++)
        {
            mp->a[i][j]=0;
            for(k=0;k<ma->m;k++)
            {
                mp->a[i][j]+=ma->a[i][k]*mb->a[k][j];
            }
        }
    }
    return mp;
}

int main()
{
    MATRICE *ma,*mb,*mc;
    int n,m;
    scanf("%d%d",&n,&m);
    ma=creeaza_MATRICE(n,m);
    ma=citeste_MATRICE(ma);
    scrie_MATRICE(ma);
    scanf("%d%d",&n,&m);
    mb=creeaza_MATRICE(n,m);
    mb=citeste_MATRICE(mb);
    scrie_MATRICE(mb);
    mc=creeaza_MATRICE(ma->n,ma->m);
    mc=aduna_MATRICE(ma,mb);
    scrie_MATRICE(mc);

    return 0;
}
