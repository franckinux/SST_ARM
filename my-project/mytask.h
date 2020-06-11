/*file: mytask.h **********************/
/**************************************/
#ifndef _MYTASK_H_
#define _MYTASK_H_
/*required includes*/
#include "sst.h"
#include "sst_stdsignal.h"
/*exported macros*/
#define myTask_ID 1
#define myTask_EVQL 4
/*exported variables*/
extern SSTEvent myTask_EQ[myTask_EVQL];
/*exported functions*/
void myTask(SSTEvent event);

typedef enum {
  LED_OFF,
  LED_ON
} led_state_type;

typedef enum {
  LED_SWITCH,
  LED_CONTROL
} led_control_type;

#define LED_SWITCH 0xAA

#define LED_HALF_PERIOD 500
#define LED_MIN_HALF_PERIOD 100
#define LED_MAX_HALF_PERIOD 2000

#endif
