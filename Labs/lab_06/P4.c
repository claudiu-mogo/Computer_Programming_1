#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compara(char *sir1,char *sir2)
{
    int i=0;
    while(sir1[i]&&sir2[i])
    {
        if(sir1[i]<sir2[i])
        {
            return -1;
        }
        else
        {
            if(sir1[i]>sir2[i])
                return 1;
            else
                i++;
        }
    }
    if(!sir1[i]&&!sir2[i])
        return 0;
    if(!sir1[i])
        return -1;
    return 1;
}

int main()
{
    char sir1[101],sir2[101];
    scanf("%s", sir1);
    scanf("%s", sir2);
    printf("%d",compara(sir1,sir2));
    return 0;
}
