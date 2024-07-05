/************************************************************/
/************************************************************/
/********************* Driver : TWI           ***************/
/********************* Layer  : MCAL          ***************/
/********************* Date   : 12 AUGUST 2022***************/
/********************* Version: V01           ***************/
/********************* Author : Ahmed Mostafa ***************/
/********************* Company: ROBO          ***************/
/************************************************************/
/************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MTWI_interface.h"
#include "MTWI_private.h"
#include "MTWI_config.h"

/* Implementation of APIs */

void MTWI_voidInit(void){
	
	/* Set Data Rate 400 kbps */
	CLR_BIT(MTWI_TWSR, MTWI_TWPS1);
	CLR_BIT(MTWI_TWSR, MTWI_TWPS0);
	MTWI_TWBR = 2;
	
	/* Enable Acknowledge Bit */
	
	SET_BIT(MTWI_TWCR, MTWI_TWEA);
	
	/* Enable TWI */
	SET_BIT(MTWI_TWCR, MTWI_TWEN);
	
}
u8 MTWI_voidSendFrame(u8 copy_u8SLA, u8 copy_u8Data){
	u8 Local_u8Error = 0;
	u8 Local_u8Checker = '';
	
	/* Send Start Condition */
	MTWI_voidStart();
	
	/* Waiting until Send */
	MTWI_voidFlagWait();
	
	/* Start Sending */
	MTWI_voidStartSend();
	/* Check for Start Condition */
	Local_u8Checker = MTWI_u8CheckFramePart();
	
	if(Local_u8Checker == 'S'){
		
		/* Load SLA+W */
		MTWI_voidLoadFramePart(copy_u8SLA);
		
		/* Start Sending */
		MTWI_voidStartSend();
		
		/* Waiting until Send */
		MTWI_voidFlagWait();
		
		/* Check for Sending SLA+W */
		Local_u8Checker = MTWI_u8CheckFramePart();
		if(Local_u8Checker == 'A'){
			
			/* Load Data */
			MTWI_voidLoadFramePart(copy_u8Data);
			
			/* Start Sending */
			MTWI_voidStartSend();
			
			/* Waiting until Send */
			MTWI_voidFlagWait();
			
			/* Check for sending Data */
			Local_u8Checker = MTWI_u8CheckFramePart();
			if(Local_u8Checker == 'D'){
				
				/* Send Stop Condition */
				MTWI_voidStop();
				
				/* Start Sending */
				MTWI_voidStartSend();
				
				/* Waiting until Send */
				MTWI_voidFlagWait();
			}
			else{
				Local_u8Error = 1;
				return Local_u8Error;
			}
		}
		else{
			Local_u8Error = 1;
			return Local_u8Error;
		}
		
	}
	else{
		Local_u8Error = 1;
		return Local_u8Error;
	}
	
	/* CLR TWSTA */
	CLR_BIT(MTWI_TWCR, MTWI_TWSTA);
	
}
void MTWI_voidSetSLA(u8 copy_u8SLA){
	
	MTWI_TWAR = copy_u8SLA<<1;
	
}

/* Implementation of Private Functions */

void MTWI_voidStart(void){
	
	/* Start Condition */
	SET_BIT(MTWI_TWCR, MTWI_TWSTA);
} 				
void MTWI_voidFlagWait(void){
	
	/* Waiting until Operation ends */
	while(GET_BIT(MTWI_TWCR, MTWI_TWINT)==0);	
} 				
u8 MTWI_u8CheckFramePart(void){
	
	u8 Localu8Operation = '';
	
	/* Check for conditions */
	switch((MTWI_TWSR & 0xF8)){
		case MTWI_START_CONDITION_RECEIVED:	Localu8Operation = 'S'; break;
		case MTWI_REPEATED_START_CONDITION: Localu8Operation = 'R'; break;	
		case MTWI_SLA_W_TRANSMITTED_ACK	  :	Localu8Operation = 'A'; break;
		case MTWI_SLA_W_TRANSMITTED_NO_ACK: Localu8Operation = 'N'; break;
		case MTWI_DATA_TRANSMITTED_ACK	  : Localu8Operation = 'D'; break;
		case MTWI_DATA_TRANSMITTED_NO_ACK : Localu8Operation = 'X'; break;
		default: Localu8Operation = 'E';
	}
	return Localu8Operation;
}				
void MTWI_voidLoadFramePart(u8 copy_u8FramePart){
	MTWI_TWDR = copy_u8FramePart;
	
}	
void MTWI_voidStop(void){
	
	/* Stop Condition */
	SET_BIT(MTWI_TWCR, MTWI_TWSTO);
	
}					
void MTWI_voidStartSend(void){
	
	/* Start Next Operaion */
	SET_BIT(MTWI_TWCR, MTWI_TWINT);
}		