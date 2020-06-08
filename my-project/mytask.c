#include <libopencm3/stm32/gpio.h>
#include "mytask.h"

void sys_tick_handler(void);

SSTEvent myTask_EQ[myTask_EVQL];

void myTask(SSTEvent event){
  static led_state_type led_state = LED_OFF;

	if(event.sig==SST_SIGNAL_TASKINIT){
			//do stuff this task may need
			//prior normal execution
	} else {
    switch (led_state) {
      case LED_ON:
        gpio_clear(PORT_LED1, PIN_LED1);
        led_state = LED_OFF;
        break;
      case LED_OFF:
        gpio_set(PORT_LED1, PIN_LED1);
        led_state = LED_OFF;
        break;
    }
	}
}


void sys_tick_handler(void)
{
  gpio_toggle(PORT_LED1, PIN_LED1);
}
