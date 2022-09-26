#include <stdio.h>
#include <stdlib.h>

int transforma(int n)
{
    int v[10]={0},i,nr;
    while(n)
    {
        v[n%10]++;
        n=n/10;
    }
    if(v[0])
    {
        nr=0;
        for(i=9;i>=0;i--)
        {
            while(v[i])
            {
                nr=nr*10+i;
                v[i]--;
            }
        }
    }
    else
    {
        nr=0;
        for(i=1;i<10;i++)
        {
            while(v[i])
            {
                nr=nr*10+i;
                v[i]--;
            }
        }
    }
    return nr;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",transforma(n));
    return 0;
}
