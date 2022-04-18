/*
 * LCD.c
 *
 * Created: 15/04/2022 10:20:01 pm
 * Author: Hossam-Mamdouh
 */

#include <mega16.h>
#include <alcd.h>
#include <stdlib.h>

eeprom char x = 0;  // Save variable x in EEPROM.

void main(void)
{
    char y = 0;
    char str[3];
    PORTC |= 0X01;  // Activate pullup resistor for pin C.1
    lcd_init(16);   // Initialize the LCD.
    
    
    while (1)
    {
        while ((PINC&0x01) == 0x01);  // Wait for the user to push the button.
        // the user pushed the button.
        x++;
        y++;
        itoa (x,str);   // Integer to Array
        lcd_clear();
        lcd_gotoxy(0,0); // Move the curser to culmon 1, Row 1.
        
        lcd_putsf("EEPROM="); 
        lcd_puts(str);
                    
        itoa (y,str);
        lcd_gotoxy(0,1);   // Move the curser to culmon 1, Row 2. 
        lcd_putsf("RAM="); 
        lcd_puts(str);
        while ((PINC&0x01) == 0x00);  // Wait for the user to release the button.   
        
    }
}
