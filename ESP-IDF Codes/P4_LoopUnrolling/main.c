#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
#include "esp_random.h"

void app_main()
{
    while (1)
    {
        vTaskDelay(10000 / portTICK_PERIOD_MS);
        const unsigned SAMPLES = 1000;
        const unsigned ROLL = 10;
        long long int start = esp_timer_get_time();
        printf("Timer: %lld μs\n", start);
        for (int retries = 0; retries < SAMPLES; retries = retries + ROLL)
        {
            long long int a = 4444444444 + 5555555555;
            printf("Sending sample %d... %llu\n", retries, a);
            
            long long int b = 4444444444 + 5555555555;
            printf("Sending sample %d... %llu\n", retries, b);

            long long int c = 4444444444 + 5555555555;
            printf("Sending sample %d... %llu\n", retries, c);

            long long int d = 4444444444 + 5555555555;
            printf("Sending sample %d... %llu\n", retries, d);

            long long int e = 4444444444 + 5555555555;
            printf("Sending sample %d... %llu\n", retries, e);

            long long int f = 4444444444 + 5555555555;
            printf("Sending sample %d... %llu\n", retries, f);

            long long int g = 4444444444 + 5555555555;
            printf("Sending sample %d... %llu\n", retries, g);

            long long int h = 4444444444 + 5555555555;
            printf("Sending sample %d... %llu\n", retries, h);

            long long int i = 4444444444 + 5555555555;
            printf("Sending sample %d... %llu\n", retries, i);

            long long int j = 4444444444 + 5555555555;
            printf("Sending sample %d... %llu\n", retries, j);

        }
        long long int end = esp_timer_get_time();
        printf("Timer: %lld μs\n", end);
        long long int diff = end - start;
        printf("%u iterations took %llu milliseconds (%llu microseconds per invocation)\n",
               SAMPLES / ROLL, diff / 1000, diff / SAMPLES);
    }
}
