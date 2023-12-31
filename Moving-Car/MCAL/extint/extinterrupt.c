#include "extinterrupt.h"


void (*ptrINT0)(void) = NULL_PTR;
void (*ptrINT1)(void) = NULL_PTR;
void (*ptrINT2)(void) = NULL_PTR;

EN_EXTINT_ERROR SET_GLOBAL_INTERRUPT(EN_GLOBAL_INT state)
{
	
	if(state == ENABLE)
	{
		sei();
	}
    else if (state == DISABLE)
	{
		cli();
	}
	else 
	{
		return EXTINT_NOT_OK;
	}
	return EXTINT_OK;
}

EN_EXTINT_ERROR EXTINT_init(EN_EXINT_NUMBER INTx ,EN_Sense_Control INTxSense)
{
	
	SET_GLOBAL_INTERRUPT(ENABLE); // SET GLOBAL INTERRUPT
	switch(INTx)
	{
		case EXTINT0:
		  if(INTxSense == LOW_LEVEL)
		  {
			  CLEAR_BIT(MCUCR,ISC00);
			  CLEAR_BIT(MCUCR,ISC01);
		  }
		  else if(INTxSense == FALLING_EDGE)
		  {
			  CLEAR_BIT(MCUCR,ISC00);
			  SET_BIT(MCUCR,ISC01);
		  }
		  else if(INTxSense == RISING_EDGE)
		  {
			  SET_BIT(MCUCR,ISC00);
			  SET_BIT(MCUCR,ISC01);
		  }
		  else if(INTxSense == ANY_LOGICAL_CHANGE)
		  {
			  SET_BIT(MCUCR,ISC00);
			  CLEAR_BIT(MCUCR,ISC01);
		  }
		  else   // handle sense option error
		  {
			  SET_GLOBAL_INTERRUPT(DISABLE);
			   return EXTINT_NOT_OK;
		  }	   
		  SET_BIT(GICR,INT0); //Enable External INT0  (PIE)
		  break;
		  
		case EXTINT1:
		  if(INTxSense == LOW_LEVEL)
		  {
			  CLEAR_BIT(MCUCR,ISC10);
			  CLEAR_BIT(MCUCR,ISC11);
		  }
		  else if(INTxSense == FALLING_EDGE)
		  {
			  CLEAR_BIT(MCUCR,ISC10);
			  SET_BIT(MCUCR,ISC11);
		  }
		  else if(INTxSense == RISING_EDGE)
		  {
			  SET_BIT(MCUCR,ISC10);
			  SET_BIT(MCUCR,ISC11);
		  }
		  else if(INTxSense == ANY_LOGICAL_CHANGE)
		  {
			  SET_BIT(MCUCR,ISC10);
			  CLEAR_BIT(MCUCR,ISC11);
		  }
		  else   // handle sense option error
		  {
		 	 SET_GLOBAL_INTERRUPT(DISABLE);
		 	 return EXTINT_NOT_OK;
		  }
		  SET_BIT(GICR,INT1); //Enable External INT1  (PIE)
		  break;
		  
		case EXTINT2:
		  if(INTxSense == FALLING_EDGE)
		  {
			  CLEAR_BIT(MCUCSR,ISC2);
		  }
		  else if(INTxSense == RISING_EDGE)
		  {
			  SET_BIT(MCUCSR,ISC2);
		  }
		  else   // handle sense option error
		  {
		 	 SET_GLOBAL_INTERRUPT(DISABLE);
		 	 return EXTINT_NOT_OK;
		  }
		  SET_BIT(GICR,INT2); //Enable External INT1  (PIE)
		  break;
		  
		default: // handle wrong Choose for EXT Interrupt Number
		  SET_GLOBAL_INTERRUPT(DISABLE);
		  return EXTINT_NOT_OK;
		  break;
	}
	return EXTINT_OK;
}

EN_EXTINT_ERROR EXTINT_CallBack(EN_EXINT_NUMBER INTx,void(*ptrfunc)(void))
{
	if(INTx == EXTINT0 )
	{ 
		ptrINT0 = ptrfunc;
	}
	else if(INTx == EXTINT1 )
	{
		 ptrINT1 = ptrfunc;
	}
	else if(INTx == EXTINT2 ) 
	{
		ptrINT2 = ptrfunc;
	}
	else
	{
		 return EXTINT_NOT_OK;
	}
	return EXTINT_OK;
}


void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	
	if(ptrINT0)
	{ 
		ptrINT0();
		
	}
}


ISR(EXT_INT_1)
{
	if(ptrINT1)
	{
		ptrINT1();
	}

	
}
/*
void __vector_2(void)  __attribute__((signal));
void __vector_2(void)
{
	if(ptrINT1)
	{ 
		ptrINT1();
	}
	
}
*/

void __vector_3(void)  __attribute__((signal));
void __vector_3(void)
{
	if (ptrINT2 != NULL_PTR)
	{
		ptrINT2();
	}
}