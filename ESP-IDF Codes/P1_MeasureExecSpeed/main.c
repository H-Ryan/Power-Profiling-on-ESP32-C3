#include <stdio.h>
#include "esp_timer.h"

/*
Measure invocation time of a method
*/
void measure_important_function(void) {
    const unsigned MEASUREMENTS = 5000000;
    uint64_t start = esp_timer_get_time();
	// Method starts here
    for (int retries = 0; retries < MEASUREMENTS; retries++) {
        // This is the thing you need to measure.  important_function(); 
    }
	// Method ends here
    uint64_t end = esp_timer_get_time();

    printf("%u iterations took %llu milliseconds (%llu microseconds per invocation)\n",
           MEASUREMENTS, (end - start)/1000, (end - start)/MEASUREMENTS);
}

void app_main(void)
{
    measure_important_function();
}
