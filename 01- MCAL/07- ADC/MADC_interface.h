/************************************************************/
/************************************************************/
/********************* Driver : ADC           ***************/
/********************* Layer  : MCAL          ***************/
/********************* Date   : 03 may 2022   ***************/
/********************* Version: V01           ***************/
/********************* Author : Ahmed Mostafa ***************/
/********************* Company: ROBO          ***************/
/************************************************************/
/************************************************************/

/* Preprocessor File Guard */

#ifndef MADC_INTERFACE_H_
#define MADC_INTERFACE_H_

void MADC_voidInit(void);

/* Options for Channel Select */

#define MADC_ADC0		0b00000000
#define MADC_ADC1		0b00000001
#define MADC_ADC2		0b00000010
#define MADC_ADC3		0b00000011
#define MADC_ADC4		0b00000100
#define MADC_ADC5		0b00000101
#define MADC_ADC6		0b00000110
#define MADC_ADC7		0b00000111


u16 MADC_u16ReadAnalog(u8 copy_u8Channel, u8 copy_u8VrefValue);

#endif