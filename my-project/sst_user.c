#include <stdlib.h> //needed  for exit(0);
#include <sst.h>

#include <libopencm3/cm3/systick.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

#define SYSTICK_PERIOD 0.001  // 0.5s period


/*The use of this function is optional*/
/*It's implementation is required     */

void SST_init(void) {
  //before doing any OS realted stuff you may need to configure you system
  //that kind of general configuration goes here
  //I.E.  processor clock setup

  // CLOCK
  // Setup internal clock to 72MHz from 8Mhz external oscillator
  rcc_clock_setup_in_hse_8mhz_out_72mhz();

  // GPIO
  rcc_periph_clock_enable(RCC_GPIOC);
#if defined(STM32F1) /* F1 is a precious snowflake */
  gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);
#else /* everyone else is sane */
  gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13);
#endif

  // SYSTICK
  systick_set_clocksource(STK_CSR_CLKSOURCE_AHB_DIV8);
  STK_CVR = 0;
  // Period of 0.5s (72000000/8*0.5=4500000)
  systick_set_reload(rcc_ahb_frequency / 8 * SYSTICK_PERIOD);
  systick_counter_enable();

  // UART
  rcc_periph_clock_enable(RCC_USART1);
  gpio_set_mode(GPIOA, GPIO_MODE_INPUT, GPIO_CNF_INPUT_FLOAT, GPIO10);
	usart_set_baudrate(USART1, 19200);
  usart_set_databits(USART1, 8);
  usart_set_parity(USART1, USART_PARITY_NONE);
  usart_set_stopbits(USART1, USART_CR2_STOPBITS_1);
  usart_set_mode(USART1, USART_MODE_RX);
	usart_set_flow_control(USART1, USART_FLOWCONTROL_NONE);
	usart_enable(USART1);
  usart_enable_rx_interrupt(USART1);
}


/*The implementation of the following functions is required*/

void SST_start(void) {
  //enable some specific interrupts
  //start some periperial, timers ..
  //your tasks are about to start
  //do they need something that haven't been done before?
  systick_interrupt_enable();
  nvic_enable_irq(NVIC_USART1_IRQ);
}


/*....................................*/
void SST_onIdle(void) {
  //spare time : do anything you want but do not loop
  //you may want to post some events anyway
  //no time critical operations
}


/*....................................*/
void SST_exit(void) {
  //shutdown some peripherials and stuff
   exit(0);
}
