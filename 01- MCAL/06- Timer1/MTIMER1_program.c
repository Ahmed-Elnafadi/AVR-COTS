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

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MTIMER1_interface.h"
#include "MTIMER1_config.h"
#include "MTIMER1_private.h"

/* Global Functions */
void (*Global_voidFunc)(void) = NULL;

/* Global Variables */

u16 Global_u16Preload = 0;

/* Implementation of APIs */

void MTIMER1_voidInit(void){
	/* Clock Select */
	#if   MTIMER1_CLK_SELECT == MTIMER1_NO_CLOCK
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_CS12);
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_CS11);
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_CS10);
	#elif MTIMER1_CLK_SELECT == MTIMER1_SYS_CLOCK
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_CS12);
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_CS11);
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_CS10);
	#elif MTIMER1_CLK_SELECT == MTIMER1_SYS_CLOCK_DIVIDED_BY_8
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_CS12);
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_CS11);
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_CS10);
	#elif MTIMER1_CLK_SELECT == MTIMER1_SYS_CLOCK_DIVIDED_BY_64
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_CS12);
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_CS11);
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_CS10);
	#elif MTIMER1_CLK_SELECT == MTIMER1_SYS_CLOCK_DIVIDED_BY_256
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_CS12);
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_CS11);
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_CS10);
	#elif MTIMER1_CLK_SELECT == MTIMER1_SYS_CLOCK_DIVIDED_BY_1024
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_CS12);
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_CS11);
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_CS10);
	#elif MTIMER1_CLK_SELECT == MTIMER1_EXTERNAL_FALLING
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_CS12);
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_CS11);
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_CS10);
	#elif MTIMER1_CLK_SELECT == MTIMER1_EXTERNAL_RISING
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_CS12);
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_CS11);
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_CS10);
	#else 
		#error("Wrong Input to System Clock of Timer1")
	#endif
	/**************************************************/
	/* Mode Selection */
	#if   MTIMER1_MODE_SELECT == MTIMER1_NORMAL_MODE
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_WGM13);
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_WGM12);
	CLR_BIT(MTIMER1_TCCR1A, MTIMER1_WGM11);
	CLR_BIT(MTIMER1_TCCR1A, MTIMER1_WGM10);
	#elif MTIMER1_MODE_SELECT == MTIMER1_PPWM_8_BIT
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_WGM13);
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_WGM12);
	CLR_BIT(MTIMER1_TCCR1A, MTIMER1_WGM11);
	SET_BIT(MTIMER1_TCCR1A, MTIMER1_WGM10);
		/* Channel A */
		#if   MTIMER1_PPWMA_MODE == MTIMER1_PPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_CUP_SDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_SUP_CDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#else
			#error ("Wrong Input to Mode Selection of PPWMA")
		#endif
		/* Channel B */
		#if   MTIMER1_PPWMB_MODE == MTIMER1_PPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_CUP_SDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_SUP_CDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#else
			#error ("Wrong Input to Mode Selection of PPWMB")
		#endif
	#elif MTIMER1_MODE_SELECT == MTIMER1_PPWM_9_BIT
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_WGM13);
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_WGM12);
	SET_BIT(MTIMER1_TCCR1A, MTIMER1_WGM11);
	CLR_BIT(MTIMER1_TCCR1A, MTIMER1_WGM10);
		/* Channel A */
		#if   MTIMER1_PPWMA_MODE == MTIMER1_PPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_CUP_SDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_SUP_CDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#else
			#error ("Wrong Input to Mode Selection of PPWMA")
		#endif
		/* Channel B */
		#if   MTIMER1_PPWMB_MODE == MTIMER1_PPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_CUP_SDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_SUP_CDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#else
			#error ("Wrong Input to Mode Selection of PPWMB")
		#endif
	#elif MTIMER1_MODE_SELECT == MTIMER1_PPWM_10_BIT
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_WGM13);
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_WGM12);
	SET_BIT(MTIMER1_TCCR1A, MTIMER1_WGM11);
	SET_BIT(MTIMER1_TCCR1A, MTIMER1_WGM10);
		/* Channel A */
		#if   MTIMER1_PPWMA_MODE == MTIMER1_PPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_CUP_SDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_SUP_CDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#else
			#error ("Wrong Input to Mode Selection of PPWMA")
		#endif
		/* Channel B */
		#if   MTIMER1_PPWMB_MODE == MTIMER1_PPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_CUP_SDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_SUP_CDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#else
			#error ("Wrong Input to Mode Selection of PPWMB")
		#endif
	#elif MTIMER1_MODE_SELECT == MTIMER1_CTC_OCR1A_TOP
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_WGM13);
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_WGM12);
	CLR_BIT(MTIMER1_TCCR1A, MTIMER1_WGM11);
	CLR_BIT(MTIMER1_TCCR1A, MTIMER1_WGM10);
		/* Channel A */
		#if   MTIMER1_CTCA_MODE == MTIMER1_CTC_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_CTCA_MODE == MTIMER1_CTC_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_CTCA_MODE == MTIMER1_CTC_CLEAR
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_CTCA_MODE == MTIMER1_CTC_SET
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#else
			#error ("Wrong Input to Mode Selection of CTCA")
		#endif
		/* Channel B */
		#if   MTIMER1_CTCB_MODE == MTIMER1_CTC_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_CTCB_MODE == MTIMER1_CTC_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_CTCB_MODE == MTIMER1_CTC_CLEAR
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_CTCB_MODE == MTIMER1_CTC_SET
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#else
			#error ("Wrong Input to Mode Selection of CTCB")
		#endif
	#elif MTIMER1_MODE_SELECT == MTIMER1_FPWM_8_BIT
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_WGM13);
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_WGM12);
	CLR_BIT(MTIMER1_TCCR1A, MTIMER1_WGM11);
	SET_BIT(MTIMER1_TCCR1A, MTIMER1_WGM10);
		/* Channel A */
		#if   MTIMER1_FPWMA_MODE == MTIMER1_FPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_FPWMA_MODE == MTIMER1_FPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_FPWMA_MODE == MTIMER1_FPWM_NON_INVERTING
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_FPWMA_MODE == MTIMER1_FPWM_INVERTING
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#else
			#error ("Wrong Input to Mode Selection of FPWMA")
		#endif
		/* Channel B */
		#if   MTIMER1_FPWMB_MODE == MTIMER1_FPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_FPWMB_MODE == MTIMER1_FPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_FPWMB_MODE == MTIMER1_FPWM_NON_INVERTING
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_FPWMB_MODE == MTIMER1_FPWM_INVERTING
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#else
			#error ("Wrong Input to Mode Selection of FPWMB")
		#endif
	#elif MTIMER1_MODE_SELECT == MTIMER1_FPWM_9_BIT
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_WGM13);
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_WGM12);
	SET_BIT(MTIMER1_TCCR1A, MTIMER1_WGM11);
	CLR_BIT(MTIMER1_TCCR1A, MTIMER1_WGM10);
		/* Channel A */
		#if   MTIMER1_FPWMA_MODE == MTIMER1_FPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_FPWMA_MODE == MTIMER1_FPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_FPWMA_MODE == MTIMER1_FPWM_NON_INVERTING
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_FPWMA_MODE == MTIMER1_FPWM_INVERTING
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#else
			#error ("Wrong Input to Mode Selection of FPWMA")
		#endif
		/* Channel B */
		#if   MTIMER1_FPWMB_MODE == MTIMER1_FPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_FPWMB_MODE == MTIMER1_FPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_FPWMB_MODE == MTIMER1_FPWM_NON_INVERTING
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_FPWMB_MODE == MTIMER1_FPWM_INVERTING
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#else
			#error ("Wrong Input to Mode Selection of FPWMB")
		#endif
	#elif MTIMER1_MODE_SELECT == MTIMER1_FPWM_10_BIT
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_WGM13);
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_WGM12);
	SET_BIT(MTIMER1_TCCR1A, MTIMER1_WGM11);
	SET_BIT(MTIMER1_TCCR1A, MTIMER1_WGM10);
		/* Channel A */
		#if   MTIMER1_FPWMA_MODE == MTIMER1_FPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_FPWMA_MODE == MTIMER1_FPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_FPWMA_MODE == MTIMER1_FPWM_NON_INVERTING
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_FPWMA_MODE == MTIMER1_FPWM_INVERTING
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#else
			#error ("Wrong Input to Mode Selection of FPWMA")
		#endif
		/* Channel B */
		#if   MTIMER1_FPWMB_MODE == MTIMER1_FPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_FPWMB_MODE == MTIMER1_FPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_FPWMB_MODE == MTIMER1_FPWM_NON_INVERTING
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_FPWMB_MODE == MTIMER1_FPWM_INVERTING
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#else
			#error ("Wrong Input to Mode Selection of FPWMB")
		#endif
	#elif MTIMER1_MODE_SELECT == MTIMER1_PWM_FREQ_CORRECT1
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_WGM13);
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_WGM12);
	CLR_BIT(MTIMER1_TCCR1A, MTIMER1_WGM11);
	CLR_BIT(MTIMER1_TCCR1A, MTIMER1_WGM10);
		/* Channel A */
		#if   MTIMER1_PPWMA_MODE == MTIMER1_PPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_CUP_SDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_SUP_CDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#else
			#error ("Wrong Input to Mode Selection of PPWMA")
		#endif
		/* Channel B */
		#if   MTIMER1_PPWMB_MODE == MTIMER1_PPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_CUP_SDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_SUP_CDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#else
			#error ("Wrong Input to Mode Selection of PPWMB")
		#endif
	#elif MTIMER1_MODE_SELECT == MTIMER1_PWM_FREQ_CORRECT2
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_WGM13);
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_WGM12);
	CLR_BIT(MTIMER1_TCCR1A, MTIMER1_WGM11);
	SET_BIT(MTIMER1_TCCR1A, MTIMER1_WGM10);
		/* Channel A */
		#if   MTIMER1_PPWMA_MODE == MTIMER1_PPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_CUP_SDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_SUP_CDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#else
			#error ("Wrong Input to Mode Selection of PPWMA")
		#endif
		/* Channel B */
		#if   MTIMER1_PPWMB_MODE == MTIMER1_PPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_CUP_SDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_SUP_CDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#else
			#error ("Wrong Input to Mode Selection of PPWMB")
		#endif
	#elif MTIMER1_MODE_SELECT == MTIMER1_PPWM_ICR1
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_WGM13);
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_WGM12);
	SET_BIT(MTIMER1_TCCR1A, MTIMER1_WGM11);
	CLR_BIT(MTIMER1_TCCR1A, MTIMER1_WGM10);
		/* Channel A */
		#if   MTIMER1_PPWMA_MODE == MTIMER1_PPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_CUP_SDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_SUP_CDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#else
			#error ("Wrong Input to Mode Selection of PPWMA")
		#endif
		/* Channel B */
		#if   MTIMER1_PPWMB_MODE == MTIMER1_PPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_CUP_SDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_SUP_CDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#else
			#error ("Wrong Input to Mode Selection of PPWMB")
		#endif
	#elif MTIMER1_MODE_SELECT == MTIMER1_PPWM_OCR1A
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_WGM13);
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_WGM12);
	SET_BIT(MTIMER1_TCCR1A, MTIMER1_WGM11);
	SET_BIT(MTIMER1_TCCR1A, MTIMER1_WGM10);
		/* Channel A */
		#if   MTIMER1_PPWMA_MODE == MTIMER1_PPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_CUP_SDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_PPWMA_MODE == MTIMER1_PPWM_SUP_CDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#else
			#error ("Wrong Input to Mode Selection of PPWMA")
		#endif
		/* Channel B */
		#if   MTIMER1_PPWMB_MODE == MTIMER1_PPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_CUP_SDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_PPWMB_MODE == MTIMER1_PPWM_SUP_CDOWN
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#else
			#error ("Wrong Input to Mode Selection of PPWMB")
		#endif
	#elif MTIMER1_MODE_SELECT == MTIMER1_CTC_ICR1_TOP
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_WGM13);
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_WGM12);
	CLR_BIT(MTIMER1_TCCR1A, MTIMER1_WGM11);
	CLR_BIT(MTIMER1_TCCR1A, MTIMER1_WGM10);
		/* Channel A */
		#if   MTIMER1_CTCA_MODE == MTIMER1_CTC_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_CTCA_MODE == MTIMER1_CTC_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_CTCA_MODE == MTIMER1_CTC_CLEAR
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_CTCA_MODE == MTIMER1_CTC_SET
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#else
			#error ("Wrong Input to Mode Selection of CTCA")
		#endif
		/* Channel B */
		#if   MTIMER1_CTCB_MODE == MTIMER1_CTC_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_CTCB_MODE == MTIMER1_CTC_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_CTCB_MODE == MTIMER1_CTC_CLEAR
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_CTCB_MODE == MTIMER1_CTC_SET
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#else
			#error ("Wrong Input to Mode Selection of CTCB")
		#endif
	#elif MTIMER1_MODE_SELECT == MTIMER1_FPWM_ICR1
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_WGM13);
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_WGM12);
	SET_BIT(MTIMER1_TCCR1A, MTIMER1_WGM11);
	CLR_BIT(MTIMER1_TCCR1A, MTIMER1_WGM10);
		/* Channel A */
		#if   MTIMER1_FPWMA_MODE == MTIMER1_FPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_FPWMA_MODE == MTIMER1_FPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_FPWMA_MODE == MTIMER1_FPWM_NON_INVERTING
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_FPWMA_MODE == MTIMER1_FPWM_INVERTING
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#else
			#error ("Wrong Input to Mode Selection of FPWMA")
		#endif
		/* Channel B */
		#if   MTIMER1_FPWMB_MODE == MTIMER1_FPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_FPWMB_MODE == MTIMER1_FPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_FPWMB_MODE == MTIMER1_FPWM_NON_INVERTING
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_FPWMB_MODE == MTIMER1_FPWM_INVERTING
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#else
			#error ("Wrong Input to Mode Selection of FPWMB")
		#endif
	#elif MTIMER1_MODE_SELECT == MTIMER1_FPWM_OCR1A
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_WGM13);
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_WGM12);
	SET_BIT(MTIMER1_TCCR1A, MTIMER1_WGM11);
	SET_BIT(MTIMER1_TCCR1A, MTIMER1_WGM10);
		/* Channel A */
		#if   MTIMER1_FPWMA_MODE == MTIMER1_FPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_FPWMA_MODE == MTIMER1_FPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_FPWMA_MODE == MTIMER1_FPWM_NON_INVERTING
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#elif MTIMER1_FPWMA_MODE == MTIMER1_FPWM_INVERTING
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1A0);
		#else
			#error ("Wrong Input to Mode Selection of FPWMA")
		#endif
		/* Channel B */
		#if   MTIMER1_FPWMB_MODE == MTIMER1_FPWM_NORMAL
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_FPWMB_MODE == MTIMER1_FPWM_TOGGLE
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_FPWMB_MODE == MTIMER1_FPWM_NON_INVERTING
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		CLR_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#elif MTIMER1_FPWMB_MODE == MTIMER1_FPWM_INVERTING
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B1);
		SET_BIT(MTIMER1_TCCR1A, MTIMER1_COM1B0);
		#else
			#error ("Wrong Input to Mode Selection of FPWMB")
		#endif
	#else
		#error("Wrong Input to Mode Selection of Timer1")
	#endif
}
u8 MTIMER1_u8SetPreloadValue(u16 copy_u16Preload){
	/* Used in Overflow mode which is Normal Mode */
	u8 Local_u8Error =0;
	if(Local_u8Error != 1){
		MTIMER1_TCNT1 = copy_u16Preload;
		Global_u16Preload = copy_u16Preload;
	}
	else{
		Local_u8Error = 1;
	}
	return Local_u8Error;
}
u8 MTIMER1_u8SetCallBackOverflow(u16 copy_u16OverflowCount, void (*copy_voidFunc)(void)){
	
	
}
u8 MTIMER1_u8SetCallBackCTC(u8 copy_u8TimerChannel, u16 copy_u16CompMatchCount, u8 copy_u8CompMatchValue, void (*copy_voidFunc)(void)){
	
	
}
u8 MTIMER1_u8AnalogWrite(u8 copy_u8TimerChannel, u8 copy_u8AnalogValue){
	
	
}
void MTIMER1_voidDelay(u32 copy_u16MicroSecond){
	
	
}
void ICU_voidInit(void){
	/* ICU Noise Canceler */
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_ICNC1);
	
	/* ICU Edge Select */
	#if   MTIMER1_ICU_EDGE == MTIMER1_RISING_EDGE
	SET_BIT(MTIMER1_TCCR1B, MTIMER1_ICES1);
	#elif MTIMER1_ICU_EDGE == MTIMER1_FALLING_EDGE
	CLR_BIT(MTIMER1_TCCR1B, MTIMER1_ICES1);
	#else
		#error("Wrong Input to ICU Edge Select")
	#endif
	/* Interrupt Enable Of Input Capture Unit */
	SET_BIT(MTIMER1_TIMSK, MTIMER1_TICIE1);
}
void ICU_voidInterrupt(u8 copy_u8State){
	
	/* Interrupt Enable/Disable Of Input Capture Unit */
	switch(copy_u8State){
		case MTIMER1_INT_ENABLE	:SET_BIT(MTIMER1_TIMSK, MTIMER1_TICIE1); break;
		case MTIMER1_INT_DISABLE:CLR_BIT(MTIMER1_TIMSK, MTIMER1_TICIE1); break;
		default: /* Do Nothing */
	}
}
u16 ICU_u16TimeRead(void){
	
	return MTIMER1_ICR1;
	
}
void ICU_voidEdgeChange(u8 copy_u8Edge){
	
	switch(copy_u8Edge){
		case MTIMER1_RISING:  SET_BIT(MTIMER1_TCCR1B, MTIMER1_ICES1); break;
		case MTIMER1_FALLING: CLR_BIT(MTIMER1_TCCR1B, MTIMER1_ICES1); break;
		default: /* Do Nothing */
	}
}

/* ISR */

/* Timer Overflow */
void __vector_9 (void) __attribute__((signal));
void __vector_9 (void){
	
	
}

/* Timer Compare Match A */
void __vector_7 (void) __attribute__((signal));
void __vector_7 (void){
	
	
}

/* Timer Compare Match B */
void __vector_8 (void) __attribute__((signal));
void __vector_8 (void){
	
	
}

/* Timer Capture unit Event */
void __vector_6 (void) __attribute_((signal));
void __vector_6 (void){
	
}

