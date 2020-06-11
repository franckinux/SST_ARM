#include <libopencm3/stm32/gpio.h>
#include "mytask.h"

SSTEvent myTask_EQ[myTask_EVQL];

void myTask(SSTEvent event){
  static led_state_type led_state = LED_OFF;
  static led_control_type led_control = 1;

  if (event.sig == SST_SIGNAL_TASKINIT) {
    //do stuff this task may need
    //prior normal execution
    gpio_set(GPIOC, GPIO13);
  } else if (event.sig == LED_SWITCH) {
    if (led_control) {
      switch (led_state) {
        case LED_ON:
          gpio_set(GPIOC, GPIO13);
          led_state = LED_OFF;
          break;
        case LED_OFF:
          gpio_clear(GPIOC, GPIO13);
          led_state = LED_ON;
          break;
      }
    }
  } else if (event.sig == LED_CONTROL) {
    led_control = event.par;
  } else {
  }
}
