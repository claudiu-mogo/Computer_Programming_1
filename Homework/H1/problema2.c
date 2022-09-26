#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Consideram o matrice cu n linii si 2 coloane
Coloana 0 reprezinta linia tablei, iar 1 coloana pe care se afla nebunul
Verificam cati nebuni se ataca,
iar daca exista o singura pereche cautam pozitii libere
*/

//functie pentru calcularea numarului de atacuri intre nebuni
//putem verifica daca 2 nebuni se afla pe aceeasi diagonala cu o formula
//variabila count retine numarul de atacuri
//daca count va fi >=2 oricum nu vor mai conta index1,2
int atac_reciproc(int nebuni[][2],int n,int *index1, int *index2)
{
    int i,count=0,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(abs(nebuni[i][0]-nebuni[j][0])==abs(nebuni[i][1]-nebuni[j][1]))
            {
                count++;
                //in momentul in care detectam primul atac,
                //punem in index1,index2 cei 2 indici ai nebunilor care se ataca
                if(count==1)
                {
                    *index1=i;
                    *index2=j;
                }
            }
        }
    }
    return count;
}

//functie de switch intre 2 variabile intregi
void var_switch(int *a,int *b)
{
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
}

//aducem nebunii cu index1,2 pe primele pozitii
//astfel vor fi la indemana pentru verificari
void switch_nebuni(int nebuni[][2],int n)
{
    int count,index1=0,index2=0;
    count=atac_reciproc(nebuni,n,&index1,&index2);
    if(count==1)
    {
        var_switch(&nebuni[0][0],&nebuni[index1][0]);
        var_switch(&nebuni[0][1],&nebuni[index1][1]);
        var_switch(&nebuni[1][0],&nebuni[index2][0]);
        var_switch(&nebuni[1][1],&nebuni[index2][1]);
    }
}

//mutam pe rand cei 2 nebuni care se ataca
//intai ii punem pe primele 2 pozitii in matrice
//apoi ii plimbam pe toate pozitiile din tabla si verificam daca e ok
//ok==1 -> pozitie buna (sau presupusa buna)
//ok==0 -> pozitia nu a fost buna
void mutare(int nebuni[][2],int n,int m)
{
    int count,index1,index2,i,j,ok,k;
    count=atac_reciproc(nebuni,n,&index1,&index2);
    printf("%d\n",count);
    //daca count==1 problema practic se opreste
    if(count!=1)
        printf("NU\n");
    else
    {
        switch_nebuni(nebuni,n);
        //pentru primul nebun - verificam toate pozitiile
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                //presupunem ca pozitia este buna
                ok=1;
                for(k=1;k<n&&ok==1;k++)
                {
                    if(abs(nebuni[k][0]-i)==abs(nebuni[k][1]-j))
                        ok=0;
                }
                if(ok==1)
                    break;
            }
            if(ok==1)
                break;
        }
        if(ok==1)
            printf("DA\n");
        else
        {
            //interschimbam nebunii cu index 1 si 2 pt a usura scrierea
            var_switch(&nebuni[0][0],&nebuni[1][0]);
            var_switch(&nebuni[0][1],&nebuni[1][1]);
            //pentru nebunul 2 - care acum se afla pe prima pozitie in matrice
            //facem aceleasi operatii ca mai inainte
            for(i=0;i<m;i++)
            {
                for(j=0;j<m;j++)
                {
                    ok=1;
                    for(k=1;k<n&&ok==1;k++)
                    {
                        if(abs(nebuni[k][0]-i)==abs(nebuni[k][1]-j))
                            ok=0;
                    }
                    if(ok==1)
                        break;
                }
                if(ok==1)
                    break;
            }
            if(ok==1)
                printf("DA\n");
            else
                printf("NU\n");
        }
    }
}

int main()
{
    int m,n,i,nebuni[10000][2];
    scanf("%d",&m);
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d%d",&nebuni[i][0],&nebuni[i][1]);
    mutare(nebuni,n,m);
    return 0;
}
