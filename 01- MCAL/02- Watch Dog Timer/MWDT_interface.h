/************************************************************/
/************************************************************/
/********************* Driver : Watch Dog     ***************/
/********************* Layer  : MCAL          ***************/
/********************* Date   : 01 may 2022   ***************/
/********************* Version: V01           ***************/
/********************* Author : Ahmed Mostafa ***************/
/********************* Company: ROBO          ***************/
/************************************************************/
/************************************************************/

/* Preprocessor File Guard */

#ifndef MWDT_INTERFACE_H_
#define MWDT_INTERFACE_H_

void MWDT_voidEnableWatchDog(void);
void MWDT_voidDisableWatchDog(void);

/********************************************************** 
*this function is put on the beginning of each block of code.
*to prevent any bug or infinite loop.
***********************************************************/
void MWDT_voidSetWatchDogTimer(u8 copy_u8Time);  


                           /* If volt = 5v */    /* If volt  = 3.0v */
#define MWDT_TIME0		0  /* Timer = 16.3 ms */ /* Timer = 17.1 ms */
#define MWDT_TIME1      1  /* Timer = 32.5 ms */ /* Timer = 34.3 ms */
#define MWDT_TIME2		2  /* Timer = 65   ms */ /* Timer = 68.5 ms */
#define MWDT_TIME3		3  /* Timer = 0.13 s  */ /* Timer = 0.14 s  */
#define MWDT_TIME4		4  /* Timer = 0.26 s  */ /* Timer = 0.27 s  */
#define MWDT_TIME5      5  /* Timer = 0.52 s  */ /* Timer = 0.55 s  */
#define MWDT_TIME6		6  /* Timer = 1.0  s  */ /* Timer = 1.1  s  */
#define MWDT_TIME7		7  /* Timer = 2.1  s  */ /* Timer = 2.2  s  */

#endif