#ifndef CONFIG_H
#define CONFIG_H
#include "hwmon.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>


/******************************************************************
 *                            Marcos                              *
 ******************************************************************
 */
#define ENTITY_PROCESSOR 0
#define ENTITY_Low_Power_DDR 1
#define ENTITY_MEMORY_DDR 2
#define ENTITY_DDR 3
#define ENTITY_DRIVE_SAS_SATA 4
#define ENTITY_CPU_POWER_TDP 5
#define ENTITY_DRIVE_NVME 6
#define ENTITY_FAN_TYPE_STD 7
#define ENTITY_FAN_TYPE_PERFORMANCE 8
#define ENTITY_HDD 9
#define ENTITY_FAN_COOLING 10
#define ENTITY_CPU_POWER 11
#define CONFIG_NUM 2
#define ENTITY_Ambient_Sensor 13
#define MAPPING_RULE_NUM 134
#define ENTITY_PCI_TIER1 15
#define ENTITY_PCI_TIER2 16
#define ENTITY_PCI_TIER3 17
#define ENTITY_PCI_TIER4 18
#define ENTITY_PCI_TIER5 19
#define ENTITY_PCI_TIER6 20
#define ENTITY_PCH 21
#define ENTITY_CPU_VR 22
#define ENTITY_MEM_VR 23
#define FAN_ZONE_NUM 1
#define ENTITY_RAID 25
#define ENTITY_Mdot2 26
#define ENTITY_LAN 27
#define ENTITY_PCI_PLDM 28
#define ENTITY_GPU 29
#define CPU_NUM 4
#define LEN(x) sizeof(x) / sizeof(x[0])
#define FAN_NUMBER 24
#define DEFAULT_CONFIG loadFanzoneConfig0
#define FAN_MIN 20
#define FAN_MAX 100
#define DIMM_INSTANCE 48

#define LOW_POWER_BAND_COMPONENTS 7

/******************************************************************
 *                         Structures                             *
 ******************************************************************
 */

struct device {
	short type;
	short quantity;
};




/* Fan Instance */
enum fanInstant {
	FAN_INSTANT1 = 1,
	FAN_INSTANT2,
	FAN_INSTANT3,
	FAN_INSTANT4,
	FAN_NUM
};
enum deviceInstant {
	DEVICE_INSTANT1 = 1,
	DEVICE_INSTANT2,
	DEVICE_INSTANT3,
	DEVICE_INSTANT4,
	DEVICE_INSTANT5,
	DEVICE_INSTANT6,
	DEVICE_INSTANT7,
	DEVICE_INSTANT8,
	DEVICE_INSTANT9,
	DEVICE_INSTANT10,
	DEVICE_INSTANT11,
	DEVICE_INSTANT12,
	DEVICE_INSTANT13,
	DEVICE_INSTANT14,
	DEVICE_INSTANT15,
	DEVICE_INSTANT16,
	DEVICE_INSTANT17,
	DEVICE_INSTANT18,
	DEVICE_INSTANT19,
	DEVICE_INSTANT20,
	DEVICE_INSTANT21,
	DEVICE_INSTANT22,
	DEVICE_INSTANT23,
	DEVICE_INSTANT24,
	DEVICE_INSTANT25,
	DEVICE_INSTANT26,
	DEVICE_INSTANT27,
	DEVICE_INSTANT28,
	DEVICE_INSTANT29,
	DEVICE_INSTANT30,
	DEVICE_INSTANT31,
	DEVICE_INSTANT32,
	DEVICE_INSTANT33,
	DEVICE_INSTANT34,
	DEVICE_INSTANT35,
	DEVICE_INSTANT36,
	DEVICE_INSTANT37,
	DEVICE_INSTANT38,
	DEVICE_INSTANT39,
	DEVICE_INSTANT40,
	DEVICE_INSTANT41,
	DEVICE_INSTANT42,
	DEVICE_INSTANT43,
	DEVICE_INSTANT44,
	DEVICE_INSTANT45,
	DEVICE_INSTANT46,
	DEVICE_INSTANT47,
	DEVICE_INSTANT48,
	DEVICE_INSTANT49,
	DEVICE_INSTANT50,
	DEVICE_INSTANT51,
	DEVICE_INSTANT52,
	DEVICE_NUM
};


/*
struct device_map_fanzone {
	short type;
	enum deviceInstant device;
	enum fanInstant instant;
	int power_sensor_value;
	int TEMP;
	
};
*/



struct fanzone {
	float STD_fan_zone_settings[6][8];
	float HP_fan_zone_settings[6][8];
};



struct device_map_fanzone {
	short 	type;
	enum 	deviceInstant device;
	float 	value;
	int   	presence;	
	float   fanduty_output_Openloop;
	float   fanduty_output_Low_POWER_POWERBAND;
	float	fanduty_output_PID_CONTROLLER;
	float   MAX_fanduty_output;
	int 	fanzone_numbers;
	int 	fail_count;
		
};




struct entity_combination {
	struct device CPU;
	struct device memory_DDR;
	struct device drive_type;
	struct device fan_type;
	struct device RAID;
	
};






struct powercapping{
	int HighAmbcap[5][5];
	int FanFailcap[7][5];

};

struct config {
	struct entity_combination entity;
	struct fanzone fanzones[FAN_ZONE_NUM];
	struct powercapping system_powercapping_settings;
	
};


struct PID_settings {
	int Margin;
	float kp;
	float ki;
	float kd;
	int T_control;
	int GB;

};

struct THRESHOLD_settings{
	float critical;
	float critical_fan_duty;
	float idle_tcontrol;
	float idle_tcontrol_fan_duty;
	float operating_tcontrol;
	float operating_tcontrol_fan_duty;
	float abnormal_tcontrol;
	float abnormal_fan_duty;

};

	
	
	

/******************************************************************
 *                      Global Variables                          *
 ******************************************************************
 */
 
struct config* currentConfig;
struct device_map_fanzone *device_map_system_fanzone;
struct PID_settings PID[CPU_NUM];
//struct THRESHOLD_settings_LPB THRESHOLD_settings[LOW_POWER_BAND_COMPONENTS];
float overall_PWM_output[4][6];
float FAN_OUTPUT[FAN_NUMBER][2];
int LOW_POWER_BAND_TRIGGER_LABEL;
float LOW_POWER_BAND_TEMP_ARRAY[LOW_POWER_BAND_COMPONENTS];
int num_mapping_rules;

 /******************************************************************
  *                           Functinos                            *
  ******************************************************************
  */
//?????????????
void get_system_fanzones();
void get_system_entity();
//void loadDeviceFanZoneMappingTable();
void initial_PID_setting();
//void initial_threshold_setting();
//void SYSTEM_BASE_OPENLOOP();
//void LOW_POWER_BAND();
//void PID_CONTROLLER();
//void CHECK_FAN_MAP();
//float PICK_UP_MAX_FANDUTY();

//void initial_overall_PWM_output();
//void get_system_power_capping_info();
#endif
