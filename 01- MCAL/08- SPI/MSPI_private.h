/************************************************************/
/************************************************************/
/********************* Driver : SPI           ***************/
/********************* Layer  : MCAL          ***************/
/********************* Date   : 03 August 2022***************/
/********************* Version: V01           ***************/
/********************* Author : Ahmed Mostafa ***************/
/********************* Company: ROBO          ***************/
/************************************************************/
/************************************************************/

/* Preprocessor File Guard */

#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_

/* Register */

#define MSPI_SPCR			*((volatile u8*)0x2D)  /* SPI Control Register */

/* Bits of SPCR */
#define MSPI_SPR0			0
#define MSPI_SPR1			1
#define MSPI_CPHA			2
#define MSPI_CPOL			3
#define MSPI_MSTR			4
#define MSPI_DORD			5
#define MSPI_SPE			6
#define MSPI_SPIE			7

#define MSPI_SPSR			*((volatile u8*)0x2E)  /* SPI Status Register */

/* Bits of SPSR */
#define MSPI_SPI2X			0
#define MSPI_WCOL			6
#define MSPI_SPIF			7

#define MSPI_SPDR			*((volatile u8*)0x2F)  /* SPI Data Register */

/* Private Macros */

#define MSPI_ENABLE			0
#define MSPI_DISABLE		1

#define MSPI_LSB_FIRST		0
#define MSPI_MSB_FIRST		1

#define MSPI_MASTER			0
#define MSPI_SLAVE 			1

#define MSPI_IDLE_HIGH		0
#define MSPI_IDLE_LOW		1

#define MSPI_TX_LEAD		0
#define MSPI_RX_LEAD		1

#define MSPI_DIV_4			0
#define MSPI_DIV_16 		1
#define MSPI_DIV_64 		2
#define MSPI_DIV_128		3
#define MSPI_DIV_2  		4
#define MSPI_DIV_8  		5
#define MSPI_DIV_32 		6
#define MSPI_DIV_64 		7

#endif