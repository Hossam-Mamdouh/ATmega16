/*
 * Stepper_Motor.c
 *
 * Created: 18/07/2022 11:15:10 pm
 * Author : Hossam-Mamdouh
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>		/* Include delay header file */

uint8_t period = 100;	/* Set period in between two steps */

void Rotate_Clockwise(void);
void Rotate_Anticlockwise(void);

int main(void)
{
    DDRD = 0x0F;	       	/* Set PORTD lower pins as output */
    while (1) 
    {
		Rotate_Clockwise();
		_delay_ms(2000);
		Rotate_Anticlockwise();
		_delay_ms(2000);
    }
}

void Rotate_Clockwise(void)
{
	/* Rotate Stepper Motor clockwise with Half step sequence */
	PORTD = 0x05;
	_delay_ms(500);
	PORTD = 0x04;
	_delay_ms(500);
	PORTD = 0x0C;
	_delay_ms(500);
	PORTD = 0x08;
	_delay_ms(500);
	PORTD = 0x0A;
	_delay_ms(500);
	PORTD = 0x02;
	_delay_ms(500);
	PORTD = 0x03;
	_delay_ms(500);
	PORTD = 0x01;
	_delay_ms(500);
	PORTD = 0x05;
}

void Rotate_Anticlockwise(void)
{
	/* Rotate Stepper Motor Anticlockwise with Full step sequence */
	PORTD = 0x05;
	_delay_ms(500);
	PORTD = 0x01;
	_delay_ms(500);
	PORTD = 0x03;
	_delay_ms(500);
	PORTD = 0x02;
	_delay_ms(500);
	PORTD = 0x0A;
	_delay_ms(500);
	PORTD = 0x08;
	_delay_ms(500);
	PORTD = 0x0C;
	_delay_ms(500);
	PORTD = 0x04;
	_delay_ms(500);
	PORTD = 0x05;
}