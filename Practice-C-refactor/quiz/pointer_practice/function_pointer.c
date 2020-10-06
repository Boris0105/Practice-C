#include <stdio.h>
#include <stdlib.h>

int func(int a, int b){

return a+b;

};


int add_function(int a, int b, int(*func_ptr)(int, int)) {
int c;
c=func_ptr(a,b);
return c;

};

int main(int argc, char* argv[])
{

int d=add_function(10,20,func);
printf("%d\n",d);

return 0;

}
