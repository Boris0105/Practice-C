/* Fan Instance */
enum fanInstant {
	FAN_INSTANT1 = 0,
	FAN_INSTANT2,
	FAN_INSTANT3,
	FAN_INSTANT4,
	FAN_NUM
};
enum deviceInstant {
	DEVICE_INSTANT1 = 0,
	DEVICE_INSTANT2,
	DEVICE_INSTANT3,
	DEVICE_INSTANT4,
	DEVICE_INSTANT5,
	DEVICE_INSTANT6,
	DEVICE_INSTANT7,
	DEVICE_INSTANT8,
	DEVICE_INSTANT9,
	DEVICE_INSTANT10,
	DEVICE_INSTANT11,
	DEVICE_INSTANT12,
	DEVICE_INSTANT13,
	DEVICE_INSTANT14,
	DEVICE_INSTANT15,
	DEVICE_INSTANT16,
	DEVICE_INSTANT17,
	DEVICE_NUM
};




struct Fan_healthy_information{

	int fan_tach_rpm
	func* event_trigger_alert


};



struct Algorithms_under_DEV{
	short THEMRMAL_ID;
	enum  deviceInstant device;
	float (Openloop*)(float amb_sensor);
	float (Threshold*)(float temp, float amb_sensor);
	float (PID*)(float kp,float ki,float kd,int T_control,int GB);

};


struct FAN_MAP_OUTPUT{

	struct Algorithms_under_DEV
	struct FAN_PWM

};


struct Overall_Fan_Status Overall_SYSTEM_FAN_STATUS[FAN_NUMBERING] {
	struct Fan_healthy_information
	struct FAN_MAP_OUTPUT

};


