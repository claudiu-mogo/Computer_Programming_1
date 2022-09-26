#include <stdio.h>
#include <stdlib.h>

int extragere (int *a,int *b,int m,int n,int *c)
{
    int i,k=0,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i]==b[j])
            {
                c[k++]=a[i];
            }
        }
    }
    return k;
}

int main()
{
    int a[101],b[101],c[101],l1,l2,l3,i;
    scanf("%d",&l1);
    for(i=0;i<l1;i++)
        scanf("%d",&a[i]);
    scanf("%d",&l2);
    for(i=0;i<l2;i++)
        scanf("%d",&b[i]);
    l3=extragere(a,b,l1,l2,c);
    printf("%d\n",l3);
    for(i=0;i<l3;i++)
        printf("%d ",c[i]);
    return 0;
}
