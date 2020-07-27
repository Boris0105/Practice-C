#include "hwmon.h"
#include <unistd.h>
#include <time.h>

/*
void* SENSOR_Threshold(void*device_map_system_fanzone)

{

	device_map_system_fanzone* SENSOR_INFO;
	SENSOR_INFO= (device_map_system_fanzone*)device_map_system_fanzone;
	
	int FANZONE = device_map_system_fanzone -> PWM_Output;
	PWM_Output = PWM_Output + 1;
	
	printf("%PWM_Output: %d\n",PWM_Output);
	
	Tnon_critical_PWM-> PWM_Output =PWM_Output;

}

*/



/*
float get_tier_base_PWM(int i, int )
{
	
	
	
	
};


void*pcie_tier(void*device_map_system_fanzone)

{
	
	while(1)
	{
	sleep(2);
	int i;
	int AMB = get_sensorValue(ENTITY_Ambient_Sensor);
	int AMB_scale;
	printf("Amb sensor reading=%d\n",AMB);
	
	if(currentConfig->entity.fan_type.type== ENTITY_FAN_TYPE_STD)
	
	{
	
	
		//pthread_mutex_lock( &mutex1 );
		
		for (i=0; i<FAN_ZONE_NUM; i=i+3)
		{   
			
		AMB_scale=amb_STD_scale(AMB,i);	
		printf("Amb_scale_output =%d\n",AMB_scale);
		
		if(currentConfig->entity.PCI_type.type== ENTITY_PCI_TIER1)
		{	
		overall_PWM_output[i][4]=Temp_TIER_SETTINGS.tier_vs_AMB_std[1][AMB_scale];
		};
		
		if(currentConfig->entity.PCI_type.type== ENTITY_PCI_TIER2)
		overall_PWM_output[i][4]=Temp_TIER_SETTINGS.tier_vs_AMB_std[2][AMB_scale];
		
		if(currentConfig->entity.PCI_type.type== ENTITY_PCI_TIER3)
		overall_PWM_output[i][4]=Temp_TIER_SETTINGS.tier_vs_AMB_std[3][AMB_scale];
		
		if(currentConfig->entity.PCI_type.type== ENTITY_PCI_TIER4)
		overall_PWM_output[i][4]=Temp_TIER_SETTINGS.tier_vs_AMB_std[4][AMB_scale];
	    
		if(currentConfig->entity.PCI_type.type== ENTITY_PCI_TIER5)
		overall_PWM_output[i][4]=Temp_TIER_SETTINGS.tier_vs_AMB_std[5][AMB_scale];
		
		if(currentConfig->entity.PCI_type.type== ENTITY_PCI_TIER6)
	    overall_PWM_output[i][4]=Temp_TIER_SETTINGS.tier_vs_AMB_std[6][AMB_scale];
		
		};

		//pthread_mutex_unlock( &mutex1 ); 
	};
	
	
	if(currentConfig->entity.fan_type.type== ENTITY_FAN_TYPE_PERFORMANCE )
	{
		AMB_scale=amb_HP_scale(AMB,i);
	 	for (i=0; i<FAN_ZONE_NUM; i=i+3)
		{   
		
		if(currentConfig->entity.PCI_type.type== ENTITY_PCI_TIER1)
		AMB_scale=amb_HP_scale(AMB,i);
		int A = Temp_TIER_SETTINGS.tier_vs_AMB_hp[1][AMB_scale];
		overall_PWM_output[i][4]=A;
		
		if(currentConfig->entity.PCI_type.type== ENTITY_PCI_TIER2)
		overall_PWM_output[i][4]=Temp_TIER_SETTINGS.tier_vs_AMB_hp[2][AMB_scale];
		
		if(currentConfig->entity.PCI_type.type== ENTITY_PCI_TIER3)
		overall_PWM_output[i][4]=Temp_TIER_SETTINGS.tier_vs_AMB_hp[3][AMB_scale];
		
		if(currentConfig->entity.PCI_type.type== ENTITY_PCI_TIER4)
		overall_PWM_output[i][4]=Temp_TIER_SETTINGS.tier_vs_AMB_hp[4][AMB_scale];
	    
		if(currentConfig->entity.PCI_type.type== ENTITY_PCI_TIER5)
		overall_PWM_output[i][4]=Temp_TIER_SETTINGS.tier_vs_AMB_hp[5][AMB_scale];
		
		if(currentConfig->entity.PCI_type.type== ENTITY_PCI_TIER6)
	    overall_PWM_output[i][4]=Temp_TIER_SETTINGS.tier_vs_AMB_hp[6][AMB_scale];
		
		};


 
	}
	
	

   }


};
*/




void*CPU_PID(void*argc)
{	


	int ERR[3];
	int hi_Target; 
	int low_Target;
	int i;
	float P;
	float I;
	float D;
	int fanduty;

	
	hi_Target = PID.T_control + PID.GB;
  	low_Target = PID.T_control- PID.GB;


   while(1)
	{
		
		
	sleep(2);
	
	

	
	//for(i=0; i<currentConfig->entity.CPU.quantity; i++) //
	//{
	
	
	int entryId = get_entryId_instance(ENTITY_PROCESSOR,DEVICE_INSTANT1);
	PID.Margin = device_map_system_fanzone[entryId].TEMP;
	
	//printf("CPU_0.Margin=%d\n",PID.Margin);
	
	if (PID.Margin < low_Target)
	{
		ERR[0] = low_Target - PID.Margin;
	}

	else if (PID.Margin > hi_Target)
	{
		ERR[0] = PID.Margin - hi_Target;
	}
	else  
	{
		ERR[0] = 0 ;
	}
	
	// P factor
	   P = PID.kp*(ERR[0]-ERR[1]);
	// I factor
	   I = PID.ki* ERR[0];
	// D factor 
	   D = PID.kd* (ERR[0]-2*ERR[1]+ ERR[2]);	
           
          
	
	   fanduty = FANMAP_output[1].Max_output+ P + I + D;
	
 	   if (fanduty <= FAN_MIN)
	   {
	      fanduty = FAN_MIN;
	      
	   }
	   else if (fanduty >= FAN_MAX)
	   {
	      fanduty = FAN_MAX;
	   }
	   
	   ERR[2] = ERR[1];
	   ERR[1] = ERR[0];
	   
	  
	  fan_map_output_PID(ENTITY_PROCESSOR,DEVICE_INSTANT1,fanduty);
	 
	
		
		
	 
	 
	};
	//}
};


void*CPU_PID1(void*argc)
{	


	int ERR[3];
	int hi_Target; 
	int low_Target;

	float P;
	float I;
	float D;
	int fanduty;

	
	hi_Target = PID_1.T_control + PID_1.GB;
  	low_Target = PID_1.T_control- PID_1.GB;


   while(1)
	{
		
		
	sleep(2);
	
	

	
	//for(int i=0; i<currentConfig->entity.CPU.quantity; i++) //
	//{
	
	
	int entryId = get_entryId_instance(ENTITY_PROCESSOR,DEVICE_INSTANT2);
	PID_1.Margin = device_map_system_fanzone[entryId].TEMP;
	
	//printf("CPU_0.Margin=%d\n",PID_1.Margin);
	
	if (PID_1.Margin < low_Target)
	{
		ERR[0] = low_Target - PID_1.Margin;
	}

	else if (PID_1.Margin > hi_Target)
	{
		ERR[0] = PID_1.Margin - hi_Target;
	}
	else  
	{
		ERR[0] = 0 ;
	}
	
	// P factor
	   P = PID_1.kp*(ERR[0]-ERR[1]);
	// I factor
	   I = PID_1.ki* ERR[0];
	// D factor 
	   D = PID_1.kd* (ERR[0]-2*ERR[1]+ ERR[2]);	
           
          
	
	   fanduty = FANMAP_output[1].Max_output+ P + I + D;
	
 	   if (fanduty <= FAN_MIN)
	   {
	      fanduty = FAN_MIN;
	      
	   }
	   else if (fanduty >= FAN_MAX)
	   {
	      fanduty = FAN_MAX;
	   }
	   
	   ERR[2] = ERR[1];
	   ERR[1] = ERR[0];
	   
	  
	  fan_map_output_PID(ENTITY_PROCESSOR,DEVICE_INSTANT2,fanduty);
	  
	
		
		
	 
	 
	};
	//}
};





/*

void* CRITICAL(void*SENSOR_DATA)
{

	PWM_Calculated_from_SC* Tnon_critical_PWM;
	Tnon_critical_PWM= (PWM_Calculated_from_SC*)PWM;
	
	int PWM = PWM -> PWM_Output;
	PWM_Output = 100;
	
	printf("%PWM_Output: %d\n",PWM_Output);
	
	Tnon_critical_PWM-> PWM_Output =PWM_Output;

}

*/


int power_ratio_HP_scale(int FANZONE_ID)
{	int i;
	float power_scale =get_CPU_Power_Ratio(FANZONE_ID);
	for (i = 1; i < 8; i++) {
		if (power_scale<= currentConfig->fanzones[FANZONE_ID].HP_fan_zone_settings[i][0])
			return i;
	}
}




int power_ratio_STD_scale(int FANZONE_ID)
{	int i;
	float power_scale =get_CPU_Power_Ratio(FANZONE_ID);
	//printf("Power_scale:%f\n", power_scale);
	for (i = 1; i < 8; i++) {
		if (power_scale<= currentConfig->fanzones[FANZONE_ID].STD_fan_zone_settings[i][0])
			return i;
	}
}




int amb_STD_scale(int ambTemp,int FANZONE_ID)
{ 	int i;
	for (int i = 1; i < 8; i++) {
		if (ambTemp <= currentConfig->fanzones[FANZONE_ID].STD_fan_zone_settings[0][i])
			return i;
	}
}



int amb_HP_scale(int ambTemp,int FANZONE_ID)
{	int i;
	for (int i = 1; i < 8; i++) {
		if (ambTemp <= currentConfig->fanzones[FANZONE_ID].HP_fan_zone_settings[0][i])
			return i;
	}
}



int get_sensorValue(int entity)
	{ int i;
		for (i=0; i<MAPPING_RULE_NUM;i++) 
		{
		if (device_map_system_fanzone[i].type==entity)
	    return device_map_system_fanzone[i].TEMP;
	
		}
	
	
	}


int get_entryId_instance(int entity,int deviceInstant)
	{ int i;
		for (i=0; i<MAPPING_RULE_NUM;i++) 
		{
		if ((device_map_system_fanzone[i].type==entity)&&(device_map_system_fanzone[i].device==deviceInstant))
			
	    return i;
	
		}
	
	};




int fan_map_output_PID(int ENTITY,int instance,float fanduty)

{
	//i: device instance
	int i;
	for(i=0;i<MAPPING_RULE_NUM;i++)
	{
		if((device_map_system_fanzone[i].type==ENTITY)&&(device_map_system_fanzone[i].device==instance))
		{
		
		overall_PWM_output[device_map_system_fanzone[i].instant][instance+1]=fanduty;
		//FANMAP_output[device_map_system_fanzone[i].instant].CPU_PID=fanduty;
		
		
		printf("CPU-0x%d,FANDUTY_Triggered_by_PID=%f\n",instance,overall_PWM_output[device_map_system_fanzone[i].instant][instance+1]);
		
		};
	
	}
};



	
	
	
float get_CPU_Power_Ratio(int FANZONE_ID)
{

  int CPU_TDP;
  int PWR=get_sensorValue(ENTITY_CPU_POWER);
     if (device_map_system_fanzone[FANZONE_ID].type==ENTITY_PROCESSOR_high_Power)
		CPU_TDP=250;
     else if (device_map_system_fanzone[FANZONE_ID].type==ENTITY_PROCESSOR)
		CPU_TDP=165;
     else if (device_map_system_fanzone[FANZONE_ID].type==ENTITY_PROCESSOR_low_Power)
		CPU_TDP=125;

	   //int PWR=get_sensorValue(ENTITY_PROCESSOR_high_Power);
	  //->  printf("CPU_POWER=%d\n",PWR);
	    //->printf("CPU_POWER_TDP=%d\n",CPU_TDP);
	    //->printf("CPU_POWER_RATIO=%f\n",(float)PWR/CPU_TDP);
	    return (float)PWR/CPU_TDP;

}	



void* openloop(void* args)

{
	
	
	int i;	
	int AMB = get_sensorValue(ENTITY_Ambient_Sensor);
	printf("Amb sensor reading=%d\n",AMB);
	//pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

	//printf("type=%d\n", currentConfig->entity.fan_type.type);	
	
	while(1)
	{
	sleep(2);
	if(currentConfig->entity.fan_type.type== ENTITY_FAN_TYPE_STD)
	
	{
		
		//pthread_mutex_lock( &mutex1 );
	
		for (i=0; i<FAN_ZONE_NUM; i++)
		{   

			int AMB_scale =amb_STD_scale(AMB,i);
			int POWER_scale=power_ratio_STD_scale(i);
			
			overall_PWM_output[i][0]= currentConfig->fanzones[i].STD_fan_zone_settings[POWER_scale][AMB_scale];
			//printf("set_openloop_to_FANMAP=%f\n", FANMAP_output[0].openloop);
		}

		//pthread_mutex_unlock( &mutex1 ); 
	}
	
	
	if(currentConfig->entity.fan_type.type== ENTITY_FAN_TYPE_PERFORMANCE )
	
	{
		
		//pthread_mutex_lock( &mutex1 ); 
		for (i=0; i<FAN_ZONE_NUM; i++)
		{
			int AMB_scale =amb_HP_scale(AMB,i);
			int POWER_scale=power_ratio_HP_scale(i);
			
			overall_PWM_output[i][0]= currentConfig->fanzones[i].HP_fan_zone_settings[POWER_scale][AMB_scale];
		}

		//pthread_mutex_unlock( &mutex1 ); 
	}
	

}

}
void*funcFanMap(void* args)
{
while(1)
	
{	
 
	sleep(4);
	int i;
	
	

	
	
	
	
	for(int i = 0;i<FAN_ZONE_NUM;i++){
		
		float max= 20;  
		for (int j=0; j<6; j++) {
			
		
			if(overall_PWM_output[i][j]> max){
	
			max =overall_PWM_output[i][j];
			
			};
		
		
        FANMAP_output[i].Max_output=max;
		overall_PWM_output[i][4]=max;
		//printf("FAN%d,FANMAP_OUTPUT%f\n=",i,FANMAP_output[i].Max_output);
		};
	 
	 printf("FAN%d,FANMAP_OUTPUT%f\n",i,overall_PWM_output[i][4]);
	
	
	
	}
	
	
	
	
	
}	
	
};
 






