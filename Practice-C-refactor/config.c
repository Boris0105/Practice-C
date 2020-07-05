#include "config.h"

int loadFanzoneConfig0()
{
	struct fanzone tempFanzones[FAN_ZONE_NUM] = {
		{
			{
				{0,21,22,23,24,25,26,27},
				{0.2,20,21,22,23,24,25,26},
				{0.4,20,21,22,23,24,25,26},
				{0.6,20,21,22,23,24,25,26},
				{0.8,20,21,22,23,24,25,26},
				{1,20,21,22,23,24,25,26}
			},
			{
				{0,21,22,23,24,25,26,27},
				{0.2,30,31,32,33,34,35,36},
				{0.4,30,31,32,33,34,35,36},
				{0.6,30,31,32,33,34,35,36},
				{0.8,30,31,32,33,34,35,36},
				{1,30,31,32,33,34,35,36}
			}
		},
		{
			{
				{0,21,22,23,24,25,26,27},
				{0.2,20,21,22,23,24,25,26},
				{0.4,20,21,22,23,24,25,26},
				{0.6,20,21,22,23,24,25,26},
				{0.8,20,21,22,23,24,25,26},
				{1,20,21,22,23,24,25,26}
			},
			{
				{0,21,22,23,24,25,26,27},
				{0.2,30,31,32,33,34,35,36},
				{0.4,30,31,32,33,34,35,36},
				{0.6,30,31,32,33,34,35,36},
				{0.8,30,31,32,33,34,35,36},
				{1,30,31,32,33,34,35,36}
			}
		},
		{
			{
				{0,21,22,23,24,25,26,27},
				{0.2,20,21,22,23,24,25,26},
				{0.4,20,21,22,23,24,25,26},
				{0.6,20,21,22,23,24,25,26},
				{0.8,20,21,22,23,24,25,26},
				{1,20,21,22,23,24,25,26}
			},
			{
				{0,21,22,23,24,25,26,27},
				{0.2,30,31,32,33,34,35,36},
				{0.4,30,31,32,33,34,35,36},
				{0.6,30,31,32,33,34,35,36},
				{0.8,30,31,32,33,34,35,36},
				{1,30,31,32,33,34,35,36}
			}
		},
		{
			{
				{0,21,22,23,34,35,36,27},
				{0.2,20,21,22,23,24,25,26},
				{0.4,20,21,22,23,24,25,26},
				{0.6,20,21,22,23,24,25,26},
				{0.8,20,21,22,23,24,25,26},
				{1,20,21,22,23,24,25,26}
			},
			{
				{0,21,22,23,24,25,26,27},
				{0.2,30,31,32,33,34,35,36},
				{0.4,30,31,32,33,34,35,36},
				{0.6,30,31,32,33,34,35,36},
				{0.8,30,31,32,33,34,35,36},
				{1,30,31,32,33,34,35,36}
			}
		},
	};

	memcpy((void *)&(currentConfig->fanzones),
           (void *)&tempFanzones,
           sizeof(struct fanzone) * FAN_ZONE_NUM);

    return 1;
}




int loadPowercapConfig0() 
{
	struct powercapping temp_system_power_cap={
		
		    {
			{37,143,0,0,1},
			{40,113,0,0,1},
			{43,75,0,0,1},
			{45,70,0,0,1},
			{50,50,0,0,1}
			},
			{
			{15,0,0,0,1},
			{27,205,0,0,1},
			{30,125,0,0,1},
			{33,113,0,0,1},
			{36,102,0,0,1},
			{39,83,570,5,1},
			{42,60,480,3,1}
			},
	};

    memcpy((void *)&(currentConfig->system_powercapping_settings),
           (void *)&temp_system_power_cap,
           sizeof(struct powercapping));

    return 1;



}



int checkAndReturnFanzoneConfig0()
{
    struct entity_combination tempEntity = {
        { 0, 2 },
        { 5, 16 },
        { 6, 16 },
        { 9, 16 },
        { 10, 16 },
        { 11, 4 },
        { 13, 1 }
    };

    if (memcmp((void *)&(currentConfig->entity),
               (void *)&tempEntity,
               sizeof(struct entity_combination)) != 0)
        return 0;

    loadFanzoneConfig0();
	loadPowercapConfig0();
    return 1;
}

int loadFanzoneConfig1()
{
	struct fanzone tempFanzones[FAN_ZONE_NUM] = {
		{
			{
				{0,21,22,23,24,25,26,27},
				{0.2,20,21,22,23,24,25,26},
				{0.4,20,21,22,23,24,25,26},
				{0.6,20,21,22,23,24,25,26},
				{0.8,20,21,22,23,24,25,26},
				{1,20,21,22,23,24,25,26}
			},
			{
				{0,21,22,23,24,25,26,27},
				{0.2,30,31,32,33,34,35,36},
				{0.4,30,31,32,33,34,35,36},
				{0.6,30,31,32,33,34,35,36},
				{0.8,30,31,32,33,34,35,36},
				{1,30,31,32,33,34,35,36}
			}
		},
		{
			{
				{0,21,22,23,24,25,26,27},
				{0.2,20,21,22,23,24,25,26},
				{0.4,20,21,22,23,24,25,26},
				{0.6,20,21,22,23,24,25,26},
				{0.8,20,21,22,23,24,25,26},
				{1,20,21,22,23,24,25,26}
			},
			{
				{0,21,22,23,24,25,26,27},
				{0.2,30,31,32,33,34,35,36},
				{0.4,30,31,32,33,34,35,36},
				{0.6,30,31,32,33,34,35,36},
				{0.8,30,31,32,33,34,35,36},
				{1,30,31,32,33,34,35,36}
			}
		},
		{
			{
				{0,21,22,23,24,25,26,27},
				{0.2,20,21,22,23,24,25,26},
				{0.4,20,21,22,23,24,25,26},
				{0.6,20,21,22,23,24,25,26},
				{0.8,20,21,22,23,24,25,26},
				{1,20,21,22,23,24,25,26}
			},
			{
				{0,21,22,23,24,25,26,27},
				{0.2,30,31,32,33,34,35,36},
				{0.4,30,31,32,33,34,35,36},
				{0.6,30,31,32,33,34,35,36},
				{0.8,30,31,32,33,34,35,36},
				{1,30,31,32,33,34,35,36}
			}
		},
		{
			{
				{0,21,22,23,24,25,26,27},
				{0.2,20,21,22,23,24,25,26},
				{0.4,20,21,22,23,24,25,26},
				{0.6,20,21,22,23,24,25,26},
				{0.8,20,21,22,23,24,25,26},
				{1,20,21,22,23,24,25,26}
			},
			{
				{0,21,22,23,24,25,26,27},
				{0.2,30,31,32,33,34,35,36},
				{0.4,30,31,32,33,34,35,36},
				{0.6,30,31,32,33,34,35,36},
				{0.8,30,31,32,33,34,35,36},
				{1,30,31,32,33,34,35,36}
			}
		},
	};

	memcpy((void *)&(currentConfig->fanzones),
           (void *)&tempFanzones,
           sizeof(struct fanzone) * FAN_ZONE_NUM);

    return 1;
}


int loadPowercapConfig1() 
{
	struct powercapping temp_system_power_cap={
		
		    {
			{37,143,0,0,1},
			{40,113,0,0,1},
			{43,75,0,0,1},
			{45,70,0,0,1},
			{50,50,0,0,1}
			},
			{
			{15,0,0,0,1},
			{27,205,0,0,1},
			{30,125,0,0,1},
			{33,113,0,0,1},
			{36,102,0,0,1},
			{39,83,570,5,1},
			{42,60,480,3,1}
			},
	};


    memcpy((void *)&(currentConfig->system_powercapping_settings),
           (void *)&temp_system_power_cap,
           sizeof(struct powercapping));

    return 1;



}




int checkAndReturnFanzoneConfig1()
{
    struct entity_combination tempEntity = {
        { 0, 1 },
        { 5, 10 },
        { 6, 10 },
        { 9, 10 },
        {10, 10 },
        {11, 3 },
        {13, 1 }
    };

    if (memcmp((void *)&(currentConfig->entity),
               (void *)&tempEntity,
               sizeof(struct entity_combination)) != 0)
        return 0;

    loadFanzoneConfig1();
    loadPowercapConfig1();
	return 1;
}

void get_system_fanzones()
{
	int i;
	//=============================================================//
	int (*checkEntityThenReturnConfig[CONFIG_NUM + 1])() = {
		checkAndReturnFanzoneConfig0,
		checkAndReturnFanzoneConfig1,
		DEFAULT_CONFIG
	};
	//==============================================================//

	for (i = 0; i < CONFIG_NUM + 1; i++) {
		printf("%s: Checking entity#%d...\n", __func__, i);
		if (checkEntityThenReturnConfig[i]() == 1)
			return;
	}
}

void get_system_entity()
{
	// [WIP] entity shall be retrieved at system startup,
	// use a temporary entity here. This shall be removed later.
    	struct entity_combination temp4Config0 = {
		{ 0, 2 },
		{ 5, 16 },
		{ 6, 16 },
		{ 9, 16 },
		{ 10, 16 },
		{ 11, 4 },
		{ 13, 1 }
    };
    	struct entity_combination temp4Config1 = {
        	{ 0, 1 },
        	{ 5, 10 },
        	{ 6, 10 },
        	{ 9, 10 },
        	{10, 10 },
        	{11, 3 },
        	{13, 1 }
    };
    	struct entity_combination temp4Default = {
        	{ 1, 2 },
        	{ 3, 4 },
        	{ 5, 6 },
        	{ 7, 8 },
        	{ 9, 10 },
        	{ 11, 12 },
        	{ 13, 14 },
        	{ 15, 16 }
    };

	memcpy(&(currentConfig->entity), &temp4Config1, sizeof(struct entity_combination));
}

void loadDeviceFanZoneMappingTable()
{
    struct device_map_fanzone dmf[MAPPING_RULE_NUM] = {
		{ ENTITY_PROCESSOR,			DEVICE_INSTANT1,	FAN_INSTANT2,  2, 80 },
		{ ENTITY_PROCESSOR,			DEVICE_INSTANT1,	FAN_INSTANT3,  3, 80 },
		{ ENTITY_PROCESSOR,			DEVICE_INSTANT2,	FAN_INSTANT2,  2, 75 },
		{ ENTITY_PROCESSOR,			DEVICE_INSTANT2,	FAN_INSTANT3,  3, 78 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT1,	FAN_INSTANT2,  2, 45 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT2,	FAN_INSTANT2,  2, 43 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT3,	FAN_INSTANT2,  2, 48 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT4,	FAN_INSTANT2,  2, 45 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT5,	FAN_INSTANT2,  2, 45 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT6,	FAN_INSTANT2,  2, 48 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT7,	FAN_INSTANT2,  2, 47 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT8,	FAN_INSTANT2,  2, 46 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT9,	FAN_INSTANT2,  2, 45 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT10,	FAN_INSTANT2,  2, 44 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT11,	FAN_INSTANT2,  2, 43 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT12,	FAN_INSTANT2,  2, 42 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT13,	FAN_INSTANT2,  2, 41 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT14,	FAN_INSTANT2,  2, 46 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT15,	FAN_INSTANT2,  2, 45 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT16,	FAN_INSTANT2,  2, 44 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT1,	FAN_INSTANT3,  3, 43 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT2,	FAN_INSTANT3,  3, 45 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT3,	FAN_INSTANT3,  3, 47 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT4,	FAN_INSTANT3,  3, 48 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT5,	FAN_INSTANT3,  3, 45 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT6,	FAN_INSTANT3,  3, 48 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT7,	FAN_INSTANT3,  3, 45 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT8,	FAN_INSTANT3,  3, 46 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT9,	FAN_INSTANT3,  3, 47 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT10,	FAN_INSTANT3,  3, 45 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT11,	FAN_INSTANT3,  3, 45 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT12,	FAN_INSTANT3,  3, 45 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT13,	FAN_INSTANT3,  3, 43 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT14,	FAN_INSTANT3,  3, 55 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT15,	FAN_INSTANT3,  3, 57 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT16,	FAN_INSTANT3,  3, 60 },
		{ ENTITY_Ambient_Sensor,	DEVICE_INSTANT1,	FAN_INSTANT1,  1, 25 },
		{ ENTITY_Ambient_Sensor,	DEVICE_INSTANT1,	FAN_INSTANT2,  2, 25 },
		{ ENTITY_Ambient_Sensor,	DEVICE_INSTANT1,	FAN_INSTANT3,  3, 25 },
		{ ENTITY_Ambient_Sensor,	DEVICE_INSTANT1,	FAN_INSTANT4,  4, 25 },
		{ ENTITY_CPU_POWER,	        DEVICE_INSTANT1,	FAN_INSTANT4,  4, 200 }	
	};
    memcpy(&device_map_system_fanzone, &dmf, sizeof(struct device_map_fanzone) * MAPPING_RULE_NUM);
}




/*
void get_system_power_capping_info()
{
	// [WIP] Leave this empty temporarily
}
*/
