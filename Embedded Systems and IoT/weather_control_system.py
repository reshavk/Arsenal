import urllib2
import RPi.GPIO as GPIO
import time
import json

GPIO.cleanup()
GPIO.setmode(GPIO.BCM)

GPIO.setup(18, GPIO.OUT)
GPIO.output(18, GPIO.LOW)
GPIO.setup(23, GPIO.OUT)
GPIO.output(23, GPIO.LOW)

while(True) :
    try :
        f = urllib2.urlopen('http://api.wunderground.com/api/d34206fb68bee54a/geolookup/conditions/q/IA/kothrud.json')
        json_string = f.read()
        parsed_json = json.loads(json_string)
        location = parsed_json['location']['city']
        temp_c = parsed_json['current_observation']['temp_c']
        wind_kph = parsed_json['current_observation']['wind_kph']
        relative_humidity = parsed_json['current_observation']['relative_humidity']

        print ("Current temperature in %s is: %s" % (location, temp_c))
        print ("Current wind speed in kph in %s is: %s" % (location, wind_kph))
        print ("Current relative humidity  in %s is: %s" % (location, relative_humidity))
        if int(temp_c) > 10:
            GPIO.output(18, GPIO.HIGH)
            time.sleep(1)
        if relative_humidity > 75:
            GPIO.output(23, GPIO.HIGH)
            time.sleep(1)
            GPIO.output(23, GPIO.LOW)

        time.sleep(1)
    except KeyboardInterrupt:
        GPIO.cleanup()
        f.close()
