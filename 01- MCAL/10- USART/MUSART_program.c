/************************************************************/
/************************************************************/
/********************* Driver : USART         ***************/
/********************* Layer  : MCAL          ***************/
/********************* Date   : 30 JULY 2022  ***************/
/********************* Version: V01           ***************/
/********************* Author : Ahmed Mostafa ***************/
/********************* Company: ROBO          ***************/
/************************************************************/
/************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MUSART_interface.h"
#include "MUSART_config.h"
#include "MUSART_private.h"

/* Implementation of APIs */

void MUSART_voidInit(void){
	u8 Local_u8UCSRC = 0;

	/* Write BaudRate */
	MUSART_UCSRC = Local_u8UCSRC;
	/* Select 9600 BaudRate */
	CLR_BIT(MUSART_UCSRA, MUSART_U2X);
	MUSART_UBRRL = 51;
	
	/* UCSRC Select */
	SET_BIT(Local_u8UCSRC, MUSART_URSEL);
	
	/* USART Mode Select */
	#if   MUSART_MODE_SELECT == MUSART_ASYN
	
	CLR_BIT(Local_u8UCSRC, MUSART_UMSEL);
	
	/* Set UCPOL to Zero */
	CLR_BIT(Local_u8UCSRC, MUSART_UCPOL);
	
	#elif MUSART_MODE_SELECT == MUSART_SYN
	
	SET_BIT(Local_u8UCSRC, MUSART_UMSEL);
	
	/* Clock Select */
	#if   MUSART_CLK_POL == MUSART_TR_RF
	
	CLR_BIT(Local_u8UCSRC, MUSART_UCPOL);
	
	#elif MUSART_CLK_POL == MUSART_TF_RR
	
	SET_BIT(Local_u8UCSRC, MUSART_UCPOL);
	
	#else 
		#error("Wrong Input to Clock Polarity of USART")
	#endif
	/*****************/
	#else
		#error("Wrong Input to USART Mode Select")
	#endif
	/*****************/

	/* Parity Mode */
	#if   MUSART_PARITY_MODE == MUSART_PAR_DISABLED
	
	CLR_BIT(Local_u8UCSRC, MUSART_UPM1);
	CLR_BIT(Local_u8UCSRC, MUSART_UPM0);
	
	#elif MUSART_PARITY_MODE == MUSART_EVEN_PARITY
	
	SET_BIT(Local_u8UCSRC, MUSART_UPM1);
	CLR_BIT(Local_u8UCSRC, MUSART_UPM0);
	
	#elif MUSART_PARITY_MODE == MUSART_ODD_PARITY
	
	SET_BIT(Local_u8UCSRC, MUSART_UPM1);
	SET_BIT(Local_u8UCSRC, MUSART_UPM0);
	
	#else
		#error(" Wrong Input to Parity Mode ")
	#endif
	/******************/
	/* Stop Bit Setting */
	
	#if   MUSART_STOP_BIT == MUSART_ONE_STOP
	
	CLR_BIT(Local_u8UCSRC, MUSART_USBS);
	
	#elif MUSART_STOP_BIT == MUSART_TWO_STOP
	
	SET_BIT(Local_u8UCSRC, MUSART_USBS);
	
	#else
		#error(" Wrong Input to Stop Bit Selection ")
	#endif
	/*******************/
	/* Character Size */
	
	#if   MUSART_CH_SIZE == MUSART_5_BIT
	
	CLR_BIT(MUSART_UCSRB, MUSART_UCSZ2);
	CLR_BIT(Local_u8UCSRC, MUSART_UCSZ1);
	CLR_BIT(Local_u8UCSRC, MUSART_UCSZ0);
	
	#elif MUSART_CH_SIZE == MUSART_6_BIT
	
	CLR_BIT(MUSART_UCSRB, MUSART_UCSZ2);
	CLR_BIT(Local_u8UCSRC, MUSART_UCSZ1);
	SET_BIT(Local_u8UCSRC, MUSART_UCSZ0);
	
	#elif MUSART_CH_SIZE == MUSART_7_BIT
	
	CLR_BIT(MUSART_UCSRB, MUSART_UCSZ2);
	SET_BIT(Local_u8UCSRC, MUSART_UCSZ1);
	CLR_BIT(Local_u8UCSRC, MUSART_UCSZ0);
	
	#elif MUSART_CH_SIZE == MUSART_8_BIT
	
	CLR_BIT(MUSART_UCSRB, MUSART_UCSZ2);
	SET_BIT(Local_u8UCSRC, MUSART_UCSZ1);
	SET_BIT(Local_u8UCSRC, MUSART_UCSZ0);
	
	#elif MUSART_CH_SIZE == MUSART_9_BIT
	
	SET_BIT(MUSART_UCSRB, MUSART_UCSZ2);
	SET_BIT(Local_u8UCSRC, MUSART_UCSZ1);
	SET_BIT(Local_u8UCSRC, MUSART_UCSZ0);
	
	#else
		#error(" Wrong Input to Character Size Select in USART ")
	#endif
	MUSART_UCSRC = Local_u8UCSRC;

	/* Transmitter Enable */
	SET_BIT(MUSART_UCSRB, MUSART_TXEN);

	/* Receiver Enable */
	SET_BIT(MUSART_UCSRB, MUSART_RXEN);

}
/*********************************************/

void MUSART_voidTransmit(u8 copy_u8Data){
	/*Polling until TXB is empty*/
	while(GET_BIT(MUSART_UCSRA, MUSART_UDRE)==0);
	
	/* Data that Sent serially on TX Pin */
	MUSART_UDR_TXB = copy_u8Data;
	
	/* Polling until Sending Data */
	while(GET_BIT(MUSART_UCSRA, MUSART_TXC) == 0);
	
	/* Clear TXC Flag */
	SET_BIT(MUSART_UCSRA, MUSART_TXC);
}
/**********************************************/

u8  MUSART_u8Recieve(void){
	u8 Local_u8Result;
	/* Polling Until Recieving All Data */
	while(GET_BIT(MUSART_UCSRA, MUSART_RXC) == 0);
	Local_u8Result = MUSART_UDR_RXB;

	/* Clear Flag */

	SET_BIT(MUSART_UCSRA, MUSART_RXC);
	/* Read Data from Register */
	return Local_u8Result;
}
