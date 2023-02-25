from machine import Pin
from machine import PWM
from time import sleep_ms

def map(x, in_min, in_max, out_min, out_max):
    return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)

class Cat:
    def __init__(self, signal_pin):
        self.pwm = PWM(Pin(signal_pin), freq = 50, duty = 0)
        
    def rotate(self, angle):
        self.pwm.duty(map(angle, 0, 180, 23, 124))
        

tomfr = Cat(signal_pin = 23)
tomfl = Cat(signal_pin = 32)
tombr = Cat(signal_pin = 33)
tombl = Cat(signal_pin = 27)
tomtl = Cat(signal_pin = 14)
tomne = Cat(signal_pin = 12)
tomhe = Cat(signal_pin = 13)

# initial position
initial_position = input('Press I for initial: ') 

if unit.upper() == "I": 
    for angle in range(0, 180, 10):
        tomfr.rotate(90)
        sleep_ms(500)
        tomfl.rotate(130)
        sleep_ms(500)
        tombr.rotate(30)
        sleep_ms(500)
        tombl.rotate(30)
        sleep_ms(500)
        tomtl.rotate(180)
        sleep_ms(500)
        tomne.rotate(20)
        sleep_ms(500)
        tomhe.rotate(150)
        sleep_ms(500)
        
       
        






