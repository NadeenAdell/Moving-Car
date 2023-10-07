/******************************************************INCLUDES********************************************/
#include "../../Common/STD_Types.h"
#include "../../Common/BIT_Math.h"
#include "../../MCAL/dio/dio_interface.h"
#include "led_config.h"
#include "led_interface.h"

/****************************************************Implement**********************************/

void HLED_ledInit(u8 Copy_u8ledNum)
{
	switch(Copy_u8ledNum)
	{
		case LED_1:   //Forward In Long Side 3s
		/*Make Direction Out*/
		MDIO_voidSetPinDirection(LED_PORT_SIDE , LED_1 , PIN_OUT_DIR);
		break;
		
		case LED_2:    //Forward In Short Side 2s
		/*Make Direction Out*/
		MDIO_voidSetPinDirection(LED_PORT_SIDE , LED_2 , PIN_OUT_DIR);
		break;
		
		case LED_3:   //stop
		/*Make Direction Out*/
		MDIO_voidSetPinDirection(LED_PORT_ACTION , LED_3 , PIN_OUT_DIR);
		break;
		
		case LED_4:   //Rotate
		/*Make Direction Out*/
		MDIO_voidSetPinDirection(LED_PORT_ACTION , LED_4 , PIN_OUT_DIR);
		break;
		
		default:
		break;
	}	
	
}

void HLED_ledOn (u8 Copy_u8ledNum)
{
	switch(Copy_u8ledNum)
	{
		case LED_1:   //Forward In Long Side 3s
		/*Make Value Is High*/
		MDIO_voidSetPinValue(LED_PORT_SIDE , LED_1 , PIN_HIGH_VALUE);		
		break;
		
		case LED_2:    //Forward In Short Side 2s
		/*Make Value Is High*/
		MDIO_voidSetPinValue(LED_PORT_SIDE , LED_2 , PIN_HIGH_VALUE);
		break;
		
		case LED_3:   //stop 
		/*Make Value Is High*/
		MDIO_voidSetPinValue(LED_PORT_ACTION , LED_3 , PIN_HIGH_VALUE);
		break;
		
		case LED_4:   //Rotate
		/*Make Value Is High*/
		MDIO_voidSetPinValue(LED_PORT_ACTION , LED_4 , PIN_HIGH_VALUE);
		break;
		
		default:
		break;
	}
}

void HLED_ledOff(u8 Copy_u8ledNum)
{
	switch(Copy_u8ledNum)
	{
		case LED_1:   //Forward In Long Side 3s
		/*Make Value Is Low*/
		MDIO_voidSetPinValue(LED_PORT_SIDE , LED_1 , PIN_LOW_VALUE);
		break;
		
		case LED_2:    //Forward In Short Side 2s
		/*Make Value Is Low*/
		MDIO_voidSetPinValue(LED_PORT_SIDE , LED_2 , PIN_LOW_VALUE);
		break;
		
		case LED_3:   //stop
		/*Make Value Is Low*/
		MDIO_voidSetPinValue(LED_PORT_ACTION , LED_3 , PIN_LOW_VALUE);
		break;
		
		case LED_4:   //Rotate
		/*Make Value Is Low*/
		MDIO_voidSetPinValue(LED_PORT_ACTION , LED_4 , PIN_LOW_VALUE);
		break;
		
		default:
		break;
	}	
}
