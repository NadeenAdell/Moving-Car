#ifndef EXT_CONFIG_H_
#define EXT_CONFIG_H_


#define SREG    (*(volatile u8*)(0x5F))
#define GICR    (*(volatile u8*)(0x5B))
#define GIFR    (*(volatile u8*)(0x5A))
#define MCUCR   (*(volatile u8*)(0x55))
#define MCUCSR  (*(volatile u8*)(0x54))

// MCUCR bits
#define ISC00     0
#define ISC01     1
#define ISC10     2
#define ISC11     3


// MCUCSR bits
#define ISC2      6


// GICR bits
#define INT0      6
#define INT1      7
#define INT2      5


#endif /* EXT_CONFIG_H_ */