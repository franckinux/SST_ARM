#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>
#include "sst.h"
#include "sst_port.h"
#include "mytask.h"

#define ISR_TICK_ID SST_ISR_BASE_PRIO
#define ISR_USART_ID (SST_ISR_BASE_PRIO + 1)

static int led_counter = LED_HALF_PERIOD;
static int led_reload_counter = LED_HALF_PERIOD;


void sys_tick_handler(void) {
  int pin;

  SST_ISR_ENTRY(pin, ISR_TICK_ID);
  if (led_reload_counter-- == 0) {
    SST_post(myTask_ID, LED_SWITCH, 0);
    led_reload_counter = led_counter;
  }
  SST_ISR_EXIT(pin, {});
}

void usart1_isr(void) {
  int pin;
  char c;

  SST_ISR_ENTRY(pin, ISR_USART_ID);

  c = usart_recv(USART1);
  if (c == '0') {
    SST_post(myTask_ID, LED_CONTROL, 0);
  } else if (c == '1') {
    SST_post(myTask_ID, LED_CONTROL, 1);
  } else if (c == '+') {
    led_counter += 10;
    if (led_counter > LED_MAX_HALF_PERIOD) {
      led_counter = LED_MAX_HALF_PERIOD;
    }
  } else if (c == '-') {
    led_counter--;
    if (led_counter < LED_MIN_HALF_PERIOD) {
      led_counter = LED_MIN_HALF_PERIOD;
    }
  }

  SST_ISR_EXIT(pin, {});
}
