#include <stdio.h>
#include <stdlib.h>

struct multime {
    unsigned int n;
    unsigned char *a;
};

void init(struct multime *m,int q)
{
    m->a=(unsigned char*)malloc((q)*sizeof(unsigned char));
    m->n=q;
    for(int i=0;i<=(m->n);i++)
        m->a[i]=0;
}

void add(struct multime *m, int x)
{
    int i;
    if(m->n<x/8)
    {
        m->a=(unsigned char*)realloc(m->a,((x)/8+1)*sizeof(unsigned char));
        for(i=(m->n);i<=(x)/8;i++)
            m->a[i]=0;
        m->n=(x)/8+1;
    }
    i=x/8;
    x=1<<(x%8);
    m->a[i]=(m->a[i])|x;
}

void del(struct multime *m, int x)
{
    int i=x/8;
    x=1<<(x%8);
    x=~x;
    m->a[i]=(m->a[i])&x;
}

void print(struct multime *m)
{
    int i,j;
    for(j=0;j<(m->n);j++)
    {
        for(i=0;i<8;i++)
        {
            if(m->a[j]&(1<<i))
                printf("%d ",i+j*8);
        }
    }
    printf("\n");
}

int contains(struct multime *m, int x)
{
    int i;
    i=x/8;
    x=1<<(x%8);
    if(m->a[i]&(x))
        return 1;
    return 0;
}

int main()
{
    struct multime mult;
    int p,i,nr,q=2;
    char c[2];
    scanf("%d",&p);
    mult.n=2;
    init(&mult,q);
    for(i=0;i<p;i++)
    {
        scanf("%s",c);
        switch(c[0])
        {
            case 'A':
            {
                scanf("%d",&nr);
                add(&mult,nr);
                break;
            }
            case 'D':
            {
                scanf("%d",&nr);
                del(&mult,nr);
                break;
            }
            case 'C':
            {
                scanf("%d",&nr);
                if(contains(&mult,nr))
                    printf("DA\n");
                else
                    printf("NU\n");
                break;
            }
            case 'P':
            {
                print(&mult);
                break;
            }
        }
    }
    return 0;
}
