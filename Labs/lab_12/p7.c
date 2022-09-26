#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define N 4
 
typedef struct Persoana{
        char* nume;
        char* prenume;
} Persoana;
 
void serializeaza(Persoana v[], int nrPersoane, char* fileName)
{
        FILE* f = fopen(fileName, "wb");
 
        int i,lungime;
        for(i=0;i<nrPersoane;i++)
        {
            lungime=strlen(v[i].nume);
            fwrite(&lungime,4,1,f);
            fwrite(v[i].nume,strlen(v[i].nume),1,f);
            lungime=strlen(v[i].prenume);
            fwrite(&lungime,4,1,f);
            fwrite(v[i].prenume,strlen(v[i].prenume),1,f);
        }
 
        fclose(f);
}
 
void deserializeaza(Persoana v[], int nrPersoane, char* fileName)
{
        FILE* f = fopen(fileName, "rb");
 
        int i,lungime;
        for(i=0;i<nrPersoane;i++)
        {
            fread(&lungime,4,1,f);
            v[i].nume=(char*)malloc(lungime*sizeof(char));
            fread(v[i].nume,lungime,1,f);
            v[i].nume[lungime]=0;
            fread(&lungime,4,1,f);
            v[i].prenume=(char*)malloc(lungime*sizeof(char));
            fread(v[i].prenume,lungime,1,f);
            v[i].prenume[lungime]=0;
        }
 
        fclose(f);
}
 
int main()
{
        Persoana v[N],w[N];
        char* prenume[N] = { "Eric", "Kyle", "Stan", "Kenny" };
        char* nume[N] = { "Cartman", "Broflovski", "Marsh", "McCormick" };
        int i;
        for (i = 0; i < N; i++){
                v[i].nume = nume[i];
                v[i].prenume = prenume[i];
        }
 
        // Serializam vectorul intr-un fisier
        serializeaza(v, N, "persoane.bin");
        // Deserializam in alt vector, din acelasi fisier. Ar trebui sa obtinem aceleasi informatii.
        deserializeaza(w, N, "persoane.bin");
 
        for (i = 0; i < N; i++){
                printf("%s %s\n",w[i].prenume,w[i].nume);
        }
 
        return 0;
}