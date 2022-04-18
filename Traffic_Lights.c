/*
 * Traffic_Lights.c
 *
 * Created: 17/04/2022 1:02:54 am
 * Author: Hossam-Mamdouh
 */

#include <mega16.h>
#include <delay.h>

#define RED 0
#define GREEN 1
#define YELLOW 2

unsigned char Time;
unsigned char State;

void Red_Blink(void);
void Red_Off(void);
void Green_Blink(void);
void Green_Off(void);
void Yellow_Blink(void);
void Yellow_Off(void);

interrupt [EXT_INT0] void ISR (void)
{
    unsigned char Remaining_Time =0;
    if (State == GREEN)
       {
           Remaining_Time = 15 - Time;
           Time = 0;
           while (Time<Remaining_Time)
                 {
                    Green_Blink();
                    Time++;
                 } 
           Green_Off();
           Time = 8;      
       }
}


void main(void)
{ 

// External Interupts Initialization
GICR |= 0X40;   // Set INT0 [bit 6] GICR = 01000000
MCUCR |= 0X03;  // Set event as Rising Edge (ISC00 = ISC01 = 1) [bits 0,1]
GIFR |= 0X40;   // Reset Interuppt0 Flag (INTF0 = 1 [bit 6])

DDRC /= 0X07;   // Set pin C.0, C.1, C.2 as output

Time = 0;
State = RED;

#asm 
sei   // Set Global Interrupts
#endasm 

while (1)
    {
     switch (State)
            {
            case RED:
                while (Time<15)
                  {
                     Red_Blink();
                     Time++;
                  } 
                Red_Off();
                Time = 0;
                State = GREEN;  

            break;

            case GREEN:
                while (Time<7)
                  {
                     Green_Blink();
                     Time++;
                  } 
                Green_Off();
                Time = 0;
                State = YELLOW; 

            break; 
            
            case YELLOW:
                while (Time<3)
                  {
                     Yellow_Blink();
                     Time++;
                  } 
                Yellow_Off();
                Time = 0;
                State = RED; 

            break;
            }

    }
}


void Red_Blink(void)
{
    PORTC |= 0X01;
    delay_ms(500); 
    PORTC &= ~0X01;
    delay_ms(500); 
}

void Red_Off(void)
{
    PORTC &= ~0X01;
}

void Yellow_Blink(void)
{
    PORTC |= 0X02;
    delay_ms(500); 
    PORTC &= ~0X02;
    delay_ms(500); 
}

void Yellow_Off(void)
{
    PORTC &= ~0X02;
}

void Green_Blink(void)
{
    PORTC |= 0X04;
    delay_ms(500); 
    PORTC &= ~0X04;
    delay_ms(500); 
}

void Green_Off(void)
{
    PORTC &= ~0X04;
}




