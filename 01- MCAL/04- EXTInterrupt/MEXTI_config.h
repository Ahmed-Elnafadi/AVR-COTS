/************************************************************/
/************************************************************/
/********************* Driver : EXTI          ***************/
/********************* Layer  : MCAL          ***************/
/********************* Date   : 02 may 2022   ***************/
/********************* Version: V01           ***************/
/********************* Author : Ahmed Mostafa ***************/
/********************* Company: ROBO          ***************/
/************************************************************/
/************************************************************/

/* Preprocessor File Guard */

#ifndef MEXTI_CONFIG_H_
#define MEXTI_CONFIG_H_

#define MEXTI_LOW_LEVEL		1
#define MEXTI_FALLING_EDGE	2
#define MEXTI_RISING_EDGE	3
#define MEXTI_ENABLE		4
#define MEXTI_DISABLE		5

/* Sense for INT1 and INT0:
	1- choose MEXTI_LOW_LEVEL    ==> for low level sense.
	2- choose MEXTI_FALLING_EDGE ==> for falling edge sense.
	3- choose MEXTI_RISING_EDGE  ==> for Rising edge sense.

 */

#define MEXTI_INT1_SENSE		MEXTI_FALLING_EDGE
#define MEXTI_INT0_SENSE		MEXTI_RISING_EDGE
/********************************************************************/


/* Sense for INT2:
	2- choose MEXTI_FALLING_EDGE ==> for falling edge sense.
	3- choose MEXTI_RISING_EDGE  ==> for Rising edge sense.
*/

#define MEXTI_INT2_SENSE		MEXTI_FALLING_EDGE
/******************************************************************/


/* GIE:
 1- MEXTI_ENABLE   ==> for enabling General Interrupt Enable for all Interrupt
 2- MEXTI_DISABLE  ==> for disabling General Interrupt Enable for all Interrupt
 */
 
#define MEXTI_GIE_CONTROL		MEXTI_ENABLE


#endif