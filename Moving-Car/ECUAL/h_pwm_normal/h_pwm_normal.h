#ifndef H_PWM_NORMAL_H_
#define H_PWM_NORMAL_H_

#include "../../MCAL/pwm_normal_mode/pwm_normal.h"



/*description : used to select the normal mode and enables the global interrupt and overflow interrupt for timer2*/
void H_PWM_NORMAL_init(void);

/*description : used to stop the timer counting once called this function.*/
void H_PWM_NORMAL_stop(void);


/*
description : used to set the duty cycle to then start the timer
arguments   : takes the duty cycle
*/
void H_PWM_NORMAL_setDutyCycle(u8 dutycycle);


#endif /* H_PWM_NORMAL_H_ */