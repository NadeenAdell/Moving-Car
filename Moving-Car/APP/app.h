#ifndef APP_H_
#define APP_H_

#include "../ECUAL/h_pwm_normal/h_pwm_normal.h"
#include "../MCAL/timer0/tim0_interface.h"
#include "../ECUAL/h_ext_int/h_ext_int.h"
#include "../ECUAL/led/led_interface.h"
#include "../ECUAL/button/pb_interface.h"
#include "../ECUAL/motor/motor.h"




void initCar(void);
void carApp(void);

static void appMoveForward(void);
static void appStop(void);
static void appRotate(void);

void button0Callback(void);
void button1Callback(void);

#endif /* APP_H_ */

