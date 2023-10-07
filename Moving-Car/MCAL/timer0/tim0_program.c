#include "../../Common/STD_Types.h"
#include "../../Common/BIT_Math.h"
#include "../extint/extinterrupt.h"


#include "tim0_private.h"
#include "tim0_register.h"
#include "tim0_interface.h"




void (*TIMER0_OVF_CallBack)(void)= NULL;
void (*TIMER0_CTC_CallBack)(void)= NULL;
void MTIMER0_voidInit(void)
{
    #if TIMER0_MODE == NORMAL_MODE
		// Set wave Generation Mode to Normal Mode
	    CLEAR_BIT(TCCR0,3);
		CLEAR_BIT(TCCR0,6);
		// Turn on Overflow Interrupt
		SET_BIT(SREG , 7);
		SET_BIT(TIMSK,0);
		CLEAR_BIT(TIMSK,1);
		// Start Timer by setting its clock
		TCCR0 &= 0b11111000;
		TCCR0 |= CLK_CONFIGURATION;
    #elif TIMER0_MODE == PHASE_CORRECT_MODE

	#elif TIMER0_MODE == CTC_MODE
		// Set wave Generation Mode to CTC Mode
		CLEAR_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
		// Turn on CTC Interrupt
		SET_BIT(TIMSK,1);
		CLEAR_BIT(TIMSK,0);
		// Set Compare Match Unit Value
		OCR0=OCR0_VALUE;
		// Start Timer by setting its clock and Set OC0 Pin Action
		TCCR0 &= 0b11001000;
		TCCR0 |= (CLK_CONFIGURATION|(CTC_OC0_PIN_ACTION<<4));
	#elif TIMER0_MODE == FAST_PWM_MODE
		// Set wave Generation Mode to Fast PWM Mode
		SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
		// Set Compare Match Unit Value
		OCR0=OCR0_VALUE;
		// Start Timer by setting its clock and Set OC0 Pin Action
		TCCR0 &= 0b11001000;
		TCCR0 |= (CLK_CONFIGURATION|(FAST_PWM_OC0_PIn_ACTION<<4));

    #else
		#error  Wrong TIMER0 Mode Configuration
    #endif

}

void MTIMER0_voidStopTimer (void)
{
	// Stop Clock of Timer 0
	TCCR0 &= 0b11111000;
}

void MTIMER0_voidsetCallBackOVF (void (*ptrToFunc) (void))
{
	if (ptrToFunc!=NULL)
	{
		TIMER0_OVF_CallBack=ptrToFunc;
	}
}

void MTIMER0_voidsetCallBackCTC (void (*ptrToFunc) (void))
{
	if (ptrToFunc!=NULL)
	{
		TIMER0_CTC_CallBack=ptrToFunc;
	}
}

void MTIMER0_voidSetPreloadValue (u8 A_u8PreloadValue)
{
	TCNT0=A_u8PreloadValue;
}


void MTIMER0_voidSetOCR0Value(u8 A_u8Value)
{
	OCR0=A_u8Value;
}


void __vector_11(void)  __attribute__((signal));
void __vector_11(void)
{
	if (TIMER0_OVF_CallBack!= NULL)
	{
		TIMER0_OVF_CallBack();
	}
}


void __vector_10(void)  __attribute__((signal));
void __vector_10(void)
{
	if (TIMER0_CTC_CallBack!= NULL)
	{
		TIMER0_CTC_CallBack();
	}
}

