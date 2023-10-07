#ifndef INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_


/*description: used to initialize timer*/
void MTIMER0_voidInit(void);

/*description: used to stop the timer*/
void MTIMER0_voidStopTimer (void);

/*description: used to set the call back function*/
void MTIMER0_voidsetCallBackOVF (void (*ptrToFunc) (void));

/*description: used to set the preload value*/
void MTIMER0_voidSetPreloadValue (u8 A_u8PreloadValue);

/*description: used to set the call back function in CTC mode*/
void MTIMER0_voidsetCallBackCTC (void (*ptrToFunc) (void));

/*description: used to set OCR0 reg value*/
void MTIMER0_voidSetOCR0Value(u8 A_u8Value);


#endif /* INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_ */
