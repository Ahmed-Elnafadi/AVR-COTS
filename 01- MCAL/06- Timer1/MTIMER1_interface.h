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

#ifndef MTIMER1_INTERFACE_H_
#define MTIMER1_INTERFACE_H_

/*Used Macros for Input Arguments of APIs*/

#define MTIMER1_CHANNEL_A		1
#define MTIMER1_CHANNEL_B		2

#define MTIMER1_RISING			1
#define MTIMER1_FALLING			2

#define MTIMER1_INT_ENABLE		1
#define MTIMER1_INT_DISABLE		2

/* APIs */

void MTIMER1_voidInit(void);
u8 MTIMER1_u8SetPreloadValue(u16 copy_u16Preload);
u8 MTIMER1_u8SetCallBackOverflow(u16 copy_u16OverflowCount, void (*copy_voidFunc)(void));
u8 MTIMER1_u8SetCallBackCTC(u8 copy_u8TimerChannel, u16 copy_u16CompMatchCount, u8 copy_u8CompMatchValue, void (*copy_voidFunc)(void));
u8 MTIMER1_u8AnalogWrite(u8 copy_u8TimerChannel, u8 copy_u8AnalogValue);
void MTIMER1_voidDelay(u32 copy_u16MicroSecond);
void ICU_voidInit(void);
void ICU_voidInterrupt(u8 copy_u8State);
u16 ICU_u16TimeRead(void);
void ICU_voidEdgeChange(u8 copy_u8Edge);


#endif