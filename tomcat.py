from time import sleep
from machine import PWM, Pin


def map(x, in_min, in_max, out_min, out_max):
    return int((x-in_min) * (out_max-out_min)/ (in_max - in_min) + out_min)

class Servo():
    __angle = 90
    __name = "Servo"
    __pin = 0
    __max_angle = 180
    __min_angle = 0

def __init__(self, name = None, pin = None):
    if name is not None:
        self.__name = name
        if pin is not None:
            self.pin = pin
    
    self.__pwm = PWM(Pin(self.__pin))
    self.__pwm.freq(1000)





@property
def angle(self):
    return self.__angle

@angle.setter
def angle(self, value):
    if value <= 180 and value >= 0:
        self.__angle = value

        #Servo Setting Code
        my_angle = map(value, 0, 180, 0, 65025)
        self.__pwm.duty_u16(my_angle)
        sleep(0.0001)


    else:
        print("The angle was too small or large:", value)
    

@property
def name(self):
    return self.__name

@name.setter
def name(self, value):
    self.__name = value

@property
def pin(self):
    return self.__pin

@pin.setter
def pin(self, value):
    if value >= 0 and value <= 40:
        self.__pin = value 
    else:
        print("The Pin was too low or too larger", value)


s =  Servo()


