#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* In acest task, ca si la task 2, vom salva intr-un vector de siteuri,
numit site_cu_cuvinte, acele siteuri care contin cel putin un cuvant bun
si niciunul din cele precedate de -, urmand a sorta vectorul.
Strategia este de a exclude intai siteurile ce contin cuvinte cu -,
urmand, ca mai apoi, sa le alegem pe cele ce contin cuvinte bune*/

//incarcare baza de date
//valid-> posibilitatea de a fi incarcat in site_cu_cuvinte,
//pentru a evita duplicatele
//valid=0 -> a fost deja incarcat sau contine cuvinte cu -
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
        //tagul contine doar secventa <p>
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
        //tagul contine cel putin o culoare
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

//functie care pune in site_cu_cuvinte siteurile ce respecta conditiile
int parsare_site_cuvinte(SITE *site_cu_cuvinte,SITE *site,int nr)
{
    int i,dim_site=0,k;
    char linie[101],rezerva[101],cuvant[101],*p;
    for(i=0;i<nr;i++)
        site[i].valid=1;
    fgets(linie, 101, stdin);
    //strtok formateaza linia citita, avem nevoie de o rezerva
    strcpy(rezerva,linie);
    //excludere siteuri cu cuvinte cu -
    //parcurgem toata linia
    for(k=0;k<strlen(linie);k++)
    {
        //cand avem ghilimele sarim peste ele
        if(rezerva[k]=='\"')
        {
            k++;
            while(rezerva[k]!='\"')
                k++;
        }
        //daca gasim un "-" intai vedem daca nu este in cuvant ex: Cluj-Napoca
        if((rezerva[k]=='-')&&(k==0||rezerva[k-1]==' '))
        {
            if(rezerva[k+1]!=' '&&rezerva[k+1]!='\n')
            {
                //din pozitia actuala, scoatem cuvantul din linie(rezerva)
                //si invalidam siteurile ce il contin
                char *word=strtok(rezerva+k+1," \n");
                for(i=0;i<nr;i++)
                {
                    p=strstr(site[i].continut,word);
                    if(p!=NULL)
                    {
                        //verificam cazul cuvant in cuvant
                        if((p==site[i].continut || !isalpha(p[-1])) &&
                        (p[strlen(word)]==0 || !isalpha(p[strlen(word)])))
                            site[i].valid=0;
                    }
                }
            }
        }
    }
    //verificare siteuri cu cuvinte bune
    //parcurgem toataa linia
    for(k=0;k<strlen(linie);k++)
    {
        //nu putem da strtok, salvam fiecare cuvant in sir de caractere
        cuvant[0]='\0';
        int poz_cuv=0; //lungimea cuvantului/secventei
        //daca gasim " ii cautam perechea
        if(linie[k]==34)
        {
            k++;
            while(linie[k]!=34)
            {
                cuvant[poz_cuv++]=linie[k++];
            }
            cuvant[poz_cuv]='\0';
            //cautare de siteuri ce contin cuvant/secventa
            for(i=0;i<nr;i++)
            {
                p=strstr(site[i].continut,cuvant);
                if(p!=NULL&&site[i].valid==1)
                {
                    //verificare cuvant in cuvant
                    if((p==site[i].continut||!isalpha(p[-1]))&&
                   (p[strlen(cuvant)]==0||!isalpha(p[strlen(cuvant)])))
                   {
                       site[i].valid=0;
                       site_cu_cuvinte[dim_site++]=site[i];
                   }
                }
            }
        }
        else
        {
            //daca dam de spatiu si nu este intre ", asamblam un cuvant normal
            if(linie[k]!=' '&&linie[k]!='\n'&&linie[k]!='\0')
            {
                while(linie[k]!=' '&&linie[k]!='\n')
                {
                    cuvant[poz_cuv++]=linie[k++];
                }
                cuvant[poz_cuv]='\0';
                //verificare
                for(i=0;i<nr;i++)
                {
                    p=strstr(site[i].continut,cuvant);
                    if(p!=NULL&&site[i].valid==1)
                    {
                        //caz cuvant in cuvant
                        if((p==site[i].continut||!isalpha(p[-1]))&&
                       (p[strlen(cuvant)]==0||!isalpha(p[strlen(cuvant)])))
                       {
                           site[i].valid=0;
                           site_cu_cuvinte[dim_site++]=site[i];
                       }
                    }
                }

            }
        }
    }
    return dim_site;
}

//comparare dupa accesari
int comparare(SITE *site1,SITE *site2)
{
    if(site1->accesari>site2->accesari)
        return 1;
    return -1;
}

//sortare bubble sort cu functie de comparare
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
    SITE *site,*site_cu_cuvinte;
    int i=0,dim_site,memorie=3,k;
    char html_de_citit[31],vect[101];
    site=(SITE *)malloc(memorie*sizeof(SITE));
    //deschidere master
    f=fopen("master.txt","r");
    if(f)
    {
        while(fgets(html_de_citit,31,f)!=NULL)
        {
            //scapam de '\n'-ul de la final
            html_de_citit[strcspn(html_de_citit,"\n")]=0;
            //deschidere fisiere din master
            f1=fopen(html_de_citit,"r");
            if(f1)
            {
                if(i%3==0&&i>0)
                {
                    memorie+=3;
                    site=(SITE *)realloc(site,memorie*sizeof(SITE));
                }
                //creare baza de date
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
    //creare si sortare site_cu_cuvinte
    site_cu_cuvinte=(SITE *)malloc(memorie*sizeof(SITE));
    dim_site=parsare_site_cuvinte(site_cu_cuvinte,site,i);
    sortare(site_cu_cuvinte,dim_site,comparare);
    //afisare si eliberare de memorie
    //i - nr total de siteuri
    for(k=0;k<i;k++)
    {
        free(site[k].cod);
        free(site[k].continut);
    }
    free(site);
    //dim_site - nr de site_cu_cuvinte
    for(i=0;i<dim_site;i++)
    {
        puts(site_cu_cuvinte[i].url);
    }
    //site_cu_cuvinte nu are memorie alocata pt continut
    free(site_cu_cuvinte);
    return 0;
}
