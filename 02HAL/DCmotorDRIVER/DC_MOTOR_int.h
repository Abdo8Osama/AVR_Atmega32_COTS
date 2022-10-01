/****************GUARD MY FILE********************/
#ifndef DC_MOTOR_INTERFACE_H
#define DC_MOTOR_INTERFACE_H

#define STEPPER_PORT PORTD

#define DC_PORT  PORTD
#define PIN_RIGHT PIN0
#define PIN_LEFT  PIN2


/**************** FUNCTIONS *********************/


void DCMOTOR_TurnRight();
void DCMOTOR_Turnleft();
void DCMOTOR_Stop();

#endif
