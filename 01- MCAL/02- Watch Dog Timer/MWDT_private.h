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

#ifndef MWDT_PRIVATE_H_
#define MWDT_PRIVATE_H_

#define MWDT_WDTCR			*((volatile u8*)0x41)
#define MWDT_MCUCSR			*((volatile u8*)0x54)

#define MWDT_WDTOE				4  /* Used for Disable WDT */
#define MWDT_WDE				3  /* Used for enabling and disabling WDT */

/* Options:
*   MCU operates on 5v:

		WDP2    WDP1    WDP0     Time to reset MCU
		 0       0       0           16.3 ms
		 0       0       1           32.5 ms
		 0       1       0           65   ms
		 0       1       1           0.13 s
		 1       0       0           0.26 s
		 1       0       1           0.52 s
		 1       1       0           1.0  s
		 1       1       1           2.1  s

*   MCU operates on 3v:

		WDP2    WDP1    WDP0     Time to reset MCU
		 0       0       0           17.1 ms
		 0       0       1           34.3 ms
		 0       1       0           68.5 ms
		 0       1       1           0.14 s
		 1       0       0           0.27 s
		 1       0       1           0.55 s
		 1       1       0           1.1  s
		 1       1       1           2.2  s
*/
#define MWDT_WDP2				2
#define MWDT_WDP1				1
#define MWDT_WDP0				0
#define MWDT_WDRF				3  /* Watch Dog Timer Flag is set to one when watch reset occur */

#endif