/*
 * Servo_Motor.c
 *
 * Created: 20/07/2022 12:18:56 am
 * Author : Hossam-Mamdouh
 */ 

#define F_CPU 8000000UL		/* Define CPU Frequency as 8MHz */

/*
 * FPWM = FOSC / ( N * ( 1 + TOP ) )
 * Where N is pre-scaler divider i.e. 1, 8, 64, 256, or 1024.
 * Hence to get 50Hz PWM frequency we need to load TOP value as 2499
 * so we get PWM frequency as,
 * FPWM = 8000000 / ( 64 * ( 1 + 2499 ) ) = 50 Hz
 * Loading ICR1 = 2499. 
 * Timer1 clock = 8MHz/64 = 125KHz = 8us.
 * loading OCR1A=  duty_cycle_period/8us.
*/

#include <avr/io.h>
#include <util/delay.h>		/* Include Delay header file */

int main(void)
{
	DDRD |= (1<<PD5);	/* Make OC1A pin as output */
	TCNT1 = 0;		    /* Set timer1 count zero */
	ICR1 = 2499;		/* Set TOP count for timer1 in ICR1 register */
	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
	TCCR1A = (1<<WGM11)|(1<<COM1A1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);	
	
    while (1) 
    {
		OCR1A = 65;  	/* Set servo shaft at -90° position */
		_delay_ms(1500);
		OCR1A = 187;	/* Set servo shaft at  0°  position */
		_delay_ms(1500);
		OCR1A = 300;	/* Set servo shaft at +90° position */
		_delay_ms(1500);
    }
}

