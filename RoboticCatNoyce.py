import requests
import time
# requests.get("http://192.168.0.188/setmany?servo1=90&servo2=180")

#Function takes servo number and angle and sends request to ESP32
def set(servo, angle):
    r = requests.get("http://192.168.0.188/set?servo="+str(servo)+"&angle="+str(angle))
#print(requests.get('http://192.168.0.188/setmany?servo1=90&servo2=180'))


class Cat:
    def introduce_self(self):
        print("My name is " + self.name)
        print("My colour is " + tom.color)

    ne = 2 #NECK
    fl = 3 #FRONT_LEFT
    fr = 4 #FRONT_RIGHT
    fll = 5 #FRONT_LEFT_LEG
    frl = 6 #FRONT_RIGHT_LEG
    bl = 7 #BACK_LEFT
    br = 8 #BACK_RIGHT
    brl = 9 #BACK_LEFT_LEG
    bll = 10 #BACK_RIGHT_FOOT
    tl = 11 #TAIL
    he = 12 #HEAD

tom = Cat()
tom.name = "Tom"
tom.color = "green"

tom.introduce_self()

print("Neck = ",tom.ne)
print("Front Left = ",tom.fl) 
print("Front Right = ",tom.fr)
print("Front Left Leg = ",tom.fll)
print("Front Right Leg = ",tom.frl)
print("Back Left = ",tom.bl)
print("Back Right = ",tom.br)
print("Back Right Leg = ",tom.brl)
print("Back Leg Left = ",tom.bll)
print("Tail = ",tom.tl) 
print("Head = ",tom.he) 


#loop infinitely
while True: 

    print("A - Initial Position") 
    print("B - Rest to Stand Position")
    print("C - Push Up")
    print("D - Crawling")
    print("E - Walking")
    
    position = input('Press A or B or C or D or E or F: ')
    if position.upper() == "A":
        print('Initial Position...')
        set(2,115) #Set servo 2 to angle 45
        set(3,90) #Set servo 3 to angle 90
        set(4,90) #Set servo 4 to angle 90
        set(5,90) #Set servo 5 to angle 90
        set(6,90) #Set servo 6 to angle 90
        set(7,90) #Set servo 7 to angle 90
        set(8,90) #Set servo 8 to angle 90
        set(9,90) #Set servo 9 to angle 90
        set(10,90) #Set servo 10 to angle 90
        set(11,90) #Set servo 11 to angle 90
        set(12,114) #Set servo 12 to angle 90

    if position.upper() == "B":
        print('Resting to standing position...')
        set(2,115) #Set servo 2
        set(3,64) #Set servo 3
        set(4,123) #Set servo 4
        set(5,82) #Set servo 5 
        set(6,128) #Set servo 6 
        set(7,121) #Set servo 7 
        set(8,53) #Set servo 8 
        set(9,57) #Set servo 9 
        set(10,111) #Set servo 10 
        set(11,150) #Set servo 11
        set(12,114) #Set servo 12
        time.sleep(3) #wait for 3 seconds

        set(2,45) #Set servo 2
        set(3,64) #Set servo 3
        set(4,137) #Set servo 4
        set(7,121) #Set servo 7 
        time.sleep(3)

        set(5,122) #Set servo 5 
        set(6,53) #Set servo 6 
        time.sleep(3)

        set(8,53) #Set servo 8 
        set(9,116) #Set servo 9 
        set(10,77) #Set servo 10 
        set(11,150) #Set servo 11
        set(12,90) #Set servo 12
        time.sleep(3) #wait for 3 seconds

    if position.upper() == "C":
       print('Push up...')
       set(2,45) #Set servo 2
       set(3,54) #Set servo 3
       set(4,143) #Set servo 4
       set(5,122) #Set servo 5 
       set(6,47) #Set servo 6 
       set(7,20) #Set servo 7 
       time.sleep(3)

       set(8,148) #Set servo 8 
       set(9,176) #Set servo 9 
       set(10,9) #Set servo 10 
       set(11,134) #Set servo 11
       set(12,82) #Set servo 12
       time.sleep(3) #wait for 3 seconds

       set(5,87) #Set servo 5 
       set(6,105) #Set servo 6
       time.sleep(1)
       set(5,122) #Set servo 5 
       set(6,47) #Set servo 6
       time.sleep(1)
       set(5,87) #Set servo 5 
       set(6,105) #Set servo 6
       time.sleep(1)
       set(5,122) #Set servo 5 
       set(6,47) #Set servo 6
       time.sleep(1)



    if position.upper() == "D":
        print('Crawling Position...')
        set(2,45)
        set(3,162)
        set(4,124)
        set(5,90)
        set(6,76)
        set(7,115)
        set(8,24)
        set(9,90)
        set(10,90)
        set(11,90)
        set(12,114)
        time.sleep(3)

        set(2,115)
        set(3,73)
        set(4,50)
        set(5,90)
        set(6,76)
        set(7,145)
        set(8,49)
        set(9,90)
        set(10,90)
        set(11,118)
        set(12,114)
        time.sleep(3)
        
    if position.upper() == "E":
        print('Walking Position...')
        set(2,155)
        set(3,64)
        set(4,116)
        set(5,111)
        set(6,41)
        set(7,121)
        set(8,86)
        set(9,127)
        set(10,78)
        set(11,150)
        set(12,82)
        time.sleep(3)
        set(2,90)
        set(3,90)
        set(4,123)
        set(5,140)
        set(6,52)
        set(7,90)
        set(8,53)
        set(9,124)
        set(10,63)
        set(11,171)
        set(12,82)
        time.sleep(3)



