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

/* Preprocessor file Guard */

#ifndef MTIMER_CONFIG_H_
#define MTIMER_CONFIG_H_

/* Selecting Mode of Timer */

/* Option: 
	1- Normal             ==> MTIMER_NORMAL_MODE
	2- Phase correct PWM  ==> MTIMER_PWM_PHASE_CORRECT
	3- CTC				  ==> MTIMER_CTC
	4- Fast PWM           ==> MTIMER_PWM_FAST
 */

#define MTIMER_TIMER0_MODE		MTIMER_NORMAL_MODE
#define MTIMER_TIMER2_MODE		MTIMER_NORMAL_MODE

/* Compare Match Output Mode */

/* Option:
	1- Normal, OC0,2 disconnected   ==> MTIMER_CTC_NORMAL
	2- Toggle  OC0,2 Pin		    ==> MTIMER_CTC_TOGGLE
	3- Clear   OC0,2 Pin		    ==> MTIMER_CTC_CLEAR
	4- Set     OC0,2 Pin			==> MTIMER_CTC_SET
*/

#define MTIMER_CTC0_MODE		MTIMER_CTC_NORMAL
#define MTIMER_CTC2_MODE		MTIMER_CTC_NORMAL

/* Fast PWM Mode */

/* Option:
	1- Normal, OC0 disconnected							 ==> MTIMER_FPWM_NORMAL
	2- Set on Top, Clear on Compare (Non inverting Mode) ==> MTIMER_FPWM_NON_INVERTING
	3- Clear on Top, Set on compare (Inverting Mode)	 ==> MTIMER_FPWM_INVERTING
 */

#define MTIMER_FPWM0_MODE		MTIMER_FPWM_NON_INVERTING
#define MTIMER_FPWM2_MODE		MTIMER_FPWM_INVERTING

/* Phase Correct PWM */

/* Option:
	1- Normal_Mode, OC0 is disconnected.													==>	MTIMER_PPWM_NORMAL
	2- Clear on compare match when up-counting, set on compare match when down-counting.	==> MTIMER_PPWM_CUP_SDOWN
	3- Set on compare match when up-counting, clear on compare match when down-counting.	==> MTIMER_PPWM_SUP_CDOWN
*/
#define MTIMER_PPWM0_MODE		MTIMER_PPWM_CUP_SDOWN
#define MTIMER_PPWM2_MODE		MTIMER_PPWM_SUP_CDOWN

/* Clock Select */

/* Option:
	1- No clock to Timer										==> MTIMER_NO_CLOCK
	2- System Clock												==> MTIMER_SYS_CLOCK
	3- System Clock/8											==> MTIMER_SYS_CLOCK_DIVIDED_BY_8
	4- System Clock/64											==> MTIMER_SYS_CLOCK_DIVIDED_BY_64
	5- System Clock/256											==> MTIMER_SYS_CLOCK_DIVIDED_BY_256
	6- System Clock/1024										==> MTIMER_SYS_CLOCK_DIVIDED_BY_1024
	7- External clock source on T0 pin. Clock on Falling Edge.	==> MTIMER_EXTERNAL_FALLING
	8- External clock source on T0 pin. Clock on Rising Edge.	==> MTIMER_EXTERNAL_RISING
 */

#define MTIMER_TIMER0_CLK	MTIMER_SYS_CLOCK_DIVIDED_BY_8
#define MTIMER_TIMER2_CLK	MTIMER_SYS_CLOCK_DIVIDED_BY_8

#endif
