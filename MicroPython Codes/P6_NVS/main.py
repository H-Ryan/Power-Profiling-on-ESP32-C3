import machine
import time
from esp32 import NVS

mS_TO_S_FACTOR = 1000
TIME_TO_SLEEP = 10
retrived = 0


print("Start.......................................................\n")
time.sleep(10)

nvsArea = NVS('storage')
retrived = nvsArea.get_i32('restart_counter')
#print(retrived)
retrived = retrived + 1
nvsArea.set_i32('restart_counter', retrived)
nvsArea.commit()

print("End.......................................................\n");
time.sleep(10)

machine.deepsleep(mS_TO_S_FACTOR*TIME_TO_SLEEP)