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

#include "MTIMER_interface.h"
#include "MTIMER_config.h"
#include "MTIMER_private.h"

/* Global Function */

void (*Global_FuncOverflow0)(void) = NULL;
void (*Global_FuncOverflow2)(void) = NULL;
void (*Global_FuncCTC0)(void) = NULL;
void (*Global_FuncCTC2)(void) = NULL;

/* Global Variables */

u16 Global_u16OverCount0 = 0;
u16 Global_u16OverCount2 = 0;

u16 Global_u16CTC0 = 0;
u16 Global_u16CTC2 = 0;

u8 Global_u8Preload = 0;

u16 Global_u16Counter = 0;

u8 Global_u8Timer0Flag;

u8 Global_u8Timer2Flag;

/* Implementation of APIs */

void MTIMER_voidInit(void){
	/* Clock Select */
	#if	  MTIMER_TIMER0_CLK == MTIMER_NO_CLOCK
	
	CLR_BIT(MTIMER_TCCR0, MTIMER_CS02);
	CLR_BIT(MTIMER_TCCR0, MTIMER_CS01);
	CLR_BIT(MTIMER_TCCR0, MTIMER_CS00);
	
	#elif MTIMER_TIMER0_CLK == MTIMER_SYS_CLOCK
	
	CLR_BIT(MTIMER_TCCR0, MTIMER_CS02);
	CLR_BIT(MTIMER_TCCR0, MTIMER_CS01);
	SET_BIT(MTIMER_TCCR0, MTIMER_CS00);
	
	#elif MTIMER_TIMER0_CLK == MTIMER_SYS_CLOCK_DIVIDED_BY_8
	
	CLR_BIT(MTIMER_TCCR0, MTIMER_CS02);
	SET_BIT(MTIMER_TCCR0, MTIMER_CS01);
	CLR_BIT(MTIMER_TCCR0, MTIMER_CS00);
	
	#elif MTIMER_TIMER0_CLK == MTIMER_SYS_CLOCK_DIVIDED_BY_64
	
	CLR_BIT(MTIMER_TCCR0, MTIMER_CS02);
	SET_BIT(MTIMER_TCCR0, MTIMER_CS01);
	SET_BIT(MTIMER_TCCR0, MTIMER_CS00);
	
	#elif MTIMER_TIMER0_CLK == MTIMER_SYS_CLOCK_DIVIDED_BY_256
	
	SET_BIT(MTIMER_TCCR0, MTIMER_CS02);
	CLR_BIT(MTIMER_TCCR0, MTIMER_CS01);
	CLR_BIT(MTIMER_TCCR0, MTIMER_CS00);
	
	#elif MTIMER_TIMER0_CLK == MTIMER_SYS_CLOCK_DIVIDED_BY_1024
	
	SET_BIT(MTIMER_TCCR0, MTIMER_CS02);
	CLR_BIT(MTIMER_TCCR0, MTIMER_CS01);
	SET_BIT(MTIMER_TCCR0, MTIMER_CS00);
	
	#elif MTIMER_TIMER0_CLK == MTIMER_EXTERNAL_FALLING
	
	SET_BIT(MTIMER_TCCR0, MTIMER_CS02);
	SET_BIT(MTIMER_TCCR0, MTIMER_CS01);
	CLR_BIT(MTIMER_TCCR0, MTIMER_CS00);
	
	#elif MTIMER_TIMER0_CLK == MTIMER_EXTERNAL_RISING
	
	SET_BIT(MTIMER_TCCR0, MTIMER_CS02);
	SET_BIT(MTIMER_TCCR0, MTIMER_CS01);
	SET_BIT(MTIMER_TCCR0, MTIMER_CS00);
	
	#else
		#error("Wrong Input to CLK Selection of Timer0")
	
	#endif
	
	#if	  MTIMER_TIMER2_CLK == MTIMER_NO_CLOCK
	
	CLR_BIT(MTIMER_TCCR2, MTIMER_CS22);
	CLR_BIT(MTIMER_TCCR2, MTIMER_CS21);
	CLR_BIT(MTIMER_TCCR2, MTIMER_CS20);
	
	#elif MTIMER_TIMER2_CLK == MTIMER_SYS_CLOCK
	
	CLR_BIT(MTIMER_TCCR2, MTIMER_CS22);
	CLR_BIT(MTIMER_TCCR2, MTIMER_CS21);
	SET_BIT(MTIMER_TCCR2, MTIMER_CS20);
	
	#elif MTIMER_TIMER2_CLK == MTIMER_SYS_CLOCK_DIVIDED_BY_8
	
	CLR_BIT(MTIMER_TCCR2, MTIMER_CS22);
	SET_BIT(MTIMER_TCCR2, MTIMER_CS21);
	CLR_BIT(MTIMER_TCCR2, MTIMER_CS20);
	
	#elif MTIMER_TIMER2_CLK == MTIMER_SYS_CLOCK_DIVIDED_BY_64
	
	CLR_BIT(MTIMER_TCCR2, MTIMER_CS22);
	SET_BIT(MTIMER_TCCR2, MTIMER_CS21);
	SET_BIT(MTIMER_TCCR2, MTIMER_CS20);
	
	#elif MTIMER_TIMER2_CLK == MTIMER_SYS_CLOCK_DIVIDED_BY_256
	
	SET_BIT(MTIMER_TCCR2, MTIMER_CS22);
	CLR_BIT(MTIMER_TCCR2, MTIMER_CS21);
	CLR_BIT(MTIMER_TCCR2, MTIMER_CS20);
	
	#elif MTIMER_TIMER2_CLK == MTIMER_SYS_CLOCK_DIVIDED_BY_1024
	
	SET_BIT(MTIMER_TCCR2, MTIMER_CS22);
	CLR_BIT(MTIMER_TCCR2, MTIMER_CS21);
	SET_BIT(MTIMER_TCCR2, MTIMER_CS20);
	
	#elif MTIMER_TIMER2_CLK == MTIMER_EXTERNAL_FALLING
	
	SET_BIT(MTIMER_TCCR2, MTIMER_CS22);
	SET_BIT(MTIMER_TCCR2, MTIMER_CS21);
	CLR_BIT(MTIMER_TCCR2, MTIMER_CS20);
	
	#elif MTIMER_TIMER2_CLK == MTIMER_EXTERNAL_RISING
	
	SET_BIT(MTIMER_TCCR2, MTIMER_CS22);
	SET_BIT(MTIMER_TCCR2, MTIMER_CS21);
	SET_BIT(MTIMER_TCCR2, MTIMER_CS20);
	
	#else
		#error("Wrong Input to CLK Selection of Timer2")
	
	#endif
	
	/* Selection Mode of Timer0 */
	
	#if MTIMER_TIMER0_MODE == MTIMER_NORMAL_MODE
	
	CLR_BIT(MTIMER_TCCR0, MTIMER_WGM01);
	CLR_BIT(MTIMER_TCCR0, MTIMER_WGM00);
	
	#elif MTIMER_TIMER0_MODE == MTIMER_PWM_PHASE_CORRECT
	
	CLR_BIT(MTIMER_TCCR0, MTIMER_WGM01);
	SET_BIT(MTIMER_TCCR0, MTIMER_WGM00);
	
	#if MTIMER_PPWM0_MODE == MTIMER_PPWM_NORMAL
	
	CLR_BIT(MTIMER_TCCR0, MTIMER_COM01);
	CLR_BIT(MTIMER_TCCR0, MTIMER_COM00);
	
	#elif MTIMER_PPWM0_MODE == MTIMER_PPWM_CUP_SDOWN
	
	SET_BIT(MTIMER_TCCR0, MTIMER_COM01);
	CLR_BIT(MTIMER_TCCR0, MTIMER_COM00);
	
	#elif MTIMER_PPWM0_MODE == MTIMER_PPWM_SUP_CDOWN
	
	SET_BIT(MTIMER_TCCR0, MTIMER_COM01);
	SET_BIT(MTIMER_TCCR0, MTIMER_COM00);
	
	#else 
		#error("Wrong Input to PPWM Mode of Timer0")
	#endif
	
	#elif MTIMER_TIMER0_MODE == MTIMER_CTC
	
	SET_BIT(MTIMER_TCCR0, MTIMER_WGM01);
	CLR_BIT(MTIMER_TCCR0, MTIMER_WGM00);
	
	#if MTIMER_CTC0_MODE == MTIMER_CTC_NORMAL
	
	CLR_BIT(MTIMER_TCCR0, MTIMER_COM01);
	CLR_BIT(MTIMER_TCCR0, MTIMER_COM00);
	
	#elif MTIMER_CTC0_MODE == MTIMER_CTC_TOGGLE
	
	CLR_BIT(MTIMER_TCCR0, MTIMER_COM01);
	SET_BIT(MTIMER_TCCR0, MTIMER_COM00);
	
	#elif MTIMER_CTC0_MODE == MTIMER_CTC_CLEAR
	
	SET_BIT(MTIMER_TCCR0, MTIMER_COM01);
	CLR_BIT(MTIMER_TCCR0, MTIMER_COM00);
	
	#elif MTIMER_CTC0_MODE == MTIMER_CTC_SET
	
	SET_BIT(MTIMER_TCCR0, MTIMER_COM01);
	SET_BIT(MTIMER_TCCR0, MTIMER_COM00);
	
	#else 
		#error("Wrong Input to selection Mode of CTC0")
	
	#endif
	
	#elif MTIMER_TIMER0_MODE == MTIMER_PWM_FAST
	
	SET_BIT(MTIMER_TCCR0, MTIMER_WGM01);
	SET_BIT(MTIMER_TCCR0, MTIMER_WGM00);
	
	#if MTIMER_FPWM0_MODE == MTIMER_FPWM_NORMAL
	
	CLR_BIT(MTIMER_TCCR0, MTIMER_COM01);
	CLR_BIT(MTIMER_TCCR0, MTIMER_COM00);
	
	#elif MTIMER_FPWM0_MODE == MTIMER_FPWM_NON_INVERTING
	
	SET_BIT(MTIMER_TCCR0, MTIMER_COM01);
	CLR_BIT(MTIMER_TCCR0, MTIMER_COM00);
	
	#elif MTIMER_FPWM0_MODE == MTIMER_FPWM_INVERTING
	
	SET_BIT(MTIMER_TCCR0, MTIMER_COM01);
	SET_BIT(MTIMER_TCCR0, MTIMER_COM00);
	
	#else
		#error("Wrong Input to selection Mode of Fast PWM0")
	
	#endif
	
	#else 
		#error("Wrong Input to Selection Mode of Timer0")
	
	#endif
	
	/****************************************************************/
	
	/* Selection Mode of Timer2 */
	
	#if MTIMER_TIMER2_MODE == MTIMER_NORMAL_MODE
	
	CLR_BIT(MTIMER_TCCR2, MTIMER_WGM21);
	CLR_BIT(MTIMER_TCCR2, MTIMER_WGM20);
	
	#elif MTIMER_TIMER2_MODE == MTIMER_PWM_PHASE_CORRECT
	
	CLR_BIT(MTIMER_TCCR2, MTIMER_WGM21);
	SET_BIT(MTIMER_TCCR2, MTIMER_WGM20);
	
	#if MTIMER_PPWM2_MODE == MTIMER_PPWM_NORMAL
	
	CLR_BIT(MTIMER_TCCR2, MTIMER_COM21);
	CLR_BIT(MTIMER_TCCR2, MTIMER_COM20);
	
	#elif MTIMER_PPWM2_MODE == MTIMER_PPWM_CUP_SDOWN
	
	SET_BIT(MTIMER_TCCR2, MTIMER_COM21);
	CLR_BIT(MTIMER_TCCR2, MTIMER_COM20);
	
	#elif MTIMER_PPWM2_MODE == MTIMER_PPWM_SUP_CDOWN
	
	SET_BIT(MTIMER_TCCR2, MTIMER_COM21);
	SET_BIT(MTIMER_TCCR2, MTIMER_COM20);
	
	#else 
		#error("Wrong Input to PPWM Mode of Timer2")
	#endif
	
	#elif MTIMER_TIMER2_MODE == MTIMER_CTC
	
	SET_BIT(MTIMER_TCCR2, MTIMER_WGM21);
	CLR_BIT(MTIMER_TCCR2, MTIMER_WGM20);
	
	#if MTIMER_CTC2_MODE == MTIMER_CTC_NORMAL
	
	CLR_BIT(MTIMER_TCCR2, MTIMER_COM21);
	CLR_BIT(MTIMER_TCCR2, MTIMER_COM20);
	
	#elif MTIMER_CTC2_MODE == MTIMER_CTC_TOGGLE
	
	CLR_BIT(MTIMER_TCCR2, MTIMER_COM21);
	SET_BIT(MTIMER_TCCR2, MTIMER_COM20);
	
	#elif MTIMER_CTC2_MODE == MTIMER_CTC_CLEAR
	
	SET_BIT(MTIMER_TCCR2, MTIMER_COM21);
	CLR_BIT(MTIMER_TCCR2, MTIMER_COM20);
	
	#elif MTIMER_CTC2_MODE == MTIMER_CTC_SET
	
	SET_BIT(MTIMER_TCCR2, MTIMER_COM21);
	SET_BIT(MTIMER_TCCR2, MTIMER_COM20);
	
	#else 
		#error("Wrong Input to selection Mode of CTC2")
	
	#endif
	
	#elif MTIMER_TIMER2_MODE == MTIMER_PWM_FAST
	
	SET_BIT(MTIMER_TCCR2, MTIMER_WGM21);
	SET_BIT(MTIMER_TCCR2, MTIMER_WGM20);
	#if MTIMER_FPWM2_MODE == MTIMER_FPWM_NORMAL
	
	CLR_BIT(MTIMER_TCCR2, MTIMER_COM21);
	CLR_BIT(MTIMER_TCCR2, MTIMER_COM20);
	
	#elif MTIMER_FPWM2_MODE == MTIMER_FPWM_NON_INVERTING
	
	SET_BIT(MTIMER_TCCR2, MTIMER_COM21);
	CLR_BIT(MTIMER_TCCR2, MTIMER_COM20);
	
	#elif MTIMER_FPWM2_MODE == MTIMER_FPWM_INVERTING
	
	SET_BIT(MTIMER_TCCR2, MTIMER_COM21);
	SET_BIT(MTIMER_TCCR2, MTIMER_COM20);
	
	#else
		#error("Wrong Input to selection Mode of Fast PWM2")
	
	#endif
	#else 
		#error("Wrong Input to Selection Mode of Timer2")
	
	#endif
	
	
}

u8 MTIMER_u8SetPreloadValue(u8 copy_u8TimerNo, u8 copy_u8Preload){
	/* Use This Function if there is Preload only */
	u8 Local_u8Error =0;
	if(Local_u8Error !=1){
		switch(copy_u8TimerNo){
			case MTIMER_TIMER0_OVERFLOW: MTIMER_TCNT0 = copy_u8Preload; Global_u8Preload = copy_u8Preload; break;
			case MTIMER_TIMER2_OVERFLOW: MTIMER_TCNT2 = copy_u8Preload; Global_u8Preload = copy_u8Preload; break;
			default: Local_u8Error = 1;
		}
	}
	else{Local_u8Error =1;}
	return Local_u8Error;
}

u8 MTIMER_u8SetCallBackOverflow(u8 copy_u8TimerNo, u16 copy_u16OverflowCount, void (*copy_voidFunc)(void)){
	u8 Local_u8Error = 0;
	Global_u8Timer0Flag = MTIMER_OVERFLOW_NO_POLLING;
	if(Local_u8Error != 1){
	switch(copy_u8TimerNo){
		case MTIMER_TIMER0_OVERFLOW: Global_FuncOverflow0 = copy_voidFunc; Global_u16OverCount0 = copy_u16OverflowCount; SET_BIT(MTIMER_TIMSK ,MTIMER_TIOE0); break;
		/*case MTIMER_TIMER1_OVERFLOW: Global_FuncOverflow1 = copy_voidFunc; Global_u16Preload1 = copy_u16Preload; break;*/
		case MTIMER_TIMER2_OVERFLOW: Global_FuncOverflow2 = copy_voidFunc; Global_u16OverCount2 = copy_u16OverflowCount; SET_BIT(MTIMER_TIMSK ,MTIMER_TOIE2); break;
		default: Local_u8Error = 1;
	}
	}
	else{
			Local_u8Error = 1;
	}
	return Local_u8Error;
}

u8 MTIMER_u8SetCallBackCTC(u8 copy_u8TimerNo, u16 copy_u16CompMatchCount, u8 copy_u8CompMatchValue, void (*copy_voidFunc)(void)){
	u8 Local_u8Error = 0;
	if(Local_u8Error != 1){
		
		switch(copy_u8TimerNo){
			case MTIMER_TIMER0_CTC: Global_FuncCTC0 = copy_voidFunc; Global_u16CTC0 = copy_u16CompMatchCount; MTIMER_OCR0 = copy_u8CompMatchValue; SET_BIT(MTIMER_TIMSK ,MTIMER_OCIE0);  break;
			case MTIMER_TIMER2_CTC: Global_FuncCTC2 = copy_voidFunc; Global_u16CTC2 = copy_u16CompMatchCount; MTIMER_OCR2 = copy_u8CompMatchValue; SET_BIT(MTIMER_TIMSK ,MTIMER_OCIE2); break;
			default: Local_u8Error = 1;
		}
	}
	else{
			Local_u8Error = 1;
	}
	return Local_u8Error;
	
	
	
}

u8 MTIMER_u8AnalogWrite(u8 copy_u8TimerNo, u8 copy_u8AnalogValue){
	u8 Local_u8Error = 0;
	if(Local_u8Error != 1){
		
		switch(copy_u8TimerNo){
			case MTIMER_TIMER0_FPWM:
				MTIMER_OCR0 = copy_u8AnalogValue;	
			
			break;
			case MTIMER_TIMER2_FPWM:
				MTIMER_OCR2 = copy_u8AnalogValue;


			break;
			case MTIMER_TIMER0_PHASE_CO:
				MTIMER_OCR0 = copy_u8AnalogValue;
			
			break;
			case MTIMER_TIMER2_PHASE_CO:
				MTIMER_OCR2 = copy_u8AnalogValue;
			
			break;
			default: Local_u8Error = 1;
			
		}
		
	}
	else {
		Local_u8Error = 1;
	}
	return Local_u8Error;
}

void MTIMER_voidDelay(u8 copy_u8TimerNo, u32 copy_u32MicroSecond){
	
	if(copy_u8TimerNo == MTIMER_TIMER0_OVERFLOW){
		
		Global_u8Timer0Flag = MTIMER_TIMER0_BUSY;
		/* Set Prescaler Divided by 8 */
		CLR_BIT(MTIMER_TCCR0, MTIMER_CS02);
		SET_BIT(MTIMER_TCCR0, MTIMER_CS01);
		CLR_BIT(MTIMER_TCCR0, MTIMER_CS00);
		/* Set Timer Mode to Normal Mode */
		CLR_BIT(MTIMER_TCCR0, MTIMER_WGM01);
		CLR_BIT(MTIMER_TCCR0, MTIMER_WGM00);
		/* Calculations */
		if(copy_u32MicroSecond == MTIMER_OVERFLOW_TIME_8BITS){
			
			Global_u16OverCount0 = 1;
		}
		else if(copy_u32MicroSecond > MTIMER_OVERFLOW_TIME_8BITS){
			
			Global_u16OverCount0 = (u16)(copy_u32MicroSecond / MTIMER_OVERFLOW_TIME_8BITS);
		}
		else{
			Global_u16OverCount0 = 1;
			Global_u8Preload = (u8) copy_u32MicroSecond;
			MTIMER_TCNT0 = Global_u8Preload;
		}
		/* Enable Interrupt */
		SET_BIT(MTIMER_TIMSK ,MTIMER_TIOE0);
		/* Polling (Busy Waiting) */
		while(Global_u16Counter != Global_u16OverCount0);
	}
	else if(copy_u8TimerNo == MTIMER_TIMER2_OVERFLOW){
		
		Global_u8Timer2Flag=MTIMER_TIMER2_BUSY;
		/* Set Prescaler Divided by 8 */
		CLR_BIT(MTIMER_TCCR2, MTIMER_CS22);
		SET_BIT(MTIMER_TCCR2, MTIMER_CS21);
		CLR_BIT(MTIMER_TCCR2, MTIMER_CS20);
		/* Set Timer Mode to Normal Mode */
		CLR_BIT(MTIMER_TCCR2, MTIMER_WGM21);
		CLR_BIT(MTIMER_TCCR2, MTIMER_WGM20);
		/* Calculations */
		if(copy_u32MicroSecond == MTIMER_OVERFLOW_TIME_8BITS){
			
			Global_u16OverCount2 = 1;
		}
		else if(copy_u32MicroSecond > MTIMER_OVERFLOW_TIME_8BITS){
			
			Global_u16OverCount2 = (u16)(copy_u32MicroSecond / MTIMER_OVERFLOW_TIME_8BITS);
		}
		else{
			Global_u16OverCount2 = 1;
			Global_u8Preload = (u8) copy_u32MicroSecond;
			MTIMER_TCNT2 = Global_u8Preload;
		}
		/* Enable Interrupt */
		SET_BIT(MTIMER_TIMSK , MTIMER_TOIE2);
		/* Polling (Busy Waiting) */
		while(Global_u16Counter != Global_u16OverCount2);
		
	}
	else{
		/* Do Nothing */
	}
}

/* ISR of TIMER0 Compare Match Point */
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void){
	static u16 Local_u16Counter = 0;
	Local_u16Counter++;
	if(Local_u16Counter == Global_u16CTC0){
	Local_u16Counter = 0;
	Global_FuncCTC0();
	
	}
	
}

/* ISR of TIMER2 Compare Match Point */
void __vector_4 (void) __attribute__((signal));
void __vector_4 (void){
	static u16 Local_u16Counter =0;
	Local_u16Counter++;
	if(Local_u16Counter == Global_u16CTC2){
		Global_FuncCTC2();
		Local_u16Counter = 0;
	}
}
/* ISR of TIMER0 Overflow */
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void){
	static u16 Local_u16Counter = 0;
	Local_u16Counter++;
	if(Global_u8Timer0Flag == MTIMER_TIMER0_BUSY){
		Global_u16Counter = Local_u16Counter;
		if(Local_u16Counter == Global_u16OverCount0){
			/* Do Nothing */
			Local_u16Counter =0;
			MTIMER_TCNT0 = Global_u8Preload;
	}
	}
	else{
		if(Local_u16Counter == Global_u16OverCount0){
			Global_FuncOverflow0();
			Local_u16Counter =0;
			MTIMER_TCNT0 = Global_u8Preload;
	}
	}
}


/* ISR of TIMER2 Overflow */
void __vector_5 (void) __attribute__((signal));
void __vector_5 (void){
	static u16 Local_u16Counter =0;
	Local_u16Counter++;
	if(Global_u8Timer2Flag == MTIMER_TIMER2_BUSY){
		Global_u16Counter = Local_u16Counter;
		if(Local_u16Counter == Global_u16OverCount2){
			Local_u16Counter = 0;
			/* Do Nothing */
			MTIMER_TCNT2 = Global_u8Preload;
	}
	else{
		if(Local_u16Counter == Global_u16OverCount2){
			Local_u16Counter = 0;
			Global_FuncOverflow2();
			MTIMER_TCNT2 = Global_u8Preload;
	}
	}
}
}


