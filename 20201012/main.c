#include "predefine.h"
#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>


int findMappingRule(struct device_map_fanzone *raw)
{
	int i;
	for (i = 0; i < num_mapping_rules; i++) {
		if (raw->type == device_map_system_fanzone[i].type && raw->device == device_map_system_fanzone[i].device)
			return i;
	}
	return -1;
}




//int type, int instance_id, float value,float fanduty_output_Openloop,float fanduty_output_Low_POWER_POWERBAND,float  fanduty_output_PID_CONTROLLER,float MAX_fanduty_output, Fanzone_NUM,int fail_count
	

void INPUT_RAW_DATA(int type, int instance_id, float value, int fanzone_ID,int fail_count)
{
	struct device_map_fanzone raw; 
	struct device_map_fanzone *temp; 
	
//1type,2instance,3value,4Openloop,5Low_POWER_POWERBAND,6PID,7MAX_fanduty_output,8fanzone_ID,9int fail_count)
	
	                 //1  2   3      4     5      6      7     8    9
	
	
	//printf("Therm Dev %d  %d %5.2f %5.2f %5.2f  %5.2f   %5.2f  %d   %d\n",type,instance_id,value,fanduty_output_Openloop,fanduty_output_Low_POWER_POWERBAND,fanduty_output_PID_CONTROLLER,MAX_fanduty_output,fanzone_ID,fail_count);	
	
	
		
		raw.type=type;
		raw.device = instance_id;
		raw.value = value;
		raw.presence=1;
		raw.fanduty_output_Openloop=Default_FAN_DUTY;
		raw.fanduty_output_Low_POWER_POWERBAND=Default_FAN_DUTY;
		raw.fanduty_output_PID_CONTROLLER=Default_FAN_DUTY;
		raw.MAX_fanduty_output=Default_FAN_DUTY;
		raw.fanzone_numbers=fanzone_ID;
		raw.fail_count=fail_count;
			
	
	
	
	int  matchedRuleIdx= findMappingRule(&raw);
	
	//printf("findMappingRule %d\n", num_mapping_rules);
	//printf("matchedRuleIdx %d\n", matchedRuleIdx);

	if (matchedRuleIdx == -1) {
		
		//複製大一些的空間
		temp = malloc(sizeof(struct device_map_fanzone)*(num_mapping_rules + 1));
		

		
		
		for(int i =0; i<num_mapping_rules;i++) {
			
			
			
			temp[i].type=device_map_system_fanzone[i].type;
			temp[i].device=device_map_system_fanzone[i].device;
			temp[i].value=device_map_system_fanzone[i].value;
			temp[i].presence=device_map_system_fanzone[i].presence;
			temp[i].fanduty_output_Openloop=device_map_system_fanzone[i].fanduty_output_Openloop;
			temp[i].fanduty_output_Low_POWER_POWERBAND=device_map_system_fanzone[i].fanduty_output_Low_POWER_POWERBAND;
			temp[i].fanduty_output_PID_CONTROLLER=device_map_system_fanzone[i].fanduty_output_PID_CONTROLLER;
			temp[i].MAX_fanduty_output=device_map_system_fanzone[i].MAX_fanduty_output;
			temp[i].fanzone_numbers=device_map_system_fanzone[i].fanzone_numbers;
			temp[i].fail_count=device_map_system_fanzone[i].fail_count;
			
		}
		
		free(device_map_system_fanzone);
		
		device_map_system_fanzone = temp;
		
		device_map_system_fanzone[num_mapping_rules]=raw;
		
		/*
		printf("raw=%f\n", raw.value);
		printf("num_mapping_rules=%d\n",num_mapping_rules);
		memcpy(device_map_system_fanzone + num_mapping_rules, &raw, sizeof(struct device_map_fanzone));
		*/
	
		num_mapping_rules++;
		
	} else {
		
		device_map_system_fanzone[matchedRuleIdx].value=raw.value;

		//memcpy(device_map_system_fanzone + matchedRuleIdx, &raw, sizeof(struct device_map_fanzone));
		//printf("match_ID=%d\n", matchedRuleIdx);
		//printf("already in DB lists=%f\n", device_map_system_fanzone[matchedRuleIdx].value);
	
	}
}

int main()
{       
	
	//initial_FAN_OUTPUT();
	//print system configuration
	currentConfig = (struct config *) malloc(sizeof(struct config));
	//printf("空間位址：%p\n", currentConfig);
    //printf("儲存的值：%d\n", *currentConfig);
	
	
	num_mapping_rules = 1;
	device_map_system_fanzone = malloc(sizeof(struct device_map_fanzone)*num_mapping_rules);
	
	//printf("空間位址_宣告：%p\n", device_map_system_fanzone);
    //printf("儲存的值_宣告：%d\n", *device_map_system_fanzone);
	
	
	

	
	//int type, int instance_id, float value,fanduty_output_Openloop,fanduty_output_Low_POWER_POWERBAND,fanduty_output_PID_CONTROLLER,MAX_fanduty_output, Fanzone_NUM,int fail_count
	
		
	INPUT_RAW_DATA(ENTITY_PROCESSOR, 1, 6,1,0);
	INPUT_RAW_DATA(ENTITY_PROCESSOR, 2, 4,1,0);
	INPUT_RAW_DATA(ENTITY_PROCESSOR, 3, 6,1,0);
	INPUT_RAW_DATA(ENTITY_PROCESSOR, 4, 3,1,0);

	
	INPUT_RAW_DATA(ENTITY_CPU_POWER, 1, 165,1,0);
	INPUT_RAW_DATA(ENTITY_CPU_POWER, 2, 164,1,0);
	INPUT_RAW_DATA(ENTITY_CPU_POWER, 3, 250,1,0);
	INPUT_RAW_DATA(ENTITY_CPU_POWER, 4, 185,1,0);


	INPUT_RAW_DATA(ENTITY_CPU_POWER_TDP, 1, 250,1,0);
	INPUT_RAW_DATA(ENTITY_CPU_POWER_TDP, 2, 250,1,0);
	INPUT_RAW_DATA(ENTITY_CPU_POWER_TDP, 3, 250,1,0);
	INPUT_RAW_DATA(ENTITY_CPU_POWER_TDP, 4, 250,1,0);	

	
	INPUT_RAW_DATA(ENTITY_AMBIENT_SENSOR, 1, 23,1,0);	
	INPUT_RAW_DATA(ENTITY_AMBIENT_SENSOR, 2, 25,1,0);

	
	
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 1,   60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 2,   60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 3,   60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 4,   60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 5,   60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 6,   60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 7,   60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 8,   60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 9,   60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 10,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 11,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 12,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 13,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 14,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 15,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 16,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 17,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 18,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 19,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 20,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 21,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 22,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 23,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 24,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 25,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 26,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 27,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 28,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 29,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 30,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 31,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 32,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 33,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 34,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 35,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 36,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 37,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 38,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 39,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 40,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 41,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 42,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 43,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 44,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 45,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 46,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 47,  60,1,0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 48,  60,1,0);

	INPUT_RAW_DATA( ENTITY_HDD, 1,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 2,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 3,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 4,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 5,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 6,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 7,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 8,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 9,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 10,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 11,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 12,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 13,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 14,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 15,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 16,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 17,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 18,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 19,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 20,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 21,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 22,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 23,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 24,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 25,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 26,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 27,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 28,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 29,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 30,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 31,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 32,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 33,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 34,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 35,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 36,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 37,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 38,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 39,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 40,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 41,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 42,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 43,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 44,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 45,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 46,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 47,  52,1,0);
	INPUT_RAW_DATA( ENTITY_HDD, 48,  52,1,0);

	
	INPUT_RAW_DATA( ENTITY_RAID, 1, 60,1,0);
	INPUT_RAW_DATA( ENTITY_RAID, 2, 60,1,0);
	INPUT_RAW_DATA( ENTITY_RAID, 3, 52,1,0);
	INPUT_RAW_DATA( ENTITY_RAID, 4, 49,1,0);
	INPUT_RAW_DATA( ENTITY_RAID, 5, 60,1,0);
	INPUT_RAW_DATA( ENTITY_RAID, 6, 55,1,0);
	
	INPUT_RAW_DATA( ENTITY_LAN, 1, 52,1,0);
	INPUT_RAW_DATA( ENTITY_PCH, 1, 52,1,0);
	INPUT_RAW_DATA( ENTITY_Mdot2,1, 52,1,0);
	
	INPUT_RAW_DATA( ENTITY_CPU_VR,1, 52,1,0);
		
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE, 1, 20,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE, 2, 20,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE, 3, 20,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE, 4, 20,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE, 5, 20,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE, 6, 52,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE, 7, 52,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE, 8, 52,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE, 9, 52,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,10, 52,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,11, 52,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,12, 52,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,13, 52,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,14, 52,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,15, 52,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,16, 52,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,17, 52,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,18, 52,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,19, 52,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,20, 52,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,21, 52,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,22, 52,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,23, 52,1,0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,24, 52,1,0);
	
	
	

	//record the data for 4min. DATA_BASE_initialization
	//Make 4s as example
	sleep(2);
	
	
	
	printf("num_mapping_rules=%d\n",num_mapping_rules);
	
	
	for (int i = 1; i < num_mapping_rules; i++){
			
			
			
			printf("#%d %d %d %5.2f %d %5.2f %5.2f %5.2f %5.2f %d %d\n ", i,

			device_map_system_fanzone[i].type,
			device_map_system_fanzone[i].device,
			device_map_system_fanzone[i].value,
			device_map_system_fanzone[i].presence,
			device_map_system_fanzone[i].fanduty_output_Openloop,
			device_map_system_fanzone[i].fanduty_output_Low_POWER_POWERBAND,
			device_map_system_fanzone[i].fanduty_output_PID_CONTROLLER,
			device_map_system_fanzone[i].MAX_fanduty_output,
			device_map_system_fanzone[i].fanzone_numbers,
			device_map_system_fanzone[i].fail_count);
			
			
			
		if(device_map_system_fanzone[i].type==ENTITY_PROCESSOR)
		{
			currentConfig->entity.CPU.type=ENTITY_PROCESSOR;
			//printf("currentConfig->entity.CPU.type =%d\n",currentConfig->entity.CPU.type);
			currentConfig->entity.CPU.quantity=device_map_system_fanzone[i].device;
			//printf("CPU quantity=%d\n",currentConfig->entity.CPU.quantity);

		}
		if(device_map_system_fanzone[i].type==ENTITY_MEMORY_DDR)
		{
			currentConfig->entity.memory_DDR.type=ENTITY_MEMORY_DDR;
			currentConfig->entity.memory_DDR.quantity=device_map_system_fanzone[i].device;
			//printf("memory_DDR quantity=%d\n",currentConfig->entity.memory_DDR.quantity);
		}
		if(device_map_system_fanzone[i].type==ENTITY_HDD)
		{
			currentConfig->entity.drive_type.type=ENTITY_HDD;
			currentConfig->entity.drive_type.quantity=device_map_system_fanzone[i].device;
			//printf("HDD quantity=%d\n",currentConfig->entity.drive_type.quantity);
		}
		
		if(device_map_system_fanzone[i].type==ENTITY_FAN_TYPE_PERFORMANCE)
		{
			currentConfig->entity.fan_type.type=ENTITY_FAN_TYPE_PERFORMANCE;
			currentConfig->entity.fan_type.quantity=device_map_system_fanzone[i].device;
			//printf("FAN quantity=%d\n",currentConfig->entity.fan_type.quantity);
		}
			
		if(device_map_system_fanzone[i].type==ENTITY_RAID)
		{
			currentConfig->entity.RAID.type=ENTITY_RAID;
			currentConfig->entity.RAID.quantity=device_map_system_fanzone[i].device;
			//printf("RAID quantity=%d\n",currentConfig->entity.RAID.quantity);
		}

		
		
	}
	
	
	
	get_system_entity();
	get_system_fanzones();
	initial_PID_setting();
	

	
	//while(0){
	SYSTEM_BASE_OPENLOOP(); //include CPU_POWERBAND
	//LOW_POWER_BAND();
	PID_CONTROLLER();
	CHECK_FAN_MAP();


	
	printf("\tDevice | Instance | Sensor_Reading | Openloop PWM | TEMPBAND |   PID PWM   | MAX PWM | FANZONE ID | SENSOR_Fail_Count\n");
	
	//printf DB Data
	for(int i=1; i<num_mapping_rules; i++){
	
	
	
		if (device_map_system_fanzone[i].type==ENTITY_PROCESSOR)
		{
			printf("\tCPU        %d         %6.2f           %6.2f         %6.2f      %6.2f       %6.2f        %d           %d\n",
													 device_map_system_fanzone[i].device,
													 device_map_system_fanzone[i].value,
													 device_map_system_fanzone[i].fanduty_output_Openloop,
													 device_map_system_fanzone[i].fanduty_output_Low_POWER_POWERBAND,
												 	 device_map_system_fanzone[i].fanduty_output_PID_CONTROLLER,
													 device_map_system_fanzone[i].MAX_fanduty_output,
													 device_map_system_fanzone[i].fanzone_numbers,
													 device_map_system_fanzone[i].fail_count);

		}
	
	}
	//}
		
	free(currentConfig);
	

}


