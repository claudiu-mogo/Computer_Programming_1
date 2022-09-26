#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a>=0 && b>=0 && c>=0 && a+b>=c && a+c>=b && b+c>=a)
        printf("DA");
    else
        printf("NU");
    return 0;
}
