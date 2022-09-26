#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,p;
    scanf("%d",&p);
    for(i=0;i<=p/2-2;i++)
    {
        for(j=i;j<=(p-i-j);j++)
        {
            if((i+j>=(p-i-j))&&(i+(p-i-j)>=j)&&(j+(p-i-j)>=i))
            {
                printf("%d %d %d \n",i,j,p-i-j);
            }
        }
    }
    return 0;
}
