import requests
import time

ip = "192.168.0.128" #IP address of ESP32 printed in the Serial Monitor

#r = requests.get("http://"+ip+"/set?servo=1&angle=180")

#Function takes servo number and angle and sends request to ESP32
def set(servo, angle):
    r = requests.get("http://"+ip+"/set?servo="+str(servo)+"&angle="+str(angle))

#loop infinitely
while True: 
    set(1,0) #Set servo 1 to angle 0
    time.sleep(3) #Wait for 3 seconds
    set(1,180) #Set servo 1 to angle 180
    time.sleep(3) #wait for 3 seconds