#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "esp_sleep.h"
#include "driver/rtc_io.h"
#include "soc/rtc.h"



#define uS_TO_S_FACTOR 1000000  /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  600        /* Time ESP32 will go to sleep (in seconds) */
void app_main(void)
{
  int time_to_sleep = TIME_TO_SLEEP * uS_TO_S_FACTOR;
  esp_sleep_enable_timer_wakeup(time_to_sleep);
  esp_deep_sleep_start();
}
