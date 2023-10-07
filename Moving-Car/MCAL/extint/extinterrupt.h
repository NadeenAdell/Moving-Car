#ifndef EXT_INTERRUPT_H_
#define EXT_INTERRUPT_H_

#include "../../Common/vect_table.h"
#include "../../Common/BIT_Math.h"
#include "../../Common/STD_Types.h"
#include "ext_config.h"



// EXT_INT TYPEDEFS
typedef enum EN_EXTINT_ERROR {
	EXTINT_OK=0,
	EXTINT_NOT_OK
}EN_EXTINT_ERROR;

typedef enum EN_Sense_Control {
	LOW_LEVEL=0,
	FALLING_EDGE,
	RISING_EDGE,
	ANY_LOGICAL_CHANGE
}EN_Sense_Control;

typedef enum EN_EXINT_NUMBER{
	EXTINT0=0,
	EXTINT1,
	EXTINT2
}EN_EXINT_NUMBER;

typedef enum EN_GLOBAL_INT{
	DISABLE=0,
	ENABLE
}EN_GLOBAL_INT;

///////////////////////////////////////////PROYOTYPES/////////////////////////////

/*
description : used to initialize the global interrupt
arguments   : takes the state -enable or disable-
return      : return the error state, if ok returns EXTINT_OK ,else returns EXTINT_OK 
*/
EN_EXTINT_ERROR SET_GLOBAL_INTERRUPT(EN_GLOBAL_INT state);


/*
description : used to initializes the external interrupt number and it's detecting type
arguments   : takes the external interrupt number (INT0,INT1 OR INT2) and sense control.
return      : return the error state, if ok returns EXTINT_OK ,else returns EXTINT_OK 
*/
EN_EXTINT_ERROR EXTINT_init(EN_EXINT_NUMBER INTx ,EN_Sense_Control INTxSense);

/*
description : used to initialize call back function.
arguments   : takes the external interrupt number (INT0,INT1 OR INT2) and pointer to the wanted function for callback.
return      : return the error state, if ok returns EXTINT_OK ,else returns EXTINT_OK 
*/
EN_EXTINT_ERROR EXTINT_CallBack(EN_EXINT_NUMBER INTx,void(*ptrfunc)(void));

#endif /* EXT_INTERRUPT_H_ */