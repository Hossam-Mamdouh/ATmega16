/*
 * Timer0_Normal.c
 *
 * Created: 21/04/2022 5:46:25 am
 * Author: Hossam-Mamdouh
 */

#include "Timer0_Normal.h"


volatile unsigned char Ticks = 0;
extern volatile unsigned char Seconds = 0; 

/* Description :
 * For clock = 8Mhz and prescaler F_CPU/1024 every system Tick will take 128 microsecond
 * so put initial timer counter=0  0 --> 255 (32ms per overflow)
 * so we need timer to overflow 31 times to get a 1 second
 */

void Timer0_Init(void)
{
	TCNT0 = 0; //timer initial value   
    
	TIMSK |= (1 << TOIE0); // Enable overflow interrupt
	
    /* Configure the timer control register
	 * 1. Non PWM mode FOC0=1
	 * 2. Normal Mode WGM01=0 & WGM00=0
	 * 3. Normal Mode COM00=0 & COM01=0
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	TCCR0 = (1 << FOC0) | (1 << CS02) | (1 << CS00);
	Seconds = 0;
}


void My_Delay(unsigned char Requird_Secends)
{
    Timer0_Init();
	while (Seconds != Requird_Secends);
	Seconds = 0;
}

interrupt [TIM0_OVF] void Timer0_OVF_ISR(void)
{
	Ticks++; 
    
	if (Ticks == NUMBER_OF_OVERFLOWS_PER_SECOND)
	{
		Seconds++;
		Ticks = 0; //clear the tick counter again to count a new 0.5 second
	}
}