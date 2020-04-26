#include <stdio.h>
#include "20200419.h"

int amb_scale(int ambTemp)
{
  if (ambTemp<22)
  {
	  return 1;

  } else if (ambTemp>=22 && ambTemp<27)
  {
          return 2;

  } else if (ambTemp>=27 && ambTemp<30)
  {
          return 3;

  } else if (ambTemp>=30 && ambTemp<35)
  { 
          return 4;

  } else if (ambTemp>=35 && ambTemp<40)
  {       
	  return 5;

  } else if (ambTemp>=40 && ambTemp<45)
  {
          return 6;

  } else if (ambTemp>45)	
  {       
	  return 7;
  };  

}


int power_scale(int power_ratio)

{
  if (power_ratio <0.2)
  {
     return  1;
  }
  else if (power_ratio>= 0.2 && power_ratio <0.4) 
  {
     return  2;
  }
  else if (power_ratio>= 0.4 && power_ratio < 0.6)
  {
     return  3;
  }
  else if (power_ratio>=0.6 && power_ratio < 0.8)
  {
     return  4;
  }
  else if (power_ratio>=0.8)
  {  return  5;
  };

}



int ambientSetting(int ambTemp)
{
	int scale = amb_scale(ambTemp);
	int amb_PWM = power_band_table[1][scale];
         return amb_PWM;	
}



int C_PowerBand(int CPU_TDP, int Power, int ambTemp)
{
//PWN(n) = AmbTemp + WN(n-1) + ERR(n) - ERR(n-1)
////ERR(n) = n + 1e
//      
//
//
        /*int power_band_table[6][8] ={{0,22,27,30,35,40,45,50},
		                     {0.2,20,21,22,23,24,25,26},
			             {0.4,27,28,29,30,31,32,33},
				     {0.6,34,35,36,37,38,39,40},
				     {0.8,41,42,43,44,45,46,47},
			             {1,48,49,50,51,52,53,54}
	};
	*/
        int A =0;
	int B =0;
	float power_ratio = Power/CPU_TDP;
	/*
	if (power_ratio <= 0.2)
	{
		A=1;
	} else if (power_ratio > 0.2 && power_ratio <= 0.4)
	{
		A=2;
	} else if (power_ratio > 0.4 && power_ratio <= 0.6)
	{
		A=3;
	} else if (power_ratio > 0.6 && power_ratio <= 0.8)
	{
	        A=4;
	} else if (power_ratio >0.8)
	{
		A=5;
        };
	
	*/
	A =power_scale(power_ratio);
        B =amb_scale(ambTemp);
  	int C =power_band_table[A][B];
	
	

}

void compareAndStorePWM(enum fanInstant fanIndex)
{       

        /*int power_band_talbe[6][8] ={{0,22,27,30,35,40,45,50},
	                            {0.2,20,21,22,23,24,25,26},
			            {0.4,27,28,29,30,31,32,33},
			            {0.6,34,35,36,37,38,39,40},
			            {0.8,41,42,43,44,45,46,47},
				    {1,48,49,50,51,52,53,54}
	};
        */


	int max = 0;
	int current = 0;
	printf("Fan[%d] =======>\n", fanIndex);
	for (int i = 0; i < (sizeof(mappingTable) / sizeof(struct deviceFanMapping)); i++) {
		if (mappingTable[i].fan != fanIndex)
			continue;

		if (mappingTable[i].entity == ENTITY_AMB) {
			current = ambientSetting(25);
			printf("AMB setting = %d\n", current);
		} else if (mappingTable[i].entity == ENTITY_PROCESSOR) {
			current = C_PowerBand(250,250,25);
			printf("CPU = %d\n", current);
		}
		max = (max > current) ? max : current;
	}
	PWM[fanIndex] = max;
	printf("Max: %d \n <========\n\n", PWM[fanIndex]);
}

int main()
{      
	for (int i = 0; i < FAN_NUM; i++)
		compareAndStorePWM(i);
}
