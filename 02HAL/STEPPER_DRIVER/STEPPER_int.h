/****************GUARD MY FILE********************/
#ifndef STEPPER_INTERFACE_H
#define STEPPER_INTERFACE_H

#define STEPPER_PORT PORTD

#define BLUE 	PIN1
#define PINK 	PIN2
#define YELLOW 	PIN3
#define ORANGE 	PIN4

#define CW 	0
#define CCW 1

/****************LED FUNCTIONS *********************/

void STEPPER_Full_STEP(u8 direction , u16 angel , u16 Tdelay);
void STEPPER_HALF_STEP(u8 direction , u16 angel , u16 Tdelay);
void STEPPER_STOP();

#endif
