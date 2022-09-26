#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ch=32;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10&&ch<128;j++,ch++)
        {
            printf("%c = %d  ", ch, ch);
        }
        printf("\n");
    }
    return 0;
}
