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

#ifndef MTIMER_PRIVATE_H_
#define MTIMER_PRIVATE_H_

/* Register of Timer0 */

#define MTIMER_TCCR0	*((volatile u8*) 0x53) /* Adjust Modes of Timers */

/* Bits of TCCR0 Register */

#define MTIMER_CS00		0
#define MTIMER_CS01		1
#define MTIMER_CS02		2
#define MTIMER_COM00	4
#define MTIMER_COM01	5
#define MTIMER_WGM01	3
#define MTIMER_WGM00	6

#define MTIMER_TCNT0	*((volatile u8*) 0x52) /* Register That is read as it contains value of counting and also can write in it preload value */
#define MTIMER_OCR0		*((volatile u8*) 0x5C) /* Register That contains Compare Match Value */

/* Register of Timer2 */

#define MTIMER_TCCR2	*((volatile u8*) 0x45)

/* Bits of TCCR2 Register */

#define MTIMER_CS20		0
#define MTIMER_CS21		1
#define MTIMER_CS22		2
#define MTIMER_COM20	4
#define MTIMER_COM21	5
#define MTIMER_WGM21	3
#define MTIMER_WGM20	6

#define MTIMER_TCNT2	*((volatile u8*) 0x44) /* Register That is read as it contains value of counting and also can write in it preload value */
#define MTIMER_OCR2		*((volatile u8*) 0x43) /* Register That contains Compare Match Value */

/* Common Registers */

#define MTIMER_TIMSK	*((volatile u8*) 0x59) /* For Enabling Interrupt of Compare Match Mode and Overflow Mode */ 

/* Bits of TIMSK Register */

/* Timer0 */

#define MTIMER_TIOE0	0 /* Overflow Interrupt Enable */
#define MTIMER_OCIE0	1 /* Compare Match Interrupt Enable */

/* Timer2 */

#define MTIMER_TOIE2	6 /* Overflow Interrupt Enable */
#define MTIMER_OCIE2	7 /* Compare Match Interrupt Enable */

#define MTIMER_TIFR		*((volatile u8*) 0x58) /* Contains Flag Bits for three Timers 0,1,2 */

/* Bits of TIFR Register */

/* Timer0 */

#define MTIMER_TOV0		0 /* Overflow Flag is set to 1 when an overflow occurs and cleared by hardware when ISR is executed or writing one to the flag */
#define MTIMER_OCF0		1 /* Compare Flag is set to 1 when compare match occurs and cleared by hardware when ISR is executed or writing one to the flag */

/* Timer2 */

#define MTIMER_TOV2		6 /* Overflow Flag is set to 1 when an overflow occurs and cleared by hardware when ISR is executed or writing one to the flag */
#define MTIMER_OCF2		7 /* Compare Flag is set to 1 when compare match occurs and cleared by hardware when ISR is executed or writing one to the flag */

/* Some Macros from Configuration File */

/* Selecting Mode of Timer */

#define MTIMER_NORMAL_MODE			1
#define MTIMER_PWM_PHASE_CORRECT	2
#define MTIMER_CTC					3
#define MTIMER_PWM_FAST				4

/* Compare Match Output Mode */

#define  MTIMER_CTC_NORMAL			1
#define  MTIMER_CTC_TOGGLE			2
#define  MTIMER_CTC_CLEAR			3
#define  MTIMER_CTC_SET				4

/* Fast PWM Mode */

#define MTIMER_FPWM_NON_INVERTING	1
#define MTIMER_FPWM_INVERTING		2

/* Phase Correct Mode */

#define MTIMER_PPWM_NORMAL			1
#define MTIMER_PPWM_CUP_SDOWN		2
#define MTIMER_PPWM_SUP_CDOWN		3

/* Clock Select */

#define MTIMER_NO_CLOCK						1
#define MTIMER_SYS_CLOCK					2
#define MTIMER_SYS_CLOCK_DIVIDED_BY_8		3
#define MTIMER_SYS_CLOCK_DIVIDED_BY_64		4
#define MTIMER_SYS_CLOCK_DIVIDED_BY_256		5
#define MTIMER_SYS_CLOCK_DIVIDED_BY_1024	6
#define MTIMER_EXTERNAL_FALLING				7
#define MTIMER_EXTERNAL_RISING				8

/* Private Micros */
#define MTIMER_OVERFLOW_TIME_8BITS				256
#define MTIMER_TIMER0_BUSY						1
#define MTIMER_TIMER2_BUSY						2
#define MTIMER_OVERFLOW_NO_POLLING				3
#endif
