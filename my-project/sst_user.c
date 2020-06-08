#include <stdlib.h> //needed  for exit(0);
#include <sst.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

/*The use of this function is optional*/
/*It's implementation is required     */

void SST_init(void) {
	//before doing any OS realted stuff
	//you may need to cofigure you system
	//that kind of general configuration
	//goes here
	//I.E.  processor clock setup
  rcc_periph_clock_enable(RCC_LED1);
#if defined(STM32F1) /* F1 is a precious snowflake */
	gpio_set_mode(PORT_LED1, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, PIN_LED1);
#else /* everyone else is sane */
  gpio_mode_setup(PORT_LED1, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_LED1);
#endif
	gpio_set(PORT_LED1, PIN_LED1);
#if defined(RCC_LED2)
  rcc_periph_clock_enable(RCC_LED2);
  gpio_mode_setup(PORT_LED2, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_LED2);
#endif
}


/*The implempletation of the following functions is required*/

void SST_start(void) {
	//enable some sepecific interrupts
	//start some periperial ,timers ..
	//your tasks are about to start
	//do they need something
	//that haven't been done before?
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
