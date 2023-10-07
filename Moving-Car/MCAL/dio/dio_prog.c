/*****************************************************************Includes*******************************************************************/
#include "../../Common/STD_Types.h"
#include "../../Common/BIT_Math.h"


#include "dio_config.h"
#include "dio_private.h"
#include "dio_interface.h"


/****************************************************************Implement********************************************************************/

void MDIO_voidSetPinDirection (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Dir)
{
	switch (Copy_u8Port)
	{
		case PORTA:
		switch (Copy_u8Dir)
		{
			case PIN_IN_DIR :
			   CLEAR_BIT(MDIO_DDRA , Copy_u8Pin);
			   break;
			   
			case PIN_OUT_DIR:
			   SET_BIT(MDIO_DDRA , Copy_u8Pin); 
			    break;
				
			default : 
			break;
		}
		break;
		
		case PORTB:
		switch (Copy_u8Dir)
		{
			case PIN_IN_DIR : 
			 CLEAR_BIT(MDIO_DDRB , Copy_u8Pin);
			  break;
			  
			case PIN_OUT_DIR:
			  SET_BIT(MDIO_DDRB , Copy_u8Pin);   
			  break;
			  
			default : 
			break;
		}
		break;

		case PORTC:
		switch (Copy_u8Dir)
		{
			case PIN_IN_DIR :  CLEAR_BIT(MDIO_DDRC , Copy_u8Pin);
			 break;
			 
			case PIN_OUT_DIR: 
			 SET_BIT(MDIO_DDRC , Copy_u8Pin);  
			  break;
			  
			default :
			 break;
		}
		break;

		case PORTD:
		switch (Copy_u8Dir)
		{
			case PIN_IN_DIR :
			  CLEAR_BIT(MDIO_DDRD , Copy_u8Pin); 
			  break;
			  
			case PIN_OUT_DIR: 
			  SET_BIT(MDIO_DDRD , Copy_u8Pin);  
			  break;
			  
			default  
			   : break;
		}
		break;

		default:
		break;
	}
}

void MDIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value)
{
	switch (Copy_u8Port)
	{
		case PORTA:
		switch (Copy_u8Value)
		{
			case PIN_LOW_VALUE :
			  CLEAR_BIT(MDIO_PORTA , Copy_u8Pin); 
			  break;
			  
			case PIN_HIGH_VALUE:  
			  SET_BIT(MDIO_PORTA , Copy_u8Pin); 
			  break;
			  
			default :
			 break;
		}
		break;
		
		case PORTB:
		switch (Copy_u8Value)
		{
			case PIN_LOW_VALUE : 
			  CLEAR_BIT(MDIO_PORTB , Copy_u8Pin);
			  break;
			  
			case PIN_HIGH_VALUE:  
			  SET_BIT(MDIO_PORTB , Copy_u8Pin);  
			  break;
			  
			default :
			 break;
		}
		break;

		case PORTC:
		switch (Copy_u8Value)
		{
			case PIN_LOW_VALUE : 
			 CLEAR_BIT(MDIO_PORTC,Copy_u8Pin); 
			 break;
			 
			case PIN_HIGH_VALUE: 
			  SET_BIT(MDIO_PORTC,Copy_u8Pin); 
			   break;
			   
			default :
			 break;
		}
		break;

		case PORTD:
		switch (Copy_u8Value)
		{
			case PIN_LOW_VALUE :
			  CLEAR_BIT(MDIO_PORTD , Copy_u8Pin); 
			  break;
			  
			case PIN_HIGH_VALUE:  
			  SET_BIT(MDIO_PORTD , Copy_u8Pin); 
			  break;
			  
			default :
			 break;
		}
		break;

		default:
		break;
	}
}

u8   MDIO_u8GetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 Local_u8Data =0;
	switch (Copy_u8Port)
	{
		case PORTA:
		Local_u8Data = GET_BIT(MDIO_PINA , Copy_u8Pin);
		break;
		
		case PORTB:
		Local_u8Data = GET_BIT(MDIO_PINB , Copy_u8Pin);
		break;

		case PORTC:
		Local_u8Data = GET_BIT(MDIO_PINC , Copy_u8Pin);
		break;

		case PORTD:
		Local_u8Data = GET_BIT(MDIO_PIND , Copy_u8Pin);
		break;

		default:
		break;
	}
	return Local_u8Data;
}

void MDIO_voidTogglePinValue(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	switch (Copy_u8Port)
	{
		case PORTA:
		TOGGLE_BIT(MDIO_PORTA , Copy_u8Pin);
		break;

		case PORTB:
		TOGGLE_BIT(MDIO_PORTB , Copy_u8Pin);
		break;

		case PORTC:
		TOGGLE_BIT(MDIO_PORTC , Copy_u8Pin);
		break;

		case PORTD:
		TOGGLE_BIT(MDIO_PORTD , Copy_u8Pin);
		break;

		default:
		break;
	}
}


void MDIO_voidSetPortDirection (u8 Copy_u8Port , u8 Copy_u8Dir)
{
	switch (Copy_u8Port)
	{
		case PORTA:
		  MDIO_DDRA = Copy_u8Dir;
		   break;
		
		case PORTB:
		  MDIO_DDRB = Copy_u8Dir;
		   break;

		case PORTC:
		  MDIO_DDRC = Copy_u8Dir;
		   break;

		case PORTD:  
		MDIO_DDRD = Copy_u8Dir; 
		break;

		default:
		break;
	}
}

void MDIO_voidSetPortValue (u8 Copy_u8Port , u8 Copy_u8Value)
{
	switch (Copy_u8Port)
	{
		case PORTA: 
		  MDIO_PORTA = Copy_u8Value; 
		  break;

		case PORTB: 
		 MDIO_PORTB = Copy_u8Value;
		  break;

		case PORTC: 
		 MDIO_PORTC = Copy_u8Value; 
		 break;

		case PORTD: 
		 MDIO_PORTD = Copy_u8Value;
		  break;

		default:
		break;
	}
}


u8 MDIO_u8GetPortValue (u8 Copy_u8Port)
{
	u8 Local_u8Data =0;
	switch (Copy_u8Port)
	{
		case PORTA: 
		Local_u8Data = MDIO_PINA;
		 break;
		
		case PORTB:
		 Local_u8Data = MDIO_PINB; 
		 break;

		case PORTC: 
		 Local_u8Data = MDIO_PINC;
		 break;

		case PORTD: 
		  Local_u8Data = MDIO_PIND; 
		  break;
		  
		default:
		break;
	}
	return Local_u8Data;

}


void  MDIO_VoidSetPullupResistor  (u8 Copy_u8Port , u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
		case PORTA :
		SET_BIT(MDIO_PORTA , Copy_u8Pin);
		break;
		
		case PORTB :
		SET_BIT(MDIO_PORTB , Copy_u8Pin);
		break;
		
		case PORTC :
		SET_BIT(MDIO_PORTC , Copy_u8Pin);
		break;
		
		case PORTD :
		SET_BIT(MDIO_PORTD , Copy_u8Pin);
		break;
		
		default:
		break;
	}
}