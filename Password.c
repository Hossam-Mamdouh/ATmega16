/*
 * Password.c
 *
 * Created: 21/04/2022 12:17:27 am
 * Author: Hossam-Mamdouh
 */ 
 
#include "Password.h"

void Get_Password(unsigned char array[])
{
    signed int i; 
    unsigned char key;
    for (i = 0; i < 4; i++)
    {
        key = KeyPad_getPressedKey();
        if (key == '*')
        {
           i = -1; 
           lcd_clear();
           continue;
        }
        else if ((key >= 0) && (key <= 9))
        {   
           lcd_putchar('*');
           array[i] = key;
           while ((KEYPAD_PORT_IN &0x0F) > 0); 
        }
        
        else
        {
            i -= 1;
            continue;
        }
        
        key = KeyPad_getPressedKey();
        if (key == '#')
        {
            break;
        }
        
        else if (key == '*')
        {
            i = -1;
            continue;
        }    
    }
}

unsigned char Check_Password(unsigned char Pass1[], unsigned char Pass2[])
{
   if((Pass1[0]== Pass2[0])&&(Pass1[1]== Pass2[1])&&(Pass1[2]== Pass2[2])&&(Pass1[3]== Pass2[3]))
   {
        return 1;
   }
   else
   {
        return 0;
   }
}

 