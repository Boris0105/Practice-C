#include "hwmon.h"
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


int pwoer_ratio_HP_scale(int FANZONE_ID)
{	int i;
	float power_scale =get_CPU_Power_Ratio(FANZONE_ID);
	for (i = 1; i < 8; i++) {
		if (power_scale<= currentConfig->fanzones[FANZONE_ID].HP_fan_zone_settings[i][0])
			return i;
	}
}




int pwoer_ratio_STD_scale(int FANZONE_ID)
{	int i;
	float power_scale =get_CPU_Power_Ratio(FANZONE_ID);
	printf("Power_scale:%f\n", power_scale);
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
		for (i=0; i<37;i++) 
		{ 
		if (device_map_system_fanzone[i].type==entity)
	    return device_map_system_fanzone[i].TEMP;
	
		}
	
	
	}



	
	
	
float get_CPU_Power_Ratio(int FANZONE_ID)
{

int CPU_TDP;

if (device_map_system_fanzone[FANZONE_ID].type==ENTITY_PROCESSOR_high_Power)
		CPU_TDP=250;
else if (device_map_system_fanzone[FANZONE_ID].type==ENTITY_PROCESSOR)
		CPU_TDP=165;
else if (device_map_system_fanzone[FANZONE_ID].type==ENTITY_PROCESSOR_low_Power)
		CPU_TDP=125;

	int PWR=get_sensorValue(ENTITY_PROCESSOR_high_Power);
	

	return (float)PWR/CPU_TDP;

}	



void* openloop(void* args)

{
	
	
	int i;	
	int AMB = get_sensorValue(ENTITY_Ambient_Sensor);
	pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

	
	if(currentConfig->entity.fan_type.type== ENTITY_FAN_TYPE_STD)
	
	{
		
		pthread_mutex_lock( &mutex1 );

		for (i=0; i<FAN_ZONE_NUM; i++)
		{   

			int AMB_scale =amb_STD_scale(AMB,i);
			int POWER_ratio=pwoer_ratio_STD_scale(i);
			
			FANMAP_output[i].openloop= currentConfig->fanzones[i].STD_fan_zone_settings[POWER_ratio][AMB_scale];
			printf("set_openloop_to_FANMAP=%f\n", FANMAP_output[0].openloop);
		}

		pthread_mutex_unlock( &mutex1 ); 
	}
	
	
	if(currentConfig->entity.fan_type.type== ENTITY_FAN_TYPE_PERFORMANCE )
	
	{
		
		pthread_mutex_lock( &mutex1 ); 
		for (i=0; i<FAN_ZONE_NUM; i++)
		{
			int AMB_scale =amb_HP_scale(AMB,i);
			int POWER_ratio=pwoer_ratio_HP_scale(i);
			
			FANMAP_output[i].openloop= currentConfig->fanzones[i].HP_fan_zone_settings[POWER_ratio][AMB_scale];
		}

		pthread_mutex_unlock( &mutex1 ); 
	}
	

}


void*funcFanMap(void* args)

{

	
	FANMAP_output[0].Max_output = max(FANMAP_output[0].openloop, 0);
	FANMAP_output[1].Max_output = max(FANMAP_output[1].openloop, 0);
	FANMAP_output[2].Max_output = max(FANMAP_output[2].openloop, 0);
	FANMAP_output[3].Max_output = max(FANMAP_output[3].openloop, 0);

	
	
}






