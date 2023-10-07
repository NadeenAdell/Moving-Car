
#include "app.h"




typedef enum
{
	car_initState,
	car_startState,
	car_longSideState,
	car_rotateState,
	car_shortSideState
}en_carStates;

u8 u8_g_state;

static u8 u8_gs_nextSide = car_longSideState;

///////////////////////////////////////// Function Implementation /////////////////////////////

void initCar(void)
{

	/* Initialize LEDs */
	HLED_ledInit(LED_1);     //Long
	HLED_ledInit(LED_2);     //Short
	HLED_ledInit(LED_4);     //Rotate
	HLED_ledInit(LED_3);     //Stop
	
	/* Initialize Buttons */
	HPushButtonOn_init(BUTTON_START);
	HPushButtonOn_init(BUTTON_STOP);
	
	/* Initialize Motors */
	HDCMotor_init();
	
	/* Initialize PWM Timer */
	MTIMER0_voidInit();
	H_PWM_NORMAL_init();

	
	/* Initialize External Interrupts */
	H_EXTINT_create(EXTINT0, FALLING_EDGE , button0Callback);
	H_EXTINT_create(EXTINT1, FALLING_EDGE, button1Callback);
	
}

void button0Callback(void)
{
	//TIM0_AsyncEndDelay();
	u8_g_state = car_initState;
}

void button1Callback(void)
{
	/* Set the app state to car_startState */
	if(u8_g_state == car_initState)
	{
		u8_g_state = car_startState;
	}
}

/*
void start_state(void)
{
	static u16 local_u16Counter_1 =0;
	local_u16Counter_1++;
	if (local_u16Counter_1==1954)
	{
		MTIMER0_voidSetPreloadValue(224);
		local_u16Counter_1=0;
		HDCMOTOR_startForward();
		HLED_ledOff(LED_3);
		HLED_ledOn(LED_1);
	}
	else if(local_u16Counter_1 == 11719)
	{
		MTIMER0_voidSetPreloadValue(64);
		local_u16Counter_1=0;
		HDCMOTOR_stop();
		
		HLED_ledOff(LED_1);  // Turn off LED1
		u8_g_state = car_longSideState;
	}
}


*/

/*
void long_side(void)
{
	static u16 local_u16Counter_2 =0;
	local_u16Counter_2++;
	if (local_u16Counter_2==11719)
	{
		MTIMER0_voidSetPreloadValue(64);
		local_u16Counter_2=0;
		H_PWM_NORMAL_setDutyCycle(50);
		HDCMOTOR_startForward();
		HLED_ledOn(LED_1);
		
	}
}
*/

void start_state(void)
{
	static u16 start_timer = 0;  // Timer to count the elapsed time
	
	// Increment the timer with each call to this function
	start_timer++;

	if (start_timer == 3907)
	 {
		 MTIMER0_voidSetPreloadValue(192);
		// After 1 second (1000 milliseconds), start moving forward
		HDCMOTOR_startForward();
		HLED_ledOn(LED_1);  // Turn on LED1 to indicate forward movement
		} 
		else if (start_timer == 3000) 
		{
		// After 3 seconds (3000 milliseconds), stop and transition to the next state
		HDCMOTOR_stop();
		HLED_ledOff(LED_1);  // Turn off LED1
		u8_g_state = car_longSideState;  // Transition to the next state
	}
}


void long_side(void)
{
	static u16 long_side_timer = 0;  // Timer to count the elapsed time
	
	// Increment the timer with each call to this function
	long_side_timer++;

	if (long_side_timer == 11719) 
	{
		MTIMER0_voidSetPreloadValue(64);
		// After 1.5 seconds (1500 milliseconds), set the car's speed to 50% of its maximum speed
		H_PWM_NORMAL_setDutyCycle(50);

		// Start moving forward
		HDCMOTOR_startForward();
		HLED_ledOn(LED_1);  // Turn on LED1 to indicate forward movement
		} 
		else if (long_side_timer == 4500)
		 {
		// After 4.5 seconds (4500 milliseconds), stop the car for 0.5 seconds
		HDCMOTOR_stop();
		HLED_ledOff(LED_1);  // Turn off LED1
		}
		 else if (long_side_timer == 5000) 
		 {
		// After 5 seconds (5000 milliseconds), rotate 90 degrees to the right
		HDCMOTOR_Rotate();
		HLED_ledOff(LED_1);  // Turn off LED1
		HLED_ledOn(LED_4);  // Turn on LED4 to indicate rotation
		} 
		else if (long_side_timer == 5500)
		 {
		// After 5.5 seconds (5500 milliseconds), stop for 0.5 seconds and transition to the next state
		HDCMOTOR_stop();
		HLED_ledOff(LED_4);  // Turn off LED4
		HLED_ledOn(LED_3);  // Turn on LED3 to indicate stopping
		u8_g_state = car_shortSideState;  // Transition to the next state
	    }
}

void stop(void)
{
	static u16 stop_timer = 0;  // Timer to count the elapsed time
	
	// Increment the timer with each call to this function
	stop_timer++;

	if (stop_timer == 1954) 
	{
		MTIMER0_voidSetPreloadValue(224);
		// After 0.5 seconds (500 milliseconds), set the car's speed to 0 (stop)
		H_PWM_NORMAL_setDutyCycle(0);

		// Stop the car and turn on LED3 to indicate stopping
		HDCMOTOR_stop();
		HLED_ledOn(LED_3);
		} else if (stop_timer == 1000)
		 {
		// After 1 second (1000 milliseconds), turn off LED3 and transition to the next state
		HLED_ledOff(LED_3);
		u8_g_state = car_rotateState;  // Transition to the next state
	   }
}

void short_side(void)
{
	static u16 short_side_timer = 0;  // Timer to count the elapsed time
	
	// Increment the timer with each call to this function
	short_side_timer++;

	if (short_side_timer == 7813) {
		MTIMER0_voidSetPreloadValue(128);
		// After 1 second (1000 milliseconds), set the car's speed to 30% of its maximum speed
		H_PWM_NORMAL_setDutyCycle(30);

		// Start moving forward
		HDCMOTOR_startForward();
		HLED_ledOn(LED_2);  // Turn on LED2 to indicate forward movement
		} else if (short_side_timer == 3000) {
		// After 3 seconds (3000 milliseconds), stop the car for 0.5 seconds
		HDCMOTOR_stop();
		HLED_ledOff(LED_2);  // Turn off LED2
		} else if (short_side_timer == 3500) {
		// After 3.5 seconds (3500 milliseconds), rotate 90 degrees to the right
		HDCMOTOR_Rotate();
		HLED_ledOff(LED_2);  // Turn off LED2
		HLED_ledOn(LED_4);  // Turn on LED4 to indicate rotation
		} else if (short_side_timer == 4000) {
		// After 4 seconds (4000 milliseconds), stop for 0.5 seconds and transition to the next state
		HDCMOTOR_stop();
		HLED_ledOff(LED_4);  // Turn off LED4
		HLED_ledOn(LED_3);  // Turn on LED3 to indicate stopping
		u8_g_state = car_rotateState;  // Transition to the next state
	}
}


/*
void stop(void)
{
	static u16 local_u16Counter_3 =0;
	local_u16Counter_3++;
	if (local_u16Counter_3==1954)
	{
		MTIMER0_voidSetPreloadValue(224);
		local_u16Counter_3=0;
		H_PWM_NORMAL_setDutyCycle(0);
		HLED_ledOn(LED_3);
		HDCMOTOR_stop();
	}
}

void short_side(void)
{
	static u16 local_u16Counter_4 =0;
	local_u16Counter_4++;
	if (local_u16Counter_4==1954)
	{
		MTIMER0_voidSetPreloadValue(224);
		local_u16Counter_4=0;
		H_PWM_NORMAL_setDutyCycle(30);
		HLED_ledOn(LED_2);
		HDCMOTOR_startForward();
	}
}
*/
void carApp(void)
{
	
	switch(u8_g_state)
	{
		
		case car_initState:
		HDCMOTOR_stop();
		HLED_ledOff(LED_1);
		HLED_ledOff(LED_2);
		HLED_ledOff(LED_4);
		HLED_ledOff(LED_3);
		break;
		
		case car_startState:
		u8_g_state = car_longSideState;
		MTIMER0_voidsetCallBackOVF(start_state);
		//H_PWM_NORMAL_setDutyCycle(0);
		//HDCMOTOR_startForward();
		
		break;
		
		case car_longSideState:
		u8_g_state = car_rotateState;
		//HLED_ledOff(LED_4);

		MTIMER0_voidsetCallBackOVF(long_side);
		u8_gs_nextSide = car_shortSideState;
		break;

		case car_rotateState:
		u8_g_state = u8_gs_nextSide;
		//HLED_ledOn(LED_4);
		MTIMER0_voidsetCallBackOVF(stop);
		//HLED_ledOff(LED_3);
		//HDCMOTOR_Rotate();
		MTIMER0_voidsetCallBackOVF(stop);
		break;
		
		case car_shortSideState:
		//HLED_ledOff(LED_3);
		MTIMER0_voidsetCallBackOVF(short_side);
		//HLED_ledOff(LED_2);
		u8_g_state = car_rotateState;
		u8_gs_nextSide = car_longSideState;
		break;
	}
}







