#include <stdio.h>
#include <stdlib.h>

int suma(int x)
{
    int s=0;
    while(x)
    {
        s+=x%10;
        x=x/10;
    }
    return s;
}

int main()
{
    int a,b;
    scanf("%d",&a);
    while(a)
    {
        scanf("%d",&b);
        if(b==(a%suma(a)))
        {
            printf("(%d %d) \n",a,b);
        }
        a=b;
    }
    return 0;
}
