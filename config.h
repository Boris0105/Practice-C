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
#define ENTITY_PROCESSOR_high_Power 0
#define ENTITY_PROCESSOR 1
#define ENTITY_PROCESSOR_low_Power 2
#define ENTITY_Low_Power_DDR 3
#define ENTITY_MEMORY_DDR 4
#define ENTITY_High_Power_DDR 5
#define ENTITY_High_power_BPS 6
#define ENTITY_DRIVE_SAS_SATA_BACKPLANE 7
#define ENTITY_DRIVE_ANYBAY_BACKPLANE 8
#define ENTITY_DRIVE_SAS_SATA 9
#define ENTITY_DRIVE_NVME 10
#define ENTITY_FAN_TYPE_STD 11
#define ENTITY_FAN_TYPE_PERFORMANCE 12
#define ENTITY_Ambient_Sensor 13
#define ENTITY_FAN_COOLING 14
#define ENTITY_CPU_POWER 15
#define CONFIG_NUM 2
#define FAN_ZONE_NUM 4
#define MAPPING_RULE_NUM 41

#define DEFAULT_CONFIG loadFanzoneConfig0

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
	FAN_INSTANT1 = 0,
	FAN_INSTANT2,
	FAN_INSTANT3,
	FAN_INSTANT4,
	FAN_NUM
};
enum deviceInstant {
	DEVICE_INSTANT1 = 0,
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
	DEVICE_NUM
};



struct device_map_fanzone {
	short type;
	enum deviceInstant device;;
	enum fanInstant instant;
	int fanzone_information;
	int TEMP;
	
};




struct entity_combination {
	struct device CPU;
	struct device memory_DDR;
	struct device memory_BPS;
	struct device drive_type;
	struct device backplane_STD;
	struct device backplane_NVME;
	struct device fan_type;
	struct device AMB;
};



//========================================



struct fanzone {
	float STD_fan_zone_settings[6][8];
	float HP_fan_zone_settings[6][8];
};


struct FAN_ZONE_MAP {
	float openloop;
	float CPU_PID;
	float SENSOR_Threshold;
	float Max_output;
};




struct powercapping{
	int HighAmbcap[5][5];
	int FanFailcap[7][5];

};

struct config {
	struct entity_combination entity;
	struct fanzone fanzones[FAN_ZONE_NUM];
	struct powercapping system_powercapping_settings;
	// [WIP] see get_system_power_capping_info in config.c
    //struct powerCappingInfo powerCapping_config;
};

/******************************************************************
 *                      Global Variables                          *
 ******************************************************************
 */
 
struct config* currentConfig;
struct FAN_ZONE_MAP FANMAP_output[FAN_ZONE_NUM];
struct device_map_fanzone device_map_system_fanzone[MAPPING_RULE_NUM];


 /******************************************************************
  *                           Functinos                            *
  ******************************************************************
  */
//?????????????
void get_system_fanzones();
void get_system_entity();
//void get_system_power_capping_info();
#endif
