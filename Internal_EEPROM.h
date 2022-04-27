/*
 * Internal_EEPROM.h
 *
 * Created: 21/04/2022 12:17:27 am
 * Author: Hossam-Mamdouh
 */

#ifndef INTERNAL_EEPROM_H_
#define INTERNAL_EEPROM_H_

#include <mega16.h>
#include <delay.h>

#define EEPROM_Start 0X0A

void EEPROM_Write(unsigned short Addr, unsigned char Data);

unsigned char EEPROM_Read(unsigned short Addr);

void Save_Password (unsigned char Password[]);

void Get_Saved_Password (unsigned char Password[]);

#endif /* INTERNAL_EEPROM_H_ */