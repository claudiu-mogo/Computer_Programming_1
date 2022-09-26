#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cresc=1,desc=1,i,n,v[101];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&v[i]);
    i=0;
    while(v[i]==v[i+1]&&i<n-1)
    {
        i++;
    }
    if(i==n-1)
        printf("constant");
    else
    {
        for(i;i<n-1;i++)
        {
            if(v[i]>v[i+1])
                cresc=0;
            if(v[i]<v[i+1])
                desc=0;
        }
        if(cresc)
            printf("crescator");
        else
            if(desc)
                printf("descrescator");
            else
                printf("neordonat");

    }

    return 0;
}
