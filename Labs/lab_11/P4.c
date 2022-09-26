#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *text, *input, *output;
    char codificare[10],linii_input[101][101],linii_input_save[101][101];
    int i=0,j,nr_linii;
    text=fopen(argv[1],"r");
    input=fopen(argv[2],"r");
    output=fopen(argv[3],"a");
    while(fgets(linii_input[i],101,input))
    {
        strcpy(linii_input_save[i],linii_input[i]);
        i++;
    }
    fclose(input);
    nr_linii=i;

    while(fgets(codificare,10,text))
    {
        for(i=0;i<nr_linii;i++)
        {
            for(j=0;j<strlen(linii_input[i]);j++)
            {
                if(linii_input_save[i][j]==codificare[0])
                {
                    linii_input[i][j]=codificare[2];
                }
                    
                if(linii_input_save[i][j]==toupper(codificare[0]))
                    linii_input[i][j]=toupper(codificare[2]);
            }
        }         
    }
    for(i=0;i<nr_linii;i++)
        fputs(linii_input[i],output);
    fclose(text);
    fclose(output);

}