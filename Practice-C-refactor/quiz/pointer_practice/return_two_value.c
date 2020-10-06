#include <stdio.h>
 
void func(int x, int y, int *a, int *b) {
 *a = x;
 *b = y;
}
 
int main() {
 int x = 2;
 int y = 3;
 int a;
 int b;
  
func(x, y, &a, &b);
 printf("a = %d\n", a);
 printf("b = %d\n", b);
}