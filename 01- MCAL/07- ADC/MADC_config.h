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

#ifndef MADC_CONFIG_H_
#define MADC_CONFIG_H_

#define MADC_AVCC			1
#define MADC_INTERNAL		2

#define MADC_RIGHT_ADJUST	3
#define MADC_LEFT_ADJUST	4

#define MADC_ENABLE			5
#define MADC_DISABLE		6

#define MADC_FREE_RUNNING				0
#define MADC_ANALOG_COMPARATOR			1
#define MADC_EXTI_REQUEST				2
#define MADC_TIMER0_COMPARE_MATCH		3
#define MADC_TIMER0_OVERFLOW			4
#define MADC_TIMER1_COMPARE_MATCHB		5
#define MADC_TIMER1_OVERFLOW			6
#define MADC_TIMER1_CAPTURE_EVENT		7

#define MADC_DIV_2						0
#define MADC_DIV_4						2
#define MADC_DIV_8						3
#define MADC_DIV_16						4
#define MADC_DIV_32						5
#define MADC_DIV_64						6
#define MADC_DIV_128					7

/* Options for Reference Voltage for ADC:
* 1- MADC_AVCC	    ==> for external voltage from VREF Pin.
* 2- MADC_INTERNAL  ==> for internal voltage 2.56V.
*/

#define MADC_VREF		MADC_AVCC

/*Option for Adjust ADC Data Register:
* 1- MADC_RIGHT_ADJUST	==> for starting to write from first bit in LOW Register
* 2- MADC_LEFT_ADJUST	==> for starting to write from last two bits in LOW Register
*/

#define MADC_ADLAR		MADC_LEFT_ADJUST

/* Option For ADC Enable:
* 1- MADC_ENABLE	==> For Enable ADC
* 2- MADC_DISABLE	==> For Disable ADC
*/

#define MADC_ADEN		MADC_ENABLE

/* Option For Auto_Starting Conversion enable or not:
* 1- MADC_ENABLE	==> For Enable Auto_Trigger
* 2- MADC_DISABLE	==> For Disable Auto_Trigger
*/
#define MADC_ADATE_SELECT		MADC_DISABLE

#if MADC_ADATE_SELECT == MADC_ENABLE
/* Option for selecting Trigger or start source for conversion:
* 1- MADC_FREE_RUNNING
* 2- MADC_ANALOG_COMPARATOR
* 3- MADC_EXTI_REQUEST
* 4- MADC_TIMER0_COMPARE_MATCH
* 5- MADC_TIMER0_OVERFLOW
* 6- MADC_TIMER1_COMPARE_MATCHB
* 7- MADC_TIMER1_OVERFLOW
* 8- MADC_TIMER1_CAPTURE_EVENT
*/

#define MADC_AUTO_TRIGGER_CONV_SOURCE		MADC_FREE_RUNNING

#elif MADC_ADATE_SELECT == MADC_DISABLE
/* Do Nothing */
#endif
/* Option For Enabling Interrupt of ADC End conversion
* 1- MADC_ENABLE	==> For Enable ADC Interrupt
* 2- MADC_DISABLE	==> For Disable ADC Interrupt
*/

#define MADC_ADIE_SELECT		MADC_DISABLE

/* Otions for Prescaler of Clock Entered to ADC from CPU Clock:
* 1- MADC_DIV_2	  ==> Division By 2
* 2- MADC_DIV_4   ==> Division By 4
* 1- MADC_DIV_8	  ==> Division By 8
* 2- MADC_DIV_16  ==> Division By 16
* 1- MADC_DIV_32  ==> Division By 32
* 2- MADC_DIV_64  ==> Division By 64
* 1- MADC_DIV_128 ==> Division By 128
*/

#define MADC_PRE_SELECT		MADC_DIV_64
#endif