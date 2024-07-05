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

#ifndef MTIMER1_CONFIG_H_
#define MTIMER1_CONFIG_H_

/* Clock of Timer1 */

/* Option:
	1- No clock to Timer										==> MTIMER1_NO_CLOCK
	2- System Clock												==> MTIMER1_SYS_CLOCK
	3- System Clock/8											==> MTIMER1_SYS_CLOCK_DIVIDED_BY_8
	4- System Clock/64											==> MTIMER1_SYS_CLOCK_DIVIDED_BY_64
	5- System Clock/256											==> MTIMER1_SYS_CLOCK_DIVIDED_BY_256
	6- System Clock/1024										==> MTIMER1_SYS_CLOCK_DIVIDED_BY_1024
	7- External clock source on T0 pin. Clock on Falling Edge.	==> MTIMER1_EXTERNAL_FALLING
	8- External clock source on T0 pin. Clock on Rising Edge.	==> MTIMER1_EXTERNAL_RISING
 */

#define MTIMER1_CLK_SELECT			MTIMER1_SYS_CLOCK

/* Mode Select */

/* Option:
	1- Normal Mode (Overflow)               ==> MTIMER1_NORMAL_MODE
	2- PWM, Phase Correct, 8-bit            ==> MTIMER1_PPWM_8_BIT
	3- PWM, Phase Correct, 9-bit            ==> MTIMER1_PPWM_9_BIT
	4- PWM, Phase Correct, 10-bit           ==> MTIMER1_PPWM_10_BIT
	5- CTC                                  ==> MTIMER1_CTC_OCR1A_TOP
	6- Fast PWM, 8-bit                      ==> MTIMER1_FPWM_8_BIT
	7- Fast PWM, 9-bit                      ==> MTIMER1_FPWM_9_BIT
	8- Fast PWM, 10-bit                     ==> MTIMER1_FPWM_10_BIT
	9- PWM, Phase and Frequency correct     ==> MTIMER1_PWM_FREQ_CORRECT1
	10-PWM, Phase and Frequency Correct     ==> MTIMER1_PWM_FREQ_CORRECT2
	11-PWM, Phase Correct                   ==> MTIMER1_PPWM_ICR1
	12-PWM, Phase Correct                   ==> MTIMER1_PPWM_OCR1A
	13-CTC                                  ==> MTIMER1_CTC_ICR1_TOP
	14-Fast PWM                             ==> MTIMER1_FPWM_ICR1
	15-Fast PWM                             ==> MTIMER1_FPWM_OCR1A
*/

#define MTIMER1_MODE_SELECT			MTIMER1_NORMAL_MODE

/* CTC Modes Select */

/* Non-PWM */

/* Option:
	1- Normal Port, OC1A/OC1B disconnected.     ==> MTIMER1_CTC_NORMAL
	2- Toggle OC1A/OC1B on compare Match.       ==> MTIMER1_CTC_TOGGLE
	3- Clear OC1A/OC1B on compare match.        ==> MTIMER1_CTC_CLEAR
	4- Set OC1A/OC1B on Compare Match.          ==> MTIMER1_CTC_SET
 */

/* Channel A */

#define MTIMER1_CTCA_MODE		MTIMER1_CTC_NORMAL	

/* Channel B */		

#define MTIMER1_CTCB_MODE		MTIMER1_CTC_NORMAL

/* Fast PWM */

/* Option:
	1- Normal Port, OC1A/OC1B disconnected                               ==> MTIMER1_FPWM_NORMAL
	2- Toggle OC1A on compare Match, OC1B disconnected                   ==> MTIMER1_FPWM_TOGGLE
	3- Clear OC1A/OC1B on compare Match, Set on top (Non-Inverting)      ==> MTIMER1_FPWM_NON_INVERTING
	4- Set OC1A/OC1B on Compare match, Clear on top (Inverting)          ==> MTIMER1_FPWM_INVERTING
 */

/* Channel A */

#define MTIMER1_FPWMA_MODE		MTIMER1_FPWM_NON_INVERTING

/* Channel B */

#define MTIMER1_FPWMB_MODE		MTIMER1_FPWM_NON_INVERTING

/* Phase Correct PWM */

/* Option:
	1- Normal Port, OC1A/OC1B disconnected                                                                       ==> MTIMER1_PPWM_NORMAL
	2- Toggle OC1A on compare Match, OC1B disconnected                                                           ==> MTIMER1_PPWM_TOGGLE
	3- Clear OC1A/OC1B on compare Match when Up-counting, Set OC1A/OC1B on compare match when downcounting.      ==> MTIMER1_PPWM_CUP_SDOWN
	4- Set OC1A/OC1B on Compare match when Up-counting. Clear OC1A/OC1B on compare match when downcounting.      ==> MTIMER1_PPWM_SUP_CDOWN
 */

/* Channel A */

#define MTIMER1_PPWMA_MODE		MTIMER1_PPWM_CUP_SDOWN

/* Channel B */

#define MTIMER1_PPWMB_MODE		MTIMER1_PPWM_CUP_SDOWN

/* ICU */
/* Option:
	1- Rising Edge   ==> MTIMER1_RISING_EDGE
	2- Falling Edge  ==> MTIMER1_FALLING_EDGE
*/

#define MTIMER1_ICU_EDGE	MTIMER1_RISING_EDGE

#endif