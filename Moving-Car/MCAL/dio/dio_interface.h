#include "../../Common/STD_Types.h"
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/***********************************************MACROS FOR PORTS**************************************************/
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

/***********************************************MACROS FOR PINS**************************************************/
#define PIN0  0
#define PIN1  1
#define PIN2  2
#define PIN3  3
#define PIN4  4
#define PIN5  5
#define PIN6  6
#define PIN7  7

/**********************************************MACROS DIRECTION FOR PINS*******************************************/
#define PIN_OUT_DIR   1
#define PIN_IN_DIR    0

/**********************************************MACROS VALUE FOR PINS**********************************************/
#define PIN_HIGH_VALUE 1
#define PIN_LOW_VALUE  0

/**********************************************MACROS DIRECTION FOR PORT*****************************************/
#define PORT_OUT_DIR 0xff
#define PORT_IN_DIR  0x00


/**********************************************MACROS VALUE FOR PORT*********************************************/
#define PORT_HIGH_VALUE 0xff
#define PORT_LOW_VALUE  0x00

/*********************************************ProtoType********************************************************/
/*description: used to set pin direction output or input*/
void MDIO_voidSetPinDirection   (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Dir);

/*description: used to set pin value high or low*/
void MDIO_voidSetPinValue       (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);

/*description: used to toggle pin value*/
void MDIO_voidTogglePinValue    (u8 Copy_u8Port , u8 Copy_u8Pin);

/*description: used to read pin value*/
u8   MDIO_u8GetPinValue         (u8 Copy_u8Port , u8 Copy_u8Pin);

/*description: used to set port direction*/
void MDIO_voidSetPortDirection  (u8 Copy_u8Port , u8 Copy_u8Dir);

void MDIO_voidSetPortDirection  (u8 Copy_u8Port  ,u8 Copy_u8Dir);

/*description: used to set port value*/
void MDIO_voidSetPortValue      (u8 Copy_u8Port , u8 Copy_u8Value);

/*description: used to read port value*/
u8   MDIO_u8GetPortValue        (u8 Copy_u8Port);

/*description: used to enable pull up resistor*/
void  MDIO_VoidSetPullupResistor  (u8 Copy_u8Port , u8 Copy_u8Pin);


#endif /* DIO_INTERFACE_H_ */