#ifndef __THERMAL_ALGORITHM_H
#define __THERMAL_ALGORITHM_H

#include "bmc_therm_device.h"



#define THERMAL_ID_cpu_dts_tdev 2
#define THERMAL_ID_cpu_power_tdev 3
#define THERMAL_ID_cpu_vr_tdev 4
#define THERMAL_ID_cpu_tdp 5
#define THERMAL_ID_dimm_proxy_tdev 6
#define THERMAL_ID_dimm_tdev 7
#define THERMAL_ID_drive_temp_tdev 8
#define THERMAL_ID_dimm_vr_tdev 9
#define THERMAL_ID_fan_proxy 10
#define THERMAL_ID_fan_sensor 11
#define THERMAL_ID_m2_drive_tdev 12
#define THERMAL_ID_m2_ambient_tdev 13
#define THERMAL_ID_pch_temp_dev 14
#define THERMAL_ID_psu_inlet_temp 15
#define THERMAL_ID_pci_tdev 16
#define THERMAL_ID_pldm_tdev 17
#define THERMAL_ID_raid_card_tdev 18
#define THERMAL_ID_raid_cap_tdev 19
#define THERMAL_ID_r7_drive_temp 20
#define THERMAL_ID_ambient_sensor 21


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
};










/******************************************************************
 *                      Global Variables                          *
 ******************************************************************
 */
 
struct config* currentConfig;
struct FAN_ZONE_MAP FANMAP_output[FAN_ZONE_NUM];
struct device_map_fanzone device_map_system_fanzone[MAPPING_RULE_NUM];
struct PID_settings PID[CPU_NUM];
struct PID_settings PID_1;

/*
 * thermal data -> pre_hook -> run -> post_hook -> action
 */
class thermal_algorithm
{
public:
	void pre_hook_raw_data(therm_device* tdev);
	void run();
	void post_hook_raw_data(therm_device* tdev);
	
	//void get_system_fanzones();
	//void get_system_entity();
	//void loadDeviceFanZoneMappingTable();
	//void initial_PID_setting();
	//void initial_tier_settings();

private:
	float m2_sensor_data;
	float amb_sensor_data;
	float fan_pwm;





#endif
