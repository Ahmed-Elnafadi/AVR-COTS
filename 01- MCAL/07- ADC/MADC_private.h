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

/* Preprocessor File Guard */

#ifndef MADC_PRIVATE_H_
#define MADC_PRIVATE_H_

ADMUX, ADCSRA, ADCL AND ADCH, SFIOR

typedef struct MADC{
	
	u8 ADCL;
	u8 ADCH;
	u8 ADCSRA;
	u8 ADMUX;
} MADC_t;

#define MADC		((volatile MADC_t*)0x24)

/* Bits in ADMUX */
/* For choosing The Referance voltage on MCU */
#define MADC_REFS1	7
#define MADC_REFS0	6

/* For defining left or right adjust */
#define MADC_ADLAR	5

/* For Adjusting Mode */
#define MADC_MUX4	4
#define MADC_MUX3	3
#define MADC_MUX2	2
#define MADC_MUX1	1
#define MADC_MUX0	0

/***********************************************/
/* Bits for ADCSRA */
/* For Enabling or Disabling ADC */
#define MADC_ADEN	7

/* For starting conversion */
#define MADC_ADSC	6

/* ADC interrupt Flag (Becomes one after conversion complete) */
#define MADC_ADIF	4

/* ADC Interrupt Enable */
#define MADC_ADIE	3

/* For prescaling clock that enters from CPU to ADC */
#define MADC_ADPS2	2
#define MADC_ADPS1	1
#define MADC_ADPS0	0

/* ADC Auto Trigger Enable */
#define MADC_ADATE	5

/***********************************************/
/* For controling Trigger source of ADC */
#define MADC_SFIOR	*((volatile u8*)0x50)

#define MADC_ADTS2	7
#define MADC_ADTS1	6
#define MADC_ADTS0	5

#endif