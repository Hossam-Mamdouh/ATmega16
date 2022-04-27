/*
 * Door_Lock.h
 *
 * Created: 21/04/2022 1:01:56 am
 * Author: Hossam-Mamdouh
 */

#ifndef DOOR_LOCK_H_
#define DOOR_LOCK_H_

#ifndef F_CPU
#define F_CPU 8000000UL //8MHz Clock frequency
#endif

#include <mega16.h>
#include <interrupt.h>
#include <delay.h>
#include <stdlib.h>
#include <alcd.h>

#include "Keypad.h"
#include "Password.h"
#include "Internal_EEPROM.h"
#include "Motor.h"
#include "Timer0_Normal.h"
#include "Timer1_Fast_PWM.h"

#define Buzzer PORTD4

#endif /* DOOR_LOCK_H_ */