import socket
import RPi.GPIO as GPIO
import time


GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(3,GPIO.OUT)
GPIO.setup(2,GPIO.OUT)

GPIO.output(3, GPIO.LOW)
GPIO.output(2, GPIO.LOW)

s=socket.socket()
port=8001
print 'Socket Created'

s.bind(('',port))
s.listen(True)

c,addr=s.accept()
print 'Client Connected'

try:
    while True:
	temp=c.recv(1024)
	if temp == '':
	    break
        temp=int(temp)
	print('Temperature is '+str(temp)+'C')
	if temp > 15:
	    GPIO.output(3,True)
	    GPIO.output(2,False)
	        
	else:
	    GPIO.output(2,True)
	    GPIO.output(3,False)        
except KeyboardInterrupt:
    GPIO.cleanup()
    s.close()
