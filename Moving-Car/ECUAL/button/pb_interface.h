#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_


/*******************************************************MACROS OF BUTTONS NUM*********************************/
#define BUTTON_START  PIN3
#define BUTTON_STOP   PIN2

/*******************************************************MACROS OF BUTTON PORT*********************************/
#define BUTTON_PORT  PORTD

/********************************************************Button Status****************************************/
#define  PRESSED             1
#define  NOT_PRESSED         0
#define DELAY_VALUE         20

/**********************************************************Includes*******************************************/
/*
description  : used to initialize the button
arguments    : copy of the button number
*/
void HPushButtonOn_init(u8 Copy_u8buttonNum);

/*
description  : used to get the button value
arguments    : copy of the button number
return       : the button value
*/
u8 HPushButton_getValue(u8 Copy_u8buttonNum);



#endif /* BUTTON_INTERFACE_H_ */