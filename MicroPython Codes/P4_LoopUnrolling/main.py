import time
import random

while True:
    time.sleep(10)
    SAMPLES = 1000
    ROLL = 10
    start = time.ticks_us()
    print("Timer: {} μs\n".format(start))
    for retries in range(0, SAMPLES, ROLL):
        a = 4444444444 + 5555555555
        print("Sending sample {}... {}\n".format(retries, a))
        
        b = 4444444444 + 5555555555
        print("Sending sample {}... {}\n".format(retries, b))
        
        c = 4444444444 + 5555555555
        print("Sending sample {}... {}\n".format(retries, c))
        
        d = 4444444444 + 5555555555
        print("Sending sample {}... {}\n".format(retries, d))
        
        e = 4444444444 + 5555555555
        print("Sending sample {}... {}\n".format(retries, e))
        
        f = 4444444444 + 5555555555
        print("Sending sample {}... {}\n".format(retries, f))
        
        g = 4444444444 + 5555555555
        print("Sending sample {}... {}\n".format(retries, g))
        
        h = 4444444444 + 5555555555
        print("Sending sample {}... {}\n".format(retries, h))
        
        i = 4444444444 + 5555555555
        print("Sending sample {}... {}\n".format(retries, i))
        
        j = 4444444444 + 5555555555
        print("Sending sample {}... {}\n".format(retries, j))
        
    end = time.ticks_us()
    print("Timer: {} μs\n".format(end))
    diff = time.ticks_diff(end, start)
    print("{} iterations took {} milliseconds ({} microseconds per invocation)\n".format(SAMPLES / ROLL, diff / 1000, diff / SAMPLES))
