import RPi.GPIO as GPIO
import time
import urllib2
import smtplib
import mimetypes
import email
import email.mime.application





def sendphoto() :
    s="/home/pi/img.jpg"
    img="img.jpg"

    data = urllib2.urlopen("http://192.168.43.57:8080/photo.jpg")
    image = open(img,"wb")
    image.write(data.read())
    image.close()
    print("image captured")

    msg = email.mime.Multipart.MIMEMultipart()
    msg['Subject'] = 'ATTENTION'
    msg['From'] = 'rupalimittal15137@gmail.com'
    msg['To'] = 'rajeevkumartiwari60@gmail.com'

    body = email.mime.Text.MIMEText("Object detected around your property")
    msg.attach(body)

    '''filename='img.jpg'
    fp=open(filename,'rb')
    att = email.mime.application.MIMEApplication(fp.read(),_subtype="jpg")
    fp.close()
    att.add_header('Content-Disposition','attachment',filename=filename)
    msg.attach(att)'''
    print "mail created"


    s = smtplib.SMTP('smtp.gmail.com',587)
    s.starttls()
    s.login('rupalimittal15137@gmail.com','AIM@rups001')
    print "login successful"

    s.sendmail('rupalimittal15137@gmail.com',['rajeevkumartiwari60@gmail.com'], msg.as_string())
    s.quit()
    print("Image sent successfully")
   


GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)



GPIO.setup(14,GPIO.IN)
try :
    
    while True:
        if(GPIO.input(14) == False): #ir sensors return true when object is in its proximity 
            print "nothing detected"
        else :
            sendphoto()
            
except(KeyboardInterrupt) :
    GPIO.cleanup()
    exit()
