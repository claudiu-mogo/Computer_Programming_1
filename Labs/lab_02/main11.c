#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input=fopen("lab-02-11.in", "r"), *output=fopen("lab-02-11.out", "w");
    float a,b,c,delta;
    fscanf(input, "%f%f%f",&a,&b,&c);
    if(!a&&!b&&!c)
        fprintf(output,"o infinitate de solutii");
    else
    {
        if(!a)
            fprintf(output,"%.2f",(-c/b));
        else
        {
            delta=b*b-4*a*c;
            if(!delta)
            {
                fprintf(output,"%.2f",(-b/2/a));
            }
            else
            {
                if(delta>0)
                    fprintf(output,"%.2f %.2f",(-b+sqrt(delta))/2/a,(-b-sqrt(delta))/2/a);
                else
                    fprintf(output,"nu exista sol");
            }
        }

    }
    return 0;
}
