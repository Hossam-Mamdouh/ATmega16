/*
 * DC_Motor.c
 *
 * Created: 20/07/2022 1:55:01 am
 * Author : Hossam-Mamdouh
 */ 

#define F_CPU  8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "My_ADC.h"

// Global Variables
unsigned char ADC_Value   = 0;    // Holds the reading of the ADC.
unsigned char Direction   = 0;    // Motor Direction.

int main(void)
{
	DDRC |= 0x03;         // Set PC0 : PC1 as Output pins.
	DDRB |= (1<<PB3);	  // Set PB3 [OC0] pin as Output.
	PORTC &= ~0x03;       // Turn OFF pins PC0 : PC1.
	sei();                // Enable Global interrupts.
	GICR |= (1 << INT0);  // Enable External interrupt INT0 [PD2].
	ADC_Init();		      // Initialize ADC peripheral.
	TCNT0 = 0;			  // Set timer0 count zero.
	/* Set Fast PWM with F_CPU/64 Timer0 clock */
	TCCR0 = (1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00)|(1<<CS01);

    while (1) 
    {
		if (Direction == 0)	/* Rotate DC motor Clockwise */
		PORTC = 1;
		else			/* Else rotate DC motor Anticlockwise */
		PORTC = 2;
	
		/* Read ADC and map it into 0-255 to write in OCR0 register */
		ADC_Value = Read_ADC(0);
		OCR0 = (ADC_Value/4);	
    }
}

// Interrupt Service Routine for External interrupt INT0 [PD2].
ISR(INT0_vect)
{
	Direction = ~Direction;		/* Toggle Direction */
	_delay_ms(50);			/* Software de-bouncing control delay */
}