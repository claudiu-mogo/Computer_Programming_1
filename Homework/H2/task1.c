#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* In acest task, am incarcat absolut toate componentele unui site
in baza de date, iar la final am afisat url-ul, nr vizualizari si titlul.
Am utilizat o enumerare pt culori si un struct SITE pt componente.
site reprezinta un vector de structuri SITE, in care vom stoca informatiile.
*/

//enumeratia "background" de culori pt text si fundal
typedef enum {white,black,red,green,blue,yellow} background;

//structura in sine
//url, lungime, titlu, accesari, checksum-> self-explanatory
//cod- sir de caractere alocat dinamic, contine tot html-ul siteului
//continut- contine doar continutul unui site (intre p-uri)
//text-culoarea textului; fundal-culoarea fundalului;
//nume_fis- contine numele fisierului ce are detaliile siteului
typedef struct
{
    char url[51],titlu[51],*cod,*continut,nume_fis[31];
    int accesari,checksum,lungime;
    background text,fundal;
}SITE;

//alocam culori textului si fundalului
//toate culorile au a3a litera diferita si profitam
//point 1 reprezinta locul unde ne aflam in tag
void switch_culori(char *point1, SITE *site)
{
    char *point3;
    switch(point1[0])
    {
        //daca incepe cu c "color"
        case 'c':
        {
            point3=strstr(point1,":");
            switch(point3[3])
            {
                case 'd':
                    site->text=red;
                    break;
                case 'a':
                    site->text=black;
                    break;
                case 'i':
                    site->text=white;
                    break;
                case 'e':
                    site->text=green;
                    break;
                case 'u':
                    site->text=blue;
                    break;
                case 'l':
                    site->text=yellow;
                    break;
                default:
                    site->text=black;
            }
            break;
        }
        //daca incepe cu b "background"
        case 'b':
        {
            point3=strstr(point1,":");
            switch(point3[3])
            {
                case 'd':
                    site->fundal=red;
                    break;
                case 'a':
                    site->fundal=black;
                    break;
                case 'i':
                    site->fundal=white;
                    break;
                case 'e':
                    site->fundal=green;
                    break;
                case 'u':
                    site->fundal=blue;
                    break;
                case 'l':
                    site->fundal=yellow;
                    break;
                default:
                    site->fundal=white;
            }
            break;
        }
    }
}

//parsarea titlului, ne miscam intre pointeri
void titlul(SITE *site1)
{
    char *point1,*point2;
    int j=0;
    point1=strstr(site1->cod,"<title>");
    point2=strstr(site1->cod,"</title>");
    point1+=7; //trecem imediat dupa <title>
    while(point1!=point2)
    {
        site1->titlu[j++]=(point1[0]);
        point1++;
    }
    site1->titlu[j]='\0';
}

//parsarea continutului, tot cu miscare de pointeri
void continutul(SITE *site1)
{
    char *point1,*point2,*point3;
    int j;
    point1=strstr(site1->cod,"<p>");
    point2=strstr(site1->cod,"</p>");
    if(point1)
    {
        //daca tagul este <p>
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
        //daca tagul cuprinde cel putin o culoare
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
        //pentru culori
        point1+=10;
        switch_culori(point1,site1);
        //verificam daca mai exista si al 2lea tag de culori
        point3=strstr(point1,";");
        point1=point3+1;
        switch_culori(point1,site1);
    }
}

int main()
{
    FILE *f, *f1;
    SITE *site;
    int i=0,j,memorie=3;
    char html_de_citit[31],vect[101];
    //alocam memorie vectorului de siteuri
    site=(SITE *)malloc(memorie*sizeof(SITE));
    //deschidem si citim din master
    f=fopen("master.txt","r");
    if(f)
    {
        while(fgets(html_de_citit,31,f)!=NULL)
        {
            //scapam de '\n'-ul de la final
            html_de_citit[strcspn(html_de_citit,"\n")]=0;
            //deschidem si citim din fiecare site
            f1=fopen(html_de_citit,"r");
            if(f1)
            {
                //i -> la al cata-lea site suntem
                if(i%3==0&&i>0)
                {
                    memorie+=3;
                    site=(SITE *)realloc(site,memorie*sizeof(SITE));
                }
                //citim prima linie
                fscanf(f1,"%s",site[i].url);
                fscanf(f1,"%d",&site[i].lungime);
                fscanf(f1,"%d",&site[i].accesari);
                fscanf(f1,"%d",&site[i].checksum);
                fgetc(f1);
                strcpy(site[i].nume_fis,html_de_citit);
                //culori default
                site[i].fundal=white;
                site[i].text=black;
                site[i].cod=(char *)malloc((site[i].lungime+1)*sizeof(char));
                site[i].cod[0]='\0';
                while(fgets(vect,101,f1))
                {
                    strcat(site[i].cod,vect);
                }
                //obtinerea titlului (deloc concerning)
                titlul(&site[i]);
                //obtinerea continutului (si mai putin concerning)
                continutul(&site[i]);
                fclose(f1);
                i++;
            }
        }
        fclose(f);
    }
    //afisare si eliberare de memorie
    for(j=0;j<i;j++)
    {
        printf("%s %d ",site[j].url,site[j].accesari);
        puts(site[j].titlu);
        free(site[j].cod);
        free(site[j].continut);
    }
    free(site);
    return 0;
}
