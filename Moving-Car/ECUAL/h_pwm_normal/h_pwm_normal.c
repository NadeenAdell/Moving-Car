#include "h_pwm_normal.h"



void H_PWM_NORMAL_init(void)
{
	timer2_init();                     //initialize the timer
}


void H_PWM_NORMAL_stop(void)
{
	timer2_stop();                      //stop thetimer
}


void H_PWM_NORMAL_setDutyCycle(u8 dutycycle)
{
	timer2_set_pwm_normal(dutycycle);       //set the duty cycle
	timer2_start();
}

