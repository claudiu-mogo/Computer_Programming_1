#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    float x,sx=0;
    double y,sy=0;
    scanf("%d%f%lf",&n,&x,&y);
    for(i=0;i<10;i++)
    {
        sx+=10*x;
        sy+=10*y;
        printf("%f %e %f %e \n",sx,sx,sy,sy);
    }
    return 0;
}
