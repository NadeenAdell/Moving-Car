#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_

/***************************************************MACROS FOR MOTORS*******************************************/
//First Motor
#define MOTOR_1_FRONT   PIN0
#define MOTOR_1_BACK    PIN1

//Second Motor
#define MOTOR_2_FRONT   PIN0
#define MOTOR_2_BACK    PIN1


//Third Motor
#define MOTOR_3_FRONT  PIN0
#define MOTOR_3_BACK   PIN1

//Fourth Motor
#define MOTOR_4_FRONT  PIN0
#define MOTOR_4_BACK   PIN1


//DC Motor Port
#define DC_MOTOR_PORT_1_2  PORTA
#define DC_MOTOR_PORT_3_4  PORTC

/**********************************************************Includes*******************************************/

/*description : used to initialize the motor */
void HDCMotor_init(void);

/*description : used to make the motor start forward */
void HDCMOTOR_startForward(void);

/*description : used to stop the motor */
void HDCMOTOR_stop(void);

/*description : used to make the motor rotate */
void HDCMOTOR_Rotate(void);




#endif /* DC_MOTOR_INTERFACE_H_ */