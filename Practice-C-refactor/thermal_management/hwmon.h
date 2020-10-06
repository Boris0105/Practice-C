#ifndef HWMON_H
#define HWMON_H
#include "config.h"


#define max(x,y) ((x > y) ? x : y)

int power_ratio_HP_scale(int FANZONE_ID);
int power_ratio_STD_scale(int FANZONE_ID);
int amb_STD_scale(int ambTemp,int FANZONE_ID);
int amb_HP_scale(int ambTemp,int FANZONE_ID);
int get_sensorValue(int entity);
int get_entryId_instance(int entity,int deviceInstant);
int fan_map_output_PID(int ENTITY,int instance,float fanduty);

	
float get_CPU_Power_Ratio(int FANZONE_ID);


void* openloop(void*args);
void* CPU_PID(void*args);
void* CPU_PID1(void*args);
void* pcie_tier(void*args);
void* funcFanMap(void*args);


#endif









