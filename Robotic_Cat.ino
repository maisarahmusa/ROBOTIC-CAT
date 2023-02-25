#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define MIN_PULSE_WIDTH 600
#define MAX_PULSE_WIDTH 2600
#define FREQUENCY 50



void setup() {
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  Serial.begin(115200);
  Serial.println();
  Serial.println("ready for command");


  initial_position();
}

int pulseWidth(int angle){
  int pulse_wide,analog_value;
  pulse_wide=map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide)/1000000 *FREQUENCY*4096);
  return analog_value;
}

void loop() {
  //If serial data received
  if(Serial.available() > 0){
    char command = Serial.read();
    if (command == 'a')
    {
      rest_to_stand();
    }
    if (command == 'b')
    {
      crawling_in_reverse();
    }
    if (command == 'c')
    {
      crawling();
    }
    if (command == 'd')
    {
      walking();
    }
 }
}

//Initial position// 
 void initial_position(){
  Serial.println("Initial position...");
    pwm.setPWM(2,0,pulseWidth(45));   //center body (Neck)
    pwm.setPWM(3,0,pulseWidth(90));  //front body (left)
    pwm.setPWM(4,0,pulseWidth(90));   //front body (right)
    pwm.setPWM(5,0,pulseWidth(90));   //front leg (left)
    pwm.setPWM(6,0,pulseWidth(90));  //front leg (right)
    pwm.setPWM(7,0,pulseWidth(90));   //rear body (left)
    pwm.setPWM(8,0,pulseWidth(90));  //rear body (right)
    pwm.setPWM(9,0,pulseWidth(90));  //rear leg (right)
    pwm.setPWM(10,0,pulseWidth(90));  //rear leg (left)
    pwm.setPWM(11,0,pulseWidth(30)); //Tail
    pwm.setPWM(12,0,pulseWidth(90)); //Head
      
}

//Resting to Standing Position 'a'
void rest_to_stand(){
   Serial.println(" Resting to Standing position...");
   pwm.setPWM(2,0,pulseWidth(115));   //center body (Neck)
   pwm.setPWM(3,0,pulseWidth(180));  //front body (left)
   pwm.setPWM(4,0,pulseWidth(30));   //front body (right)
   pwm.setPWM(5,0,pulseWidth(180));   //front leg (left)
   pwm.setPWM(6,0,pulseWidth(0));  //front leg (right)
   pwm.setPWM(7,0,pulseWidth(30));   //rear body (left)
   pwm.setPWM(8,0,pulseWidth(180));  //rear body (right)
   pwm.setPWM(9,0,pulseWidth(150));  //rear leg (right)
   pwm.setPWM(10,0,pulseWidth(30));  //rear leg (left)
   pwm.setPWM(11,0,pulseWidth(60)); //Tail
   delay(5000);
   
   pwm.setPWM(2,0,pulseWidth(45));   //center body (Neck)
   pwm.setPWM(5,0,pulseWidth(70));   //front leg (left)
   pwm.setPWM(6,0,pulseWidth(120));  //front leg (right)
   pwm.setPWM(11,0,pulseWidth(30)); //Tail
   delay(1000);

   pwm.setPWM(2,0,pulseWidth(115));   //center body (Neck)
   pwm.setPWM(9,0,pulseWidth(110));  //rear leg (right)
   pwm.setPWM(10,0,pulseWidth(70));  //rear leg (left)
   pwm.setPWM(11,0,pulseWidth(60)); //Tail
   delay(1000);

   pwm.setPWM(2,0,pulseWidth(115));   //center body (Neck)
   pwm.setPWM(9,0,pulseWidth(90));  //rear leg (right)
   pwm.setPWM(10,0,pulseWidth(90));  //rear leg (left)
   pwm.setPWM(11,0,pulseWidth(60)); //Tail
   delay(1000);
   
   pwm.setPWM(3,0,pulseWidth(90));  //front body (left)
   pwm.setPWM(4,0,pulseWidth(50));   //front body (right)
   pwm.setPWM(5,0,pulseWidth(60));   //front leg (left)
   pwm.setPWM(6,0,pulseWidth(120));  //front leg (right)
   pwm.setPWM(7,0,pulseWidth(50));   //rear body (left)
   pwm.setPWM(8,0,pulseWidth(180));  //rear body (right)
   pwm.setPWM(9,0,pulseWidth(70));  //rear leg (right)
   pwm.setPWM(10,0,pulseWidth(80));  //rear leg (left)
   pwm.setPWM(11,0,pulseWidth(60)); //Tail
   delay(2000);

   
}

//Crawling 'b'//
void crawling_in_reverse(){
  Serial.println(" Crawling in reverse...");
  pwm.setPWM(2,0,pulseWidth(45));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(90));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(90));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(90));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(90));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(90));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(90));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(90));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(90));  //rear leg (left)
  delay(3000);

  pwm.setPWM(2,0,pulseWidth(115));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(180));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(90));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(120));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(90));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(10));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(90));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(90));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(50));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(45));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(90));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(50));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(90));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(60));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(90));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(130));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(120));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(90));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(115));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(180));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(90));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(120));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(90));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(10));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(90));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(90));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(50));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(45));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(90));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(50));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(90));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(60));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(90));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(130));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(120));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(90));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(115));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(180));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(90));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(120));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(90));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(10));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(90));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(90));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(50));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(45));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(90));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(50));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(90));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(60));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(90));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(130));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(120));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(90));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(115));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(180));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(90));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(120));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(90));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(10));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(90));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(90));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(50));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(45));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(90));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(50));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(90));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(60));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(90));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(130));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(120));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(90));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(115));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(180));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(90));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(120));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(90));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(10));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(90));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(90));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(50));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(45));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(90));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(50));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(90));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(60));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(90));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(130));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(120));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(90));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(115));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(180));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(90));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(120));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(90));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(10));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(90));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(90));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(50));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(45));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(90));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(50));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(90));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(60));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(90));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(130));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(120));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(90));  //rear leg (left)
  delay(1000);
}

//Crawling 'c'
void crawling(){
  Serial.println(" Crawling position...");
   pwm.setPWM(2,0,pulseWidth(45));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(90));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(90));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(90));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(90));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(90));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(90));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(90));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(90));  //rear leg (left)
  delay(3000);

  pwm.setPWM(2,0,pulseWidth(115));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(180));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(90));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(120));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(90));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(10));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(90));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(90));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(50));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(45));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(60));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(50));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(90));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(60));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(90));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(150));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(120));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(90));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(115));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(180));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(90));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(120));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(90));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(10));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(90));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(90));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(50));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(45));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(60));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(50));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(90));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(60));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(90));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(130));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(120));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(90));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(115));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(180));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(90));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(120));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(90));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(10));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(90));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(90));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(50));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(45));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(60));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(50));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(90));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(60));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(90));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(130));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(120));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(90));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(115));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(180));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(90));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(120));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(90));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(10));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(90));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(90));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(50));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(45));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(60));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(50));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(90));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(60));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(90));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(130));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(120));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(90));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(115));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(180));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(90));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(120));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(90));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(10));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(90));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(90));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(50));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(45));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(60));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(50));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(90));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(60));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(90));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(130));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(120));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(90));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(115));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(180));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(90));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(120));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(90));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(10));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(90));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(90));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(50));  //rear leg (left)
  delay(1000);

  pwm.setPWM(2,0,pulseWidth(45));   //center body (Neck)
  pwm.setPWM(3,0,pulseWidth(60));  //front body (left)
  pwm.setPWM(4,0,pulseWidth(50));   //front body (right)
  pwm.setPWM(5,0,pulseWidth(90));   //front leg (left)
  pwm.setPWM(6,0,pulseWidth(60));  //front leg (right)
  pwm.setPWM(7,0,pulseWidth(90));   //rear body (left)
  pwm.setPWM(8,0,pulseWidth(130));  //rear body (right)
  pwm.setPWM(9,0,pulseWidth(120));  //rear leg (right)
  pwm.setPWM(10,0,pulseWidth(90));  //rear leg (left)
  delay(1000);

}

void walking(){
 Serial.println(" Walking...");
   pwm.setPWM(2,0,pulseWidth(115));   //center body (Neck)
   pwm.setPWM(3,0,pulseWidth(180));  //front body (left)
   pwm.setPWM(4,0,pulseWidth(30));   //front body (right)
   pwm.setPWM(5,0,pulseWidth(180));   //front leg (left)
   pwm.setPWM(6,0,pulseWidth(0));  //front leg (right)
   pwm.setPWM(7,0,pulseWidth(30));   //rear body (left)
   pwm.setPWM(8,0,pulseWidth(180));  //rear body (right)
   pwm.setPWM(9,0,pulseWidth(150));  //rear leg (right)
   pwm.setPWM(10,0,pulseWidth(30));  //rear leg (left)
   pwm.setPWM(11,0,pulseWidth(60)); //Tail
   delay(5000);
   
   pwm.setPWM(2,0,pulseWidth(45));   //center body (Neck)
   pwm.setPWM(5,0,pulseWidth(70));   //front leg (left)
   pwm.setPWM(6,0,pulseWidth(120));  //front leg (right)
   pwm.setPWM(11,0,pulseWidth(30)); //Tail
   delay(1000);

   pwm.setPWM(2,0,pulseWidth(115));   //center body (Neck)
   pwm.setPWM(9,0,pulseWidth(110));  //rear leg (right)
   pwm.setPWM(10,0,pulseWidth(70));  //rear leg (left)
   pwm.setPWM(11,0,pulseWidth(60)); //Tail
   delay(1000);

   pwm.setPWM(2,0,pulseWidth(115));   //center body (Neck)
   pwm.setPWM(9,0,pulseWidth(90));  //rear leg (right)
   pwm.setPWM(10,0,pulseWidth(90));  //rear leg (left)
   pwm.setPWM(11,0,pulseWidth(60)); //Tail
   delay(1000);
   
   pwm.setPWM(3,0,pulseWidth(90));  //front body (left)
   pwm.setPWM(4,0,pulseWidth(50));   //front body (right)
   pwm.setPWM(5,0,pulseWidth(60));   //front leg (left)
   pwm.setPWM(6,0,pulseWidth(120));  //front leg (right)
   pwm.setPWM(7,0,pulseWidth(50));   //rear body (left)
   pwm.setPWM(8,0,pulseWidth(180));  //rear body (right)
   pwm.setPWM(9,0,pulseWidth(70));  //rear leg (right)
   pwm.setPWM(10,0,pulseWidth(80));  //rear leg (left)
   pwm.setPWM(11,0,pulseWidth(60)); //Tail
   delay(2000);

   pwm.setPWM(3,0,pulseWidth(90));  //front body (left)
   pwm.setPWM(4,0,pulseWidth(90));   //front body (right)
   pwm.setPWM(5,0,pulseWidth(10));   //front leg (left)
   pwm.setPWM(6,0,pulseWidth(160));  //front leg (right)
   delay(2000);
   
   pwm.setPWM(7,0,pulseWidth(90));   //rear body (left)
   pwm.setPWM(8,0,pulseWidth(90));  //rear body (right)
   pwm.setPWM(9,0,pulseWidth(40));  //rear leg (right)
   pwm.setPWM(10,0,pulseWidth(180));  //rear leg (left)
   delay(2000);

   //Left//

   //Right//
    pwm.setPWM(4,0,pulseWidth(100));   //front body (right)
    pwm.setPWM(6,0,pulseWidth(160));  //front leg (right)
    pwm.setPWM(8,0,pulseWidth(120));  //rear body (right)
    delay(1000);
    pwm.setPWM(9,0,pulseWidth(40));  //rear leg (right)
    delay(1000);

    //Left//
    pwm.setPWM(3,0,pulseWidth(80));  //front body (left)
    pwm.setPWM(5,0,pulseWidth(10));   //front leg (left)
    pwm.setPWM(7,0,pulseWidth(70));   //rear body (left)
    pwm.setPWM(10,0,pulseWidth(120));  //rear leg (left)

    pwm.setPWM(4,0,pulseWidth(80));   //front body (right)
    pwm.setPWM(6,0,pulseWidth(180));  //front leg (right)
    pwm.setPWM(8,0,pulseWidth(90));  //rear body (right)
    delay(2000);
    pwm.setPWM(9,0,pulseWidth(40));  //rear leg (right)
    delay(2000);

//step
    pwm.setPWM(3,0,pulseWidth(60));  //front body (left)
    pwm.setPWM(5,0,pulseWidth(10));   //front leg (left)
    delay(2000);
    pwm.setPWM(8,0,pulseWidth(120));  //rear body (right)
    pwm.setPWM(9,0,pulseWidth(40));  //rear leg (right)
    delay(2000);

    pwm.setPWM(4,0,pulseWidth(100));   //front body (right)
    pwm.setPWM(6,0,pulseWidth(180));  //front leg (right)
    delay(2000);
    pwm.setPWM(7,0,pulseWidth(60));   //rear body (left)
    pwm.setPWM(10,0,pulseWidth(120));  //rear leg (left)
    delay(2000);

    

    pwm.setPWM(3,0,pulseWidth(60));  //front body (left)
    pwm.setPWM(5,0,pulseWidth(10));   //front leg (left)
    delay(2000);
    pwm.setPWM(8,0,pulseWidth(120));  //rear body (right)
    pwm.setPWM(9,0,pulseWidth(40));  //rear leg (right)
    delay(2000);

    pwm.setPWM(4,0,pulseWidth(100));   //front body (right)
    pwm.setPWM(6,0,pulseWidth(180));  //front leg (right)
    delay(2000);
    pwm.setPWM(7,0,pulseWidth(60));   //rear body (left)
    pwm.setPWM(10,0,pulseWidth(120));  //rear leg (left)
    delay(2000);

    pwm.setPWM(3,0,pulseWidth(60));  //front body (left)
    pwm.setPWM(5,0,pulseWidth(10));   //front leg (left)
    delay(2000);
    pwm.setPWM(8,0,pulseWidth(120));  //rear body (right)
    pwm.setPWM(9,0,pulseWidth(40));  //rear leg (right)
    delay(2000);

    pwm.setPWM(4,0,pulseWidth(100));   //front body (right)
    pwm.setPWM(6,0,pulseWidth(180));  //front leg (right)
    delay(2000);
    pwm.setPWM(7,0,pulseWidth(60));   //rear body (left)
    pwm.setPWM(10,0,pulseWidth(120));  //rear leg (left)
    delay(2000);

    pwm.setPWM(3,0,pulseWidth(60));  //front body (left)
    pwm.setPWM(5,0,pulseWidth(10));   //front leg (left)
    delay(2000);
    pwm.setPWM(8,0,pulseWidth(120));  //rear body (right)
    pwm.setPWM(9,0,pulseWidth(40));  //rear leg (right)
    delay(2000);

    pwm.setPWM(4,0,pulseWidth(100));   //front body (right)
    pwm.setPWM(6,0,pulseWidth(180));  //front leg (right)
    delay(2000);
    pwm.setPWM(7,0,pulseWidth(60));   //rear body (left)
    pwm.setPWM(10,0,pulseWidth(120));  //rear leg (left)
    delay(2000);
    
}
