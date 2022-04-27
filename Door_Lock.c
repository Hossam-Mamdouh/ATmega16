/*
 * Door_Lock.c
 *
 * Created: 21/04/2022 1:01:56 am
 * Author: Hossam-Mamdouh
 */


#include "Door_Lock.h"

/*-------------------------------------- Variables----------------------------------------*/
unsigned char flag = 0;
unsigned char val;               // Holds the value from the EEPROM.
unsigned char Password_1[4];     // Holds the first entered password.
unsigned char Password_2[4];     // Holds the second entered password.
unsigned char Saved_Password[4]; // Holds the Password saved in EEPROM.
unsigned char Compare = 0;       // holds the result of comparing the two passwords.
unsigned char User_Choise;       // The user choice to open the door or change password.
unsigned char wrong_Counter = 0; // Contains the number of wrong password trials by the user.
/*---------------------------------- End Of Variables -------------------------------------*/

void main(void)
{
DDRD |= (1 << Buzzer);   // Set Buzzer pin as Output pin.
PORTD &= ~(1 << Buzzer); // Turn the Buzzer OFF.

Keypad_Init();   // Initialize the Keypad..
lcd_init(16);    // Initialize the LCD.

sei(); // Enable Global Intrrupts

//Reading the stored value (0x05) in address (0x0F) of Internal EEPROM
val = EEPROM_Read(0x0F); 

if (val == 0x05) 
{
    flag = 1;  // It's not the first Time to use the system.
}
else if (val != 0x05)
{
    flag = 0;  // It's the first Time to use the system
}

while (1)
  {    
   /*-------------------------  It's the first Time to use the System -----------------------*/

    if (flag == 0)
    {
        lcd_puts("*** Welcome! ***\n");
        lcd_puts("Create Password"); 
        My_Delay(1);
        lcd_clear();
        
        lcd_puts("Only 4 Numbers\n"); 
        lcd_puts("*:DEL  #:ENTER\n");
        My_Delay(1);
        lcd_clear();
           
        lcd_puts("Enter Password\n");
        Get_Password(Password_1); 
        lcd_clear();
        
        lcd_puts("ReEnter Password");  
        Get_Password(Password_2);
        lcd_clear(); 
        
        Compare = Check_Password (Password_1 , Password_2);
        
        if(Compare == 1)
           {
            EEPROM_Write(0x0F, 0x05);
            flag = 1;
            
            Save_Password (Password_1); 
            
            lcd_clear();
            lcd_puts("Password Saved!");  
            My_Delay(2); 
            lcd_clear(); 
           } 
        else
           {    
                flag = 0;
                lcd_puts("NO Match!\n");
                lcd_puts("Try Again!");    
                My_Delay(2); 
                lcd_clear();  
           }
        Compare = 0; 
    }

    /*------------------------It's NOT the first Time to use the System-----------------------*/
       
    else if (flag == 1)
    {
            lcd_puts("*** Welcome! ***\n");
            lcd_puts("Select an Option:");
            My_Delay(1); 
            lcd_clear();
              
            lcd_puts("# : Open Door\n");
            lcd_puts("* : Change Pass");
            
            User_Choise = KeyPad_getPressedKey();
            
            if (User_Choise == '*')
                {
                    
                    Get_Saved_Password (Saved_Password);
                    
                    lcd_clear();
                    lcd_puts("Please Enter\n");
                    My_Delay(1);
                    lcd_clear();
                    lcd_puts("Current Password");
                    
                    Get_Password(Password_1);
                    
                    Compare = Check_Password (Password_1, Saved_Password);
                    
                    if(Compare == 1)
                    {   
                        lcd_clear();
                        lcd_puts("Create Password"); 
                        My_Delay(1);
                        lcd_clear();
        
                        lcd_puts("Only 4 Numbers\n"); 
                        lcd_puts("*:DEL  #:ENTER");
                        My_Delay(1);
                        lcd_clear();
                                                
                        lcd_puts("Enter Password\n");
                        Get_Password(Password_1); 
                        lcd_clear();             
                        
                        lcd_puts("ReEnter Password"); 
                        lcd_puts("\n"); 
        
                        Get_Password(Password_2);
                        lcd_clear(); 
                        
                        Compare = Check_Password (Password_1, Password_2);
                    
                        if(Compare == 1)
                        {
                            Save_Password (Password_1);
                            lcd_clear();
                            lcd_puts("Password Saved!");  
                            My_Delay(2); 
                            lcd_clear();
                        } 
                        else
                        {    
                            lcd_puts("NO Match!\n");
                            lcd_puts("Try Again!");    
                            My_Delay(2); 
                            lcd_clear();  
                        }
                        
                        Compare = 0; 
                    }
                    
                    else
                    {   
                        lcd_puts("NO Match!\n");
                        lcd_puts("Try Again!");    
                        My_Delay(2); 
                        lcd_clear(); 
                    }                    
                }
            else if (User_Choise == '#')
                {
                    HERE:
                    
                    lcd_clear();
                    lcd_puts("Enter Password\n");
                    
                    Get_Password(Password_1);
                    Get_Saved_Password (Saved_Password);
                    
                    Compare = Check_Password (Password_1, Saved_Password);
                            
                    if(Compare == 1)
                    {
                        lcd_clear(); 
                        lcd_puts("Opening ...");
                        Motor_Init();
                        Start_Motor_Open(30000); 
                        My_Delay(2);  
                        lcd_clear(); 
                        
                        lcd_puts("Closing ...");
                        Start_Motor_Close(30000); 
                        My_Delay(2);  
                        lcd_clear();
                        
                        Stop_Motor();
                        wrong_Counter = 0;
                    } 
					else
					{
                        wrong_Counter++;
                        
                        if (wrong_Counter<3)
                        {   
                            lcd_clear();
                            lcd_puts("Wrong Password!\n");
                            My_Delay(2);;
                            lcd_clear(); 
                            
                            goto HERE;         
                        }
                        
                        else
                        {
                            lcd_clear();
                            lcd_puts("     ERROR     \n"); 
                            PORTD |= (1 << Buzzer);
                            My_Delay(10);
                            PORTD &= ~ (1 << Buzzer);
                            lcd_clear();
        
                        }
                              
                        
					}
                    
                    Compare = 0;
				}

	}
  }
}
