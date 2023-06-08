/* Non-Volatile Storage (NVS) Read and Write a Value - Example

   The adopted from espressif documentation and changed for testing:
   https://github.com/espressif/esp-idf/tree/master/examples

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "nvs.h"
#include "esp_sleep.h"
#include <time.h>
#include <sys/time.h>
#include "esp_random.h"

#define uS_TO_S_FACTOR 1000000 /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP 10        /* Time ESP32 will go to sleep (in seconds) */

void app_main(void)
{
    
    printf("Start.......................................................\n");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    
    // Initialize NVS
    esp_err_t err = nvs_flash_init();
    nvs_handle_t my_handle;
    nvs_open("storage", NVS_READWRITE, &my_handle);
	nvs_get_i32(my_handle, "restart_counter", &restart_counter);
    restart_counter++;
    nvs_set_i32(my_handle, "restart_counter", restart_counter);
    nvs_commit(my_handle);
    nvs_close(my_handle);
    
    printf("End.......................................................\n");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    int time_to_sleep = TIME_TO_SLEEP * uS_TO_S_FACTOR;
    esp_sleep_enable_timer_wakeup(time_to_sleep);
    esp_deep_sleep_start();
}
