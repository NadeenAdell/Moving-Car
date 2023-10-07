#ifndef HAL_HPWM_HPWM_H_
#define HAL_HPWM_HPWM_H_



typedef enum
{
	PWM_OK,
	PWM_NOK,

}enu_pwmStatus_t;


//////////////////////////////////PROTOTYPES/////////////////////////

/*
Description : used to initialize the PWM ,set the prescaller and PWM mode
return      : return the PWM error state
*/
enu_pwmStatus_t pwm_enInit(void);

 /*
Description : used to generate PWM signal
arguments   : takes the duty cycle
return      : return the PWM error state
*/
enu_pwmStatus_t pwm_enGenerate(Uchar8_t copy_u8PWMDutyCycle);


#endif /* HAL_HPWM_HPWM_H_ */
