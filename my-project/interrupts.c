#include <libopencm3/stm32/gpio.h>
#include "sst_port.h"
#include "mytask.h"

#define ISR_TICK_ID 250

void sys_tick_handler(void);

void sys_tick_handler(void) {
  int pin;

  SST_ISR_ENTRY(pin, ISR_TICK_ID);
  SST_post(myTask_ID, SIGNAL_TICK, 0);
  /* SST_ISR_EXIT(pin,(SCB->ICSR = SCB_ICSR_PENDSVSET_Msk)); */
  SST_ISR_EXIT(pin, {});
}
