#ifndef PWM_NORMAL_H_
#define PWM_NORMAL_H_

#include "../../Common/vect_table.h"
#include "../../Common/STD_Types.h"
#include "../../Common/BIT_Math.h"
#include "../../MCAL/dio/dio_interface.h"
#include "pwm_config.h"




/*description :used to select normal mode and enables the global interrupt and overflow interrupt for timer2*/
void timer2_init(void);

/*description : used to make the timer start counting */
void timer2_start(void);


/*description : used to stop the timer*/
void timer2_stop(void);


/*
description : used to calculate the duty cycle.
arguments   : takes the duty cycle
*/
void timer2_set_pwm_normal(u8 a_dutycycle);


#endif /*  PWM_NORMAL_H_ */