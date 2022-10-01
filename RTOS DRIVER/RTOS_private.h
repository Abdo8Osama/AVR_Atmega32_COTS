/****************GUARD MY FILE********************/

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

#define SUSPENDED 0
#define RESUME	  1

typedef struct
{
	u32 Periodicity;
	void (*TaskHandler_ptr)(void);
	u8 status ;
}Task_t;

static void Scheduler(void);

static void TIMER_INIT(u8 TIMER_MODE , u8 CLOCK_SOURCE , u8 INTERRUPT_POLLING ,u8 TCNT_PRELOAD ,u8 OCR_PRELOAD , u8 OCO_INVERTING_NONINVERTING);
static void CALLback_TIMER (void (* ptr) (void));



#endif
