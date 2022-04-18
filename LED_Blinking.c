#include <mega16.h>
#include <delay.h>

unsigned char i;     // Global Variable

// Functions Prototype
void Pattern_1 (void);
void Pattern_2 (void);
void Pattern_3 (void);
void Pattern_4 (void);


void main ()
{
    DDRA = 0XFF;    // set port A as Output  
    
    while(1)
    {
        Pattern_1();
        Pattern_2();   
        Pattern_3();
        Pattern_4();
    }               
    
}


void Pattern_1 (void)
{
    PORTA = 0X01;  
    
    for (i=1;i<=8;i++) 
    {
        delay_ms (100);
        PORTA = (PORTA << 1);
    }

}

void Pattern_2 (void)
{
    PORTA = 0X80;  
    
    for (i=1;i<=8;i++) 
    {                        
        delay_ms (100); 
        PORTA = (PORTA >> 1);   
    }

}

void Pattern_3 (void)
{
    PORTA = 0X01;  
    
    for (i=1;i<=8;i++) 
    {
        delay_ms (100);    
        PORTA |= (PORTA << 1);    
    }

}

void Pattern_4 (void)
{
    PORTA = 0XFF;  
    
    for (i=1;i<=8;i++) 
    {   
        delay_ms (100);
        PORTA = (PORTA >> 1);
            
    }

}

