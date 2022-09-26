#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* In aceasta problema vom considera o matrice,
aceasta va avea pe fiecare linie cate o pereche de cuvinte
si un vector double pentru gradele anagramelor.
grad[i] este gradul anagramei de pe linia i din matrice
Ne propunem sa verificam daca 2 cuvinte sunt anagrame,
sa le calculam gradul, iar la final sa le ordonam
*/

//bubble sort pentru vectori cu elemente intregi
//ok==1 - vector ordonat; ok==0 - vector neordonat
void bubble(int *v, int n)
{
    int i,ok,aux;
    do{
        ok=1;
        for(i=0;i<n-1;i++)
        {
            if(v[i]>v[i+1])
            {
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                ok=0;
            }
        }
        n--;
    }while(!ok);
}

//functie pentru determinarea existentei unei anagrame
//0->nu este anagrama; 1->este anagrama
//am luat fiecare cuvant, am transformat literele in numere si am ordonat
//daca vectorii ordonati sunt identici, atunci sunt anagrame
int is_anagram(char *s1, char *s2)
{
    int aux1[50],aux2[50],i;
    if(strlen(s1)!=strlen(s2))
        return 0;
    else
    {
        for(i=0;i<strlen(s1);i++)
            aux1[i]=(s1[i]-'0');
        for(i=0;i<strlen(s2);i++)
            aux2[i]=(s2[i]-'0');
        bubble(aux1,strlen(s1));
        bubble(aux2,strlen(s2));
        for(i=0;i<strlen(s1);i++)
            if(aux1[i]!=aux2[i])
                return 0;
        return 1;
    }
}

//functie pentru calcularea gradelor cu o formula pentru suprapuneri
//variabila suparpuneri arata cate litere se afla pe aceeasi pozitie
//daca sunt anagrame sirurile vor avea aceeasi lungime,
//de aceea folosim doar strlen(s1)
double compute_grade(char *s1, char *s2)
{
    int suprapuneri=0,i;
    double grad;
    if(!is_anagram(s1,s2))
        return -1;
    else
    {
        for(i=0;i<strlen(s1);i++)
        {
            if(s1[i]==s2[i])
                suprapuneri++;
        }
        grad=(double)(strlen(s1)-suprapuneri)/strlen(s1);
        return grad;
    }
}

//cu bubble sort ordonam descrescator dupa grade
//daca gradele sunt egale comparam liniile matricei cu strcmp
void ordonare_multipla(char mat[][101],double *grade,int n)
{
    int i,ok;
    double aux1;
    char aux2[101];
    do{
        ok=1;
        for(i=0;i<n-1;i++)
        {
            if(grade[i]<grade[i+1])
            {
                aux1=grade[i];
                grade[i]=grade[i+1];
                grade[i+1]=aux1;
                ok=0;
                strcpy(aux2,mat[i]);
                strcpy(mat[i],mat[i+1]);
                strcpy(mat[i+1],aux2);
            }
            else
            {
                if(grade[i]==grade[i+1]&&(strcmp(mat[i],mat[i+1])<0))
                {
                    ok=0;
                    strcpy(aux2,mat[i]);
                    strcpy(mat[i],mat[i+1]);
                    strcpy(mat[i+1],aux2);
                }
            }
        }
        n--;
    }while(!ok);
}

//ne folosim de 2 siruri s1 si s2 pentru a face compute_grade
//apoi concatenam sirurile pentru a face matricea de stringuri
void citire(char mat[][101],double *grade,int n)
{
    int i;
    char s1[50],s2[50];
    for(i=0;i<n;i++)
    {
        scanf("%s",s1);
        scanf("%s",s2);
        grade[i]=compute_grade(s1,s2);
        strcpy(mat[i],s1);
        strcat(mat[i]," ");
        strcat(mat[i],s2);
    }
}

int main()
{
    char mat[1000][101];
    double grade[1000];
    int n,i;
    scanf("%d",&n);
    citire(mat,grade,n);
    ordonare_multipla(mat,grade,n);
    for(i=0;i<n;i++)
        printf("%s\n",mat[i]);
    return 0;
}
