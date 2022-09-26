#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *src;
    char input[101];
    int i,k=0,oki=0,okn=0,okc=0,nr_linii_gasite=0;
    src=fopen(argv[argc-2],"r");
    for(i=1;i<argc-2;i++)
    {
        switch(argv[i][0])
        {
            case 'n':
                okn=1;
                break;
            case 'i':
                oki=1;
                break;
            case 'c':
                okc=1;
                break;
        }
    }
    while(fgets(input,101,src))
    {
        k++;
        if(!oki&&strstr(input,argv[argc-1]))
        {
            nr_linii_gasite++;
            if(okn)
                printf("[%d] ",k);
            fputs(input,stdout);
        }
        else
        {
            if(oki)
            {
                char copie[101],copie2[101];
                strcpy(copie,argv[argc-1]);
                strcpy(copie2,input);
                for(i=0;i<strlen(copie);i++)
                    copie[i]=toupper(copie[i]);
                for(i=0;i<strlen(copie2);i++)
                    copie2[i]=toupper(copie2[i]);
                if(strstr(copie2,copie))
                {
                    nr_linii_gasite++;
                    if(okn)
                        printf("[%d] ",k);
                    fputs(input,stdout);
                }

            }
        }

    }
    if(okc)
        printf("Numar total de linii: %d",nr_linii_gasite);
    fclose(src);
    return 0;
}