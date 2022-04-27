#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Door_Lock.h"

#define N_col 3
#define N_row 4

/* Keypad Port Configurations */
#define KEYPAD_PORT_OUT PORTB
#define KEYPAD_PORT_IN  PINB 
#define KEYPAD_PORT_DIR DDRB


void Keypad_Init();
unsigned char KeyPad_getPressedKey(void);

#endif /* KEYPAD_H_ */