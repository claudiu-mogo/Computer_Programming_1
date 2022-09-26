#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void vectori(double *v, double *u)
{
    u[0]=acos((pow(v[2],2)+pow(v[1],2)-pow(v[0],2))/(2*v[1]*v[2]))*180/M_PI;
    u[1]=acos((pow(v[2],2)+pow(v[0],2)-pow(v[1],2))/(2*v[0]*v[2]))*180/M_PI;
    u[2]=acos((pow(v[0],2)+pow(v[1],2)-pow(v[2],2))/(2*v[1]*v[0]))*180/M_PI;
}

void argumente(double *a,double *b,double *c,double *d,double *e,double *f)
{
    *d=acos((pow(*c,2)+pow(*b,2)-pow(*a,2))/(2*(*b)*(*c)))*180/M_PI;
    *e=acos((pow(*c,2)+pow(*a,2)-pow(*b,2))/(2*(*a)*(*c)))*180/M_PI;
    *f=acos((pow(*a,2)+pow(*b,2)-pow(*c,2))/(2*(*b)*(*a)))*180/M_PI;
}

int main()
{
    double v[3],u[3],i,u1,u2,u3;
    scanf("%lf%lf%lf",&v[0],&v[1],&v[2]);
    vectori(v,u);
    printf("%.3lf %.3lf %.3lf\n",u[0],u[1],u[2]);
    argumente(&v[0],&v[1],&v[2],&u1,&u2,&u3);
    printf("%.3lf %.3lf %.3lf",u1,u2,u3);
    return 0;
}
