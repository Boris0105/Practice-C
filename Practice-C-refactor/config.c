#include "config.h"

int loadFanzoneConfig0()
{
	printf("loadFanzoneConfig0\n");
	struct fanzone tempFanzones = {
		
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

	};
	
	
	memcpy((void *)&(currentConfig->fanzones),
           (void *)&tempFanzones,
           sizeof(struct fanzone) * FAN_ZONE_NUM);
	
	
	printf("complete to load openloop table\n");
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
		
	printf("complete to load Power cap config\n");

    return 1;

}




int checkAndReturnFanzoneConfig0()
{
    struct entity_combination tempEntity = {
    { 0, 4  },
	{ 3, 48 },
	{ 4, 48 },
	{ 7, 24 },
	{ 25, 4 },
    };


    if (memcmp((void *)&(currentConfig->entity),(void *)&tempEntity,sizeof(struct entity_combination))!= 0)
        return 0;

    loadFanzoneConfig0();
	loadPowercapConfig0();
	printf("Check out here2");
    return 1;
	
}

int loadFanzoneConfig1()
{
	struct fanzone tempFanzones = {
		
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
	
		{ 0,  2 },
		{ 3, 48 },
		{ 4, 48 },
		{ 11,24 },
		{ 28, 4 },
		
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
	int (*checkEntityThenReturnConfig[CONFIG_NUM + 1])() = {
		checkAndReturnFanzoneConfig0,
		checkAndReturnFanzoneConfig1,
		DEFAULT_CONFIG
	};
	//==============================================================//

	for (i = 0; i < CONFIG_NUM + 1; i++) {
		printf("%s: Checking entity#%d...\n", __func__, i);
		if (checkEntityThenReturnConfig[i]() == 1)	
		printf("complete to get_system_fanzones");
		return;
	}
}

void get_system_entity()
{
	// [WIP] entity shall be retrieved at system startup,
	// use a temporary entity here. This shall be removed later.
    	struct entity_combination temp4Config0 = {
		{ 0, 4   },
		{ 3, 48  },
		{ 4, 48  },
		{ 7, 24  },
		{ 25, 4  },
		};
    
    	struct entity_combination temp4Config1 = {
		{ 0, 3 },
		{ 3, 48 },
		{ 4, 48 },
		{ 7, 24  },
		{ 25, 4},
		};
    
    	struct entity_combination temp4Default = {
		{ 0, 4 },
		{ 3, 48 },
		{ 4, 48 },
		{ 7, 24 },
		{ 25, 3},
		};

	memcpy(&(currentConfig->entity), &temp4Config0, sizeof(struct entity_combination));
}

void loadDeviceFanZoneMappingTable()
{
    struct device_map_fanzone dmf[MAPPING_RULE_NUM] = {
		{ ENTITY_PROCESSOR,			DEVICE_INSTANT1,		50, 	1,0,0,0,0,1 },
		{ ENTITY_PROCESSOR,			DEVICE_INSTANT2,		43, 	1,0,0,0,0,1 },
		{ ENTITY_PROCESSOR,			DEVICE_INSTANT3,		17, 	1,0,0,0,0,1 },
		{ ENTITY_PROCESSOR,			DEVICE_INSTANT4,	 	5, 		1,0,0,0,0,1 },
		{ ENTITY_PROCESSOR,			DEVICE_INSTANT5,        0, 	 	0,0,0,0,0,1 },
		{ ENTITY_PROCESSOR,			DEVICE_INSTANT6,	    0, 		0,0,0,0,0,1 },
		{ ENTITY_PROCESSOR,			DEVICE_INSTANT7,	    0, 		0,0,0,0,0,1 },
		{ ENTITY_PROCESSOR,			DEVICE_INSTANT8,	    0, 		0,0,0,0,0,1 },
		
		
		{ ENTITY_CPU_POWER,			DEVICE_INSTANT1,	  100, 		1,0,0,0,0,1 },
		{ ENTITY_CPU_POWER,			DEVICE_INSTANT2,	  165, 		1,0,0,0,0,1 },
		{ ENTITY_CPU_POWER,			DEVICE_INSTANT3,	  205, 		1,0,0,0,0,1 },
		{ ENTITY_CPU_POWER,			DEVICE_INSTANT4,	  185, 		1,0,0,0,0,1 },
		
		{ ENTITY_CPU_POWER_TDP,		DEVICE_INSTANT1,	  250, 		1,0,0,0,0,1 },
		{ ENTITY_CPU_POWER_TDP,		DEVICE_INSTANT2,	  250, 		1,0,0,0,0,1 },
		{ ENTITY_CPU_POWER_TDP,		DEVICE_INSTANT3,	  250, 		1,0,0,0,0,1 },
		{ ENTITY_CPU_POWER_TDP,		DEVICE_INSTANT4,	  250, 		1,0,0,0,0,1 },
		
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT1,	  60, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT2,	  56, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT3,	  60, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT4,	  55, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT5,	  50, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT6,	  51, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT7,	  52, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT8,	  53, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT9,	  50, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT10,	  51, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT11,	  52, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT12,	  56, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT13,	  59, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT14,	  52, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT15,	  55, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT16,	  54, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT17,	  54, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT18,	  51, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT19,	  54, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT20,	  53, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT21,	  50, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT22,	  53, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT23,	  52, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT24,	  50, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT25,	  59, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT26,	  62, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT27,	  58, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT28,	  56, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT29,	  59, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT30,	  58, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT31,	  53, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT32,	  52, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT33,	  52, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT34,	  59, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT35,	  52, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT36,	  53, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT37,	  54, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT38,	  53, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT39,	  58, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT40,	  54, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT41,	  56, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT42,	  54, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT43,	  59, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT44,	  51, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT45,	  53, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT46,	  54, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT47,	  58, 		1,0,0,0,0,1 },
		{ ENTITY_MEMORY_DDR,		DEVICE_INSTANT48,	  52, 		1,0,0,0,0,1 },
		
		{ ENTITY_Ambient_Sensor,	DEVICE_INSTANT1,	  25, 		1,0,0,0,0,1  },
		{ ENTITY_Ambient_Sensor,	DEVICE_INSTANT2,	  24, 		1,0,0,0,0,1  },
		{ ENTITY_Ambient_Sensor,	DEVICE_INSTANT3,	  0, 		0,0,0,0,0,1  },
		{ ENTITY_Ambient_Sensor,	DEVICE_INSTANT4,	  0, 		0,0,0,0,0,1  },
		
		{ ENTITY_RAID,				DEVICE_INSTANT1,	  60, 		1,0,0,0,0,1  },
		{ ENTITY_RAID,				DEVICE_INSTANT2,	  68, 		1,0,0,0,0,1  },
		{ ENTITY_RAID,				DEVICE_INSTANT3,	  63, 		1,0,0,0,0,1  },
		{ ENTITY_RAID,				DEVICE_INSTANT4,	  0, 		0,0,0,0,0,1  },
		{ ENTITY_RAID,				DEVICE_INSTANT5,	  0, 		0,0,0,0,0,1  },
		{ ENTITY_RAID,				DEVICE_INSTANT6,	  0, 		0,0,0,0,0,1  },
		
		{ ENTITY_HDD,				DEVICE_INSTANT1,	  40, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT2,	  45, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT3,	  44, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT4,	  41, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT5,	  43, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT6,	  45, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT7,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT8,	  42, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT9,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT10,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT11,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT12,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT13,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT14,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT15,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT16,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT17,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT18,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT19,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT20,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT21,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT22,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT23,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT24,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT25,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT26,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT27,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT28,	  48, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT29,	  49, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT30,	  51, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT31,	  50, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT32,	  49, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT33,	  49, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT34,	  49, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT35,	  49, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT36,	  49, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT37,	  49, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT38,	  49, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT39,	  49, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT40,	  49, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT41,	  49, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT42,	  49, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT43,	  49, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT44,	  49, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT45,	  49, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT46,	  49, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT47,	  49, 		1,0,0,0,0,1  },
		{ ENTITY_HDD,				DEVICE_INSTANT48,	  49, 		1,0,0,0,0,1  },
	
		{ ENTITY_LAN,				DEVICE_INSTANT1,	  70, 		1,0,0,0,0,1  },
		{ ENTITY_PCH,				DEVICE_INSTANT1,	  68, 		1,0,0,0,0,1  },
		{ ENTITY_Mdot2,				DEVICE_INSTANT1,	  58, 		1,0,0,0,0,1  },
		{ ENTITY_GPU,			    DEVICE_INSTANT1,	  80, 		1,0,0,0,0,1  },
		{ ENTITY_CPU_VR,			DEVICE_INSTANT1,	  90, 		1,0,0,0,0,1  },


		
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
	
	PID[2].Margin=0;
	PID[2].kp=10.14;
	PID[2].ki=2;
	PID[2].kd=06;
	PID[2].T_control=8;
	PID[2].GB=1;
	
	PID[3].Margin=0;
	PID[3].kp=10.14;
	PID[3].ki=2;
	PID[3].kd=06;
	PID[3].T_control=8;
	PID[3].GB=1;
	

};


/*
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



*/

void INIT_THEMRAL_DATA_BASE()
{
	
	for(int i=0; i<MAPPING_RULE_NUM; i++)
	{
		if(device_map_system_fanzone[i].value==0)
		{
			device_map_system_fanzone[i].presence=0;
		};
		
		
		if(device_map_system_fanzone[i].value!=0)
		{
			device_map_system_fanzone[i].presence=1;
		};

	};



	
	
	
	
	
	
	
	
	
};
	
	
	
	
	


