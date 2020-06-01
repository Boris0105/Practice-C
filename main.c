#include "config.h"

int main()
{
	int i;
	pthread_t thread_get_A;
	currentConfig = (struct config *) malloc(sizeof(struct config));

	get_system_entity();
	get_system_fanzones();
	pthread_create(&thread_get_A, NULL, get_system_power_capping_info, NULL);

	for (i = 0; i < 10; i++) {
		get_system_entity();
		get_system_fanzones();

		printf("%f, %f, %f, %f, %f, %f, %f, %f, %f\n",
			currentConfig->fanzones[0].STD_fan_zone_settings[0][0],
			currentConfig->fanzones[0].STD_fan_zone_settings[0][1],
			currentConfig->fanzones[0].STD_fan_zone_settings[0][2],
			currentConfig->fanzones[0].STD_fan_zone_settings[0][3],
			currentConfig->fanzones[0].STD_fan_zone_settings[0][4],
			currentConfig->fanzones[0].STD_fan_zone_settings[0][5],
			currentConfig->fanzones[0].STD_fan_zone_settings[0][6],
			currentConfig->fanzones[0].STD_fan_zone_settings[0][7],
			currentConfig->powerCapping);
	}
	pthread_join(thread_get_A, NULL);
}
