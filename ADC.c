/*
 * ADC.c
 *
 * Created: 18/04/2022 2:02:41 am
 * Author: Hossam-Mamdouh
 */

#include <mega16.h>
#include <delay.h>
#include <alcd.h>
#include <stdlib.h>

unsigned char Read_ADC (unsigned char Channel);


void main(void)
{

float x;        // Variable to hold ADC float read
char str[4];    // Equivalent Array to the Float X

ADMUX = 0X20;   // ADMUX bit 5 [ADLAR] = 1, for 8-bit reselution. 
ADCSRA = 0X81;  // ADCSRA bit 7 [ADEN] = 1 to Enable ADC module, ADCSRA Bit 5 [ADATE] = 0
                // to select Single Convertion mode, ADCSRA bits 2,1,0 [ADPS] = 001
                // to set the division factor for the pre scaler to 2.
                  

lcd_init(16);   // Initioate the LCD

while (1)
    {
        lcd_clear();
        x = Read_ADC (0X00);   // Get the value of ADC0 Connected to PORTA.0
        x = x*5/255.0;         
        ftoa(x,2,str);         // Converts this value to a string
        lcd_putsf("ADC0=");
        lcd_puts(str);
        lcd_puts("V");
        delay_ms(100);
    }
}

unsigned char Read_ADC (unsigned char Channel)
{
    ADMUX = Channel | 0X20; // Select the ADC pin and ADLAR = 1, for 8-bit reselution . 
    delay_us(10);           // For ADC input voltage stabilization
    ADCSRA |= 0X40;         // ADCSRA bit 6 [ADSC] = 1 to start conversion. 
    
    while ((ADCSRA&0X10)==0); // Wait untel ADCSRA bit 5 (end of conversion flag) [ADIF] = 1.
    ADCSRA |= 0X10;           // Reset end of conversion flag.
    return ADCH;              // Return the upper 8 bits in ADC Data Register.
}
