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
		   
		   
		printf("%d, %d,%d, %d, %d, %d, %d\n",
		currentConfig->system_powercapping_settings.FanFailcap[0][1],
		currentConfig->system_powercapping_settings.FanFailcap[1][1],
		currentConfig->system_powercapping_settings.FanFailcap[2][1],
		currentConfig->system_powercapping_settings.FanFailcap[3][1],
		currentConfig->system_powercapping_settings.FanFailcap[4][1],
		currentConfig->system_powercapping_settings.FanFailcap[5][1],
		currentConfig->system_powercapping_settings.FanFailcap[6][1]);

    return 1;



}




int checkAndReturnFanzoneConfig0()
{
    struct entity_combination tempEntity = {
        { 0, 2 },
		{ 5, 16 },
		{ 6, 16 },
		{ 8, 4  },
		{ 9, 16 },
		{ 10, 16 },
		{ 11, 4 },
		{ 13, 1 },
		{	18,4}
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
        {13, 1 },
		{17,4}
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
		{ 8, 4  },
		{ 9, 16 },
		{ 10, 16 },
		{ 11, 4 },
		{ 13, 1 },
		{18,4}
    };
    	struct entity_combination temp4Config1 = {
        	{ 0, 1 },
        	{ 5, 10 },
        	{ 6, 10 },
			{8,4},
        	{ 9, 10 },
        	{10, 10 },
        	{11, 3 },
        	{13, 1 },
			{17,4}
    };
    	struct entity_combination temp4Default = {
        	{ 0, 1},
        	{ 3, 4 },
        	{ 5, 6 },
        	{ 7, 8 },
        	{ 9, 10 },
        	{ 11, 12 },
        	{ 11, 3 },
        	{ 13, 1 },
			{16,4}
    };

	memcpy(&(currentConfig->entity), &temp4Config0, sizeof(struct entity_combination));
}

void loadDeviceFanZoneMappingTable()
{
    struct device_map_fanzone dmf[MAPPING_RULE_NUM] = {
		{ ENTITY_PROCESSOR,			DEVICE_INSTANT1,	FAN_INSTANT2,  200, 3 },
		{ ENTITY_PROCESSOR,			DEVICE_INSTANT1,	FAN_INSTANT3,  200, 3 },
		{ ENTITY_PROCESSOR,			DEVICE_INSTANT2,	FAN_INSTANT2,  250, 5 },
		{ ENTITY_PROCESSOR,			DEVICE_INSTANT2,	FAN_INSTANT3,  250, 5 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT1,	FAN_INSTANT2,  15, 45 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT2,	FAN_INSTANT2,  15, 43 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT3,	FAN_INSTANT2,  15, 48 },
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
		{ ENTITY_Ambient_Sensor,	DEVICE_INSTANT1,	FAN_INSTANT1,  0, 25 },
		{ ENTITY_Ambient_Sensor,	DEVICE_INSTANT1,	FAN_INSTANT2,  0, 25 },
		{ ENTITY_Ambient_Sensor,	DEVICE_INSTANT1,	FAN_INSTANT3,  0, 25 },
		{ ENTITY_Ambient_Sensor,	DEVICE_INSTANT1,	FAN_INSTANT4,  0, 25 },
		{ ENTITY_RAID,				DEVICE_INSTANT1,	FAN_INSTANT4,  0, 70 },
		{ ENTITY_HDD,				DEVICE_INSTANT1,	FAN_INSTANT4,  0, 40 },
		{ ENTITY_LAN,				DEVICE_INSTANT1,	FAN_INSTANT4,  0, 66 },
		{ ENTITY_PCH,				DEVICE_INSTANT1,	FAN_INSTANT4,  0, 70 },
		{ ENTITY_Mdot2,				DEVICE_INSTANT1,	FAN_INSTANT4,  0, 60 },
		{ ENTITY_PCI_PLDM,			DEVICE_INSTANT1,	FAN_INSTANT4,  0, 75 },
		{ ENTITY_CPU_VR,			DEVICE_INSTANT1,	FAN_INSTANT4,  0, 65 },
		
	};
    memcpy(&device_map_system_fanzone, &dmf, sizeof(struct device_map_fanzone) * MAPPING_RULE_NUM);
}



void initial_PID_setting()
{
	PID[0].Margin=0;
	PID[0].kp=10.14;
	PID[0].ki=2;
	PID[0].kd=06;
	PID[0].T_control=8;
	PID[0].GB=1;
	
	PID[1].Margin=0;
	PID[1].kp=10.14;
	PID[1].ki=2;
	PID[1].kd=06;
	PID[1].T_control=8;
	PID[1].GB=1;
	

};

//void initial_overall_PWM_output()
//{
	float overall_PWM_output[4][6]=
							{
								{0,0,0,0,0,0},
								{0,0,0,0,0,0},
								{0,0,0,0,0,0},
								{0,0,0,0,0,0}
								
								
								
							};
	
	
//};



void initial_tier_settings()
{
 
 struct Tier Temp_tier= 
 {
					{
					{21,25,28,30,34,38,41,45},
					{1,20,21,22,23,24,25,26},
					{2,25,26,27,28,29,30,31},
					{3,30,31,32,33,34,35,36},
					{4,35,36,37,38,39,40,41},
					{5,40,41,42,43,44,45,46},
					{6,45,46,47,48,49,50,51}
					},
					{
					{21,25,28,30,34,38,41,45},
					{1,20,21,22,23,24,25,26},
					{2,25,26,27,28,29,30,31},
					{3,30,31,32,33,34,35,36},
					{4,35,36,37,38,39,40,41},
					{5,40,41,42,43,44,45,46},
					{6,45,46,47,48,49,50,51}
					}
};
	
	
	memcpy(&Temp_TIER_SETTINGS, &Temp_tier, sizeof(struct  Tier));
					
	

};






/*
void get_system_power_capping_info()
{
	// [WIP] Leave this empty temporarily
}
*/
