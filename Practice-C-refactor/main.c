#include "config.h"

int main()
{
	currentConfig = (struct config *) malloc(sizeof(struct config));

	get_system_entity();
	get_system_fanzones();
	//get_system_power_capping_info();
    
	 
	/*printf("%f, %f, %f, %f, %f, %f, %f, %f\n",
		currentConfig->fanzones[0].STD_fan_zone_settings[0][0],
		currentConfig->fanzones[0].STD_fan_zone_settings[0][1],
		currentConfig->fanzones[0].STD_fan_zone_settings[0][2],
		currentConfig->fanzones[0].STD_fan_zone_settings[0][3],
		currentConfig->fanzones[0].STD_fan_zone_settings[0][4],
		currentConfig->fanzones[0].STD_fan_zone_settings[0][5],
		currentConfig->fanzones[0].STD_fan_zone_settings[0][6],
		currentConfig->fanzones[0].STD_fan_zone_settings[0][7]);
		
		
		printf("%d, %d,%d, %d, %d, %d, %d\n",
		currentConfig->system_powercapping_settings.FanFailcap[0][1],
		currentConfig->system_powercapping_settings.FanFailcap[1][1],
		currentConfig->system_powercapping_settings.FanFailcap[2][1],
		currentConfig->system_powercapping_settings.FanFailcap[3][1],
		currentConfig->system_powercapping_settings.FanFailcap[4][1],
		currentConfig->system_powercapping_settings.FanFailcap[5][1],
		currentConfig->system_powercapping_settings.FanFailcap[6][1]);
	*/

	


		
		pthread_t SYSTEM_OPENLOOP;
		//pthread_t CPU_Closeloop_pid;
		pthread_t GET_FAN_MAP;
		//pthread_t Sensor_Threshold;
		
		
		
		
		pthread_create(&SYSTEM_OPENLOOP,NULL,openloop,NULL);   //P1: function: AMB_Base_Duty
		//pthread_create(&CPU_Closeloop_pid,NULL,CPU_PID,NULL); // P2: CPU_PID
		pthread_create(&GET_FAN_MAP,NULL,funcFanMap,NULL); //P3: funcFanMap
		
		//pthread_create(&Sensor_Threshold,NULL,SENSOR_Threshold,&device_map_temperature); // SENSOR_Threshold




	pthread_join(SYSTEM_OPENLOOP,NULL);
	pthread_join(GET_FAN_MAP,NULL);
	printf("FANZONE 1 =%f\n", FANMAP_output[0].Max_output);
	printf("FANZONE 2 =%f\n", FANMAP_output[1].Max_output);
	printf("FANZONE 3 =%f\n", FANMAP_output[2].Max_output);
	printf("FANZONE 4 =%f\n", FANMAP_output[3].Max_output);
	free(currentConfig);

}
