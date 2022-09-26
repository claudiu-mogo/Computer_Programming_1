#include <stdio.h>
#include <stdlib.h>

void spirala (int a[][101], int m, int n, int *v)
{
    int lin=0,col=0,i,j,k=0;
    while(lin<=m/2)
    {
        for(i=0+lin;i<m-lin;i++)
        {
            v[k++]=a[i][col];
        }
        for(j=1+col;j<n-col;j++)
        {
            v[k++]=a[m-1-lin][j];
        }
        for(i=m-2-lin;i>=lin;i--)
        {
            v[k++]=a[i][n-1-col];
        }
        for(j=n-2-col;j>col;j--)
        {
            v[k++]=a[lin][j];
        }
        lin++;
        col++;
    }

}

void afisare(int *v,int dim)
{
    for(int i=0;i<dim;i++)
        printf("%d ",v[i]);
}

int main()
{
    int a[101][101],v[10001],i,j,m,n;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    spirala(a,n,m,v);
    afisare(v,n*m);
    return 0;
}
