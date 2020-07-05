#include <stdio.h>
#include <string.h>

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

#define CONFIG_NUM 2
#define FAN_ZONE_NUM 4
#define FAN_NUM 4

#define DEFAULT_CONFIG loadFanzoneConfig0

/******************************************************************
 *                         Structures                             *
 ******************************************************************
 */

struct device {
	short type;
	short quantity;
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

struct fanzone {
	float STD_fan_zone_settings[6][8];
	float HP_fan_zone_settings[6][8];
};

struct config {
	struct entity_combination entity;
	struct fanzone fanzones[FAN_ZONE_NUM];
	// [WIP] see get_system_power_capping_info in config.c
    //struct powerCappingInfo powerCapping_config;
};

/******************************************************************
 *                      Global Variables                          *
 ******************************************************************
 */

struct config *currentConfig;


 /******************************************************************
  *                           Functinos                            *
  ******************************************************************
  */
//?????????????
void get_system_fanzones();
void get_system_entity();
void get_system_power_capping_info();
