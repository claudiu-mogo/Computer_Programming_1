#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,aux;
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)
    {
        aux=a;
        a=b;
        b=aux;
    }
    if(b>c)
    {
        aux=b;
        b=c;
        c=aux;
    }
    if(a>b)
    {
        aux=a;
        a=b;
        b=aux;
    }
    printf("%d %d %d",a,b,c);
    return 0;
}
