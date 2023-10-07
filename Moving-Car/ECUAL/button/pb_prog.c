#include "../../Common/STD_Types.h"
#include "../../Common/BIT_Math.h"
#include "../../MCAL/dio/dio_interface.h"
#include "pb_config.h"
#include "pb_interface.h"

#define F_CPU 80000000
#include <util/delay.h>

/**********************************************************Implementation*******************************************/
void HPushButtonOn_init(u8 Copy_u8buttonNum)
{
	switch(Copy_u8buttonNum)
	{
		case BUTTON_START:
		MDIO_voidSetPinDirection(BUTTON_PORT , BUTTON_START , PIN_IN_DIR);
		MDIO_VoidSetPullupResistor(BUTTON_PORT,Copy_u8buttonNum);
		break;
		
		case BUTTON_STOP:
		MDIO_voidSetPinDirection(BUTTON_PORT , BUTTON_STOP , PIN_IN_DIR);
		MDIO_VoidSetPullupResistor(BUTTON_PORT ,Copy_u8buttonNum);
		break;
		
		default:
		break;
	}
}


u8 HPushButton_getValue(u8 Copy_u8buttonNum)
{
	u8 Local_u8value = 0;
	switch(Copy_u8buttonNum)
	{
		case 1:
		Local_u8value = MDIO_u8GetPinValue(BUTTON_PORT , BUTTON_START);
		while(MDIO_u8GetPinValue(BUTTON_PORT , BUTTON_START)!=NOT_PRESSED);
		_delay_ms(DELAY_VALUE);  //debouncing 
		break;
		
		case 2:
		Local_u8value = MDIO_u8GetPinValue(BUTTON_PORT , BUTTON_STOP);
		while(MDIO_u8GetPinValue(BUTTON_PORT , BUTTON_STOP)!=NOT_PRESSED);
		_delay_ms(DELAY_VALUE);
		break;
		
		default:
		break;
	}
	return Local_u8value;
}



