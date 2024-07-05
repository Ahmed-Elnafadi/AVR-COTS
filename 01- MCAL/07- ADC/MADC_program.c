/************************************************************/
/************************************************************/
/********************* Driver : ADC           ***************/
/********************* Layer  : MCAL          ***************/
/********************* Date   : 03 may 2022   ***************/
/********************* Version: V01           ***************/
/********************* Author : Ahmed Mostafa ***************/
/********************* Company: ROBO          ***************/
/************************************************************/
/************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MADC_interface.h"
#include "MADC_private.h"
#include "MADC_config.h"

#include "MSLM_interface.h"

void MADC_voidInit(void){
	
	/* Choose Reference Voltage */
	
	#if MADC_VREF == MADC_AVCC
	CLR_BIT(MADC->ADMUX, MADC_REFS1);
	SET_BIT(MADC->ADMUX, MADC_REFS0);
	#elif MADC_VREF == MADC_INTERNAL
	SET_BIT(MADC->ADMUX, MADC_REFS1);
	SET_BIT(MADC->ADMUX, MADC_REFS0);
	#else
		#error("Out of range of input Values")
	#endif
	
	/* Adjusting Left and Right Adjust */
	
	#if MADC_ADLAR == MADC_RIGHT_ADJUST
	CLR_BIT(MADC->ADMUX, MADC_ADLAR);
	#elif MADC_ADLAR == MADC_LEFT_ADJUST
	SET_BIT(MADC->ADMUX, MADC_ADLAR);
	#else
		#error("Out of range of input Values")
	#endif
	
	/* Prescaler of Clock of ADC */
	
	#if MADC_PRE_SELECT == MADC_DIV_2
	MADC->ADCSRA|=MADC_DIV_2;
	#elif MADC_PRE_SELECT == MADC_DIV_4
	MADC->ADCSRA|=MADC_DIV_4;
	#elif MADC_PRE_SELECT == MADC_DIV_8
	MADC->ADCSRA|=MADC_DIV_8;
	#elif MADC_PRE_SELECT == MADC_DIV_16
	MADC->ADCSRA|= MADC_DIV_16;
	#elif MADC_PRE_SELECT == MADC_DIV_32
	MADC->ADCSRA|= MADC_DIV_32;
	#elif MADC_PRE_SELECT == MADC_DIV_64
	MADC->ADCSRA|= MADC_DIV_64;
	#elif MADC_PRE_SELECT == MADC_DIV_128
	MADC->ADCSRA|= MADC_DIV_128;
	#else 
		#error("Out of range of input Values")
	#endif
	
	/* Interrupt of ADC */
	
	#if MADC_ADIE_SELECT == MADC_ENABLE
	SET_BIT(MADC->ADCSRA, MADC_ADIE);
	#elif MADC_ADIE_SELECT == MADC_DISABLE
	CLR_BIT(MADC->ADCSRA, MADC_ADIE);
	#else
		#error("Out of range of input Values")
	#endif
	
	/* Auto Trigger Enable Select */
	
	#if MADC_ADATE_SELECT == MADC_ENABLE
	SET_BIT(MADC->ADCSRA, MADC_ADATE);
	#elif MADC_ADATE_SELECT == MADC_DISABLE
	CLR_BIT(MADC->ADCSRA, MADC_ADATE);
	#else
		#error("Out of range of input Values")
	#endif
	
	/* Select Trigger Source */
	
	#if MADC_AUTO_TRIGGER_CONV_SOURCE == MADC_FREE_RUNNING
	MADC_SFIOR|=(5<<MADC_FREE_RUNNING);
	#elif MADC_AUTO_TRIGGER_CONV_SOURCE == MADC_ANALOG_COMPARATOR
	MADC_SFIOR|=(5<<MADC_ANALOG_COMPARATOR);
	#elif MADC_AUTO_TRIGGER_CONV_SOURCE == MADC_EXTI_REQUEST
	MADC_SFIOR|=(5<<MADC_EXTI_REQUEST);
	#elif MADC_AUTO_TRIGGER_CONV_SOURCE == MADC_TIMER0_COMPARE_MATCH
	MADC_SFIOR|=(5<<MADC_TIMER0_COMPARE_MATCH);
	#elif MADC_AUTO_TRIGGER_CONV_SOURCE == MADC_TIMER0_OVERFLOW
	MADC_SFIOR|=(5<<MADC_TIMER0_OVERFLOW);
	#elif MADC_AUTO_TRIGGER_CONV_SOURCE == MADC_TIMER1_COMPARE_MATCHB
	MADC_SFIOR|=(5<<MADC_TIMER1_COMPARE_MATCHB);
	#elif MADC_AUTO_TRIGGER_CONV_SOURCE == MADC_TIMER1_OVERFLOW
	MADC_SFIOR|=(5<<MADC_TIMER1_OVERFLOW);
	#elif MADC_AUTO_TRIGGER_CONV_SOURCE == MADC_TIMER1_CAPTURE_EVENT
	MADC_SFIOR|=(5<<MADC_TIMER1_CAPTURE_EVENT);
	#else
		#error("Out of range of input Values")
	#endif
	
	/* Enable ADC */
	
	#if MADC_ADEN == MADC_ENABLE
	SET_BIT(MADC->ADCSRA, MADC_ADEN);
	#elif MADC_ADEN == MADC_DISABLE
	CLR_BIT(MADC->ADCSRA, MADC_ADEN);
	#else
		#error("Out of range of input Values")
	#endif
}
u16 MADC_u16ReadAnalog(u8 copy_u8Channel, u8 copy_u8VrefValue){
	u16 Local_u16AnalogValue=0;
	/* Select Channel */
	
	MADC->ADMUX|= copy_u8Channel;
	
	/* Start Conversion */
	SET_BIT(MADC->ADCSRA, MADC_ADSC);
	
	/* Polling until Flag of conversion complete raised */
	while(GET_BIT(MADC->ADCSRA, MADC_ADIF)!=1);
	
	/* Clear Flag */
	SET_BIT(MADC->ADCSRA, MADC_ADIF);

	/* Conversion from digital value to analog value */
	Local_u16AnalogValue = (MADC->ADCH)*(copy_u8VrefValue/(1024));

	return Local_u16AnalogValue;
}