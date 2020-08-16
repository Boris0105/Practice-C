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


	int ERR[CPU_NUM][3];
	
	int hi_Target; 
	int low_Target;
	int i;
	float P;
	float I;
	float D;
	int fanduty;

	


   while(1)
	{
		
		
	sleep(2);
	
	

	
	for(i=0; i<CPU_NUM; i++) //
	{
	
	hi_Target = PID[i].T_control + PID[i].GB;
  	low_Target = PID[i].T_control- PID[i].GB;

	int entryId = get_entryId_instance(ENTITY_PROCESSOR,i);
	PID[i].Margin = device_map_system_fanzone[entryId].TEMP;
	
	printf("CPU_%d.Margin=%d\n",i,PID[i].Margin);
	
	if (PID[i].Margin < low_Target)
	{
		ERR[i][0] = low_Target - PID[i].Margin;
	}

	else if (PID[i].Margin > hi_Target)
	{
		ERR[i][0] = PID[i].Margin - hi_Target;
	}
	else  
	{
		ERR[i][0] = 0 ;
	}
	
	// P factor
	   P = PID[i].kp*(ERR[i][0]-ERR[i][1]);
	// I factor
	   I = PID[i].ki* ERR[i][0];
	// D factor 
	   D = PID[i].kd* (ERR[i][0]-2*ERR[i][1]+ ERR[i][2]);	
           
          
		
	   fanduty = FANMAP_output[1].Max_output+ P + I + D;
	
 	   if (fanduty <= FAN_MIN)
	   {
	      fanduty = FAN_MIN;
	      
	   }
	   else if (fanduty >= FAN_MAX)
	   {
	      fanduty = FAN_MAX;
	   }
	   
	   ERR[i][2] = ERR[i][1];
	   ERR[i][1] = ERR[i][0];
	   
	  
	  fan_map_output_PID(ENTITY_PROCESSOR,i,fanduty);
	 
	
		
		
	 
	 
	};
	}
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
		// define ambient with 8 different scale
		if (ambTemp <= currentConfig->fanzones[FANZONE_ID].STD_fan_zone_settings[0][i])
			return i;
	}
}



int amb_HP_scale(int ambTemp,int FANZONE_ID)
{	int i;
	for (int i = 1; i < 8; i++) {
		// define ambient with 8 different scale 
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
		
		
		//printf("CPU-0x%d,FANDUTY_Triggered_by_PID=%f\n",instance,overall_PWM_output[device_map_system_fanzone[i].instant][instance+1]);
		
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


void init_log_parser()

{
	
	
	for (int i=0; i<CPU_NUM; i++) {
		
		
	}
	
	
	printf("\t\t  Sensor_Reading\t\t Target\t\t\t Present\t\t Event\t\t Display_Name\t\t\n");
	printf("--------------------------------------------------------------------------------------------------------------------------\n");
	printf("CPU0\t\t\t%d" "\t\t\t%d" "\t\t\tYES\n",device_map_system_fanzone[0].TEMP,6);
	printf("CPU1\t\t\t%d" "\t\t\t%d" "\t\t\tYES\n",device_map_system_fanzone[3].TEMP,6);
	printf("GPU0\t" "\t\t\t\t\t\t\t\tNo\n");
	printf("GPU1\t" "\t\t\t\t\t\t\t\tNo\n");
	printf("GPU2\t" "\t\t\t\t\t\t\t\tNo\n");
	printf("GPU4\t" "\t\t\t\t\t\t\t\tNo\n");
	printf("AMB\t\t\t%d" "\t\t\t%d" "\t\t\tYES\n",device_map_system_fanzone[37].TEMP,43);
	printf("Hotest RAID\t\t%d" "\t\t\t%d" "\t\t\tYES\n" ,device_map_system_fanzone[40].TEMP,95);
	printf("Hotest DIMM\t\t%d" "\t\t\t%d" "\t\t\tYES\n",device_map_system_fanzone[33].TEMP, 73);
	printf("Hotest HDD\t\t%d" "\t\t\t%d" "\t\t\tYES\n",device_map_system_fanzone[42].TEMP,55);
	printf("LAN\t\t\t%d" "\t\t\t%d" "\t\t\tYES\n",device_map_system_fanzone[42].TEMP,95);
	printf("CPU VR\t\t\t%d" "\t\t\t%d" "\t\t\tYES\n",device_map_system_fanzone[46].TEMP,90);
	printf("PCH\t\t\t%d" "\t\t\t%d" "\t\t\tYES\n",device_map_system_fanzone[43].TEMP,95);
	printf("M.2\t\t\t%d" "\t\t\t%d" "\t\t\tYES\n",device_map_system_fanzone[44].TEMP,65);
	printf("PCI PLDM\t\n");
	
	//printf("\t\t  Sensor_Reading\t Target\t\t Present\t Event\t\t Display_Name\t\t\n");
	printf("--------------------------------------------------------------------------------------------------------------------------\n");
	
	
	
	
	
	
	
	
};


void*funcFanMap(void* args)
{
while(1)
	
{	
 
	sleep(4);
	int i;
	
	
	
	init_log_parser();
	
	
		
	for(int i = 0;i<FAN_ZONE_NUM;i++){
		
		float max= 20;  
		for (int j=0; j<6; j++) {
			
		
			if(overall_PWM_output[i][j]> max){
	
			max =overall_PWM_output[i][j];
			
			};
		
		
        FANMAP_output[i].Max_output=max;
		overall_PWM_output[i][4]=max;
		
		};
	 
	 printf("[Open loop output from FAN%d]=>[%f]\n",i+1,overall_PWM_output[i][0]);
	 printf("[CPU0 output from FAN%d]=>[%f]\n",i+1,overall_PWM_output[i][1]);
	 printf("[CPU1 output from FAN%d]=>[%f]\n",i+1,overall_PWM_output[i][2]);
	 printf("[MAX fan duty output from FAN%d]=>[%f]\n",i+1,overall_PWM_output[i][4]);
	 printf ("******************************************************\n");  
	
	
	}
	
	
	
	
	
}	
	
};
 






