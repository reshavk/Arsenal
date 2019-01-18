import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)


GPIO.setup(3, GPIO.OUT)
GPIO.setup(2,GPIO.OUT) 
GPIO.setup(14,GPIO.IN)
try :
    
    while True:
        if(GPIO.input(14) == False): #ir sensors return true when object is in its proximity 
            GPIO.output(3, GPIO.HIGH)
            GPIO.output(2,GPIO.LOW)
        else :
            GPIO.output(3, GPIO.LOW)
            GPIO.output(2, GPIO.HIGH)
            
except(KeyboardInterrupt) :
    GPIO.cleanup()
    exit()

