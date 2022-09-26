#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*In aceasta problema vom face matricele din numere intregi
Astfel ne va fi mai usor la calcul
Facem cele 3 matrice cerute si calculam scorul pentru fiecare,
iar la final facem o functie pentru departajare */

//facem schimbarile clasice ale bazei cu impartire, respectiv puteri de 2
void dec_to_bin(int n, char *s)
{
    int i;
    for(i=0;i<8;i++)
        s[i]='0';
    while(n)
    {
        s[--i]=n%2+'0';
        n/=2;
    }
    s[8]='\0';
}

int bin_to_dec(char *s)
{
    int n=0,putere=1,i;
    for(i=7;i>=0;i--)
    {
        n+=putere*(s[i]-'0');
        putere*=2;
    }
    return n;
}

//pune in produs a*b
void inmultire_matrice(int a[][8],int b[][8],int produs[][8])
{
    int i,j,s,k;
    for(i=0;i<8;i++)
    {
        for(k=0;k<8;k++)
        {
            s=0;
            for(j=0;j<8;j++)
            {
                s+=a[i][j]*b[j][k];
            }
            if(s)
                produs[i][k]=1;
            else
                produs[i][k]=0;
        }
    }
}

//face at transpusul lui a
void transpus(int a[][8],int at[][8])
{
    int i,j;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            at[j][i]=a[i][j];
}

//verificam daca exista o linie plina de 1
int verif_lin(int mat[][4])
{
    int i,j,count=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(mat[i][j]==0)
                break;
        }
        if(j==4)
            count++;
    }
    return count;
}

//verificam daca exista o coloana plina de 1
int verif_col(int mat[][4])
{
    int i,j,count=0;
    for(j=0;j<4;j++)
    {
        for(i=0;i<4;i++)
        {
            if(mat[i][j]==0)
                break;
        }
        if(i==4)
            count++;
    }
    return count;
}

//verificam daca exista vreo diagonala plina de 1
int verif_diag(int mat[][4])
{
    int i,count=0;
    for(i=0;i<4;i++)
        if(mat[i][i]==0)
                break;
    if(i==4)
        count++;
    for(i=0;i<4;i++)
        if(mat[i][3-i]==0)
            break;
    if(i==4)
        count++;
    return count;
}

//calculeaza scorul pt matricea m
int sum_X_0(int m[][8])
{
    int a[4][4],i,j,s=0;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            a[i][j]=m[i][j];
    s+=verif_lin(a)+verif_col(a)+verif_diag(a);
    for(i=0;i<4;i++)
        for(j=4;j<8;j++)
            a[i][j-4]=m[i][j];
    s+=verif_lin(a)+verif_col(a)+verif_diag(a);
    for(i=4;i<8;i++)
        for(j=0;j<4;j++)
            a[i-4][j]=m[i][j];
    s+=verif_lin(a)+verif_col(a)+verif_diag(a);
    for(i=4;i<8;i++)
        for(j=4;j<8;j++)
            a[i-4][j-4]=m[i][j];
    s+=verif_lin(a)+verif_col(a)+verif_diag(a);
    return s;
}

//compara scorurile matricelor a b c si face departajarea la egalitate
void afisare_castigator(int a[][8],int b[][8],int c[][8])
{
    int x,y,z,i,j;
    char s[9];
    s[8]='\0';
    x=sum_X_0(a);
    y=sum_X_0(b);
    z=sum_X_0(c);
    if(x>=y&&x>=z)
    {
        for(i=0;i<8;i++)
        {
            //tansformam din int in char
            for(j=0;j<8;j++)
                s[j]=(a[i][j]+'0');
            printf("%d\n",bin_to_dec(s));
        }
    }
    else
    {
        if(y>=z&&y>=x)
        {
            for(i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                    s[j]=(b[i][j]+'0');
                printf("%d\n",bin_to_dec(s));
            }
        }
        else
        {
            for(i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                    s[j]=(c[i][j]+'0');
                printf("%d\n",bin_to_dec(s));
            }
        }
    }
}

//Avem matricele a, a2=A^2, at= a transpus, axat= a*at
int main()
{
    int i,nr,j,a[8][8],a2[8][8],at[8][8],axat[8][8];
    char s[9];
    for(i=0;i<8;i++)
    {
        scanf("%d",&nr);
        dec_to_bin(nr,s);
        //transformam din char in int
        for(j=0;j<8;j++)
            a[i][j]=(s[j]-'0');
    }
    transpus(a,at);
    inmultire_matrice(a,at,axat);
    inmultire_matrice(a,a,a2);
    afisare_castigator(a,axat,a2);
    return 0;
}
