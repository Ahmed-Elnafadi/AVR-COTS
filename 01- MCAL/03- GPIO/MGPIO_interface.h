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

#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

void MGPIO_voidSetPinDirection(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8PinDirection);
void MGPIO_voidSetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8PinValue);
void MGPIO_voidSetPortDirection(u8 copy_u8Port, u8 copy_u8PortDirection);
void MGPIO_voidSetPortValue(u8 copy_u8Port, u8 copy_u8PortValue);

u8 MGPIO_u8GetPinValue(u8 copy_u8Port, u8 copy_u8Pin);


void MGPIO_voidEnableInternalPullUp(void);
void MGPIO_voidDisableInternalPullUp(void);

#define MGPIO_PORTA			0
#define MGPIO_PORTB			1
#define MGPIO_PORTC			2
#define MGPIO_PORTD			3


#define MGPIO_PIN0			0
#define MGPIO_PIN1			1
#define MGPIO_PIN2			2
#define MGPIO_PIN3			3
#define MGPIO_PIN4			4
#define MGPIO_PIN5			5
#define MGPIO_PIN6			6
#define MGPIO_PIN7			7

#define MGPIO_OUTPUT		1
#define MGPIO_INPUT			0

#define MGPIO_LOW			0
#define MGPIO_HIGH			1
#endif