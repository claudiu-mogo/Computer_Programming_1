#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,prim=0,ultim=0,smax,s=0,v[101],i,primrel=0;

    //notam cu prim si ultim pozitiile capetelor subsirului cautat
    //s este o suma relativa, iar primrel este pozitia de la care
    //am inceput sa retinem s

    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&v[i]);
    smax=v[0];

    //chiar daca vom verifica si pt prima valoare daca s este mai
    //mare decat smax (imposibil), nu va afecta rezultatul

    for(i=0;i<n;i++)
    {
        s+=v[i];
        //daca suma relativa este mai mare decat smax,
        //updatam datele ce ne intereseaza pt afisarea finala
        if(s>smax)
        {
            ultim=i;
            prim=primrel;
            smax=s;
        }
        //daca suma relativa va deveni <0 deja subsirul nu mai are continuitate.
        //resetam suma relativa si pozitia relativa de inceput
        if(s<0)
        {
            primrel=i+1;
            s=0;
        }
    }
    for(i=prim;i<=ultim;i++)
        printf("%d ",v[i]);
    return 0;
}
