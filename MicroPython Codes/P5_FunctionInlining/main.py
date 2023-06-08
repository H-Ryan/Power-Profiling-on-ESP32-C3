import time
import random


def calculate():
    answer = 4444444444 + 5555555555
    return answer

while True:
    time.sleep(10)
    SAMPLES = 1000
    start = time.ticks_us()
    print("Timer: {} μs\n".format(start))
    
    for retries in range(SAMPLES):
        #localFunction = 4444444444 + 5555555555
        
        functionCall = calculate()
    
    end = time.ticks_us()
    print("Timer: {} μs\n".format(end))
    diff = time.ticks_diff(end, start)
    print("{} iterations took {} milliseconds ({} microseconds per invocation)\n".format(SAMPLES, diff / 1000, diff / SAMPLES))