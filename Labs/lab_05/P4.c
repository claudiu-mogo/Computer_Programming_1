#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b)
{
    int r,aux;
    if(b>a)
    {
        aux=a;
        a=b;
        b=aux;
    }
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int cmmmc(int a, int b)
{
    return (a*b/cmmdc(a,b));
}

int main()
{
    int x1,x2,y1,y2,c;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    c=cmmmc(y1,y2);
    printf("%d %d\n",x1*c/y1,c);
    printf("%d %d\n",x2*c/y2,c);
    return 0;
}
