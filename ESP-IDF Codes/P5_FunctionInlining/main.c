#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
#include "esp_random.h"

long long int calculate()
{
    long long int answer = 4444444444 + 5555555555;
    return answer;
}

void app_main()
{
    while (1)
    {
        vTaskDelay(10000 / portTICK_PERIOD_MS);
        const unsigned SAMPLES = 10000000;
        long long int start = esp_timer_get_time();
        printf("Timer: %lld μs\n", start);
        for (int retries = 0; retries < SAMPLES; retries++)
        {
             //long long int localFunction = 4444444444 + 5555555555;

            long long int functionCall = calculate();
        }
        long long int end = esp_timer_get_time();
        printf("Timer: %lld μs\n", end);
        long long int diff = end - start;
        printf("%u iterations took %llu milliseconds (%llu microseconds per invocation)\n",
               SAMPLES, diff / 1000, diff / SAMPLES);
    }
}
