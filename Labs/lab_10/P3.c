#include <stdio.h>
#include <stdlib.h>
#define MAX 5

enum examen{C,S,A};

typedef struct
{
    char nume[15];
    int ore_curs;
    enum examen tip_examen;
}MATERIA;

MATERIA citire_MAT()
{
    MATERIA ma;
    char orar[10];
    printf("nume:");
    //fflush(stdin);
    fgets(ma.nume,15,stdin);
    printf("ore_curs:");
    fgets(orar,15,stdin);
    ma.ore_curs=atoi(orar);
    printf("tip.examen:");
    fgets(orar,15,stdin);
    ma.tip_examen=orar[0];
    return ma;
}

void citire_PROGRAMA(MATERIA PROGRAMA[])
{
    for(int i=0;i<MAX;i++)
        PROGRAMA[i]=citire_MAT();
}

void afisare(char c, int n, MATERIA PROGRAMA[])
{
   int i;
   char tip;
   for(i=0;i<MAX;i++)
   {
        if(PROGRAMA[i].tip_examen==c&&PROGRAMA[i].ore_curs==n)
        {
            printf("%s %d ",PROGRAMA[i].nume,PROGRAMA[i].ore_curs);
            switch (PROGRAMA[i].tip_examen)
            {
                case C : tip='C';
                    break;
                case S : tip='S';
                    break;
                case A : tip='A';
                    break;
            }
            printf("%c\n",tip);
        }
   }
}

int main()
{
    char c;
    int n;
    scanf("%c%d",&c,&n);
    MATERIA programa[MAX];
    citire_PROGRAMA(programa);
    afisare(c,n,programa);
    return 0;
}
