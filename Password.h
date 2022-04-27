#ifndef PASSWORD_H_
#define PASSWORD_H_

#include "keypad.h"
#include "alcd.h"

void Get_Password(unsigned char array[]);
unsigned char Check_Password(unsigned char Pass1[], unsigned char Pass2[]);

#endif /* PASSWORD_H_ */