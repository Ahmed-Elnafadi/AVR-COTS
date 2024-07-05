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

/* Preprocessor File Guard */

#ifndef MUSART_PRIVATE_H_
#define MUSART_PRIVATE_H_

/* Registers of USART */

#define MUSART_UDR_TXB		*((volatile u8*)0x2C)
#define MUSART_UDR_RXB		*((volatile u8*)0x2C)
#define MUSART_UCSRA		*((volatile u8*)0x2B)
/* Bits of UCSRA */
#define MUSART_MPCM			0
#define MUSART_U2X			1
#define MUSART_PE			2
#define MUSART_DOR			3
#define MUSART_FE			4
#define MUSART_UDRE			5
#define MUSART_TXC			6
#define MUSART_RXC			7


#define MUSART_UCSRB		*((volatile u8*)0x2A)
/* Bits of UCSRB */
#define MUSART_TXB8			0
#define MUSART_RXB8			1
#define MUSART_UCSZ2		2
#define MUSART_TXEN			3
#define MUSART_RXEN			4
#define MUSART_UDRIE		5
#define MUSART_TXCIE		6
#define MUSART_RXCIE		7

#define MUSART_UBRRL		*((volatile u8*)0x29)
#define MUSART_UCSRC		*((volatile u8*)0x40)
/* Bits of UCSRC */
#define MUSART_UCPOL		0
#define MUSART_UCSZ0		1
#define MUSART_UCSZ1		2
#define MUSART_USBS			3
#define MUSART_UPM0			4
#define MUSART_UPM1			5
#define MUSART_UMSEL		6
#define MUSART_URSEL		7

#define MUSART_UBRRH		*((volatile u8*)0x40)

/* Some Macros */

#define MUSART_ASYN				1
#define MUSART_SYN				2

#define MUSART_PAR_DISABLED		1
#define MUSART_EVEN_PARITY		2
#define MUSART_ODD_PARITY		3

#define MUSART_ONE_STOP			1
#define MUSART_TWO_STOP			2

#define MUSART_5_BIT			1
#define MUSART_6_BIT			2
#define MUSART_7_BIT			3
#define MUSART_8_BIT			4
#define MUSART_9_BIT			5

#define MUSART_TR_RF			1
#define MUSART_TF_RR			2
#endif