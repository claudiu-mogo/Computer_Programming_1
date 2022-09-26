#include <stdio.h>
#include <stdlib.h>

int prim(int x)
{
    for(int i=2;i*i<=x;i++)
        if(!(x%i))
            return 0;
    return 1;
}

int main()
{
    int n,i,f1=1,f2=1,f3;
    scanf("%d",&n);
    for(i=2;i<n;i++)
    {
        f3=f2+f1;
        if(prim(f3))
            printf("%d \n",f3);
        f1=f2;
        f2=f3;
    }
    return 0;
}
