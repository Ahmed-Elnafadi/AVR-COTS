/************************************************************/
/************************************************************/
/********************* Driver : EXTI          ***************/
/********************* Layer  : MCAL          ***************/
/********************* Date   : 02 may 2022   ***************/
/********************* Version: V01           ***************/
/********************* Author : Ahmed Mostafa ***************/
/********************* Company: ROBO          ***************/
/************************************************************/
/************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MEXTI_interface.h"
#include "MEXTI_private.h"
#include "MEXTI_config.h"

/* Making Global Function */
void(* GlobalFunc0)(void);
void(* GlobalFunc1)(void);
void(* GlobalFunc2)(void);
/* Implementation of APIs */

void MEXTI_voidInit(void){

	/* GIE Control */
	#if MEXTI_GIE_CONTROL == MEXTI_ENABLE
		
		SET_BIT(MEXTI_SREG, MEXTI_I);
		
	#elif MEXTI_GIE_CONTROL == MEXTI_DISABLE
		
		CLR_BIT(MEXTI_SREG, MEXTI_I);
	#else
		#error("This Vlaue is out of range of the correct values.")
	#endif
	
	/* Sense for INT0 */
	#if MEXTI_INT0_SENSE == MEXTI_FALLING_EDGE
	SET_BIT(MEXTI_MCUCR, MEXTI_ISC01);
	CLR_BIT(MEXTI_MCUCR, MEXTI_ISC00);
	#elif MEXTI_INT0_SENSE == MEXTI_RISING_EDGE
	SET_BIT(MEXTI_MCUCR, MEXTI_ISC01);
	SET_BIT(MEXTI_MCUCR, MEXTI_ISC00);
	#elif MEXTI_INT0_SENSE == MEXTI_LOW_LEVEL
	CLR_BIT(MEXTI_MCUCR, MEXTI_ISC01);
	CLR_BIT(MEXTI_MCUCR, MEXTI_ISC00);
	#else 
		#error("This Vlaue is out of range of the correct values.")
	#endif
	
	/* Sense for INT1 */
	#if MEXTI_INT1_SENSE == MEXTI_FALLING_EDGE
	SET_BIT(MEXTI_MCUCR, MEXTI_ISC11);
	CLR_BIT(MEXTI_MCUCR, MEXTI_ISC10);
	#elif MEXTI_INT1_SENSE == MEXTI_RISING_EDGE
	SET_BIT(MEXTI_MCUCR, MEXTI_ISC11);
	SET_BIT(MEXTI_MCUCR, MEXTI_ISC10);
	#elif MEXTI_INT1_SENSE == MEXTI_LOW_LEVEL
	CLR_BIT(MEXTI_MCUCR, MEXTI_ISC11);
	CLR_BIT(MEXTI_MCUCR, MEXTI_ISC10);
	#else 
		#error("This Vlaue is out of range of the correct values.")
	#endif
	
	/* Sense for INT2 */
	
	#if MEXTI_INT2_SENSE == MEXTI_FALLING_EDGE
	CLR_BIT(MEXTI_MCUCSR, MEXTI_ISC2);
	#elif MEXTI_INT2_SENSE == MEXTI_RISING_EDGE
	SET_BIT(MEXTI_MCUCSR, MEXTI_ISC2);
	#else
		#error("This Vlaue is out of range of the correct values.")
	#endif
}
void MEXTI_voidEnableINT(u8 copy_u8INTValue){
	
	switch(copy_u8INTValue){
		
		case MEXTI_INT0_ENABLE: SET_BIT(MEXTI_GICR, MEXTI_INT0); break;
		case MEXTI_INT1_ENABLE: SET_BIT(MEXTI_GICR, MEXTI_INT1); break;
		case MEXTI_INT2_ENABLE: SET_BIT(MEXTI_GICR, MEXTI_INT2); break;
		default: /* Do Nothing */ 								 break;
		
	}
	
	
}
void MEXTI_voidExecuteFunctionInISR(void(*copy_pvoidFunc)(void), u8 copy_u8INTValue){
	
	switch(copy_u8INTValue){
		
		case MEXTI_INT0_PIN: GlobalFunc0 = copy_pvoidFunc; break;
		case MEXTI_INT1_PIN: GlobalFunc1 = copy_pvoidFunc; break;
		case MEXTI_INT2_PIN: GlobalFunc2 = copy_pvoidFunc; break;
		default: /* No thing */                        break;
	}
	
	
}

/* ISR for INT0 */

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void){
	
	GlobalFunc0();
	
}

/* ISR for INT1 */

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void){
	
	GlobalFunc1();
	
}

/* ISR for INT2 */

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void){
	
	GlobalFunc2();
	
}
