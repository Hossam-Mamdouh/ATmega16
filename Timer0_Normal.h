/*
 * Timer0_Normal.ch
 *
 * Created: 21/04/2022 5:46:25 am
 * Author: Hossam-Mamdouh
 */

#ifndef TIMER0_NORMAL_H_
#define TIMER0_NORMAL_H_

#include <mega16.h>
#include <interrupt.h>
#include "Door_Lock.h" 

#define NUMBER_OF_OVERFLOWS_PER_SECOND 32

void Timer0_Init(void);

void My_Delay(unsigned char Requird_Secends);

#endif /* TIMER0_NORMAL_H_ */
