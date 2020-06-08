#include <stdlib.h> //needed  for exit(0);
#include <sst.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
/* #include <libopencm3/cm3/nvic.h> */
#include <libopencm3/cm3/systick.h>

#define SYSTICK_PERIOD 0.5  // 0.5s period


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
  rcc_periph_clock_enable(RCC_LED1);
#if defined(STM32F1) /* F1 is a precious snowflake */
	gpio_set_mode(PORT_LED1, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, PIN_LED1);
#else /* everyone else is sane */
  gpio_mode_setup(PORT_LED1, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_LED1);
#endif
	gpio_set(PORT_LED1, PIN_LED1);

  // SYSTICK
	systick_set_clocksource(STK_CSR_CLKSOURCE_AHB_DIV8);
  STK_CVR = 0;
  // Period of 0.5s (72000000/8*0.5=4500000)
	systick_set_reload(rcc_ahb_frequency / 8 * SYSTICK_PERIOD);
	systick_counter_enable();
	systick_interrupt_enable(); //TODO: remove it when SST_run() will be called
}


/*The implempletation of the following functions is required*/

void SST_start(void) {
	//enable some sepecific interrupts
	//start some periperial ,timers ..
	//your tasks are about to start
	//do they need something that haven't been done before?
	systick_interrupt_enable();
}


/*....................................*/
void SST_onIdle(void) {
	//spare time
	//do anithing you want
	//but do not loop
	//you may want to post some events anyway
	//no time critical operations
}


/*....................................*/
void SST_exit(void) {
	//shutdown some peripherials and stuff
 	exit(0);
}
