#include <stdio.h>
double sum(double a, double b);
double product(double a, double b);

int main(void)
{

double (*pf_it)(double, double);

pf_it=product; //pf_it 
printf("5*8=%f\n", pf_it(5,8));
pf_it=sum;
printf("5*(2+6)+3=%f\n",pf_it(product(5,pf_it(2,6)),3));
getchar();
return 0;

}


double product(double a, double b)
{
return a*b;

}


double sum(double a, double b)
{
return a+b;

}
