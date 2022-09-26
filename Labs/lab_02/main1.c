#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int a,b;
    a=rand()%101;
    b=rand()%101;
    printf("%d + %d = %d",a,b,a+b);
    return 0;
}
