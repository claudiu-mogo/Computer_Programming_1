#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float re,im;
}complex;

complex adunare(complex a, complex b)
{
    complex sum;
    sum.re=a.re+b.re;
    sum.im=a.im+b.im;
    return sum;
}

complex scadere(complex a, complex b)
{
    complex sum;
    sum.re=a.re-b.re;
    sum.im=a.im-b.im;
    return sum;
}

complex inmultire(complex a, complex b)
{
    complex rez;
    rez.re=a.re*b.re-a.im*b.im;
    rez.im=a.im*b.re+a.re*b.im;
    return rez;
}

complex putere(complex a, int putere)
{
    complex rez;
    rez.re=1;
    rez.im=0;
    for(int i=0;i<putere;i++)
    {
        rez=inmultire(rez,a);
    }
    return rez;
}

void scrie(complex a)
{
    printf("%f %f ",a.re,a.im);
}

int main()
{
    complex x,rez,factor;
    rez.re=rez.im=0;
    int n,i;
    float coef[101];
    scanf("%f%f",&x.re,&x.im);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%f",&coef[i]);
        factor.re=coef[i];
        factor.im=0;
        rez=adunare(rez,inmultire(factor,putere(x,i)));
    }
    scrie(rez);
    return 0;
}
