#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	float a,b,c,aux;
	scanf("%f %f %f",&a,&b,&c);
	if(a>b)
	{
		aux=a;
		a=b;
		b=aux;
	}
	if(b>c)
	{
		aux=b;
		b=c;
		c=aux;
	}
	if(a>b)
	{
		aux=a;
		a=b;
		b=aux;
	}
	if(b-a<= 0.001||c-b<=0.001||c-a<=0.001)
	{
		if(b-a<=0.001&&c-b<=0.001)
		{
			printf("echilateral\n");
		}
		else
		{
			if(fabs(c*c-a*a-b*b)<=0.001)
				printf("dreptunghic isoscel\n");
			else
				printf("isoscel\n");
		}
	}
	else
	{
		if(fabs(c*c-a*a-b*b)<=0.001)
			printf("dreptunghic\n");
		else
			printf("oarecare\n");
	}

	return 0;
}
