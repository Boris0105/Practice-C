#ifndef __THERMAL_ALGORITHM_CPP
#define __THERMAL_ALGORITHM_CPP

#include <bmc_thermal_algorithm.h>
#include <bmc_fan_proxy_therm_dev.h>

void thermal_algorithm::input_raw_data(therm_device* tdev)
{
	uint32 fail_count = tdev->get_reading_fail_count();
	float raw_value = tdev->get_thermal_dev_value();
	//float processed_value = therm_devs[i]->process_raw_data(raw_value);
	float processed_value = raw_value;
	LOG::log(log_thermal, 0x20, "Therm Dev [%s][%d]- Processing... Value=%f, %ld\n", tdev->get_name().c_str(), tdev->get_inst(), processed_value, fail_count);
	
	
	
	
	//if(tdev->get_name().compare("m2_ambient_tdev") == 0)
		
	switch(tdev->get_name().c_str()){	
		
		
		case m2_ambient_tdev:
		float M_2 = processed_value;
		break;
		
		
		case ambient_sensor:
		float M_2 = processed_value;
		break;

	}	
		fan_proxy_therm_dev *fan_proxy = (fan_proxy_therm_dev*)tdev;
		fan_proxy->write_thermal_dev_value_to_fpga();
	
	
	
	
	
	
	
	
}



int M_2_powerband(int M2_temp, int system_amb)
{



	if (M2_temp >= M2_critical)
	{	
		return 100;
	}
	
	else if (M2_temp < 45)
	{
		if (system_amb<=55)
		{
			return 25;
		}
		else 
		{
			return 100;	
		}
		

	}
	
	else if (M2_temp  <= 65 )
	{
		if (system_amb <=40)
		{
			return 30;
		}
		else 
		{
			return 100;	
		}
	

	}
	
	else if (M2_temp > 65)
	{
		if (system_amb <= 25)
		{
			return 30;
		}
		else 
		{
			return 100;	
		} 
		
	}


};






/*
void thermal_algorithm::set_fan_pwm(uint inst, uint pwm)
{
}
*/


void thermal_algorithm::run()
{
	LOG::log(log_thermal, 0x20, "Thermal Algorithm running...\n");
}

#endif


