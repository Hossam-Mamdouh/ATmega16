/*
 * Internal_EEPROM.c
 *
 * Created: 21/04/2022 12:17:27 am
 * Author: Hossam-Mamdouh
 */ 

#include "Internal_EEPROM.h"

unsigned char k;

void EEPROM_Write(unsigned short Addr, unsigned char Data)
{
    /* Wait for completion of previous write */
    while (EECR & (1 << EEWE));
    /* Set up address and data registers */
    EEAR = Addr;
    EEDR = Data;
    /* Write logical one to EEMWE */
    EECR |= (1 << EEMWE);
    /* Start EEPROM write by setting EEWE */
    EECR |= (1 << EEWE);
}

unsigned char EEPROM_Read(unsigned short Addr)
{
    /* Wait for completion of previous write */
    while (EECR & (1 << EEWE));
    /* Set up address register */
    EEAR = Addr;
    /* Start EEPROM read by writing EERE */
    EECR |= (1 << EERE);
    /* Return data from data register */
    return EEDR;
}

void Save_Password (unsigned char Password[])
{
    for (k=0;k<4;k++) 
    {
        EEPROM_Write((EEPROM_Start + k), Password[k]);   
    } 
}

void Get_Saved_Password (unsigned char Password[])
{
    for (k=0;k<4;k++) 
    {
        Password[k] = EEPROM_Read(EEPROM_Start + k);   
    }
}

