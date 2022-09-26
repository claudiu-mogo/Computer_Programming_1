#include "Produs.h"
#include <string.h>

void afisare_ecran(char* nume_fisier)
{
    FILE *f;
    Produs produs1;
    int i;
    f=fopen(nume_fisier,"rb");
    while(fread(&produs1,sizeof(Produs),1,f)==1)
    {
        printf("%s %d %f\n",produs1.nume_produs,produs1.cantitate,produs1.pret_produs);
    }
    fclose(f);
}

void creare_fisier(char* fisier1)
{
    int i;
    int X;
    FILE *f;
    Produs produs1;
    f=fopen(fisier1,"wb");
    for(i=0;i<100;i++)
    {
        X=rand();
        sprintf(produs1.nume_produs,"Produs%d",X);
        produs1.cantitate=X%100;
        produs1.pret_produs=(X <= 100 ? X : X % 100);
        fwrite(&produs1,sizeof(Produs),1,f);
    }
    fclose(f);
}

void adus_vector(char *nume_fisier, Produs* vect)
{
    Produs produs1;
    FILE* f;
    int i=0;
    f=fopen(nume_fisier,"rb");
    while(fread(&produs1,sizeof(Produs),1,f)==1)
    {
        sprintf(vect[i].nume_produs,"%s",produs1.nume_produs);
        vect[i].cantitate=produs1.cantitate;
        vect[i++].pret_produs=produs1.pret_produs;
    }
    fclose(f);
}

void sortare(char* fisier1,Produs* vect)
{
    int nr=100;
    int ok;
    FILE *f;
    Produs produs1;
    f=fopen(fisier1,"wb");
    do{
        ok=1;
        //presupunem ca vectorul e ordonat
        for(int i=0;i<nr-1;i++)
        {
            if(strcmp(vect[i].nume_produs,vect[i+1].nume_produs)>0)
            {
                Produs sch;
                sch=vect[i];
                vect[i]=vect[i+1];
                vect[i+1]=sch;
                ok=0;
            }
        }
        nr--;
        //maximul a ajuns la locul lui
    }while(!ok);
    for(int i=0;i<100;i++)
    {
        sprintf(produs1.nume_produs,"%s",vect[i].nume_produs);
        produs1.cantitate=vect[i].cantitate;
        produs1.pret_produs=vect[i++].pret_produs;
        fwrite(&produs1,sizeof(Produs),1,f);
    }
    fclose(f);
}

void gasit_produs(char* nume_fisier, char* cautare)
{
    int ok=0;
    FILE *f;
    Produs produs1;
    f=fopen(nume_fisier,"rb");
    while(fread(&produs1,sizeof(Produs),1,f)==1)
    {
        if(strcmp(cautare,produs1.nume_produs)==0)
        {
            printf("Datele sunt: %s %d %f",produs1.nume_produs,produs1.cantitate,produs1.pret_produs);
            ok=1;
        }
    }
    if(!ok)
        printf("Atat s-a putut");
    fclose(f);
}

void inlocuire(char* nume_fisier, char* cautare)
{
    int ok=0;
    FILE *f;
    Produs produs1;
    f=fopen(nume_fisier,"rb+");
    while(fread(&produs1,sizeof(Produs),1,f)==1)
    {
        if(strcmp(cautare,produs1.nume_produs)==0)
        {
            scanf("%d%f",&produs1.cantitate,&produs1.pret_produs);
            ok=1;
            fseek(f,-1*((long)sizeof(Produs)),SEEK_CUR);
            fwrite(&produs1,sizeof(Produs),1,f);
            fseek(f,((long)sizeof(Produs)),SEEK_CUR);
        }
    }
    if(!ok)
        printf("Atat s-a putut");
    fclose(f);
}

int main(int argc, char *argv[])
{
    char file1[]="fisier.out",cautat[101];
    scanf("%s",cautat);
    Produs vect[101];
    creare_fisier(file1);
    adus_vector(file1,vect);
    sortare(file1,vect);
    afisare_ecran(file1);
    gasit_produs(file1,cautat);
    inlocuire(file1,cautat);
    afisare_ecran(file1);
    return 0;
}