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

#ifndef MTIMER_INTERFACE_H_
#define MTIMER_INTERFACE_H_

/* Some Used Macros */

#define MTIMER_TIMER0_OVERFLOW	1
#define MTIMER_TIMER0_CTC		2
#define MTIMER_TIMER2_OVERFLOW	4
#define MTIMER_TIMER2_CTC		5
#define MTIMER_TIMER0_FPWM		6
#define MTIMER_TIMER0_PHASE_CO	7
#define MTIMER_TIMER2_FPWM		8
#define MTIMER_TIMER2_PHASE_CO	9
/* Definition of APIs */

void MTIMER_voidInit(void);
u8 MTIMER_u8SetPreloadValue(u8 copy_u8TimerNo, u8 copy_u8Preload);
u8 MTIMER_u8SetCallBackOverflow(u8 copy_u8TimerNo, u16 copy_u16OverflowCount, void (*copy_voidFunc)(void));
u8 MTIMER_u8SetCallBackCTC(u8 copy_u8TimerNo, u16 copy_u16CompMatchCount, u8 copy_u8CompMatchValue, void (*copy_voidFunc)(void));
u8 MTIMER_u8AnalogWrite(u8 copy_u8TimerNo, u8 copy_u8AnalogValue);
void MTIMER_voidDelay(u8 copy_u8TimerNo, u32 copy_u16MicroSecond);
#endif
