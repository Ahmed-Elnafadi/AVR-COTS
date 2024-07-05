/************************************************************/
/************************************************************/
/********************* Driver : GPIO          ***************/
/********************* Layer  : MCAL          ***************/
/********************* Date   : 01 may 2022   ***************/
/********************* Version: V01           ***************/
/********************* Author : Ahmed Mostafa ***************/
/********************* Company: ROBO          ***************/
/************************************************************/
/************************************************************/

/* Preprocessor File Guard */

#ifndef MGPIO_PRIVATE_H_
#define MGPIO_PRIVATE_H_

typedef struct registers{
	u8 PIND;
	u8 DDRD;
	u8 PORTD;
	u8 PINC;
	u8 DDRC;
	u8 PORTC;
	u8 PINB;
	u8 DDRB;
	u8 PORTB;
	u8 PINA;
	u8 DDRA;
	u8 PORTA;	
} MGPIO_t;

#define MGPIO        ((volatile MGPIO_t *)0x30)

#define MGPIO_SFIOR  *((volatile u8 *)0x50)

#define GPIO_PUD	2
#endif