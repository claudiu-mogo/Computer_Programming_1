#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float dist(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

int main()
{
    int x1,y1,x2,y2,mat[101][1],n,i,j;
    float dmax=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&mat[i][0],&mat[i][1]);
        for(j=0;j<i;j++)
        {
            if(dist(mat[i][0],mat[i][1],mat[j][0],mat[j][1])>dmax)
                {
                    x1=mat[i][0];
                    y1=mat[i][1];
                    x2=mat[j][0];
                    y2=mat[j][1];
                    dmax=dist(mat[i][0],mat[i][1],mat[j][0],mat[j][1]);
                }
        }
    }
    printf("%d %d\n%d %d\n%f",x1,y1,x2,y2,dmax);
    return 0;
}
