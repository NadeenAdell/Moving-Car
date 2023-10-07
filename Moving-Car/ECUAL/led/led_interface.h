#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/*****************************************************************MACROS OF LEDS**************************************************/
#define LED_1   6     //Forward In Long Side 3s
#define LED_2   5    //Forward In Short Side 2s
#define LED_3   3    //stop
#define LED_4   2  //Rotate
#define LED_PORT_SIDE  PORTA
#define LED_PORT_ACTION PORTA


/*************************************************************************ProtoTypes***********************************************/
/*
description : initializes the LED.
arguments   : takes the LED number
*/
void HLED_ledInit(u8 Copy_u8ledNum);

/*
description : used to set the LED on 
arguments   : takes the LED number
*/
void HLED_ledOn (u8 Copy_u8ledNum);

/*
description : used to turn the LED off 
arguments   : takes the LED number
*/
void HLED_ledOff(u8 Copy_u8ledNum);




#endif /* LED_INTERFACE_H_ */