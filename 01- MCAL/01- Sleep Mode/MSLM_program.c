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

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MSLM_interface.h"
#include "MSLM_private.h"
#include "MSLM_config.h"

/* Implementation Of APIs */

void MSLM_voidSelectSleepMode(u8 copy_u8SleepMode){
	
	/* Enabling SE Bit */
	SET_BIT(MSLM_MCUCR ,MSLM_SE);
	
	switch(copy_u8SleepMode){
		
		case MSLM_IDLE:  				CLR_BIT(MSLM_MCUCR, MSLM_SM2);
										CLT_BIT(MSLM_MCUCR, MSLM_SM1);
										CLR_BIT(MSLM_MCUCR, MSLM_SM0);break;

		case MSLM_ADC_NOISE_REDUCTION:  CLR_BIT(MSLM_MCUCR, MSLM_SM2);
										CLT_BIT(MSLM_MCUCR, MSLM_SM1);
										SET_BIT(MSLM_MCUCR, MSLM_SM0);break;

		case MSLM_POWER_DOWN:  			CLR_BIT(MSLM_MCUCR, MSLM_SM2);
										SET_BIT(MSLM_MCUCR, MSLM_SM1);
										CLR_BIT(MSLM_MCUCR, MSLM_SM0);break;

		case MSLM_POWER_SAVE:  			CLR_BIT(MSLM_MCUCR, MSLM_SM2);
										SET_BIT(MSLM_MCUCR, MSLM_SM1);
										SET_BIT(MSLM_MCUCR, MSLM_SM0);break;
						 
		case MSLM_STANDBY:  			SET_BIT(MSLM_MCUCR, MSLM_SM2);
										SET_BIT(MSLM_MCUCR, MSLM_SM1);
										CLR_BIT(MSLM_MCUCR, MSLM_SM0);break;

		case MSLM_EXTENDED_STANDBY:  	SET_BIT(MSLM_MCUCR, MSLM_SM2);
										SET_BIT(MSLM_MCUCR, MSLM_SM1);
										SET_BIT(MSLM_MCUCR, MSLM_SM0);break;
										
		default: /* Do noting */ break;
		
	}
	
	
}