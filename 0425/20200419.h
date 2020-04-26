int power_band_table[6][8] ={{0,22,27,30,35,40,45,50},
                            {0.2,20,21,22,23,24,25,26},
		            {0.4,27,28,29,30,31,32,33},
		            {0.6,34,35,36,37,38,39,40},
		            {0.8,41,42,43,44,45,46,47},
		            {1,48,49,50,51,52,53,54}};



int CPU_TDP=250;
int Power=150;
int ambTemp =25; 




/* Fan Instance */
enum fanInstant {
	FAN_INSTANT1 = 0,
	FAN_INSTANT2,
	FAN_NUM
};
enum deviceInstant {
	DEVICE_INSTANT1 = 0,
	DEVICE_NUM
};

enum errorIteration {
	N = 0,
	N_MINUS_1
};

/* Entity */
#define ENTITY_PROCESSOR 3
#define ENTITY_FAN_COOLING 29
#define ENTITY_AMB 39

struct fanInfo {
	int entity;
	enum fanInstant instant;
	int value;
};
struct fanInfo fanMap[2] = {
	{ ENTITY_FAN_COOLING, FAN_INSTANT1, 60 },
	{ ENTITY_FAN_COOLING, FAN_INSTANT2, 60 }
};

struct deviceFanMapping {
	int entity;
	enum deviceInstant device;
	enum fanInstant fan;
};
struct deviceFanMapping mappingTable[3] = {
	{ ENTITY_PROCESSOR, DEVICE_INSTANT1, FAN_INSTANT1 },
	{ ENTITY_AMB, DEVICE_INSTANT1, FAN_INSTANT1 },
	{ ENTITY_AMB, DEVICE_INSTANT1, FAN_INSTANT2 }
};

//PWN(n) = AmbTemp + WN(n-1) + ERR(n) - ERR(n-1)
//ERR(n) = n + 1
int PWM[2];
int ERR[2][2];
