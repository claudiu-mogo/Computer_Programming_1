#include <stdio.h>
#include <stdlib.h>

int prim (int n)
{
    if(n==1)
        return 1;
    //for some reason zice ca 1 e prim
    if(n==0)
        return 0;
    for(int i=2;i*i<=n;i++)
        if(!(n%i))
            return 0;
    return 1;
}

void goldbach(int n)
{
    if(n==4)
        printf("2 + 2\n");
    // 4 e singurul nr care merge scris drept suma de numere prime pare
    for(int i=1;i<=n/2;i=i+2)
    {
        if(prim(i)&&prim(n-i))
            printf("%d + %d\n",i,n-i);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    goldbach(n);
    return 0;
}
