#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void panta(int x1, int y1, int x2, int y2, float *m, float *n)
{
    float dif1, dif2;
    dif1=y2-y1;
    dif1=dif1/1.0;
    dif2=x2-x1;
    dif2=dif2/1.0;
    if(dif2)
    {
        *m=dif1/dif2;
        *n=(float)y2-(*m)*x2;
    }
    else
    {
        *m=INT_MAX;
    }

}

int main()
{
    int x1,x2,x3,y1,y2,y3;
    float m,n;
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    panta(x1,y1,x2,y2,&m,&n);
    if(m!=INT_MAX)
    {
        if(y3==(m*x3+n))
            printf("DA");
        else
            printf("NU");
    }
    else
    {
        if(x1==x3)
            printf("DA");
        else
            printf("NU");
    }
    return 0;
}
