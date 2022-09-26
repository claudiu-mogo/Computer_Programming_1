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

char* my_replace(char *s, char *s1, char *s2)
{
    char *p;
    p=strstr(s,s1);
    strdel(p,strlen(s1));
    strins(p,s2);
}

int main()
{
    char *s,*s1,*s2;
    s1=(char *)calloc(100,sizeof(char));
    s2=(char *)calloc(100,sizeof(char));
    scanf("%s%s",s1,s2);
    getchar();
    s=(char *)calloc(200,sizeof(char));
    gets(s);
    my_replace(s,s1,s2);
    puts(s);
    free(s);
    free(s1);
    free(s2);
    return 0;
}
