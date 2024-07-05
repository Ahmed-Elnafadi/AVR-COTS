/************************************************************/
/************************************************************/
/********************* Driver : Timer         ***************/
/********************* Layer  : MCAL          ***************/
/********************* Date   : 13 July 2022  ***************/
/********************* Version: V01           ***************/
/********************* Author : Ahmed Mostafa ***************/
/********************* Company: ROBO          ***************/
/************************************************************/
/************************************************************/

/* Preprocessor File Guard */

#ifndef MTIMER1_PRIVATE_H_
#define MTIMER1_PRIVATE_H_

/* Registers */

#define MTIMER1_TCCR1A		*((volatile u8*)0x4F)

/* Bits of TCCR1A */

#define MTIMER1_WGM10		0
#define MTIMER1_WGM11		1
#define MTIMER1_COM1B0		4
#define MTIMER1_COM1B1		5
#define MTIMER1_COM1A0		6
#define MTIMER1_COM1A1		7
/****************************/
#define MTIMER1_TCCR1B		*((volatile u8*)0x4E)

/* Bits of TCCR1B */

#define MTIMER1_CS10		0
#define MTIMER1_CS11		1
#define MTIMER1_CS12		2
#define MTIMER1_WGM12		3
#define MTIMER1_WGM13		4
#define MTIMER1_ICES1		6
#define MTIMER1_ICNC1		7
/****************************/
#define MTIMER1_TCNT1		*((volatile u16*)0x4C)

#define MTIMER1_OCR1A		*((volatile u16*)0x4A)

#define MTIMER1_OCR1B		*((volatile u16*)0x48)

#define MTIMER1_ICR1		*((volatile u16*)0x46)

#define MTIMER1_TIMSK		*((volatile u8*)0x59)

/* Bits of TIMSK */

#define MTIMER1_TOIE1		2
#define MTIMER1_OCIE1B		3
#define MTIMER1_OCIE1A		4
#define MTIMER1_TICIE1		5
/****************************/
#define MTIMER1_TIFR		*((volatile u8*)0x58)

/* Bits of TIFR */

#define MTIMER1_TOV1		2
#define MTIMER1_OCF1B		3
#define MTIMER1_OCF1A		4
#define MTIMER1_ICF1		5

/* Macros for config Files */

#define MTIMER1_NO_CLOCK					1
#define MTIMER1_SYS_CLOCK					2
#define MTIMER1_SYS_CLOCK_DIVIDED_BY_8		3
#define MTIMER1_SYS_CLOCK_DIVIDED_BY_64		4
#define MTIMER1_SYS_CLOCK_DIVIDED_BY_256	5
#define MTIMER1_SYS_CLOCK_DIVIDED_BY_1024	6
#define MTIMER1_EXTERNAL_FALLING			7
#define MTIMER1_EXTERNAL_RISING				8

#define MTIMER1_NORMAL_MODE					1
#define MTIMER1_PPWM_8_BIT					2
#define MTIMER1_PPWM_9_BIT					3
#define MTIMER1_PPWM_10_BIT					4
#define MTIMER1_CTC_OCR1A_TOP				5
#define MTIMER1_FPWM_8_BIT					6
#define MTIMER1_FPWM_9_BIT					7
#define MTIMER1_FPWM_10_BIT					8
#define MTIMER1_PWM_FREQ_CORRECT1			9
#define MTIMER1_PWM_FREQ_CORRECT2			10
#define MTIMER1_PPWM_ICR1					11
#define MTIMER1_PPWM_OCR1A					12
#define MTIMER1_CTC_ICR1_TOP				13
#define MTIMER1_FPWM_ICR1					14
#define MTIMER1_FPWM_OCR1A					15

#define MTIMER1_CTC_NORMAL					1
#define MTIMER1_CTC_TOGGLE					2
#define MTIMER1_CTC_CLEAR					3
#define MTIMER1_CTC_SET						4

#define MTIMER1_FPWM_NORMAL					1
#define MTIMER1_FPWM_TOGGLE					2
#define MTIMER1_FPWM_NON_INVERTING			3
#define MTIMER1_FPWM_INVERTING				4

#define MTIMER1_PPWM_NORMAL					1
#define MTIMER1_PPWM_TOGGLE					2
#define MTIMER1_PPWM_CUP_SDOWN				3
#define MTIMER1_PPWM_SUP_CDOWN				4

#define MTIMER1_RISING_EDGE					1
#define MTIMER1_FALLING_EDGE				2

#endif