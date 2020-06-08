/*file: mytask.h **********************/
/**************************************/
#ifndef _MYTASK_H_
#define _MYTASK_H_
/*required includes*/
#include "sst.h"
#include "sst_stdsignal.h"
/*exported macros*/
#define myTask_ID 1
#define myTask_EVQL 2
/*exported variables*/
extern SSTEvent myTask_EQ[myTask_EVQL];
/*exported functions*/
void myTask(SSTEvent event);

typedef enum {
  LED_ON,
  LED_OFF
} led_state_type;

#define SIGNAL_TICK 0xAA
#endif
