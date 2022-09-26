#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* In acest task salvam toate siteurile ce contin cel putin un cuvant
din input intr-un vector auxiliar numit site_cu_cuvinte,
urmand sa il ordonam pe acesta.
Nu este necesara incarcarea absolut tuturor elementelor din baza de date,
(de exemplu titlu sau culori)*/

//incarcare baza de date
//valid-> posibilitatea de a fi incarcat in site_cu_cuvinte,
//pentru a evita duplicatele
//valid=0 -> a fost deja incarcat
//valid=1 -> nu a fost incarcat, dar poate fi
typedef struct
{
    char url[51],*cod,*continut,nume_fis[31];
    int accesari,checksum,lungime,valid;
}SITE;

//parsare continut
void continutul(SITE *site1)
{
    char *point1,*point2,*point3;
    int j;
    point1=strstr(site1->cod,"<p>");
    point2=strstr(site1->cod,"</p>");
    if(point1)
    {
        //daca exista exact <p>
        site1->continut=(char *)malloc((point2-point1-3+1)*sizeof(char));
        point1+=3;
        j=0;
        while(point1!=point2)
        {
            site1->continut[j++]=(point1[0]);
            point1++;
        }
        site1->continut[j]='\0';
    }
    else
    {
        //daca exista culori in tag
        point1=strstr(site1->cod,"<p style=");
        //pentru continut exclusiv
        point3=strstr(point1,">");
        site1->continut=(char *)malloc((point2-point3-1+1)*sizeof(char));
        point3++;
        j=0;
        while(point3!=point2)
        {
            site1->continut[j++]=(point3[0]);
            point3++;
        }
        site1->continut[j]='\0';
    }
}

//functie care incarca din vectorul mare in site_cu_cuvinte
//nr == de elemente din site
int parsare_site_cuvinte(SITE *site_cu_cuvinte,SITE *site,int nr)
{
    int i,nr_gasit=0;
    char linie[101],*p,*word;
    for(i=0;i<nr;i++)
        site[i].valid=1;
    //salvam intr-un sir de caractere ce primim de la tastatura
    fgets(linie, 101, stdin);
    //despartim cuvintele dupa spatiu si enter
    word=strtok(linie," \n");
    while(word!=NULL)
    {
        //cautam in fiecare site
        for(i=0;i<nr;i++)
        {
            p=strstr(site[i].continut,word);
            //daca am gasit cuvantul si siteul poate fi pus in site_cu_cuvinte
            if(p!=NULL&&site[i].valid==1)
            {
                //conditie pt a anula cazul cuvant in cuvant
                //trebuie sa fie la inceput sau dupa spatiu
                //si trebuie sa fie la final sau inainte de spatiu
                if((p==site[i].continut || !isalpha(p[-1])) &&
                   (p[strlen(word)]==0 || !isalpha(p[strlen(word)])))
                {
                    site[i].valid=0; //siteul nu mai poate fi pus a2a oara
                    site_cu_cuvinte[nr_gasit++]=site[i];
                }
            }
        }
        word=strtok(NULL," \n");
    }
    //returneaza nr de elemente din site_cu_cuvinte
    return nr_gasit;
}

//comparare dupa continut, iar apoi dupa accesari
int comparare(SITE *site1,SITE *site2)
{
    if(strcmp(site1->continut,site2->continut)<0)
        return 1;
    if(strcmp(site1->continut,site2->continut)>0)
        return -1;
    if(site1->accesari>site2->accesari)
        return 1;
    return -1;
}

//sortare bubblesort, dar cu conditia de comparare
void sortare(SITE *site_cu_cuvinte,int nr,int (*comparare)(SITE *,SITE *))
{
    int ok;
    do{
        ok=1;
        //presupunem ca vectorul e ordonat
        for(int i=0;i<nr-1;i++)
        {
            if(comparare(&site_cu_cuvinte[i],&site_cu_cuvinte[i+1])==-1)
            {
                SITE sch;
                sch=site_cu_cuvinte[i];
                site_cu_cuvinte[i]=site_cu_cuvinte[i+1];
                site_cu_cuvinte[i+1]=sch;
                ok=0;
            }
        }
        nr--;
        //maximul a ajuns la locul lui
    }while(!ok);
}

int main()
{
    FILE *f, *f1;
    SITE *site, *site_cu_cuvinte;;
    int i=0,nr_gasit,memorie=3,k;
    char html_de_citit[31],vect[101];
    site=(SITE *)malloc(memorie*sizeof(SITE));
    //deschidere si citire master
    f=fopen("master.txt","r");
    if(f)
    {
        while(fgets(html_de_citit,31,f)!=NULL)
        {
            //scapam de '\n'-ul de la final
            html_de_citit[strcspn(html_de_citit,"\n")]=0;
            //deschidere si citire fisiere din master
            f1=fopen(html_de_citit,"r");
            if(f1)
            {
                if(i%3==0&&i>0)
                {
                    memorie+=3;
                    site=(SITE *)realloc(site,memorie*sizeof(SITE));
                }
                //parsare prima linie
                fscanf(f1,"%s",site[i].url);
                fscanf(f1,"%d",&site[i].lungime);
                fscanf(f1,"%d",&site[i].accesari);
                fscanf(f1,"%d",&site[i].checksum);
                fgetc(f1);
                strcpy(site[i].nume_fis,html_de_citit);
                site[i].cod=(char *)malloc((site[i].lungime+1)*sizeof(char));
                site[i].cod[0]='\0';
                while(fgets(vect,101,f1))
                {
                    strcat(site[i].cod,vect);
                }
                //obtinerea continutului
                continutul(&site[i]);
                fclose(f1);
                i++;
            }
        }
        fclose(f);
    }

    //alocare si sortare site_cu_cuvinte
    site_cu_cuvinte=(SITE *)malloc(memorie*sizeof(SITE));
    nr_gasit=parsare_site_cuvinte(site_cu_cuvinte,site,i);
    sortare(site_cu_cuvinte,nr_gasit,comparare);
    //eliberare memorie si afisare
    //i-nr total de siteuri
    for(k=0;k<i;k++)
    {
        free(site[k].cod);
        free(site[k].continut);
    }
    free(site);
    //nr_gasit - nr de site_cu_cuvinte
    for(i=0;i<nr_gasit;i++)
    {
        puts(site_cu_cuvinte[i].url);
    }
    //site_cu_cuvinte nu are continut alocat, deci nu trebuie eliberat
    free(site_cu_cuvinte);
    return 0;
}
