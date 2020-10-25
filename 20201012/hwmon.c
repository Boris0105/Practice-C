#include "hwmon.h"
#include <unistd.h>
#include <time.h>




void PID_CONTROLLER()
{	
	
	printf("running into PID_1st line");



		for(int i=1; i<CPU_NUM+1; i++) //
		{
			
				int hi_Target; 
				int low_Target;
	
				float P;
				float I;
				float D;
				float fanduty;	
			
				
				hi_Target = PID[i-1].T_control + PID[i-1].GB;
				low_Target = PID[i-1].T_control- PID[i-1].GB;

				int entryId = get_entryId_instance(ENTITY_PROCESSOR,i);
				PID[i-1].Margin = device_map_system_fanzone[entryId].value;

				printf("CPU_%d.Margin=%d\n",i,PID[i-1].Margin);
	
				if (PID[i-1].Margin < low_Target)
				{
					ERR[i-1][0] = low_Target - PID[i-1].Margin;
				}

				if (PID[i-1].Margin > hi_Target)
				{
					ERR[i-1][0] = PID[i-1].Margin - hi_Target;
				}
				if (PID[i-1].Margin >= low_Target && PID[i-1].Margin <= hi_Target) 
				{
					ERR[i-1][0] = 0 ;
				}
	
	            
				
	
					// P factor
						
						P = PID[i-1].kp*(ERR[i-1][0]-ERR[i-1][1]);
					
					// I factor
						
						I = PID[i-1].ki* ERR[i-1][0];
					// D factor 
			
						D = PID[i-1].kd* (ERR[i-1][0]-2*ERR[i-1][1]+ ERR[i-1][2]);	
           
						
						for(int fanzone=0;fanzone<FAN_ZONE_NUM;fanzone++){	
						
						fanduty = MAX_FAN_DUTY_ALL+ P + I + D;
	
						}
						
						if(i==4){
						printf("MAX_FAN_DUTY_ALL%5.2f\n", MAX_FAN_DUTY_ALL);
						
						printf("PID OUTPUT_CPU_4 =%5.2f\n",fanduty);
						
						};
						if (fanduty <= FAN_MIN){
								fanduty = FAN_MIN;
							}
						else if (fanduty >= FAN_MAX){
								fanduty = FAN_MAX;
							}
	   
			
						ERR[i-1][2] = ERR[i-1][1];
						ERR[i-1][1] = ERR[i-1][0];
			
	        fan_map_output_PID(ENTITY_PROCESSOR,i,fanduty);
			
		};
};








int power_ratio_HP_scale(int FANZONE_ID)
{	
	float power_ratio =get_CPU_Power_Ratio(FANZONE_ID);
	printf("power_ratio=%f\n",power_ratio);
	
	for (int i = 1; i < 8; i++) {
		
		if (power_ratio<= currentConfig->fanzones[FANZONE_ID-1].HP_fan_zone_settings[i][0])
		return i;
	}
}




int power_ratio_STD_scale(int FANZONE_ID)
{	
	float power_ratio =get_CPU_Power_Ratio(FANZONE_ID);
	//Place 24 fans into single FANZONE
	for (int i = 1; i < 8; i++) {
		if (power_ratio<= currentConfig->fanzones[FANZONE_ID-1].STD_fan_zone_settings[i][0])
		return i;
	}
}




int amb_STD_scale(int ambTemp,int FANZONE_ID)
{	
		
		printf("ambient=%d\n",ambTemp);
		//printf("FANZONE_ID=%d\n",FANZONE_ID);
		
		// define ambient with 8 different scale 
		
		
		for(int i=0; i<8;i++){
		
		if (ambTemp <= currentConfig->fanzones[FANZONE_ID-1].STD_fan_zone_settings[0][i])
			{		printf("test=%f\n",currentConfig->fanzones[0].STD_fan_zone_settings[0][i]);
				printf("HP_AMB_SCALE=%d\n",i);	
				return i;
			}
		
		}
}


int amb_HP_scale(int ambTemp,int FANZONE_ID)
{	
		
		printf("ambient=%d\n",ambTemp);
		//printf("FANZONE_ID=%d\n",FANZONE_ID);
		
		// define ambient with 8 different scale 
		
		
		for(int i=0; i<8;i++){
		
		if (ambTemp <= currentConfig->fanzones[FANZONE_ID-1].HP_fan_zone_settings[0][i])
			{		printf("test=%f\n",currentConfig->fanzones[0].HP_fan_zone_settings[0][i]);
				printf("HP_AMB_SCALE=%d\n",i);	
				return i;
			}
		
		}
}



int get_sensorValue(int entity)
{ 
	printf("check into get_sensor Value\n");
	  float max_return_in=0;
	  float max_return_out=0;	  
	  int   MAX_SENSOR_SPACE;
	  
		for (int i=0; i<num_mapping_rules;i++){
			if (device_map_system_fanzone[i].type==entity){
				max_return_in = device_map_system_fanzone[i].value;

				//printf("max_return_out%d,%f\n=",entity,max_return_out);
				
				//printf("max_return_in%d,%f\n=",entity,max_return_in);
				
				if (max_return_in> max_return_out)
				{
					max_return_out=max_return_in;
				};
				
				
			}
			
			
		}
		
		//printf("max_return_value_out=%f\n",max_return_out);
		return max_return_out;
	
	
	}


int get_entryId_instance(int entity,int deviceInstant)
{ 
		for (int i=0; i<num_mapping_rules;i++) 
		{
			if ((device_map_system_fanzone[i].type==entity)&&(device_map_system_fanzone[i].device==deviceInstant))
			return i;
	
		}
	
	

	};




int fan_map_output_PID(int ENTITY,int instance,float fanduty)

{
	
	
	for(int i=0;i<num_mapping_rules;i++)
	{
		if((device_map_system_fanzone[i].type==ENTITY)&&(device_map_system_fanzone[i].device==instance))
		{
		
		
			device_map_system_fanzone[i].fanduty_output_PID_CONTROLLER=fanduty;
			printf("PID Output = %f\n", device_map_system_fanzone[i].fanduty_output_PID_CONTROLLER);
		
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
		int CPU_INSTANCE;
		

				
					CPU_TDP = get_sensorValue(ENTITY_CPU_POWER_TDP);
					//printf("return CPU_TDP=%f\n",CPU_TDP);
					PWR=get_sensorValue(ENTITY_CPU_POWER);
					printf("return CPU_POWER=%f\n",PWR);
					power_ratio_value=PWR/CPU_TDP;
					//printf("return CPU_POWER_RATIO=%f\n",power_ratio_value);
					if (power_ratio_value>=MAX_POWER_RATIO)
					{
					
						MAX_POWER_RATIO=power_ratio_value;
					}
				
		
		
		//printf("return MAX POWER RATIO=%f\n",MAX_POWER_RATIO);		
		
		
		
		return MAX_POWER_RATIO;

}	



void SYSTEM_BASE_OPENLOOP()

{
	
	int AMB = get_sensorValue(ENTITY_AMBIENT_SENSOR);
	printf("Amb sensor reading=%d\n",AMB);
	
	//printf("currentConfig->entity.fan_type.type=%d\n",currentConfig->entity.fan_type.type);
	//printf("ENTITY_FAN_TYPE_STD=%d\n",ENTITY_FAN_TYPE_STD);
	
	
	
	
	if(currentConfig->entity.fan_type.type==ENTITY_FAN_TYPE_STD)
	{
		printf("======Run function into STD OPENLOOP======");
	
		for (int i=0; i<FAN_ZONE_NUM; i++)
		{
		
		
			int AMB_scale =amb_STD_scale(AMB,i);
			int POWER_scale=power_ratio_STD_scale(i);

			for (int j=0;j<num_mapping_rules;j++)
			{	
		
				for(int k=1; k<FAN_ZONE_NUM+1;k++){	
		
					if 	(device_map_system_fanzone[j].fanzone_numbers==k)
					{	
						device_map_system_fanzone[j].fanduty_output_Openloop=currentConfig->fanzones[i].STD_fan_zone_settings[POWER_scale][AMB_scale];
						printf("openloop_output=%f\n",device_map_system_fanzone[j].fanduty_output_Openloop);
					};	
				};	
			
			};
			
		};
		
	
		
	

	};
	
	
	
	printf("currentConfig->entity.fan_type.type=%d\n",currentConfig->entity.fan_type.type);
	
	if(currentConfig->entity.fan_type.type==ENTITY_FAN_TYPE_PERFORMANCE){ 
	    printf("======Run function into HIGHPERFORMANCE OPENLOOP======\n");
			
			
			for (int i=1; i<FAN_ZONE_NUM+1; i++){
				
				
				int AMB_scale =amb_HP_scale(AMB,i);
				int POWER_scale=power_ratio_HP_scale(i);
			
				printf("AMB_scale=%d, POWER_scale=%d\n", AMB_scale,POWER_scale);
				
				for (int j=0;j<num_mapping_rules;j++){	
					
					if 	(device_map_system_fanzone[j].fanzone_numbers==FAN_ZONE_NUM)
					{	
						//Must to add for loop for FANZONE_NUM for cases over 1 fan zone
						device_map_system_fanzone[j].fanduty_output_Openloop=currentConfig->fanzones[FAN_ZONE_NUM-1].HP_fan_zone_settings[POWER_scale][AMB_scale];
						printf("openloop_output=%f\n",device_map_system_fanzone[j].fanduty_output_Openloop);	
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



/*
void Low_Power_BAND(float system_amb,float temp,int i) 
{	


	
	//settings[0]-->M2
	//settings[1]-->HDD
	//settings[2]-->RAID
	//settings[3]-->PCH
	//settings[4]-->CPU_VR
	//settings[5]-->MEM_VR


	//critical
		
		if (temp >= THRESHOLD_settings[i].critical)
		{	
			 
			return THRESHOLD_settings[i].critical_fan_duty;
			 
		}

	
		//idle
		else if (temp < THRESHOLD_settings[i].idle_tcontrol)
		{
			if (system_amb<=55)
			{
				return THRESHOLD_settings[i].idle_tcontrol_fan_duty;
			}
			else 
			{
				return THRESHOLD_settings[i].abnormal_fan_duty;	
			}
		

		}
		
		
	//operating
		else if (temp <= THRESHOLD_settings[i].operating_tcontrol )
		{
			if (system_amb <=40)
			{
				return THRESHOLD_settings[i].operating_tcontrol_fan_duty;
			}
			else 
			{
				return THRESHOLD_settings[i].abnormal_fan_duty;	
			}
	

	
	//abnormal
		else if (temp>THRESHOLD_settings[i].abnormal_tcontrol)
		{
			if (system_amb <= 25)
			{
				return THRESHOLD_settings[i].operating_tcontrol_fan_duty;
			}
			else 
			{
				return THRESHOLD_settings[i].abnormal_fan_duty;	
			} 
		
	}
	
	
	
	
	
}

/*

/*
void LOW_POWER_BAND_MODULE()
{
		

		system_amb=get_sensorValue(ENTITY_Ambient_Sensor);
		LOW_POWER_BAND_TEMP_ARRAY[0]=get_sensorValue(ENTITY_MEMORY_DDR);
		LOW_POWER_BAND_TEMP_ARRAY[1]=get_sensorValue(ENTITY_RAID);
		LOW_POWER_BAND_TEMP_ARRAY[2]=get_sensorValue(ENTITY_HDD);
		LOW_POWER_BAND_TEMP_ARRAY[3]=get_sensorValue(ENTITY_LAN);
		LOW_POWER_BAND_TEMP_ARRAY[4]=get_sensorValue(ENTITY_PCH);
		LOW_POWER_BAND_TEMP_ARRAY[5]=get_sensorValue(ENTITY_Mdot2);
		LOW_POWER_BAND_TEMP_ARRAY[6]=get_sensorValue(ENTITY_CPU_VR);
		
		
			for(int i=0; i<LOW_POWER_BAND_COMPONENTS; i++){
				
				flaot temp; 

				if(LOW_POWER_BAND_TEMP_ARRAY[i]>temp)
				{
					
					temp=LOW_POWER_BAND_TEMP_ARRAY[i];
					LOW_POWER_BAND_TRIGGER_LABEL=i;
					
				}					
					
				
				float low_power_band_fanduty =Low_Power_BAND(system_amb,temp,LOW_POWER_BAND_TRIGGER_LABEL);
				
				
				
			}
			
			
			
				for (int i=0; i<num_mapping_rules;i++){
					
					if(device_map_system_fanzone[i].type==ENTITY_MEMORY_DDR)
						device_map_system_fanzone[i].MAX_fanduty_output=low_power_band_fanduty;
					if(device_map_system_fanzone[i].type==ENTITY_RAID)
						device_map_system_fanzone[i].MAX_fanduty_output=low_power_band_fanduty;
					if(device_map_system_fanzone[i].type==ENTITY_HDD)
						device_map_system_fanzone[i].MAX_fanduty_output=low_power_band_fanduty;
					if(device_map_system_fanzone[i].type==ENTITY_LAN)
						device_map_system_fanzone[i].MAX_fanduty_output=low_power_band_fanduty;
					if(device_map_system_fanzone[i].type==ENTITY_PCH)
						device_map_system_fanzone[i].MAX_fanduty_output=low_power_band_fanduty;
					if(device_map_system_fanzone[i].type==ENTITY_Mdot2)
						device_map_system_fanzone[i].MAX_fanduty_output=low_power_band_fanduty;
					if(device_map_system_fanzone[i].type==ENTITY_CPU_VR)
						device_map_system_fanzone[i].MAX_fanduty_output=low_power_band_fanduty;

				}
					
			
		
		
	


};

	
*/	
	
	
	
	






void CHECK_FAN_MAP()
{
	for (int k=1; k<FAN_ZONE_NUM+1; k++){
	
		for (int i=0; i<num_mapping_rules; i++){
			
			if(device_map_system_fanzone[i].fanzone_numbers==k)
			{	
				if(device_map_system_fanzone[i].type==ENTITY_FAN_TYPE_PERFORMANCE)
				{
					SET_SYS_FANDUTY2_BMC[FAN_NUMBER].ENTITY=ENTITY_FAN_TYPE_PERFORMANCE;
				
				}
				else if(device_map_system_fanzone[i].type==ENTITY_FAN_TYPE_STD)
				{
					SET_SYS_FANDUTY2_BMC[FAN_NUMBER].ENTITY=ENTITY_FAN_TYPE_STD;
				
				}	
			
				device_map_system_fanzone[i].MAX_fanduty_output=PICK_UP_MAX_FANDUTY(i);
		
				if (device_map_system_fanzone[i].MAX_fanduty_output>=MAX_FAN_DUTY_ALL)
				{	 
					MAX_FAN_DUTY_ALL=device_map_system_fanzone[i].MAX_fanduty_output;
					printf("MAX_FAN_DUTY_ALL=%f\n",MAX_FAN_DUTY_ALL);
				};
			}	

		};
	
	
		// OUTPUT THE FANDUTY TO THE FAN
	
	
	
		for (int j=1; j<FAN_NUMBER+1; j++){
			if (fanzone_map_fan[j-1]==k)
			{	
				SET_SYS_FANDUTY2_BMC[j].FANZONE_ID=k;
				SET_SYS_FANDUTY2_BMC[j].FAN_INSTANCE=j;
				SET_SYS_FANDUTY2_BMC[j].value=MAX_FAN_DUTY_ALL;
				printf("FAN %d, FANDUTY OUTPUT = %f\n",j,MAX_FAN_DUTY_ALL);
			}
			else
				printf("fanzone_map_fan[%d]=%d != %d\n", j, fanzone_map_fan[j-1], k);
		};

	}

};	

