#include "predefine.h"


int fanzone_map_fan[FAN_NUMBER] =
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int loadFanzoneConfig0()
{
	printf("loadFanzoneConfig0\n");
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
	};
	
	
	memcpy((void *)&(currentConfig->fanzones),
           (void *)&tempFanzones,
           sizeof(struct fanzone));
	
	
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
		
	printf("complete to load Power cap config%ds\n", 123);

    return 1;

}





int checkAndReturnFanzoneConfig0()
{
    struct entity_combination tempEntity = {
    { 0, 4  },
	{ 2, 48 },
	{ 4, 48 },
	{ 8, 24 },
	{ 25, 6 },
    };


    if (memcmp((void *)&(currentConfig->entity),(void *)&tempEntity,sizeof(struct entity_combination))!= 0)
        return 0;

    loadFanzoneConfig0();
    loadPowercapConfig0();
    printf("Check out here%d", 2);

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
		//printf("complete to get_system_fanzones");
		return;
		
	}
}

void get_system_entity()
{
	// [WIP] entity shall be retrieved at system startup,
	// use a temporary entity here. This shall be removed later.
    	struct entity_combination temp4Config0 = {
		{ ENTITY_PROCESSOR, 4   },
		{ ENTITY_MEMORY_DDR, 48  },
		{ ENTITY_DRIVE_SAS_SATA, 48  },
		{ ENTITY_FAN_TYPE_PERFORMANCE, 24  },
		{ ENTITY_RAID, 6  },
		};
    
    	struct entity_combination temp4Config1 = {
		{ ENTITY_PROCESSOR, 3 },
		{ ENTITY_MEMORY_DDR, 48 },
		{ ENTITY_DRIVE_SAS_SATA, 48 },
		{ ENTITY_FAN_TYPE_PERFORMANCE, 24  },
		{ ENTITY_RAID, 4},
		};
    
    	struct entity_combination temp4Default = {
		{ ENTITY_PROCESSOR, 4 },
		{ ENTITY_MEMORY_DDR, 40 },
		{ ENTITY_DRIVE_SAS_SATA, 28 },
		{ ENTITY_FAN_TYPE_PERFORMANCE, 24 },
		{ ENTITY_RAID, 3},
		};

	memcpy(&(currentConfig->entity), &temp4Config0, sizeof(struct entity_combination));
};




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

	


