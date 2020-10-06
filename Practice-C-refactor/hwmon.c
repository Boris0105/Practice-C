#include "hwmon.h"
#include <unistd.h>
#include <time.h>




void PID_CONTROLLER()
{	


	int ERR[CPU_NUM][3];
	
	int hi_Target; 
	int low_Target;
	int i;
	float P;
	float I;
	float D;
	int fanduty;

	
		
		sleep(2);
	
	

	
		for(i=1; i<CPU_NUM+1; i++) //
		{
	
			hi_Target = PID[i].T_control + PID[i].GB;
			low_Target = PID[i].T_control- PID[i].GB;

			int entryId = get_entryId_instance(ENTITY_PROCESSOR,i);
			PID[i].Margin = device_map_system_fanzone[entryId].value;
	
			//printf("CPU_%d.Margin=%d\n",i,PID[i].Margin);
	
			if (PID[i].Margin < low_Target)
			{
				ERR[i][0] = low_Target - PID[i].Margin;
			}

			if (PID[i].Margin > hi_Target)
			{
				ERR[i][0] = PID[i].Margin - hi_Target;
			}
			if (PID[i].Margin >= low_Target && PID[i].Margin <= hi_Target) 
			{
				ERR[i][0] = 0 ;
			}
	
				// P factor
			P = PID[i].kp*(ERR[i][0]-ERR[i][1]);
				// I factor
			I = PID[i].ki* ERR[i][0];
				// D factor 
			D = PID[i].kd* (ERR[i][0]-2*ERR[i][1]+ ERR[i][2]);	
           
	   
			fanduty = device_map_system_fanzone[i].MAX_fanduty_output+ P + I + D;
	
			if (fanduty <= FAN_MIN){
			fanduty = FAN_MIN;
			}
			else if (fanduty >= FAN_MAX){
			fanduty = FAN_MAX;
			}
	   
			
			ERR[i][2] = ERR[i][1];
			ERR[i][1] = ERR[i][0];
	        fan_map_output_PID(ENTITY_PROCESSOR,i,fanduty);
		};
};








int power_ratio_HP_scale(int FANZONE_ID)
{	
	float power_scale =get_CPU_Power_Ratio(FANZONE_ID);
	//Place 24 fans into single FANZONE
	for (int i = 0; i < FAN_ZONE_NUM; i++) {
		
		if (power_scale<= currentConfig->fanzones[FANZONE_ID].HP_fan_zone_settings[i][0])
		return i;
	}
}




int power_ratio_STD_scale(int FANZONE_ID)
{	
	float power_scale =get_CPU_Power_Ratio(FANZONE_ID);
	//Place 24 fans into single FANZONE
	for (int i = 0; i < FAN_ZONE_NUM; i++) {
		if (power_scale<= currentConfig->fanzones[FANZONE_ID].STD_fan_zone_settings[i][0])
		return i;
	}
}




int amb_STD_scale(int ambTemp,int FANZONE_ID)
{ 	
    //Place 24 fans into single FANZONE
	for (int i = 1; i < FAN_ZONE_NUM+1; i++) 
	{
		// define ambient with 8 different scale
		if (ambTemp <= currentConfig->fanzones[FANZONE_ID].STD_fan_zone_settings[0][i])
		return i;
	}
}



int amb_HP_scale(int ambTemp,int FANZONE_ID)
{	
	for (int i = 1; i < FAN_ZONE_NUM+1; i++) 
	{
		// define ambient with 8 different scale 
		if (ambTemp <= currentConfig->fanzones[FANZONE_ID].HP_fan_zone_settings[0][i])
			return i;
	}
}



int get_sensorValue(int entity)
{ 
	printf("check into get_sensor Value");
	  float max_return_value_in;
	  float max_return_value_out;	  
		
		for (int i=0; i<MAPPING_RULE_NUM;i++) 
		{
			if (device_map_system_fanzone[i].type==entity)
			{
				max_return_value_in = device_map_system_fanzone[i].value;
				
				if (max_return_value_in>max_return_value_out)
				{
				max_return_value_out=max_return_value_in;
				}
			}
			
			
		}
		
		
		return max_return_value_out;
	
	
	}


int get_entryId_instance(int entity,int deviceInstant)
{ 
		for (int i=0; i<MAPPING_RULE_NUM;i++) 
		{
			if ((device_map_system_fanzone[i].type==entity)&&(device_map_system_fanzone[i].device==deviceInstant))
			return i;
	
		}
	
	

	};




int fan_map_output_PID(int ENTITY,int instance,float fanduty)

{
	
	
	for(int i=0;i<MAPPING_RULE_NUM;i++)
	{
		if((device_map_system_fanzone[i].type==ENTITY)&&(device_map_system_fanzone[i].device==instance))
		{
		
		
			device_map_system_fanzone[i].fanduty_output_PID_CONTROLLER=fanduty;
		
		};
	
	}
};



	
	
	
float get_CPU_Power_Ratio(int FANZONE_ID)
{
		int k=0;
		float CPU_TDP;
		float PWR;
		float power_ratio_value;
		float MAX_POWER_RATIO;
		
		
		for(int i=0;i<MAPPING_RULE_NUM;i++)
		{	
			if(device_map_system_fanzone[i].type==ENTITY_PROCESSOR)
			{	
				CPU_TDP = get_sensorValue(ENTITY_CPU_POWER_TDP);
				PWR=get_sensorValue(ENTITY_CPU_POWER);
				power_ratio_value=PWR/CPU_TDP;
				
				if (power_ratio_value>=MAX_POWER_RATIO)
				{
					
					MAX_POWER_RATIO=power_ratio_value;
				}

			}
			
		return MAX_POWER_RATIO;
		}

}	



void SYSTEM_BASE_OPENLOOP()

{

	int AMB = get_sensorValue(ENTITY_Ambient_Sensor);
	printf("Amb sensor reading=%d\n",AMB);
	sleep(2);
	if(currentConfig->entity.fan_type.type==ENTITY_FAN_TYPE_STD)
	{

	for (int i=0; i<FAN_ZONE_NUM; i++)
	{
		int AMB_scale =amb_STD_scale(AMB,i);
		int POWER_scale=power_ratio_STD_scale(i);

		for (int j=0;j<MAPPING_RULE_NUM;j++)
		{		
			if 	(device_map_system_fanzone[j].fanzone_numbers==FAN_ZONE_NUM)
			{	
			device_map_system_fanzone[j].fanduty_output_Openloop=currentConfig->fanzones[i].STD_fan_zone_settings[POWER_scale][AMB_scale];
			}	
		}
	

	};
	
	
		if(currentConfig->entity.fan_type.type== ENTITY_FAN_TYPE_PERFORMANCE)
		{ 

			for (int i=0; i<FAN_ZONE_NUM; i++)
			{
				int AMB_scale =amb_HP_scale(AMB,i);
				int POWER_scale=power_ratio_HP_scale(i);
			
			
				
				for (int j=0;j<MAPPING_RULE_NUM;j++)
				{	
					
					if 	(device_map_system_fanzone[j].fanzone_numbers==FAN_ZONE_NUM)
					{	
					device_map_system_fanzone[j].fanduty_output_Openloop=currentConfig->fanzones[i].HP_fan_zone_settings[POWER_scale][AMB_scale];
					}
					
				}

			}
			
			
		}		

}



float PICK_UP_MAX_FANDUTY(int i)
{
	float MAX_DUTY;
		
	if (device_map_system_fanzone[i].fanduty_output_Openloop >=device_map_system_fanzone[i].fanduty_output_Low_POWER_POWERBAND) 
	{
		MAX_DUTY=device_map_system_fanzone[i].fanduty_output_Openloop;

	}
	else if (device_map_system_fanzone[i].fanduty_output_Openloop <=device_map_system_fanzone[i].fanduty_output_Low_POWER_POWERBAND)
	{
		MAX_DUTY=device_map_system_fanzone[i].fanduty_output_Low_POWER_POWERBAND;
		
	}
	
	if ( device_map_system_fanzone[i].fanduty_output_PID_CONTROLLER>=MAX_DUTY) 
	{
		MAX_DUTY=device_map_system_fanzone[i].fanduty_output_PID_CONTROLLER;

	}

	return MAX_DUTY;
}


void LOW_POWER_BAND()
{
	
}



void CHECK_FAN_MAP()
{
	float MAX_FAN_DUTY_ALL;
	for (int i=0; i<MAPPING_RULE_NUM; i++){
		
		
		if(device_map_system_fanzone[i].presence!=0)
		{	
			device_map_system_fanzone[i].MAX_fanduty_output=PICK_UP_MAX_FANDUTY(i);
		};


		if (device_map_system_fanzone[i].MAX_fanduty_output>=MAX_FAN_DUTY_ALL)
		{	 
			MAX_FAN_DUTY_ALL=device_map_system_fanzone[i].MAX_fanduty_output;
			printf("MAX_FAN_DUTY_ALL=%f",MAX_FAN_DUTY_ALL);
		};

	};
	
	
		// OUTPUT THE FANDUTY TO THE FAN
	
		for (int i=0; i<FAN_NUMBER; i++){
			FAN_OUTPUT[i][1]=MAX_FAN_DUTY_ALL;
			printf("FAN %d, FANDUTY OUTPUT = %f PWM",i,MAX_FAN_DUTY_ALL);
		};



};	

};