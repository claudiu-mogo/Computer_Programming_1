#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[101];
    int aparitie;
}Pereche;

int main()
{
    Pereche *v;
    int i,n,p=2,elemente=0,j;
    v=(Pereche *)malloc(p*sizeof(Pereche));
    for(i=0;i<p;i++)
        v[i].aparitie=0;
    char cuvant[101];
    scanf("%d",&n);
    scanf("%s",cuvant);
    strcpy(v[0].s,cuvant);
    v[0].aparitie++;
    elemente++;
    for(i=1;i<n;i++)
    {
        scanf("%s",cuvant);
        for(j=0;j<elemente;j++)
        {
            if(!strcmp(cuvant,v[j].s))
            {
                v[j].aparitie++;
                break;
            }
        }
        if(j==elemente)
        {
            if(elemente==p)
            {
                p=p*2;
                v=(Pereche *)realloc(v,p*sizeof(Pereche));
                for(int k=p/2;k<p;k++)
                    v[k].aparitie=0;
            }
            strcpy(v[j].s,cuvant);
            v[j].aparitie++;
            elemente++;
        }

    }
    for(i=0;i<elemente;i++)
        printf("%s %d\n",v[i].s,v[i].aparitie);
    return 0;
}
