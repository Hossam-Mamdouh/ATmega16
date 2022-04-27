/*
 * Keypad.c
 *
 * Created: 21/04/2022 12:17:27 am
 * Author: Hossam-Mamdouh
 */ 
 
#include "Keypad.h"
#include <delay.h>

void Keypad_Init()
{
    KEYPAD_PORT_DIR = 0XF0;
    KEYPAD_PORT_OUT = 0X00;
}
 
unsigned char KeyPad_getPressedKey(void)
{
 unsigned char col, row;
 while (1)
  {   
    for(col=0;col<3;col++) /* loop for columns */
    {
        for(row=0;row<4;row++) /* loop for rows */
        {  
           if (col == 0)
           {
               KEYPAD_PORT_OUT = 0x10; 
               delay_ms(10);
               switch (KEYPAD_PORT_IN & 0x0F)
               {
                  case 0x01:
                  return 1;
                  break;

                  case 0x02:
                  return 4;
                  break;
                  
                  case 0x04:
                  return 7;
                  break;
                  
                  case 0x08:
                  return '*';
                  break;  
               }
           }
           
           if (col == 1)
           {   
               KEYPAD_PORT_OUT = 0x20; 
               delay_ms(10);
               switch (KEYPAD_PORT_IN & 0x0F)
               {
                  case 0x01:
                  return 2;
                  break;

                  case 0x02:
                  return 5;
                  break;
                  
                  case 0x04:
                  return 8;
                  break;
                  
                  case 0x08:
                  return 0;
                  break;  
               }
           }
                  
           if (col == 2)
           {
               KEYPAD_PORT_OUT = 0x40; 
               delay_ms(10);
               switch (KEYPAD_PORT_IN & 0x0F)
               {
                  case 0x01:
                  return 3;
                  break;

                  case 0x02:
                  return 6;
                  break;
                  
                  case 0x04:
                  return 9;
                  break;
                  
                  case 0x08:
                  return '#';
                  break;  
               }
           }
        }
    }
  }    
} 