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

#ifndef MSLM_INTERFACE_H_
#define MSLM_INTERFACE_H_

void MSLM_voidSelectSleepMode(u8 copy_u8SleepMode);

/* Otions for that Function: */
#define MSLM_IDLE						0  /* Idle Mode */
#define MSLM_ADC_NOISE_REDUCTION		1  /* ADC Noise Reduction Mode */
#define MSLM_POWER_DOWN					2  /* Power Down Mode */
#define MSLM_POWER_SAVE					3  /* Power Save Mode */
#define MSLM_STANDBY					6  /* Standby Mode */
#define MSLM_EXTENDED_STANDBY			7  /* Extended Standby Mode */

#endif