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

/* Preprocessor File Guard */

#ifndef MEXTI_INTERFACE_H_
#define MEXTI_INTERFACE_H_

#define	MEXTI_INT0_ENABLE		1
#define MEXTI_INT1_ENABLE		2
#define MEXTI_INT2_ENABLE		3

#define	MEXTI_INT0_PIN				4
#define MEXTI_INT1_PIN				5
#define MEXTI_INT2_PIN				6

void MEXTI_voidInit(void);

/* Options:
1- MEXTI_INT0_ENABLE
2- MEXTI_INT1_ENABLE
3- MEXTI_INT2_ENABLE
*/
void MEXTI_voidEnableINT(u8 copy_u8INTValue);

/* Options:
1- MEXTI_INT0
2- MEXTI_INT1
3- MEXTI_INT2
*/
void MEXTI_voidExecuteFunctionInISR(void(*copy_pvoidFunc)(void), u8 copy_u8INTValue);
#endif
