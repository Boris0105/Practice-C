#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define M 4   //基因成員
#define N 10  //基因字串長度

int farm[M][N];  //group
int temp[2][N];  //group

double a=0.0;    //Min.X
double b=32;     //Max.X
double x_value[M]; //x 區間值
double f_value[M]; //適應值
double x_temp[2];// 暫存
double f_temp[2]; //暫存


void setup()
{

time_t t;
int j,k;
srand((unsigned) time(&t));

for (j=0; j<M; j++) {
	for (k=0;k<N; k++) {
		farm[j][k]=rand()%2; //以0,1亂數產生母代
	
	  }

	}
}


void compute_f_value(int i) //計算適應值
{
int j,k;
double m,x;
m=0.0;

for (j=0; j<N; j++) {
	k=j;
	m=m+farm[i][N-j-1]*pow(2.0,k); //二進位轉十進位
	//編程時，調用到pow , gcc後面需加-lm
}

x_value[i]=a+m*(b-a)/(pow(2.0,N)-1.0);//轉換為區間值
x=x_value[i];
f_value[i]=x*x; //求適應值
}


void compute_f_temp(int i) //計算暫存適應值
{
int j,k;
double m,x;
m=0.0;

for (j=0;j<N; j++){
 k=j;
 m=m+temp[i][N-j-1]*pow(2.0,k);
 };

x_temp[i]=a+m*(b-a)/(pow(2.0,N)-1.0);
x=x_temp[i];
f_temp[i]=x*x;
}



void crossing() //交配
{
	int r1, r2, r3, j;
	r1=rand()%M; //選取欲交配基因
	r2=rand()%M;

	while (r2 == r1) {
	r2=rand()%M;

	}


	for (j=0; j<N; j++) {
	temp[0][j]=farm[r1][j];
	temp[1][j]=farm[r2][j];

	}

	r3=rand()%(N-2) +1; //計算交配點
	for (j=r3; j<N; j++) {
	temp[0][j]=farm[r2][j];
	temp[1][j]=farm[r1][j];
	}
	
	compute_f_temp(0);
	compute_f_temp(1);

	if (f_temp[0] > f_value[r1]) {
	for (j=0;j<N;j++) {
	farm[r1][j]=temp[0][j];
		}
	}
	
	if (f_temp[1] > f_value[r2]) {
	for (j=0;j<N;j++) {
	farm[r2][j]=temp[1][j];
			}
		}
	
	}

void mutate() //mutaiton
{
	
	int rn, rm;
	double a1, a2;
	rn=rand()%N;
	rm=rand()%M;
	a1=f_value[rm];
	farm[rm][rn]=1-farm[rm][rn];
	compute_f_value(rm);
	a2=f_value[rm];
	if (a1 > a2) farm[rm][rn]=1-farm[rm][rn];
}
	
	
void print_farm() //印出族群
{
	
	int i,j;
	for (i=0;i<M; i++){
		printf("farm[%2d]=", i);
		for (j=0; j<N;j++) {
			printf("%d", farm[i][j]);
		}
		printf("\n");
	}
	printf("\n");
			
}
	
	
void print_value()
{
	
	int i;
	for (i=0; i<M; i++) {
		compute_f_value(i);
		printf("x_value[%2d]=%8.4f   ", i,x_value[i]);
		printf("f_value[%2d]=%8.4f\n ", i,f_value[i]);
	}
	
	printf("\n");
}
	
	

void print_max()
{
	int i;
	double x_max, f_max;
	x_max=x_value[0];
	f_max=f_value[0];
	for (i=1; i<M; i++){
		if (f_value[i] > f_max){
			x_max=x_value[i];
			f_max=x_value[i];

		}
		
	}
	printf("x_max=%8.4f f_max=%8.4f\n\n", x_max, f_max);	
	
}

int main(void)
{
	int i,j;
	setup();
	print_farm();
	printf("=== GA Run Before ===\n");
	print_value();
	
	
	for (i=0;i<1100; i++){
		
		crossing();
		mutate();
	}
	
	printf("===GA Run After ===\n");
	print_value();
	print_max();
	
	//getchar();
	return 0;

}
