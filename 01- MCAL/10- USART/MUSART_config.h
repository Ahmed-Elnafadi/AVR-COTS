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

#ifndef MUSART_CONFIG_H_
#define MUSART_CONFIG_H_

/* USART Mode Select */
/* Option:
	1- Asynnchronous Operation		==> MUSART_ASYN
	2- Synchronous Operation		==> MUSART_SYN
*/

#define MUSART_MODE_SELECT		MUSART_ASYN


/* Select Clock Polarity */
/* Option:
	1- Transmit at Rising, Received at Falling		==> MUSART_TR_RF	
	2- Transmit at Falling, Received at Rising		==> MUSART_TF_RR
*/

#define MUSART_CLK_POL			MUSART_TR_RF


/* Parity Mode */
/* Option:
	1- Disabled						==> MUSART_PAR_DISABLED
	2- Enabled Even Parity			==> MUSART_EVEN_PARITY
	3- Enabled Odd Parity			==> MUSART_ODD_PARITY
*/

#define MUSART_PARITY_MODE		MUSART_PAR_DISABLED

/* Stop Bit Setting */
/* Option:
	1- 1_Bit						==> MUSART_ONE_STOP
	2- 2_Bit						==> MUSART_TWO_STOP
*/

#define MUSART_STOP_BIT			MUSART_ONE_STOP

/* Character Size */
/* Option:
	1- 5_Bit						==> MUSART_5_BIT
	2- 6_Bit                        ==> MUSART_6_BIT
	3- 7_Bit                        ==> MUSART_7_BIT
	4- 8_Bit                        ==> MUSART_8_BIT
	5- 9_Bit                        ==> MUSART_9_BIT
*/

#define MUSART_CH_SIZE			MUSART_8_BIT

#endif
