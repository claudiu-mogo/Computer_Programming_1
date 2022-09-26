#include <stdio.h>
#include <stdlib.h>

int minim(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}

int maxim(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int arie_intersectie(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22)
{
    int ymin,xmin,ymax,xmax;
    ymin=maxim(y12,y22);
    xmin=maxim(x11,x21);
    xmax=minim(x12,x22);
    ymax=minim(y11,y21);
    if(ymin>ymax||xmin>xmax)
        return 0;
    return ((ymax-ymin)*(xmax-xmin));
}

int main()
{
    int x11,y11,x12,y12,x21,y21,x22,y22;
    scanf("%d%d%d%d%d%d%d%d",&x11,&y11,&x12,&y12,&x21,&y21,&x22,&y22);
    printf("%d",arie_intersectie(x11,y11,x12,y12,x21,y21,x22,y22));
    return 0;
}
