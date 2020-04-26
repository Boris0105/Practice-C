#include <stdio.h>
#include<stdlib.h>
#include<time.h>

//void arrayRand(int[10]);
//int arrayMax(int[10]);
//void arrayPrint(int[10]);


void main() {
    //srand(time(0));
    int v[4][4]={
	    {1,2,3,4},
	    {6,7,8,9},
	    {11,12,13,14},
	    {16,17,18,19}
    };
   
    //arrayRand(v);
    //arrayPrint(v);
    printf("%d\n",v[3][3]);
   
}




/*
int arrayMax(int v[10]) {
	int max=v[0],i;
	for (i=1; i<10; i++){
		    if (v[i]>max) {
		    max = v[i];
		    }
		
		}
	return max;

}
*/





/*
void arrayRand(int v[10]) {
	int i;
	for (i=0; i<10; i++) {
	   v[i] = rand() % 100;
	}
      //arrayrand function cannot return array to main since the rule in C
      //Transfer array between each function is based on same array not copy
      //Follow this rule, modify array in each function you need 

}
*/

/*
void arrayPrint(int v[10]) {

     int i;
     for (i=0; i<10; i++) {
         printf("%d\n",v[i]);
     
     }     
     printf("\n");
}

*/

/*

int main() {
   srand(time(0));
   int v[10];
   arrayRand(v);
   arrayPrint(v);
   printf("Max: %d\n", arrayMax(v));
   return 0;
}
*/
