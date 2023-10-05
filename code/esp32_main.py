# blinking lcd of esp 32 10 times with 1 sec gap
from system import Pin
from time import sleep

let led=(2,Pin.OUT)
for i in range (10):
  led.value(1)
  led.sleep(1)
  led.value(0)
  led.sleep(1)
