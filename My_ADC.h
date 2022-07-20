#ifndef MY_ADC_H_
#define MY_ADC_H_

#include <avr/io.h>
#include <util/delay.h>

// Functions Prototypes
void ADC_Init (void);
unsigned char Read_ADC (unsigned char Channel);

// Functions Definitions.
void ADC_Init (void)
{
	// ADMUX bit 5 [ADLAR] = 1, for 8-bit resolution.
	ADMUX = 0x20;
	
	// ADCSRA bit 7 [ADEN] = 1 to Enable ADC module, ADCSRA Bit 5 [ADATE] = 0
	// to select Single Conversion mode, ADCSRA bits 2,1,0 [ADPS] = 001
	// to set the division factor for the pre scaler to 2.
	ADCSRA = 0x81;
}

unsigned char Read_ADC (unsigned char Channel)
{
	ADMUX = Channel | 0x20;   // Select the ADC Channel and ADLAR = 1, for 8-bit resolution.
	_delay_us(10);            // For ADC input voltage stabilization
	ADCSRA |= 0x40;           // ADCSRA bit 6 [ADSC] = 1 to start conversion.
	// Wait until ADCSRA bit 5 (end of conversion flag) [ADIF] = 1.
	while ((ADCSRA & 0x10) == 0);
	ADCSRA |= 0x10;           // Reset end of conversion flag.
	return ADCH;              // Return the upper 8 bits in ADC Data Register.
}

#endif /* MY_ADC_H_ */