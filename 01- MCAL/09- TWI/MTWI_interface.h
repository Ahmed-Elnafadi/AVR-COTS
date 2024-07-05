/************************************************************/
/************************************************************/
/********************* Driver : TWI           ***************/
/********************* Layer  : MCAL          ***************/
/********************* Date   : 12 AUGUST 2022***************/
/********************* Version: V01           ***************/
/********************* Author : Ahmed Mostafa ***************/
/********************* Company: ROBO          ***************/
/************************************************************/
/************************************************************/

/* Preprocessor File Guard */

#ifndef MTWI_INTERFACE_H_
#define MTWI_INTERFACE_H_

/* Declaration of APIs */

void MTWI_voidInit(void);
void MTWI_voidSendFrame(u8 copy_u8SLA, u8 copy_u8Data);
void MTWI_voidSetSLA(u8 copy_u8SLA);
#endif