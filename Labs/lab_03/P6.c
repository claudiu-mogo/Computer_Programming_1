#include <stdio.h>
#include <stdlib.h>
int combinari(int n, int m)
{
    if(m)
        return (combinari(n,m-1))*(n-m+1)/m;
    return 1;
}
int factorial(int x)
{
    int p=1;
    for(int i=2;i<=x;i++)
    {
        p*=i;
    }
    return p;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(n<m)
        printf("date incorecte");
    else
    {
        printf("%d\n",combinari(n,m));
        printf("%d",factorial(n)/(factorial(m)*factorial(n-m)));
    }

    return 0;
}
