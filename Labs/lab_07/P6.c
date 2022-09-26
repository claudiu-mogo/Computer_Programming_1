#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *next (char *from, char *word)
{
    char *p;
    int i=0,j=0;
    while(from[i]>'z'||from[i]<'a')
    {
        i++;
    }
    j=i;
    while(from[j]<='z'&&from[j]>='a')
    {
        j++;
    }
    strncpy(word,from+i,j-i);
    word[j-i]='\0';
    if(!from[j-i])
        return 0;
    return from+j+1;
}

int main()
{
    char s[101],*p,word[101];
    gets(s);
    p=next(s,word);
    while(p)
    {
        printf("%s ",word);
        p=next(p,word);
    }

    return 0;
}
