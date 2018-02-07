import urllib2
import json
import time
import socket

url = "http://api.wunderground.com/api/d34206fb68bee54a/geolookup/conditions/q/IA/"

s = socket.socket()
port = 8001

s.connect(('127.0.0.1', port))
print ("Server connected")

try :
    while(True) :
        area = raw_input("Enter area : ")
        f = urllib2.urlopen(url + area + ".json")
        json_string = f.read()
        parsed_json = json.loads(json_string)
		
	temp_c = parsed_json['current_observation']['temp_c']
		
	s.send(str(temp_c))
	time.sleep(2)
except(KeyboardInterrupt) :
    s.close()
    exit()
