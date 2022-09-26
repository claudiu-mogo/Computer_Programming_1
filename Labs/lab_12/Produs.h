#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nume_produs[21];
    int cantitate;
    float pret_produs;
}Produs;

void creare_fisier(char* nume_fisier);
void afisare_ecran(char* nume_fisier);
void adus_vector(char *nume_fisier, Produs* vect);
void sortare(char* fisier1,Produs* vect);
void gasit_produs(char* nume_fisier, char* cautare);
void inlocuire(char* nume_fisier, char* cautare);