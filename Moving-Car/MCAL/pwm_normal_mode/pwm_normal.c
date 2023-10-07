#include "pwm_normal.h"

u32 FLAG_OVF = ON_TIME;
u8 comp_VAL  = ON_TIME;


void timer2_init(void)
{
	TCCR2 = NORMAL_MODE;       //setnormal mode
	
	
	sei();                     //enable global interrupt
	SET_BIT(TIMSK,TOIE2);          // overflow interrupt for timer 2
	
}
void timer2_start(void)
{
  SET_BIT(TCCR2,CS20);
  SET_BIT(TCCR2,CS21);
  SET_BIT(TCCR2,CS22);
}
void timer2_stop(void)
{
	// stop the timer
	//TCCR2 = NORMAL_MODE;
	 CLEAR_BIT(TCCR2,CS20);
	 CLEAR_BIT(TCCR2,CS21);
	 CLEAR_BIT(TCCR2,CS22);
	
}

void timer2_set_pwm_normal(u8 a_dutycycle)
{
	MDIO_voidSetPinDirection(PORTA , PIN4 , PIN_OUT_DIR);  
	MDIO_voidSetPinDirection(PORTC , PIN4 , PIN_OUT_DIR); 
	comp_VAL = ((a_dutycycle*REG_SIZE)/PERCENT)-ONE_BIT;
	TCNT2 = REG_SIZE - comp_VAL;
}

void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{

	if(FLAG_OVF==ON_TIME)
	{
		// switch level of cycle to LOW
		MDIO_voidSetPinValue(PORTA ,PIN4 , PIN_LOW_VALUE);
		MDIO_voidSetPinValue(PORTC ,PIN4 , PIN_LOW_VALUE);
		FLAG_OVF=OFF_TIME;
		TCNT2 =comp_VAL;
	}
	else if(FLAG_OVF == OFF_TIME)
	{
		// switch level of cycle to HIGH
		MDIO_voidSetPinValue(PORTA ,PIN4 , PIN_HIGH_VALUE);
		MDIO_voidSetPinValue(PORTC ,PIN4 , PIN_HIGH_VALUE);
		FLAG_OVF=ON_TIME;
		TCNT2 =REG_SIZE - comp_VAL;
	}
		
}


