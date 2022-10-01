/****************GUARD MY FILE********************/
#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H

// KEPAD IS CONNECTED TO PORTC " PINS 0123 IS OUTPUT" " PINS 4567 IS OUTPUT"
#define KEYS_PORT PORTC

/****************LED FUNCTIONS *********************/

u8  Keypad_u8_getPressedKey (void );


#endif
