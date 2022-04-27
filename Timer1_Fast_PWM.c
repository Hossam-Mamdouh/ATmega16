/*
 * Timer1_Fast_PWM.c
 *
 * Created: 21/04/2022 3:30:56 am
 * Author: Hossam-Mamdouh
 */
 
#include "Timer1_Fast_PWM.h"

void Timer1_Init()
{
/* Timer 1 Fast PWM mode */

TCNT1 = 0;     //initial timer value

// FOC1A = 0, to disable Force Output Compare for Channel A to use PWM Mode.
TCCR1A &= ~(1 << FOC1A);

TCCR1A = (1 << WGM11) | (1 << WGM10);  //  WGM11 = WGM10 = 1, for Fast PWM Mode.

TCCR1B = (1 << WGM12) | (1 << WGM13);  // WGM13 = WGM12 = 1, for Fast PWM Mode.

TCCR1A |= (1 << COM1A1); // COM1A1 = 1, Non-Inverting Mode.
                                                           
TCCR1B |= (1 << CS10);   // CS10 = 1, No Prescaling Frequancy = F_CPU. 
}     