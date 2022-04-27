/*
 * Motor.c
 *
 * Created: 21/04/2022 2:01:56 am
 * Author: Hossam-Mamdouh
 */ 

#include <mega16.h>
#include "Motor.h" 
#include "Timer1_Fast_PWM.h"

void Motor_Init()
{
	Motor_DDR |= (1 << IN1);  // configure IN1 pin as Output pin.
	Motor_DDR |= (1 << IN2);  // configure IN2 pin as Output pin.
    Motor_DDR |= (1 << EN1);  // configure EN1 (OC1A) pin as Output pin.
	
    /*Motor is stop at the beginning*/
	Stop_Motor();
}

void Start_Motor_Open(unsigned short Duty_Cycle)
{
	/* Direction of the DC Motor*/
	Motor_PORT |= (1 << IN1);
	Motor_PORT &= ~(1 << IN2);
    Timer1_Init();
	OCR1A = Duty_Cycle;
}

void Start_Motor_Close(unsigned short Duty_Cycle)
{
	/* Direction of the DC Motor*/
	Motor_PORT &= ~(1 << IN1);
	Motor_PORT |= (1 << IN2);
    Timer1_Init();
    OCR1A = Duty_Cycle;
	
}

void Stop_Motor()
{
	Motor_PORT &= ~((1 << IN1) | (1 << IN2));
}
