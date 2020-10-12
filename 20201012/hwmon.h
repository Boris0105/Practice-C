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
float PICK_UP_MAX_FANDUTY(int i);


void SYSTEM_BASE_OPENLOOP();
void CHECK_FAN_MAP();
void PID_CONTROLLER();
void LOW_POWER_BAND();










#endif









