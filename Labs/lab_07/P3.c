#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strdel(char *p, int n)
{
    char aux[101];
    strcpy(aux,p+n);
    strcpy(p,aux);
}

char *strins(char *p, char *s)
{
    char aux[101];
    strcpy(aux,p);
    strcpy(p,s);
    strcat(p,aux);
}

int main()
{
    int n,i;
    char text[101],sir_de_inlocuit[101],cu_care_se_inloc[101],*p,*c;
    gets(text);
    gets(sir_de_inlocuit);
    gets(cu_care_se_inloc);
    c=strstr(text,sir_de_inlocuit);
    while(c)
    {
        p=strdel(c,strlen(sir_de_inlocuit));
        strins(p,cu_care_se_inloc);
        c=strstr(c+strlen(cu_care_se_inloc),sir_de_inlocuit);
    }
    puts(text);
    return 0;
}
