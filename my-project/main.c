#include "sst.h"
#include "mytask.h"
#include "sst_stdsignal.h"

#include <libopencm3/stm32/gpio.h>

/* #include "api.h" */
/* #include "api-asm.h" */

int main(void) {
  //if needed do stuff before calling any OS related functions
  SST_init(); //optional
  SST_task(myTask,myTask_ID, myTask_EQ, myTask_EVQL, SST_SIGNAL_TASKINIT, 0);
  //add more tasks if nedded
  /* SST_run(); */
  /* return 0; */

	while(1) {
		/* wait a little bit */
		for (int i = 0; i < LITTLE_BIT; i++) {
			__asm__("nop");
		}
		gpio_toggle(PORT_LED1, PIN_LED1);
#if defined(RCC_LED2)
		gpio_toggle(PORT_LED2, PIN_LED2);
#endif
	}
}
