#ifndef PWM_CONFIG_H_
#define PWM_CONFIG_H_

#define TCCR2  (*(volatile u8*)(0x45))
#define TCNT2  (*(volatile u8*)(0x44))
#define TIMSK  (*(volatile u8*)(0x59))
#define SREG   (*(volatile u8*)(0x5F))




#define NORMAL_MODE     0x00
#define REG_SIZE        256
#define REG_NEW_SIZE    128
#define ONE_BIT         1
#define PERCENT         100
#define ON_TIME         0
#define OFF_TIME        1


// TIMSK bits
#define TOIE2 6

// TCCR2 bits
#define CS20  0
#define CS21  1
#define CS22  2

#endif /* PWM_CONFIG_H_ */