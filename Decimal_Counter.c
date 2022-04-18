#include <mega16.h>
#include <delay.h>

// the figure of number          0    ,    1    ,    2    ,    3    ,    4    ,   5     ,   6     ,    7    ,    8    ,    9    
flash unsigned char LUT[] = {0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1101111};

void main(void)
{
    unsigned char i = 0;
    DDRC = 0XFF;      // set port C as output
    PORTC = LUT[0];   // Initialize port C with ( 0 )
    DDRD = 0XFF;      // set port D as output
    PORTD = LUT[0];   // Initialize port D with ( 0 )
    DDRA = 0X00;      // set port A as input
    PORTA = 0X01;     // activate the pullup resistor of bin A.0 
    
    while (1)
    { 
        while ((PINA&0X01) == 0X01)  // while button has not been pushed.
              {
                 ;  // wait for user to Push the button
              } 
        // the user pushed the button
        i++;
        if (i == 100)
           {
                i = 0; // if the user pushed the button 100 times, reset the counter.
           }  
        PORTD = LUT[i % 10 ];  // Port D displays the Ones value
        PORTC = LUT[i / 10 ];  // Port C displays the Tens value
        
        while ((PINA&0X01) == 0X00)  
              {
                 ;  // wait for user to Release the button
              }  

    }
    
}