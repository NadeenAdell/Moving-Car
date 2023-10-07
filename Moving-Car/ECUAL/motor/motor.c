#include "../../Common/STD_Types.h"
#include "../../Common/BIT_Math.h"
#include "../../MCAL/dio/dio_interface.h"
#include "motor.h"


/******************************************************************Implementation*****************************************/
void HDCMotor_init(void)
{
	/*Make Direction With Output Direction*/
	MDIO_voidSetPinDirection(DC_MOTOR_PORT_1_2 , MOTOR_1_FRONT , PIN_OUT_DIR);
	MDIO_voidSetPinDirection(DC_MOTOR_PORT_1_2 , MOTOR_1_BACK , PIN_OUT_DIR);
	
	
	MDIO_voidSetPinDirection(DC_MOTOR_PORT_3_4 , MOTOR_3_FRONT , PIN_OUT_DIR);
	MDIO_voidSetPinDirection(DC_MOTOR_PORT_3_4 , MOTOR_3_BACK , PIN_OUT_DIR);
	
	
}


void HDCMOTOR_startForward(void)
{
	
	MDIO_voidSetPinValue(DC_MOTOR_PORT_1_2 , MOTOR_1_FRONT , PIN_LOW_VALUE);
	MDIO_voidSetPinValue(DC_MOTOR_PORT_1_2 , MOTOR_1_BACK , PIN_HIGH_VALUE);
	
	MDIO_voidSetPinValue(DC_MOTOR_PORT_3_4 , MOTOR_3_FRONT , PIN_LOW_VALUE);
	MDIO_voidSetPinValue(DC_MOTOR_PORT_3_4 , MOTOR_3_BACK , PIN_HIGH_VALUE);
}

void HDCMOTOR_stop(void)
{
	MDIO_voidSetPinValue(DC_MOTOR_PORT_1_2 , MOTOR_1_FRONT , PIN_LOW_VALUE);
	MDIO_voidSetPinValue(DC_MOTOR_PORT_1_2 , MOTOR_1_BACK , PIN_LOW_VALUE);
	MDIO_voidSetPinValue(DC_MOTOR_PORT_3_4 , MOTOR_3_FRONT , PIN_LOW_VALUE);
	MDIO_voidSetPinValue(DC_MOTOR_PORT_3_4 , MOTOR_3_BACK , PIN_LOW_VALUE);
	
	
}

void HDCMOTOR_Rotate(void)
{
	MDIO_voidSetPinValue(DC_MOTOR_PORT_1_2 , MOTOR_1_FRONT , PIN_HIGH_VALUE);
	MDIO_voidSetPinValue(DC_MOTOR_PORT_1_2 , MOTOR_1_BACK , PIN_LOW_VALUE);
	
	MDIO_voidSetPinValue(DC_MOTOR_PORT_3_4 , MOTOR_3_FRONT , PIN_LOW_VALUE);
	MDIO_voidSetPinValue(DC_MOTOR_PORT_3_4 , MOTOR_3_BACK , PIN_LOW_VALUE);
	
}