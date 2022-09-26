#include <stdio.h>
#include <stdlib.h>

void bubble(int *v, int n)
{
    int i,j,ok,aux;
    // ok==1 - vector ordonat
    // ok==0 - vector neordonat
    do{
        ok=1;
        //presupunem ca vectorul e ordonat
        for(i=0;i<n-1;i++)
        {
            if(v[i]>v[i+1])
            {
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                ok=0;
                //deci presupunerea era falsa
            }
        }
        n--;
        //maximul a ajuns la locul lui
    }while(!ok);
}

void afisare(int *v, int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",v[i]);
}

int main()
{
    #define N 100
    int v[N],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&v[i]);
    bubble(v,n);
    afisare(v,n);
    return 0;
}
