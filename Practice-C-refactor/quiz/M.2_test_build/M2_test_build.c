#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M2_critical 84

int system_amb=35;


 





int check_amb_temp(int M2_temp, int system_amb)
{



	if (M2_temp >= M2_critical)
	{	
		return 100;
	}
	
	else if (M2_temp < 45)
	{
		if (system_amb<=55)
		{
			return 25;
		}
		else 
		{
			return 100;	
		}
		

	}
	
	else if (M2_temp  <= 65 )
	{
		if (system_amb <=40)
		{
			return 30;
		}
		else 
		{
			return 100;	
		}
	

	}
	
	else if (M2_temp > 65)
	{
		if (system_amb <= 25)
		{
			return 30;
		}
		else 
		{
			return 100;	
		} 
		
	}


};





int main()
{
	
	while(1)
	{
		
		
	  srand( time(NULL) );

	/* 指定亂數範圍 */
	int min = 35;
	int max = 80;

	//int min_1 =20;
	//int max_1 =35;

	/* 產生 [min , max] 的整數亂數 */
	int M2_temp = rand() % (max - min + 1) + min;
    //int system_amb =rand() % (max_1 -min_1 +1) + min_1;
	printf("M2_temp= %d\n",M2_temp);
  
	
	int PWM;
	PWM= check_amb_temp(M2_temp,system_amb);
	printf("M.2_temp=%d,system_amb=%d\n",M2_temp,system_amb);
	printf("System_Fan_duty_output=%d\n", PWM);
	sleep(2);

	};
	
	
}
