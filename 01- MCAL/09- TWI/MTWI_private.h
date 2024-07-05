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

/* Preprocessor File Guard */

#ifndef MTWI_PRIVATE_H_
#define MTWI_PRIVATE_H_

/* Registers */

#define MTWI_TWBR		*((volatile u8*)0x20)

#define MTWI_TWCR		*((volatile u8*)0x56)

/* Bits of TWCR Register */
#define MTWI_TWIE		0
#define MTWI_TWEN		2
#define MTWI_TWWC		3
#define MTWI_TWSTO		4
#define MTWI_TWSTA		5
#define MTWI_TWEA		6
#define MTWI_TWINT		7

#define MTWI_TWSR		*((volatile u8*)0x21)

/* Bits of TWSR Register */
#define MTWI_TWPS0		0
#define MTWI_TWPS1		1
#define MTWI_TWS3		3
#define MTWI_TWS4		4
#define MTWI_TWS5		5
#define MTWI_TWS6		6
#define MTWI_TWS7		7

#define MTWI_TWDR		*((volatile u8*)0x23)
#define MTWI_TWAR		*((volatile u8*)0x22)

/* Declaration of Private Functions */

void MTWI_voidStart(void);  						/* Sending Start Condition */
void MTWI_voidFlagWait(void); 						/* Wating until certain part of frame sent */
u8 MTWI_u8CheckFramePart(void);						/* Checking for what is the part sent */
void MTWI_voidLoadFramePart(u8 copy_u8FramePart);	/* Send part of Frame */
void MTWI_voidStop(void);							/* Stop condition */
void MTWI_voidStartSend(void);				    	/* Start sending Frame Part */


/* Configuration Macros */

/* Macros for Program_c_ */
#define MTWI_START_CONDITION_RECEIVED		0x08
#define MTWI_REPEATED_START_CONDITION		0x10
#define MTWI_SLA_W_TRANSMITTED_ACK			0x18
#define MTWI_SLA_W_TRANSMITTED_NO_ACK		0x20
#define MTWI_DATA_TRANSMITTED_ACK			0x28
#define MTWI_DATA_TRANSMITTED_NO_ACK		0x30

#endif