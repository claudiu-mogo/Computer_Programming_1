#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* substr(char *src, int n, char *dest)
{
    strncpy(dest,src,n);
    dest[n]='\0';
}

int main()
{
    char s[101],p[101]="Maria";
    //printf("%s\n",p);
    int a,b;
    //printf("%d",n);
    gets(s);
    scanf("%d%d",&a,&b);
    substr(s+a,b,p);
    puts(p);
    return 0;
}
