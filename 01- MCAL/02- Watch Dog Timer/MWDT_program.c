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

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MWDT_interface.h"
#include "MWDT_private.h"
#include "MWDT_config.h"
/* Include driver of Timer when it is prepared */

/* Implementaion of APIs */

void MWDT_voidEnableWatchDog(void){
/* Enable Watch-Dog-Timer:
*By Set Bit WDE (Watch Dog Enable)
*in WDTCR Register.
**********************************/
	SET_BIT(MWDT_WDTCR, MWDT_WDE);
}


void MWDT_voidDisableWatchDog(void){
/* Disable Watch-Dog-Timer:
*By Set Bit WDTOE and WDE.
*Then wait for 4 clock cycle.
*Then Clear WDE Bit. 
**********************************/
	MWDT_WDTCR |= 0b00011000;
	/* Wait 4 cycles or 2.5 microsecond */
	MWDT_WDTCR = 0;
}
void MWDT_voidSetWatchDogTimer(u8 copy_u8Time){
	
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
	
	/* Writing Zero to The watch Dog Flag */
	CLR_BIT(MWDT_MCUCSR, MWDT_WDRF);
	switch(copy_u8Time){
		
		case MWDT_TIME0:	MWDT_WDTCR = 0x04; break;
		case MWDT_TIME1:	MWDT_WDTCR = 0x05; break;
		case MWDT_TIME2:	MWDT_WDTCR = 0x06; break;
		case MWDT_TIME3:	MWDT_WDTCR = 0x07; break;
		case MWDT_TIME4:	MWDT_WDTCR = 0x08; break;
		case MWDT_TIME5:	MWDT_WDTCR = 0x09; break;
		case MWDT_TIME6:	MWDT_WDTCR = 0x0A; break;
		case MWDT_TIME7:	MWDT_WDTCR = 0X0B; break;
		default: /* Do Nothing*/               break;
	}                 
	
}