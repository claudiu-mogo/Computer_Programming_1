#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x,y;
    scanf("%f %f",&x,&y);
    if(x==0||!y)
        printf("punct pe axe");
    else
    {
        if(x>0&&y>0)
        {
            printf("1");
        }
        else
        {
            if(x>0&&y<0)
                printf("4");
            else
            {
                if(y>0)
                    printf("2");
                else
                    printf("3");
            }
        }
    }

    return 0;
}
