#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Fiecare fata a cubului este pusa sub forma unei matrice;
Folosim o matrice de caractere, fiecare linie fiind o culoare;
pentru fiecare comanda primita facem rotire de fata si una a liniilor
Vom lucra cu codurile culorilor,
reprezentate de nr liniei pe care se afla culoarea in matrice
*/

//transpunem in matrice codurile culorilor aferente
void creare_matrice(int m[][3],char culori[][11])
{
    int i,j,k;
    char s[37],*p;
    for(i=0;i<3;i++)
    {
        j=0;
        scanf("%s",s);
        s[strlen(s)]='\0';
        getchar();
        p=strtok(s,". ");
        while(p!=NULL)
        {
            for(k=0;k<6;k++)
            {
                if(!strcmp(p,culori[k]))
                {
                    m[i][j]=k;
                    break;
                }
            }
            p=strtok(NULL,". ");
            j++;
        }
    }
}

//rotim clockwise o fata
void rotatie_fata_normal(int mat[][3])
{
    int aux1,aux2,aux3,i;
    aux1=mat[0][0];
    aux2=mat[0][1];
    aux3=mat[0][2];
    for(i=2;i>=0;i--)
        mat[0][i]=mat[2-i][0];
    for(i=0;i<3;i++)
        mat[i][0]=mat[2][i];
    for(i=0;i<3;i++)
        mat[2][i]=mat[2-i][2];
    mat[0][2]=aux1;
    mat[1][2]=aux2;
    mat[2][2]=aux3;
}

//rotim trigonometric fata
void rotatie_fata_prim(int mat[][3])
{
    rotatie_fata_normal(mat);
    rotatie_fata_normal(mat);
    rotatie_fata_normal(mat);
}

//fiecare din urmatoarele functii modifica fetele conform mutarii
void UP(int front1[][3],int back2[][3],int left5[][3],int right6[][3])
{
    int aux0,aux1,aux2,i;
    aux0=front1[0][0];
    aux1=front1[0][1];
    aux2=front1[0][2];
    for(i=0;i<3;i++)
        front1[0][i]=right6[0][i];
    for(i=0;i<3;i++)
        right6[0][i]=back2[0][i];
    for(i=0;i<3;i++)
        back2[0][i]=left5[0][i];
    left5[0][0]=aux0;
    left5[0][1]=aux1;
    left5[0][2]=aux2;
}

void UPP(int front1[][3],int back2[][3],int left5[][3],int right6[][3])
{
    int aux0,aux1,aux2,i;
    aux0=front1[0][0];
    aux1=front1[0][1];
    aux2=front1[0][2];
    for(i=0;i<3;i++)
        front1[0][i]=left5[0][i];
    for(i=0;i<3;i++)
        left5[0][i]=back2[0][i];
    for(i=0;i<3;i++)
        back2[0][i]=right6[0][i];
    right6[0][0]=aux0;
    right6[0][1]=aux1;
    right6[0][2]=aux2;
}

void DOWN(int front1[][3],int back2[][3],int left5[][3],int right6[][3])
{
    int aux0,aux1,aux2,i;
    aux0=front1[2][0];
    aux1=front1[2][1];
    aux2=front1[2][2];
    for(i=0;i<3;i++)
        front1[2][i]=left5[2][i];
    for(i=0;i<3;i++)
        left5[2][i]=back2[2][i];
    for(i=0;i<3;i++)
        back2[2][i]=right6[2][i];
    right6[2][0]=aux0;
    right6[2][1]=aux1;
    right6[2][2]=aux2;
}

void DOWNP(int front1[][3],int back2[][3],int left5[][3],int right6[][3])
{
    int aux0,aux1,aux2,i;
    aux0=front1[2][0];
    aux1=front1[2][1];
    aux2=front1[2][2];
    for(i=0;i<3;i++)
        front1[2][i]=right6[2][i];
    for(i=0;i<3;i++)
        right6[2][i]=back2[2][i];
    for(i=0;i<3;i++)
        back2[2][i]=left5[2][i];
    left5[2][0]=aux0;
    left5[2][1]=aux1;
    left5[2][2]=aux2;
}

void RIGHT(int front1[][3],int back2[][3],int up3[][3],int down4[][3])
{
    int aux0,aux1,aux2,i;
    aux0=front1[0][2];
    aux1=front1[1][2];
    aux2=front1[2][2];
    for(i=0;i<3;i++)
        front1[i][2]=down4[i][2];
    for(i=0;i<3;i++)
        down4[i][2]=back2[2-i][0];
    for(i=0;i<3;i++)
        back2[2-i][0]=up3[i][2];
    up3[0][2]=aux0;
    up3[1][2]=aux1;
    up3[2][2]=aux2;
}

void RIGHTP(int front1[][3],int back2[][3],int up3[][3],int down4[][3])
{
    int aux0,aux1,aux2,i;
    aux0=front1[0][2];
    aux1=front1[1][2];
    aux2=front1[2][2];
    for(i=0;i<3;i++)
        front1[i][2]=up3[i][2];
    for(i=0;i<3;i++)
        up3[i][2]=back2[2-i][0];
    for(i=0;i<3;i++)
        back2[2-i][0]=down4[i][2];
    down4[0][2]=aux0;
    down4[1][2]=aux1;
    down4[2][2]=aux2;
}

void LEFT(int front1[][3],int back2[][3],int up3[][3],int down4[][3])
{
    int aux0,aux1,aux2,i;
    aux0=front1[0][0];
    aux1=front1[1][0];
    aux2=front1[2][0];
    for(i=0;i<3;i++)
        front1[i][0]=up3[i][0];
    for(i=0;i<3;i++)
        up3[i][0]=back2[2-i][2];
    for(i=0;i<3;i++)
        back2[2-i][2]=down4[i][0];
    down4[0][0]=aux0;
    down4[1][0]=aux1;
    down4[2][0]=aux2;
}

void LEFTP(int front1[][3],int back2[][3],int up3[][3],int down4[][3])
{
    int aux0,aux1,aux2,i;
    aux0=front1[0][0];
    aux1=front1[1][0];
    aux2=front1[2][0];
    for(i=0;i<3;i++)
        front1[i][0]=down4[i][0];
    for(i=0;i<3;i++)
        down4[i][0]=back2[2-i][2];
    for(i=0;i<3;i++)
        back2[2-i][2]=up3[i][0];
    up3[0][0]=aux0;
    up3[1][0]=aux1;
    up3[2][0]=aux2;
}

void FRONT(int left5[][3],int right6[][3],int up3[][3],int down4[][3])
{
    int aux0,aux1,aux2,i;
    aux0=right6[0][0];
    aux1=right6[1][0];
    aux2=right6[2][0];
    for(i=0;i<3;i++)
        right6[i][0]=up3[2][i];
    for(i=0;i<3;i++)
        up3[2][i]=left5[2-i][2];
    for(i=0;i<3;i++)
        left5[2-i][2]=down4[0][2-i];
    down4[0][2]=aux0;
    down4[0][1]=aux1;
    down4[0][0]=aux2;
}

void FRONTP(int left5[][3],int right6[][3],int up3[][3],int down4[][3])
{
    int aux0,aux1,aux2,i;
    aux0=right6[0][0];
    aux1=right6[1][0];
    aux2=right6[2][0];
    for(i=0;i<3;i++)
        right6[i][0]=down4[0][2-i];
    for(i=0;i<3;i++)
        down4[0][2-i]=left5[2-i][2];
    for(i=0;i<3;i++)
        left5[2-i][2]=up3[2][i];
    up3[2][0]=aux0;
    up3[2][1]=aux1;
    up3[2][2]=aux2;
}

void BACK(int left5[][3],int right6[][3],int up3[][3],int down4[][3])
{
    int aux0,aux1,aux2,i;
    aux0=right6[0][2];
    aux1=right6[1][2];
    aux2=right6[2][2];
    for(i=0;i<3;i++)
        right6[i][2]=down4[2][2-i];
    for(i=0;i<3;i++)
        down4[2][2-i]=left5[2-i][0];
    for(i=0;i<3;i++)
        left5[2-i][0]=up3[0][i];
    up3[0][0]=aux0;
    up3[0][1]=aux1;
    up3[0][2]=aux2;
}

void BACKP(int left5[][3],int right6[][3],int up3[][3],int down4[][3])
{
    int aux0,aux1,aux2,i;
    aux0=right6[0][2];
    aux1=right6[1][2];
    aux2=right6[2][2];
    for(i=0;i<3;i++)
        right6[i][2]=up3[0][i];
    for(i=0;i<3;i++)
        up3[0][i]=left5[2-i][0];
    for(i=0;i<3;i++)
        left5[2-i][0]=down4[2][2-i];
    down4[2][2]=aux0;
    down4[2][1]=aux1;
    down4[2][0]=aux2;
}

//functie de afisare a unei fete
void afisare_fata(int mat[][3],char culori[][11])
{
    int i;
    char s[37];
    for(i=0;i<3;i++)
    {
        strcpy(s,culori[mat[i][0]]);
        strcat(s,".");
        strcat(s,culori[mat[i][1]]);
        strcat(s,".");
        strcat(s,culori[mat[i][2]]);
        printf("%s\n",s);
    }
}

int main()
{
    int front1[3][3],back2[3][3],up3[3][3];
    int down4[3][3],left5[3][3],right6[3][3];
    char culori[6][11],cod[7];
    int i,n;
    for(i=0;i<6;i++)
    {
        scanf("%s",culori[i]);
    }

    getchar();
    creare_matrice(front1,culori);
    creare_matrice(back2,culori);
    creare_matrice(up3,culori);
    creare_matrice(down4,culori);
    creare_matrice(left5,culori);
    creare_matrice(right6,culori);
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        //cod reprezinta comanda primita (de genul F')
        scanf("%s",cod);
        //switch-ul face legatura dintre ce am primit si functii
        switch(cod[0])
        {
            case 'F':
            {
                if(cod[1]==39)
                {
                    rotatie_fata_prim(front1);
                    FRONTP(left5,right6,up3,down4);
                }
                else
                {
                    rotatie_fata_normal(front1);
                    FRONT(left5,right6,up3,down4);
                }
                break;
            }
            case 'B':
            {
                if(cod[1]==39)
                {
                    rotatie_fata_prim(back2);
                    BACKP(left5,right6,up3,down4);
                }
                else
                {
                    rotatie_fata_normal(back2);
                    BACK(left5,right6,up3,down4);
                }
                break;
            }
            case 'U':
            {
                if(cod[1]==39)
                {
                    rotatie_fata_prim(up3);
                    UPP(front1,back2,left5,right6);
                }
                else
                {
                    rotatie_fata_normal(up3);
                    UP(front1,back2,left5,right6);
                }
                break;
            }
            case 'D':
            {
                if(cod[1]==39)
                {
                    rotatie_fata_prim(down4);
                    DOWNP(front1,back2,left5,right6);
                }
                else
                {
                    rotatie_fata_normal(down4);
                    DOWN(front1,back2,left5,right6);
                }
                break;
            }
            case 'L':
            {
                if(cod[1]==39)
                {
                    rotatie_fata_prim(left5);
                    LEFTP(front1,back2,up3,down4);
                }
                else
                {
                    rotatie_fata_normal(left5);
                    LEFT(front1,back2,up3,down4);
                }
                break;
            }
            case 'R':
            {
                if(cod[1]==39)
                {
                    rotatie_fata_prim(right6);
                    RIGHTP(front1,back2,up3,down4);
                }
                else
                {
                    rotatie_fata_normal(right6);
                    RIGHT(front1,back2,up3,down4);
                }
                break;
            }
            default: printf("que?");
        }
    }

    afisare_fata(front1,culori);
    afisare_fata(back2,culori);
    afisare_fata(up3,culori);
    afisare_fata(down4,culori);
    afisare_fata(left5,culori);
    afisare_fata(right6,culori);

    return 0;
}
