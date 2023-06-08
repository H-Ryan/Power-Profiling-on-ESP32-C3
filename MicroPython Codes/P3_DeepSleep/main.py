import machine

mS_TO_S_FACTOR = 1000
TIME_TO_SLEEP = 600

machine.deepsleep(mS_TO_S_FACTOR*TIME_TO_SLEEP)