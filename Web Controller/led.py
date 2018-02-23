import time
import sys
import RPi.GPIO as GPIO

flag = sys.argv[1]

GPIO.setwarnings(False)
GPIO.cleanup()
GPIO.setmode(GPIO.BCM)
GPIO.setup(3, GPIO.OUT)

if(flag == 'false'):
    GPIO.output(3, GPIO.LOW)
else : 
    GPIO.output(3, GPIO.HIGH)
