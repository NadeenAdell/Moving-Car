#include "h_ext_int.h"
EN_EXTINT_ERROR H_EXTINT_create(EN_EXINT_NUMBER INTx ,EN_Sense_Control INTxSense,void(*ptrfunc)(void))
{
	if(!EXTINT_init(INTx,INTxSense) && !EXTINT_CallBack(INTx,ptrfunc)) 
	{
		return EXTINT_OK;
	}
	return EXTINT_NOT_OK;
	
}