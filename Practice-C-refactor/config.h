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
#define ENTITY_HDD 13
#define ENTITY_FAN_COOLING 14
#define ENTITY_CPU_POWER 15
#define CONFIG_NUM 2
#define FAN_ZONE_NUM 4
#define MAPPING_RULE_NUM 41
#define ENTITY_PCI_TIER1 16
#define ENTITY_PCI_TIER2 17
#define ENTITY_PCI_TIER3 18
#define ENTITY_PCI_TIER4 19
#define ENTITY_PCI_TIER5 20
#define ENTITY_PCI_TIER6 21
#define ENTITY_PCH 22
#define ENTITY_CPU_VR 23
#define ENTITY_MEM_VR 24
#define ENTITY_Ambient_Sensor 27

#define DEFAULT_CONFIG loadFanzoneConfig0
#define FAN_MIN 20
#define FAN_MAX 100

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
	int power_sensor_value;
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
	struct device PCI_type;
};



//========================================



struct fanzone {
	float STD_fan_zone_settings[6][8];
	float HP_fan_zone_settings[6][8];
};



/*
struct EXPECT_FAN_PWM[FAN_ZONE_NUM]{
	float PWM;
};
*/

/*
struct FAN_ZONE_MAP{
	struct EXPECT_FAN_PWM openloop;
	struct EXPECT_FAN_PWM CPU_PID;
	struct EXPECT_FAN_PWM SENSOR_Threshold;
	struct EXPECT_FAN_PWM pcie_tier;
	struct EXPECT_FAN_PWM MAX_output;


};
*/

struct FAN_ZONE_MAP {
	float openloop;
	float CPU_PID;
	float CPU_PID1;
	float SENSOR_Threshold;
	float pcie_tier;
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


struct PID_settings {
	int Margin;
	float kp;
	float ki;
	float kd;
	int T_control;
	int GB;

};

struct Tier {
	
	float tier_vs_AMB_std[7][8];
	float tier_vs_AMB_hp[7][8];
};




//struct PWM_output {
	
	
	//float system_output[4][6];
	
//};

	
	
	

/******************************************************************
 *                      Global Variables                          *
 ******************************************************************
 */
 
struct config* currentConfig;
struct FAN_ZONE_MAP FANMAP_output[FAN_ZONE_NUM];
struct device_map_fanzone device_map_system_fanzone[MAPPING_RULE_NUM];
struct PID_settings PID;
struct PID_settings PID_1;
struct Tier Temp_TIER_SETTINGS;
float overall_PWM_output[4][6];
 /******************************************************************
  *                           Functinos                            *
  ******************************************************************
  */
//?????????????
void get_system_fanzones();
void get_system_entity();
void loadDeviceFanZoneMappingTable();
void initial_PID_setting();

void initial_tier_settings();
//void initial_overall_PWM_output();
//void get_system_power_capping_info();
#endif
