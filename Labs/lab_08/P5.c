#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char s[37],*sir;
    int n,i,l;
    scanf("%d",&n);
    scanf("%s",s);
    sir=(char *)malloc((strlen(s)+2)*sizeof(char));
    strcpy(sir,s);
    strcat(sir,"-");
    for(i=1;i<n;i++)
    {
        scanf("%s",s);
//        printf("%s\n",s);
//        printf("%s\n",sir);
        l=strlen(sir);
        if((abs(sir[l-3]-s[0])==('a'-'A')||sir[l-3]==s[0])&&(abs(sir[l-2]-s[1])==('a'-'A')||sir[l-2]==s[1]))
        {
            sir=(char *)realloc(sir,(l+strlen(s)+2)*sizeof(char));
            strcat(sir,s);
            strcat(sir,"-");
        }

    }
    sir[strlen(sir)-1]=NULL;
    printf("%s",sir);
    return 0;
}
