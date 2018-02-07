import urllib2
import cookielib
from getpass import getpass
import sys
import os
from stat import *
import time
import json


def sendsms(message, number) :    
    username = "8007680311"
    passwd = "qwerty123"

    message = "+".join(message.split(' '))

 
    url ='http://site24.way2sms.com/Login1.action?'
    data = 'username='+username+'&password='+passwd+'&Submit=Sign+in'


    cj= cookielib.CookieJar()
    opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))

    opener.addheaders=[('User-Agent','Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/37.0.2062.120')]
    try:
        usock =opener.open(url, data)
    except IOError:
        print "error"
        

    jession_id =str(cj).split('~')[1].split(' ')[0]
    send_sms_url = 'http://site24.way2sms.com/smstoss.action?'
    send_sms_data = 'ssaction=ss&Token='+jession_id+'&mobile='+number+'&message='+message+'&msgLen=136'
    opener.addheaders=[('Referer', 'http://site25.way2sms.com/sendSMS?Token='+jession_id)]
    try:
        sms_sent_page = opener.open(send_sms_url,send_sms_data)
    except IOError:
        print "error"

    print "success" 





try :
    f = urllib2.urlopen('http://api.wunderground.com/api/d34206fb68bee54a/geolookup/conditions/q/IA/kothrud.json')
    json_string = f.read()
    parsed_json = json.loads(json_string)
    location = parsed_json['location']['city']
    temp_c = parsed_json['current_observation']['temp_c']
    wind_kph = parsed_json['current_observation']['wind_kph']
    relative_humidity = parsed_json['current_observation']['relative_humidity']

   
    if int(temp_c) > 15:
        message = "Current temperature in " + location + " is " + str(temp_c)
        sendsms(message, "8007678702")

except KeyboardInterrupt:
    f.close()




    
