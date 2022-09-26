#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Strategia de lucru este de a lua fiecare url primit de la tastatura,
urmand sa parcurgem fiecare site in master si sa vedem daca ii gasim un match.
Daca da, atunci salvam elementele siteului respectiv.
Daca nu, cream un cod artificial vid, care sa indice ca siteul nu exista
si sa putem afisa in consecinta.
In momentul in care inchidem un fisier si il redeschidem,
cursorul se muta la inceput*/

//incarcare baza de date
//cod-variabila importanta. retine de la html la html
typedef struct
{
    char url[51],*cod,nume_fis[31];
    int accesari,checksum,lungime;
}SITE;

//functie de rotire circulara la dreapta
//char-ul are dimensiune de 8 biti obligatoriu,
//deci orice 8 face o rotatie completa si nu ne intereseaza, de aici k%8
int rotr(char x,int k)
{
    //char este -128 127, avem nevoie insa de 0 255, facem 2 rezerve unsigned
    unsigned char rezerva1,rezerva2;
    rezerva1=rezerva2=x;
    //shiftarea la dreapta lasa pe primele k%8 pozitii zerouri
    rezerva1=rezerva1>>(k%8);
    //shiftarea la stanga lasa pe ultimele 8-k%8 pozitii zerouri
    rezerva2=rezerva2<<(8-(k%8));
    //sau-ul logic se va face pe fiecare bit intre 0 si valoarea buna
    return rezerva1|rezerva2;
}

//functie de rotire circulara la stanga
//acelasi principiu ca la rotr
int rotl(char x,int k)
{
    unsigned char rezerva1,rezerva2;
    rezerva1=rezerva2=x;
    rezerva1=rezerva1<<(k%8);
    rezerva2=rezerva2>>(8-(k%8));
    return rezerva1|rezerva2;
}

//functie de calculare a cheii gasite pentru un cod html de lungime n
int cheie(char *s,int n)
{
    int i,gasit=0;
    gasit=rotl(s[0],0);
    for(i=1;i<n;i++)
    {
        if(i%2)
            gasit=gasit^rotr(s[i],i);
        else
            gasit=gasit^rotl(s[i],i);
    }
    return gasit;
}

int main()
{
    FILE *f, *f1;
    SITE *site;
    int i=0,j,memorie=3,ok;
    char html_de_citit[31],vect[101],input[101];
    site=(SITE *)malloc(memorie*sizeof(SITE));
    //citire de la tastatura a url-urilor
    while(fgets(input,100,stdin)!=NULL)
    {
        //daca gasim sir null, am parcurs tot
        if(input[0]=='\n'&&input[1]=='\0')
            break;
        input[strcspn(input,"\n")]=0;
        ok=0;
        //deschidere si citire master
        f=fopen("master.txt","r");
        if(f)
        {
            while(fgets(html_de_citit,31,f)!=NULL)
            {
                html_de_citit[strcspn(html_de_citit,"\n")]=0;
                //deschidere si citire din fisiere
                f1=fopen(html_de_citit,"r");
                if(f1)
                {
                    if(i%3==0&&i>0)
                    {
                        memorie+=3;
                        site=(SITE *)realloc(site,memorie*sizeof(SITE));
                    }
                    fscanf(f1,"%s",site[i].url);
                    //daca url-ul siteului curent coincide cu linia primita
                    //citim tot codul html al siteului
                    if(strcmp(input,site[i].url)==0)
                    {
                        ok=1;
                        fscanf(f1,"%d",&site[i].lungime);
                        fscanf(f1,"%d",&site[i].accesari);
                        fscanf(f1,"%d",&site[i].checksum);
                        fgetc(f1);
                        strcpy(site[i].nume_fis,html_de_citit);
                        site[i].cod=(char *)malloc
                                        ((site[i].lungime+1)*sizeof(char));
                        site[i].cod[0]='\0';
                        while(fgets(vect,101,f1))
                        {
                            strcat(site[i].cod,vect);
                        }
                        if(site[i].cod[strlen(site[i].cod)-1]=='\n')
                            site[i].cod[strlen(site[i].cod)-1]='\0';
                        fclose(f1);
                        i++;
                    }

                }
            }
            fclose(f);
        }
        //ok ne zice daca s-a gasit siteul
        //daca nu s-a gasit, "cream" un site cu cod html vid
        if(!ok)
        {
            if(i%3==0&&i>0)
            {
                memorie+=3;
                site=(SITE *)realloc(site,memorie*sizeof(SITE));
            }
            site[i].cod=(char *)malloc(1*sizeof(char));
            site[i].cod[0]='\0';
            i++;
        }
    }
    //i -> nr de url-uri primite
    for(j=0;j<i;j++)
    {
        //daca siteul are continutul vid (deci nu exista)
        if(!site[j].cod[0])
            printf("Website not found!\n");
        else
        {
            //daca se potrivesc cheile
            if(site[j].checksum==cheie(site[j].cod,site[j].lungime))
                printf("Website safe!\n");
            else
            {
                //daca nu se potrivesc cheile
                printf("Malicious website! Official key: ");
                printf("%d. ",site[j].checksum);
                printf("Found key: %d\n",cheie(site[j].cod,site[j].lungime));
            }
        }
        free(site[j].cod);
    }
    free(site);
    return 0;
}
