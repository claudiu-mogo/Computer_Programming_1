#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int nrcifre=0,n,m,contor=0;
    scanf("%d",&n);
    m=n;
    while(m)
    {
        m=m/10;
        contor++;
    }
    //contor = numarul de cifre al lui n
    for(int i=0;i<contor-1;i++)
    {
        nrcifre+=9*pow(10,i)*(i+1);
    }
    nrcifre+=(n-pow(10,contor-1)+1)*contor;
    printf("%d",nrcifre);

    return 0;
}
