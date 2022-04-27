/*
 * Motor.h
 *
 * Created: 21/04/2022 2:01:56 am
 * Author: Hossam-Mamdouh
 */ 
 
#ifndef MOTOR_H_
#define MOTOR_H_

#include "Door_Lock.h"

#define Motor_DDR DDRD
#define Motor_PORT PORTD
#define IN1 PORTD2
#define IN2 PORTD3
#define EN1 PORTD5

void Motor_Init();
void Start_Motor_Open(unsigned short Duty_Cycle);
void Start_Motor_Close(unsigned short Duty_Cycle);
void Stop_Motor();

#endif /* MOTOR_H_ */
