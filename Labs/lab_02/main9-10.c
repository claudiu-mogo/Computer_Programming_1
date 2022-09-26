#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h,m,s;
    if(scanf("%d%d%d",&h,&m,&s)&&h>=0&&h<=23&&m>=0&&m<=59&&s>=0&&s<=59)
        printf("%02d:%02d:%02d",h,m,s);
    else
        printf("Date eronate");
    return 0;
}
