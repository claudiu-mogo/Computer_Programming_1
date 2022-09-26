#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *v,cap,n;
}vector;

void init_vector(vector *a, int nr)
{
    a->v=(int*)malloc(nr*sizeof(int));
    a->cap=nr;
    a->n=0;
}

void adauga_vector(vector *a, int n)
{
    if(a->n==a->cap)
    {
        a->cap*=2;
        a->v=(int*)realloc(a->v,a->cap*sizeof(int));
    }
    a->v[a->n]=n;
    a->n++;
}

void scrie_vector(vector *a)
{
    int i;
    for(i=0;i<a->n;i++)
    {
        printf("%d ",a->v[i]);
    }
}

int main()
{
    vector vect;
    int i;
    init_vector(&vect,3);
    for(i=0;i<=100;i++)
    {
        adauga_vector(&vect,i);
        scrie_vector(&vect);
        printf("\n");
    }
    return 0;
}
