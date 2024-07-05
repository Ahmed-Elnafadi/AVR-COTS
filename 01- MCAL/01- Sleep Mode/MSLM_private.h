/************************************************************/
/************************************************************/
/********************* Driver : Sleep Mode    ***************/
/********************* Layer  : MCAL          ***************/
/********************* Date   : 01 may 2022   ***************/
/********************* Version: V01           ***************/
/********************* Author : Ahmed Mostafa ***************/
/********************* Company: ROBO          ***************/
/************************************************************/
/************************************************************/

/* Preprocessor File Guard */

#ifndef MSLM_PRIVATE_H_
#define MSLM_PRIVATE_H_

#define MSLM_MCUCR			*((volatile u8 *)0x55) /* Register used for controlling Sleep Modes in AVR */

#define MSLM_SE				7                      /* This must be enable if you want to choose any sleep Mode */

/* Those bits:
if  SM2   SM1  SM0    Sleep Mode
     0     0    0       Idle
	 0     0    1       ADC Noise Reduction
	 0     1    0       Power-Down
	 0	   1    1       Power-save
	 1     0    0       Reserved(Not used option)
     1     0    1       Reserved(Not used option)
	 1     1    0       Standby
	 1     1    1       Extended Standby
 */
#define MSLM_SM2			6
#define MSLM_SM1			5
#define MSLM_SM0			4
#endif