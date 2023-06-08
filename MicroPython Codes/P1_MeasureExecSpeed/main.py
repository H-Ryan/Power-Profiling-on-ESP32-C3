import time
'''
Measure invocation time of a method
'''
def measure_important_function():
    MEASUREMENTS = 5000000
    start = time.ticks_us()
    # Method starts here
    for retries in range(MEASUREMENTS):
        pass
    # Method ends here
    end = time.ticks_us()
    print("{} iterations took {} milliseconds ({} microseconds per invocation)".format(MEASUREMENTS, (end - start)/1000, (end - start)/MEASUREMENTS))

measure_important_function()  