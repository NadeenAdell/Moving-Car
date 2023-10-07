#include "../../Common/STD_Types.h"
#include "../../Common/Bit_Math.h"
#include "pwm_private.h"
#include "pwm_interface.h"
#include "pwm_config.h"

 
#define PRESCALLER_CLR_MSK				(0b11111000)
#define PWM_MODE_CLR_MSK				(0b11001111)
#define TIMER2_PRESCALLER_OFFSET		0
#define TIMER2_PWM_MODE_OFFSET			4

#define PWM_MODE_CLR_COM1B_MSK					(0b11001111)
#define PWM_MODE_CLR_COM1A_MSK					(0b00111111)
#define TIMER1_PRESCALLER_OFFSET				0
#define TIMER1_PWM_MODE_COM1A_OFFSET			6
#define TIMER1_PWM_MODE_COM1B_OFFSET			4

enu_timer1Mode_t gen_PwmMode;




enu_timer1Status_t Timer1_enuInit (enu_timer1Mode_t copy_enTmerMode)
{
	enu_timer1Status_t errorStatus = TIMER1_OK;

	if(copy_enTmerMode < TIMER1_MODE_INVALID)
	{
		switch (copy_enTmerMode)
		{
			case TIMER1_NORMAL_0xFFFF				: CLEAR_BIT(TCCR1B_REG, WGM13); CLEAR_BIT(TCCR1B_REG, WGM12); CLEAR_BIT(TCCR1A_REG, WGM11); CLEAR_BIT(TCCR1A_REG, WGM10); break;
			case TIMER1_PWM_PHASE_CORRECT_8_0x00FF	: CLEAR_BIT(TCCR1B_REG, WGM13); CLEAR_BIT(TCCR1B_REG, WGM12); CLEAR_BIT(TCCR1A_REG, WGM11); SET_BIT(TCCR1A_REG, WGM10); break;
			case TIMER1_PWM_PHASE_CORRECT_9_0x01FF	: CLEAR_BIT(TCCR1B_REG, WGM13); CLEAR_BIT(TCCR1B_REG, WGM12); SET_BIT(TCCR1A_REG, WGM11); CLEAR_BIT(TCCR1A_REG, WGM10); break;
			case TIMER1_PWM_PHASE_CORRECT_10_0x03FF	: CLEAR_BIT(TCCR1B_REG, WGM13); CLEAR_BIT(TCCR1B_REG, WGM12); SET_BIT(TCCR1A_REG, WGM11); SET_BIT(TCCR1A_REG, WGM10); break;
			case TIMER1_CTC_OCR1A					: CLEAR_BIT(TCCR1B_REG, WGM13); SET_BIT(TCCR1B_REG, WGM12); CLEAR_BIT(TCCR1A_REG, WGM11); CLEAR_BIT(TCCR1A_REG, WGM10); break;
			case TIMER1_FAST_PWM_8_0x00FF			: CLEAR_BIT(TCCR1B_REG, WGM13); SET_BIT(TCCR1B_REG, WGM12); CLEAR_BIT(TCCR1A_REG, WGM11); SET_BIT(TCCR1A_REG, WGM10); gen_PwmMode =TIMER1_FAST_PWM_8_0x00FF;  break;
			case TIMER1_FAST_PWM_9_0x01FF			: CLEAR_BIT(TCCR1B_REG, WGM13); SET_BIT(TCCR1B_REG, WGM12); SET_BIT(TCCR1A_REG, WGM11); CLEAR_BIT(TCCR1A_REG, WGM10); gen_PwmMode =TIMER1_FAST_PWM_9_0x01FF;  break;
			case TIMER1_FAST_PWM_10_0x03FF			: CLEAR_BIT(TCCR1B_REG, WGM13); SET_BIT(TCCR1B_REG, WGM12); SET_BIT(TCCR1A_REG, WGM11); SET_BIT(TCCR1A_REG, WGM10); gen_PwmMode =TIMER1_FAST_PWM_10_0x03FF; break;
			case TIMER1_PWM_PHASE_FREQ_CORRECT_ICR1	: SET_BIT(TCCR1B_REG, WGM13); CLEAR_BIT(TCCR1B_REG, WGM12); CLEAR_BIT(TCCR1A_REG, WGM11); CLEAR_BIT(TCCR1A_REG, WGM10); break;
			case TIMER1_PWM_PHASE_FREQ_CORRECT_OCR1A: SET_BIT(TCCR1B_REG, WGM13); CLEAR_BIT(TCCR1B_REG, WGM12); CLEAR_BIT(TCCR1A_REG, WGM11); SET_BIT(TCCR1A_REG, WGM10); break;
			case TIMER1_PWM_PHASE_CORRECT_ICR1		: SET_BIT(TCCR1B_REG, WGM13); CLEAR_BIT(TCCR1B_REG, WGM12); SET_BIT(TCCR1A_REG, WGM11); CLEAR_BIT(TCCR1A_REG, WGM10); break;
			case TIMER1_PWM_PHASE_CORRECT_OCR1A		: SET_BIT(TCCR1B_REG, WGM13); CLEAR_BIT(TCCR1B_REG, WGM12); SET_BIT(TCCR1A_REG, WGM11); SET_BIT(TCCR1A_REG, WGM10); break;
			case TIMER1_CTC_ICR1					: SET_BIT(TCCR1B_REG, WGM13); SET_BIT(TCCR1B_REG, WGM12); CLEAR_BIT(TCCR1A_REG, WGM11); CLEAR_BIT(TCCR1A_REG, WGM10); break;
			case TIMER1_FAST_PWM_ICR1				: SET_BIT(TCCR1B_REG, WGM13); SET_BIT(TCCR1B_REG, WGM12); SET_BIT(TCCR1A_REG, WGM11); CLEAR_BIT(TCCR1A_REG, WGM10); gen_PwmMode =TIMER1_FAST_PWM_ICR1;  break;
			case TIMER1_FAST_PWM_OCR1A				: SET_BIT(TCCR1B_REG, WGM13); SET_BIT(TCCR1B_REG, WGM12); SET_BIT(TCCR1A_REG, WGM11); SET_BIT(TCCR1A_REG, WGM10); break;
			default: break;
		}

		TCNT1_REG = (Uint16_t)0;
	}else
	{
		errorStatus = TIMER1_NOK;
	}

	return errorStatus;
}


enu_timer1Status_t Timer1_enuSetPrescallar(enu_timer1Prescalar_t copy_enTimerPrescaller)
{
	enu_timer1Status_t errorStatus = TIMER1_OK;
	Uchar8_t temp_reg;
	if(copy_enTimerPrescaller < TIMER1_PRESCALR_INVALID)
	{
		temp_reg = TCCR1B_REG;
		temp_reg &= PRESCALLER_CLR_MSK;
		temp_reg |= copy_enTimerPrescaller << TIMER1_PRESCALLER_OFFSET;
		TCCR1B_REG = temp_reg;
	}
	else
	{
		errorStatus = TIMER1_NOK;
	}
	return errorStatus;
}


enu_timer1Status_t Timer1_enuFastPWMInit(enu_pwm1Mode_t copy_enPWMMode)
{
	enu_timer1Status_t errorStatus = TIMER1_OK;
	Uchar8_t local_u8Temp;

	if(copy_enPWMMode < TIMER1_PWM_INVALID)
	{
#if TIMER1_COM1_TYPE == TIMER1_COM1A

		local_u8Temp = TCCR1A_REG;
		local_u8Temp &= PWM_MODE_CLR_COM1A_MSK;
		local_u8Temp |= (copy_enPWMMode << TIMER1_PWM_MODE_COM1A_OFFSET);
		TCCR1A_REG = local_u8Temp;

#elif TIMER1_COM1_TYPE == TIMER1_COM1B

		local_u8Temp = TCCR1A_REG;
		local_u8Temp &= PWM_MODE_CLR_COM1B_MSK;
		local_u8Temp |= (copy_enPWMMode << TIMER1_PWM_MODE_COM1B_OFFSET);
		TCCR1A_REG = local_u8Temp;

#endif
	}else
	{
		errorStatus = TIMER1_NOK;
	}
	return errorStatus;

}


enu_timer1Status_t Timer1_enuPWMGenerate(Uchar8_t copy_u8DutyCycle)
{
	enu_timer1Status_t errorStatus = TIMER1_OK;

	if( copy_u8DutyCycle > 0 && copy_u8DutyCycle <= 100)
	{
#if TIMER1_COM1_TYPE == TIMER1_COM1A

		if(gen_PwmMode == TIMER1_FAST_PWM_8_0x00FF)
		{
			OCR1A_REG = ((copy_u8DutyCycle * 256)/100)-1 ;
		}
		else if(gen_PwmMode == TIMER1_FAST_PWM_9_0x01FF)
		{
			OCR1A_REG = ((copy_u8DutyCycle * 512)/100)-1 ;
		}
		else if(gen_PwmMode == TIMER1_FAST_PWM_10_0x03FF)
		{
			OCR1A_REG = ((copy_u8DutyCycle * 1024)/100)-1 ;
		}
		else if (gen_PwmMode == TIMER1_FAST_PWM_ICR1)
		{
			OCR1A_REG = copy_u8DutyCycle;
		}
		else
		{
			/*
				 * do nothing
			 */
		}


#elif TIMER1_COM1_TYPE == TIMER1_COM1B

		if(gen_PwmMode == TIMER1_FAST_PWM_8_0x00FF)
		{
			OCR1B_REG = ((copy_u8DutyCycle * 256)/100)-1 ;
		}
		else if(gen_PwmMode == TIMER1_FAST_PWM_9_0x01FF)
		{
			OCR1B_REG = ((copy_u8DutyCycle * 512)/100)-1 ;
		}
		else if(gen_PwmMode == TIMER1_FAST_PWM_10_0x03FF)
		{
			OCR1B_REG = ((copy_u8DutyCycle * 1024)/100)-1 ;
		}
		else if (gen_PwmMode == TIMER1_FAST_PWM_ICR1)
		{
			OCR1B_REG = copy_u8DutyCycle;
		}
		else
		{
			/*
				 * do nothing
			 */
		}

#endif
	}else
	{
		errorStatus = TIMER1_NOK;
	}



	return errorStatus;
}


enu_timer2Status_t Timer2_enuInit (enu_timer2Mode_t copy_enTmerMode)
{
	enu_timer2Status_t errorStatus = TIMER2_OK;

	if(copy_enTmerMode < TIMER2_TIMER_MODE_INVALID)
	{
		switch (copy_enTmerMode)
		{
		case TIMER2_OVF_MODE 				: CLEAR_BIT(TCCR2_REG, WGM21);CLEAR_BIT(TCCR2_REG, WGM20); break;
		case TIMER2_PHASE_CORRECT_PWM_MODE 	: CLEAR_BIT(TCCR2_REG, WGM21);SET_BIT(TCCR2_REG, WGM20); break;
		case TIMER2_CTC_MODE 				: SET_BIT(TCCR2_REG, WGM21);CLEAR_BIT(TCCR2_REG, WGM20); break;
		case TIMER2_FAST_PWM_MODE 			: SET_BIT(TCCR2_REG, WGM21);SET_BIT(TCCR2_REG, WGM20); break;
		default 					: errorStatus = TIMER2_NOK; break;
		}
		TCNT2_REG = (Uchar8_t)0;
	}else
	{
		errorStatus = TIMER2_NOK;
	}


	return errorStatus;
}

 
 
enu_timer2Status_t Timer2_enuSetPrescallar(enu_timerPrescalar_t copy_enTimerPrescaller)
{
	enu_timer2Status_t errorStatus = TIMER2_OK;
	Uchar8_t temp_reg;
	if(copy_enTimerPrescaller < TIMER2_PRESCALR_INVALID)
	{
		temp_reg = TCCR2_REG;
		temp_reg &= PRESCALLER_CLR_MSK;
		temp_reg |= copy_enTimerPrescaller << TIMER2_PRESCALLER_OFFSET;
		TCCR2_REG = temp_reg;
	}
	else
	{
		errorStatus = TIMER2_NOK;
	}


	return errorStatus;
}



enu_timer2Status_t Timer2_enuFastPWMInit(enu_pwmMode_t copy_enPWMMode)
{
	enu_timer2Status_t errorStatus = TIMER2_OK;
	Uchar8_t local_u8Temp;

	if(copy_enPWMMode < TIMER2_PWM_INVALID)
	{
		local_u8Temp = TCCR2_REG;
		local_u8Temp &= PWM_MODE_CLR_MSK;
		local_u8Temp |= (copy_enPWMMode << TIMER2_PWM_MODE_OFFSET);
		TCCR2_REG = local_u8Temp;
	}else
	{
		errorStatus = TIMER2_NOK;
	}
	return errorStatus;
}



enu_timer2Status_t Timer2_enuPWMGenerate(Uchar8_t copy_u8DutyCycle)
{
	enu_timer2Status_t errorStatus = TIMER2_OK;

	if( copy_u8DutyCycle > 0 && copy_u8DutyCycle <= 100)
	{
		OCR2_REG = ((copy_u8DutyCycle * 256)/100)-1 ;
	}else
	{
		errorStatus = TIMER2_NOK;
	}

	return errorStatus;
}

