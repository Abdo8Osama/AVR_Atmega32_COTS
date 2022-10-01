/****************GUARD MY FILE********************/
#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_


void RTOS_START(void);
void RTOS_CREAT_TASK(u32 Task_Periodicity , u8 Task_Priority, void (*ptr)(void));
void RTOS_SUSPEND_TASK(u8 TASK_ID);
void RTOS_RESUME_TASK(u8 TASK_ID);

#endif
