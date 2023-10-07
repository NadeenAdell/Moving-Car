#include "APP/app.h"
#include "MCAL/dio/dio_interface.h"

void Toggle_LedOVF(void);
int main(void)
{ 
    //MDIO_voidSetPinDirection(PORTB, PIN0, PIN_OUT_DIR);
	//MTIMER0_voidInit();
	
	initCar();
	
    /* Replace with your application code */
    while (1) 
    {
	//MTIMER0_voidsetCallBackOVF(Toggle_LedOVF);
		carApp();
    }
   
   
}
/*
void Toggle_LedOVF(void)
{
	static u16 local_u16Counter =0;
	static u8  local_u8Flag=0;
	local_u16Counter++;
	if (local_u16Counter==3907)
	{
		MTIMER0_voidSetPreloadValue(192);
		local_u16Counter=0;
		if (local_u8Flag==0)
		{
			local_u8Flag=1;
			MDIO_voidSetPinValue(PORTB, PIN0, PIN_HIGH_VALUE);
		}
		else
		{
			local_u8Flag=0;
			MDIO_voidSetPinValue(PORTB, PIN0, PIN_LOW_VALUE);
		}
	}
}



*/



