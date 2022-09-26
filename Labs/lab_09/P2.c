#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t timp;
    timp=time(NULL);
    struct tm* t=localtime(&timp);
    printf("%s\n",asctime(t));
    printf("%s\n",ctime(&timp));
    return 0;
}
