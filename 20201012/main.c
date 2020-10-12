#include "config.h"
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


void INPUT_RAW_DATA(int type, int instance_id, int value, int fail_count)
{
	struct device_map_fanzone raw; 
	struct device_map_fanzone *temp; 
	
	/*
	printf("Therm Dev [%d][%d]- Processing... Value=%d, %d\n",
		   type, instance_id, value, fail_count);
	*/
	
	
	if(type == ENTITY_PROCESSOR) {
		raw.type = ENTITY_PROCESSOR;
		raw.device = instance_id;
		raw.value = value;
		raw.presence=1;
	}
	if(type == ENTITY_CPU_POWER) {
		raw.type = ENTITY_CPU_POWER;
		raw.device = instance_id;
		raw.value = value;
		raw.presence=1;
	}
	if(type == ENTITY_CPU_POWER_TDP) {
		raw.type = ENTITY_CPU_POWER_TDP;
		raw.device = instance_id;
		raw.value = value;
		raw.presence=1;
	}
	if(type == ENTITY_CPU_POWER_TDP) {
		raw.type = ENTITY_CPU_POWER_TDP;
		raw.device = instance_id;
		raw.value = value;
		raw.presence=1;
	}
	if(type == ENTITY_Ambient_Sensor) {
		raw.type = ENTITY_Ambient_Sensor;
		raw.device = instance_id;
		raw.value = value;
		raw.presence=1;
	}
	
	if(type == ENTITY_MEMORY_DDR) {
		raw.type = ENTITY_MEMORY_DDR;
		raw.device = instance_id;
		raw.value = value;
		raw.presence=1;
	}
	if(type == ENTITY_HDD) {
		raw.type = ENTITY_HDD;
		raw.device = instance_id;
		raw.value = value;
		raw.presence=1;
	}
	if(type == ENTITY_RAID) {
		raw.type = ENTITY_RAID;
		raw.device = instance_id;
		raw.value = value;
		raw.presence=1;
	}
	if(type == ENTITY_LAN) {
		raw.type = ENTITY_LAN;
		raw.device = instance_id;
		raw.value = value;
		raw.presence=1;
	}
	if(type == ENTITY_PCH) {
		raw.type = ENTITY_PCH;
		raw.device = instance_id;
		raw.value = value;
		raw.presence=1;
	}
	if(type == ENTITY_Mdot2) {
		raw.type = ENTITY_Mdot2;
		raw.device = instance_id;
		raw.value = value;
		raw.presence=1;
	}
	if(type == ENTITY_CPU_VR) {
		raw.type = ENTITY_CPU_VR;
		raw.device = instance_id;
		raw.value = value;
		raw.presence=1;
	}
	if(type == ENTITY_FAN_TYPE_PERFORMANCE) {
		raw.type = ENTITY_FAN_TYPE_PERFORMANCE;
		raw.device = instance_id;
		raw.value = value;
		raw.presence=1;
	}		
	
	
	
	
	int matchedRuleIdx = findMappingRule(&raw);
	
	//printf("findMappingRule %d\n", num_mapping_rules);
	//printf("matchedRuleIdx %d\n", matchedRuleIdx);
	if (matchedRuleIdx == -1) {
		temp = realloc(device_map_system_fanzone, sizeof(struct device_map_fanzone) * (num_mapping_rules + 1));
		//free(device_map_system_fanzone);
		
		device_map_system_fanzone = temp;
		
		memcpy(device_map_system_fanzone + num_mapping_rules, &raw, sizeof(struct device_map_fanzone));
		num_mapping_rules++;
		
	} else {
		memcpy(device_map_system_fanzone + matchedRuleIdx, &raw, sizeof(struct device_map_fanzone));
		
	}
}

int main()
{       
	
	//print system configuration
	currentConfig = (struct config *) malloc(sizeof(struct config));
	
	num_mapping_rules = 1;
	device_map_system_fanzone = malloc(0);
	
	
	for(int i=0;i<2;i++){
	i;
	INPUT_RAW_DATA(ENTITY_PROCESSOR, 1, 65, 0);
	INPUT_RAW_DATA(ENTITY_PROCESSOR, 2, 64, 0);
	INPUT_RAW_DATA(ENTITY_PROCESSOR, 3, 63, 0);
	INPUT_RAW_DATA(ENTITY_PROCESSOR, 4, 62, 0);

	
	INPUT_RAW_DATA(ENTITY_CPU_POWER, 1, 65, 0);
	INPUT_RAW_DATA(ENTITY_CPU_POWER, 2, 64, 0);
	INPUT_RAW_DATA(ENTITY_CPU_POWER, 3, 63, 0);
	INPUT_RAW_DATA(ENTITY_CPU_POWER, 4, 62, 0);


	INPUT_RAW_DATA(ENTITY_CPU_POWER_TDP, 1, 250, 0);
	INPUT_RAW_DATA(ENTITY_CPU_POWER_TDP, 2, 250, 0);
	INPUT_RAW_DATA(ENTITY_CPU_POWER_TDP, 3, 250, 0);
	INPUT_RAW_DATA(ENTITY_CPU_POWER_TDP, 4, 250, 0);	

	
	INPUT_RAW_DATA(ENTITY_Ambient_Sensor, 1, 23, 0);	
	INPUT_RAW_DATA(ENTITY_Ambient_Sensor, 2, 25, 0);

	
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 1,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 2,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 3,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 4,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 5,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 6,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 7,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 8,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 9,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 10,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 11,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 12,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 13,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 14,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 15,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 16,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 17,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 18,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 19,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 20,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 21,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 22,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 23,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 24,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 25,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 26,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 27,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 28,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 29,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 30,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 31,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 32,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 33,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 34,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 35,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 36,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 37,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 38,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 39,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 40,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 41,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 42,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 43,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 44,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 45,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 46,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 47,  60, 0);
	INPUT_RAW_DATA( ENTITY_MEMORY_DDR, 48,  60, 0);

	INPUT_RAW_DATA( ENTITY_HDD, 1,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 2,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 3,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 4,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 5,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 6,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 7,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 8,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 9,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 10,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 11,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 12,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 13,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 14,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 15,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 16,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 17,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 18,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 19,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 20,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 21,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 22,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 23,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 24,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 25,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 26,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 27,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 28,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 29,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 30,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 31,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 32,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 33,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 34,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 35,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 36,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 37,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 38,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 39,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 40,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 41,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 42,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 43,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 44,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 45,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 46,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 47,  52, 0);
	INPUT_RAW_DATA( ENTITY_HDD, 48,  52, 0);

	
	INPUT_RAW_DATA( ENTITY_RAID, 1, 60, 0);
	INPUT_RAW_DATA( ENTITY_RAID, 2, 60, 0);
	INPUT_RAW_DATA( ENTITY_RAID, 3, 52, 0);
	INPUT_RAW_DATA( ENTITY_RAID, 4, 49, 0);
	INPUT_RAW_DATA( ENTITY_RAID, 5, 60, 0);
	INPUT_RAW_DATA( ENTITY_RAID, 6, 55, 0);
	
	INPUT_RAW_DATA( ENTITY_LAN, 1, 52, 0);
	INPUT_RAW_DATA( ENTITY_PCH, 1, 52, 0);
	INPUT_RAW_DATA( ENTITY_Mdot2,1, 52, 0);
	INPUT_RAW_DATA( ENTITY_CPU_VR,1, 52, 0);
		
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE, 1, 20, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE, 2, 20, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE, 3, 20, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE, 4, 20, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE, 5, 20, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE, 6, 52, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE, 7, 52, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE, 8, 52, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE, 9, 52, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,10, 52, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,11, 52, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,12, 52, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,13, 52, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,14, 52, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,15, 52, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,16, 52, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,17, 52, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,18, 52, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,19, 52, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,20, 52, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,21, 52, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,22, 52, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,23, 52, 0);
	INPUT_RAW_DATA( ENTITY_FAN_TYPE_PERFORMANCE,24, 52, 0);
	
	}
	

	//record the data for 4min. DATA_BASE_initialization
	//Make 4s as example
	sleep(4);
	
	
	
	printf("num_mapping_rules=%d",num_mapping_rules);
	
	
	for (int i = 0; i < num_mapping_rules; i++){
		printf("#%d %d %d %5.2f\n", 			i,
			//(device_map_system_fanzone + i)->type,
			//(device_map_system_fanzone + i)->device,
			//(device_map_system_fanzone + i)->value);
			
			
			device_map_system_fanzone[i].type,
			device_map_system_fanzone[i].device,
			device_map_system_fanzone[i].value);

		if(device_map_system_fanzone[i].type==ENTITY_PROCESSOR)
		{
			currentConfig->entity.CPU.type=ENTITY_PROCESSOR;
			//printf("currentConfig->entity.CPU.type =%d\n",currentConfig->entity.CPU.type);
			currentConfig->entity.CPU.quantity=device_map_system_fanzone[i].device;
			printf("CPU quantity=%d\n",currentConfig->entity.CPU.quantity);

		}
		if(device_map_system_fanzone[i].type==ENTITY_MEMORY_DDR)
		{
			currentConfig->entity.memory_DDR.type=ENTITY_MEMORY_DDR;
			currentConfig->entity.memory_DDR.quantity=device_map_system_fanzone[i].device;
			printf("memory_DDR quantity=%d\n",currentConfig->entity.memory_DDR.quantity);
		}
		if(device_map_system_fanzone[i].type==ENTITY_HDD)
		{
			currentConfig->entity.drive_type.type=ENTITY_HDD;
			currentConfig->entity.drive_type.quantity=device_map_system_fanzone[i].device;
			printf("HDD quantity=%d\n",currentConfig->entity.drive_type.quantity);
		}
		
		if(device_map_system_fanzone[i].type==ENTITY_FAN_TYPE_PERFORMANCE)
		{
			currentConfig->entity.fan_type.type=ENTITY_FAN_TYPE_PERFORMANCE;
			currentConfig->entity.fan_type.quantity=device_map_system_fanzone[i].device;
			printf("FAN quantity=%d\n",currentConfig->entity.fan_type.quantity);
		}
			
		if(device_map_system_fanzone[i].type==ENTITY_RAID)
		{
			currentConfig->entity.RAID.type=ENTITY_RAID;
			currentConfig->entity.RAID.quantity=device_map_system_fanzone[i].device;
			printf("RAID quantity=%d\n",currentConfig->entity.RAID.quantity);
		}
		
		
	}
	
	
	
	get_system_entity();
	get_system_fanzones();
	
	
	
	initial_PID_setting();
	
/*	
	
	while(1){
	SYSTEM_BASE_OPENLOOP(); //include CPU_POWERBAND
	//void LOW_POWER_BAND();
	PID_CONTROLLER();
	//CHECK_FAN_MAP();

	};
*/
		
	free(currentConfig);
	

}


