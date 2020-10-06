 #include<stdio.h>
 #include<stdio.h>
 

 int a[5] = {23, 5, 33, 7, 82};
 int b[5]; 

void main()
{
for(int i=0;i<5;i++){
	b[i]= a[i]/10;
	printf("quotient of a[%d]=%d\n",i,b[i]);
}
} 

