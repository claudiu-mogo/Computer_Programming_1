#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
     double x, PI = M_PI;
     printf("%8s %8s %8s \n","x", "sin(x)", "cos(x)");
     for (x = 0; x <= 2 * PI; x = x + PI / 20) {
        printf("¦========================¦\n");
        printf("%+8.3f%+8.3f%+8.3f \n",x, sin(x),cos(x));
     }
     getchar();
     return 0;
}
