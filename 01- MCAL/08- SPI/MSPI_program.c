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

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MSPI_interface.h"
#include "MSPI_private.h"
#include "MSPI_config.h"

/* Implementation of APIs */

void MSPI_voidInit(void){
	/* SPI Interrupt Enable/Disable */
	#if MSPI_INT_EN == MSPI_ENABLE
		SET_BIT(MSPI_SPCR, MSPI_SPIE);
	#elif MSPI_INT_EN == MSPI_DISABLE
		CLR_BIT(MSPI_SPCR, MSPI_SPIE);
	#else
		#error("Wrong Input to Interrupt Enable")
	#endif
	
	/* Order of First Transmitting Bit */
	#if MSPI_FIRST_BIT == MSPI_LSB_FIRST
		SET_BIT(MSPI_SPCR, MSPI_DORD);
	#elif MSPI_FIRST_BIT == MSPI_MSB_FIRST
		CLR_BIT(MSPI_SPCR, MSPI_DORD);
	#else
		#error("Wrong Input to Transmission Data in SPI")
	#endif
	
	/* Master/Slave Select */
	#if MSPI_MODE_SELECT == MSPI_MASTER
		SET_BIT(MSPI_SPCR, MSPI_MSTR);
		/* Clock Rate Select at Master Mode */
		#if   MSPI_CLK_SELECT == MSPI_DIV_4
			CLR_BIT(MSPI_SPSR,MSPI_SPI2X);
			CLR_BIT(MSPI_SPCR, MSPI_SPR1);
			CLR_BIT(MSPI_SPCR, MSPI_SPR0);
		#elif MSPI_CLK_SELECT == MSPI_DIV_16
			CLR_BIT(MSPI_SPSR,MSPI_SPI2X);
			CLR_BIT(MSPI_SPCR, MSPI_SPR1);
			SET_BIT(MSPI_SPCR, MSPI_SPR0);
		#elif MSPI_CLK_SELECT == MSPI_DIV_64
			CLR_BIT(MSPI_SPSR,MSPI_SPI2X);
			SET_BIT(MSPI_SPCR, MSPI_SPR1);
			CLR_BIT(MSPI_SPCR, MSPI_SPR0);
		#elif MSPI_CLK_SELECT == MSPI_DIV_128
			CLR_BIT(MSPI_SPSR,MSPI_SPI2X);
			SET_BIT(MSPI_SPCR, MSPI_SPR1);
			SET_BIT(MSPI_SPCR, MSPI_SPR0);
		#elif MSPI_CLK_SELECT == MSPI_DIV_2
			SET_BIT(MSPI_SPSR,MSPI_SPI2X);
			CLR_BIT(MSPI_SPCR, MSPI_SPR1);
			CLR_BIT(MSPI_SPCR, MSPI_SPR0);
		#elif MSPI_CLK_SELECT == MSPI_DIV_8
			SET_BIT(MSPI_SPSR,MSPI_SPI2X);
			CLR_BIT(MSPI_SPCR, MSPI_SPR1);
			SET_BIT(MSPI_SPCR, MSPI_SPR0);
		#elif MSPI_CLK_SELECT == MSPI_DIV_32
			SET_BIT(MSPI_SPSR,MSPI_SPI2X);
			SET_BIT(MSPI_SPCR, MSPI_SPR1);
			CLR_BIT(MSPI_SPCR, MSPI_SPR0);
		#elif MSPI_CLK_SELECT == MSPI_DIV_64
			SET_BIT(MSPI_SPSR,MSPI_SPI2X);
			SET_BIT(MSPI_SPCR, MSPI_SPR1);
			SET_BIT(MSPI_SPCR, MSPI_SPR0);
		#else
			#error("Wrong Input to CLK Select of Master")
		#endif
	#elif MSPI_MODE_SELECT == MSPI_SLAVE
		CLR_BIT(MSPI_SPCR, MSPI_MSTR);
	#else
		#error("Wrong Input to Master/slave Select in SPI")
	#endif
	
	/* Clock Polarity */
	#if MSPI_IDLE_STATE == MSPI_IDLE_HIGH
		SET_BIT(MSPI_SPCR, MSPI_CPOL);
	#elif MSPI_IDLE_STATE == MSPI_IDLE_LOW
		CLR_BIT(MSPI_SPCR, MSPI_CPOL);
	#else
		#error("Wrong Input to CLK Polarity in SPI")
	#endif
	
	/* Clock Phase */
	#if MSPI_PHASE_SELECT == MSPI_TX_LEAD
		SET_BIT(MSPI_SPCR, MSPI_CPHA);
	#elif MSPI_PHASE_SELECT == MSPI_RX_LEAD
		CLR_BIT(MSPI_SPCR, MSPI_CPHA);
	#else
		#error("Wrong Input to Phase CLK of SPI")
	#endif
	
	/* SPI Enable/Disable */
	#if MSPI_EN == MSPI_ENABLE
		SET_BIT(MSPI_SPCR, MSPI_SPE);
	#elif MSPI_EN == MSPI_DISABLE
		CLR_BIT(MSPI_SPCR, MSPI_SPE);
	#else
		#error("Wrong Input to SPI Enable")
	#endif
}
u8 MSPI_u8Transceiver(u8 copy_u8Data){
	u8 Local_u8Read;
	MSPI_SPDR = copy_u8Data;
	while(GET_BIT(MSPI_SPSR, MSPI_SPIF)==0);
	Local_u8Read = MSPI_SPDR;
	return Local_u8Read;
}
