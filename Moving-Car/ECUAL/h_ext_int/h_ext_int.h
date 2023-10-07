#ifndef H_EXT_INT_H_
#define H_EXT_INT_H_

#include "../../MCAL/extint/extinterrupt.h"

/*
description : initializes external interrupt number,detecting type and initialize call back function.
arguments   : takes the external interrupt number( INT0,INT1 OR INT2) and sense control and pointer to the wanted function in the interrupt.
return      : return interrupt error state
*/
EN_EXTINT_ERROR H_EXTINT_create(EN_EXINT_NUMBER INTx ,EN_Sense_Control INTxSense,void(*ptrfunc)(void));



#endif /* H_EXT_INT_H_ */