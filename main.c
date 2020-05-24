#include "config.h"
#include <stdlib.h>

int main()
{
	currentConfig = (struct config *) malloc(sizeof(struct config));

	get_system_entity();
	get_system_fanzones();
	get_system_power_capping_info();

	printf("%f, %f, %f, %f, %f, %f, %f, %f\n",
		currentConfig->fanzones[0].STD_fan_zone_settings[0][0],
		currentConfig->fanzones[0].STD_fan_zone_settings[0][1],
		currentConfig->fanzones[0].STD_fan_zone_settings[0][2],
		currentConfig->fanzones[0].STD_fan_zone_settings[0][3],
		currentConfig->fanzones[0].STD_fan_zone_settings[0][4],
		currentConfig->fanzones[0].STD_fan_zone_settings[0][5],
		currentConfig->fanzones[0].STD_fan_zone_settings[0][6],
		currentConfig->fanzones[0].STD_fan_zone_settings[0][7]);
}
