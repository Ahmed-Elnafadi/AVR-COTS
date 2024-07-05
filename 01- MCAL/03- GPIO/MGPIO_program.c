/************************************************************/
/************************************************************/
/********************* Driver : GPIO          ***************/
/********************* Layer  : MCAL          ***************/
/********************* Date   : 01 may 2022   ***************/
/********************* Version: V01           ***************/
/********************* Author : Ahmed Mostafa ***************/
/********************* Company: ROBO          ***************/
/************************************************************/
/************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MGPIO_interface.h"
#include "MGPIO_private.h"
#include "MGPIO_config.h"

/* Implementation of APIs */

void MGPIO_voidSetPinDirection(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8PinDirection){
	
	switch(copy_u8Port){
		
		case MGPIO_PORTA:
			if(copy_u8PinDirection == MGPIO_INPUT){
				CLR_BIT(MGPIO->DDRA, copy_u8Pin);
			}
			else if(copy_u8PinDirection == MGPIO_OUTPUT){
				SET_BIT(MGPIO->DDRA, copy_u8Pin);
			}break;

		case MGPIO_PORTB:
			if(copy_u8PinDirection == MGPIO_INPUT){
				CLR_BIT(MGPIO->DDRB, copy_u8Pin);
			}
			else if(copy_u8PinDirection == MGPIO_OUTPUT){
				SET_BIT(MGPIO->DDRB, copy_u8Pin);
			}break;

		case MGPIO_PORTC:
			if(copy_u8PinDirection == MGPIO_INPUT){
				CLR_BIT(MGPIO->DDRC, copy_u8Pin);
			}
			else if(copy_u8PinDirection == MGPIO_OUTPUT){
				SET_BIT(MGPIO->DDRC, copy_u8Pin);
			}break;

		case MGPIO_PORTD:
			if(copy_u8PinDirection == MGPIO_INPUT){
				CLR_BIT(MGPIO->DDRD, copy_u8Pin);
			}
			else if(copy_u8PinDirection == MGPIO_OUTPUT){
				SET_BIT(MGPIO->DDRD, copy_u8Pin);
			}break;
		default: /* Do Nothing */ break;
	}
	
}
void MGPIO_voidSetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8PinValue){


	switch(copy_u8Port){
		
		case MGPIO_PORTA:
			if(copy_u8PinValue == MGPIO_LOW){
				CLR_BIT(MGPIO->PORTA, copy_u8Pin);
			}
			else if(copy_u8PinValue == MGPIO_HIGH){
				SET_BIT(MGPIO->PORTA, copy_u8Pin);
			}break;
		
		case MGPIO_PORTB:
			if(copy_u8PinValue == MGPIO_LOW){
				CLR_BIT(MGPIO->PORTB, copy_u8Pin);
			}
			else if(copy_u8PinValue == MGPIO_HIGH){
				SET_BIT(MGPIO->PORTB, copy_u8Pin);
			}break;
		
		case MGPIO_PORTC:
			if(copy_u8PinValue == MGPIO_LOW){
				CLR_BIT(MGPIO->PORTC, copy_u8Pin);
			}
			else if(copy_u8PinValue == MGPIO_HIGH){
				SET_BIT(MGPIO->PORTC, copy_u8Pin);
			}break;
		
		case MGPIO_PORTD:
			if(copy_u8PinValue == MGPIO_LOW){
				CLR_BIT(MGPIO->PORTD, copy_u8Pin);
			}
			else if(copy_u8PinValue == MGPIO_HIGH){
				SET_BIT(MGPIO->PORTD, copy_u8Pin);
			}break;
		default: /* Do Nothing */ break;
	}
	
}
void MGPIO_voidSetPortDirection(u8 copy_u8Port, u8 copy_u8PortDirection){

	if(copy_u8PortDirection<= 0xFF){
		switch(copy_u8Port){
			
			case MGPIO_PORTA: MGPIO->DDRA = copy_u8PortDirection; break;
			
			case MGPIO_PORTB: MGPIO->DDRB = copy_u8PortDirection; break;
			
			case MGPIO_PORTC: MGPIO->DDRC = copy_u8PortDirection; break;
			
			case MGPIO_PORTD: MGPIO->DDRD = copy_u8PortDirection; break;
			default: /* Do Nothing */ break;
		}	
	}
	else{
		/* Error */
	}
}
void MGPIO_voidSetPortValue(u8 copy_u8Port, u8 copy_u8PortValue){
	if(copy_u8PortValue<= 0xFF){
		switch(copy_u8Port){
			
			case MGPIO_PORTA: MGPIO->PORTA = copy_u8PortValue; break;
			
			case MGPIO_PORTB: MGPIO->PORTB = copy_u8PortValue; break;
			
			case MGPIO_PORTC: MGPIO->PORTC = copy_u8PortValue; break;
			
			case MGPIO_PORTD: MGPIO->PORTD = copy_u8PortValue; break;
			default: /* Do Nothing */ break;
		}	
	}
	else{
		/* Error */
	}
	
}

u8 MGPIO_u8GetPinValue(u8 copy_u8Port, u8 copy_u8Pin){

	u8 Local_u8Variable;
	switch(copy_u8Port){
		
		case MGPIO_PORTA: Local_u8Variable= GET_BIT(MGPIO->PINA, copy_u8Pin); break;
		
		case MGPIO_PORTB: Local_u8Variable= GET_BIT(MGPIO->PINB, copy_u8Pin); break;
		
		case MGPIO_PORTC: Local_u8Variable= GET_BIT(MGPIO->PINC, copy_u8Pin); break;
		
		case MGPIO_PORTD: Local_u8Variable= GET_BIT(MGPIO->PIND, copy_u8Pin); break;
		default: /* Do Nothing */ break;
	}	
	return Local_u8Variable;
}

void MGPIO_voidEnableInternalPullUp(void){
	
	CLR_BIT(MGPIO_SFIOR, GPIO_PUD);
}
void MGPIO_voidDisableInternalPullUp(void){
	
	SET_BIT(MGPIO_SFIOR, GPIO_PUD);
}
