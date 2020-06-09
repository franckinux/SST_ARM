#include <libopencm3/stm32/gpio.h>
#include <libopencm3/cm3/nvic.h>
#include "sst.h"
#include "sst_port.h"
#include "mytask.h"

#define ISR_TICK_ID SST_ISR_BASE_PRIO

void sys_tick_handler(void) {
  int pin;

  SST_ISR_ENTRY(pin, ISR_TICK_ID);
  SST_post(myTask_ID, SIGNAL_TICK, 0);
  SST_ISR_EXIT(pin, {});
}
