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

#ifndef MSPI_CONFIG_H_
#define MSPI_CONFIG_H_

/* SPI Interrupt Enable/Disable */

/* Option:
	1- Enable		==> MSPI_ENABLE
	2- Disable		==> MSPI_DISABLE
*/

#define MSPI_INT_EN		MSPI_ENABLE

/* SPI Enable/Disable */

/* Option:
	1- Enable       ==> MSPI_ENABLE
	2- Disable      ==> MSPI_DISABLE
*/

#define MSPI_EN			MSPI_ENABLE

/* Order of First Transmitting Bit */

/* Option:
	1- LSB Transmitted First  ==> MSPI_LSB_FIRST
	2- MSB Transmitted First  ==> MSPI_MSB_FIRST
*/

#define MSPI_FIRST_BIT		MSPI_LSB_FIRST

/* Master/Slave Select */

/* Option:
	1- Master Select  ==> MSPI_MASTER
	2- Slave Select   ==> MSPI_SLAVE 
*/

#define MSPI_MODE_SELECT	MSPI_MASTER

/* Clock Polarity */

/*  Option:
	1- Idle is High		==> MSPI_IDLE_HIGH
	2- Idle is Low		==> MSPI_IDLE_LOW
*/

#define MSPI_IDLE_STATE		MSPI_IDLE_HIGH

/* Clock Phase */

/* Option:
	1- Transmit at Leading  ==> MSPI_TX_LEAD
	2- Receive at Leading   ==> MSPI_RX_LEAD
*/

#define MSPI_PHASE_SELECT	MSPI_TX_LEAD

/* Clock Rate Select at Master Mode */

/* Option:
	1- Divided by 4		==> MSPI_DIV_4		
	2- Divided by 16    ==> MSPI_DIV_16  
	3- Divided by 64    ==> MSPI_DIV_64  
	4- Divided by 128   ==> MSPI_DIV_128 
	5- Divided by 2     ==> MSPI_DIV_2   
	6- Divided by 8     ==> MSPI_DIV_8   
	7- Divided by 32    ==> MSPI_DIV_32  
	8- Divided by 64    ==> MSPI_DIV_64  
*/

#define MSPI_CLK_SELECT		MSPI_DIV_4

#endif