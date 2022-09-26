#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c;
    srand(time(NULL));
    a=rand();
    scanf("%f%f",&b,&c);
    printf("%f %g %e",a,b,c);
    return 0;
}
