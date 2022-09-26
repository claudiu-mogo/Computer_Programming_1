#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,i,*aparitii,nr=3,elemente=0,j;
    char s[20],**cuvinte;
    cuvinte=(char **)calloc(nr,sizeof(char*));
    for(i=0;i<nr;i++)
        cuvinte[i]=(char *)calloc(20,sizeof(char));
    aparitii=(int *)calloc(nr,sizeof(int));
    scanf("%d",&n);
    scanf("%s",s);
    strcpy(cuvinte[elemente],s);
    aparitii[elemente++]++;
    for(i=1;i<n;i++)
    {
        scanf("%s",s);
        for(j=0;j<elemente;j++)
        {
            if(!strcmp(cuvinte[j],s))
            {
                aparitii[j]++;
                break;
            }
        }
        if(j==elemente)
        {
            if(elemente==nr)
            {
                nr*=2;
                cuvinte=(char **)realloc(*cuvinte,nr*sizeof(char*));
                for(int k=elemente;k<nr;k++)
                    cuvinte[k]=(char *)malloc(20*sizeof(char));
                aparitii=(int *)realloc(aparitii,nr*sizeof(int));
                for(int k=elemente;k<nr;k++)
                    aparitii[k]=0;
            }
            strcpy(cuvinte[elemente],s);
            aparitii[elemente++]++;
        }
    }

    for(i=0;i<elemente;i++)
    {
        printf("%s %d\n",cuvinte[i],aparitii[i]);
    }
    free(aparitii);
    free(cuvinte);
    return 0;
}
