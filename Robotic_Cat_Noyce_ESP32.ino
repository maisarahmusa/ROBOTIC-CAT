// http://arduino.esp8266.com/stable/package_esp8266com_index.json

#include <Arduino.h>
#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>
#include "Wire.h"
#include "Adafruit_PWMServoDriver.h"

#define MIN_PULSE_WIDTH 600
#define MAX_PULSE_WIDTH 2600
#define FREQUENCY 50

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
AsyncWebServer server(80);

const char* ssid = "musas66 2.4Ghz@unifi";
const char* password = "31400226";

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
  <style>
    body {
      text-align: center;
      font-family: "Trebuchet MS", Arial;
      margin-left:auto;
      margin-right:auto;
    }
    .slider {
      width: 300px;
    }
  </style>
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
</head>
<body>
  <h1>NodeMCU with Servo</h1>
  <p>Position: <span id="servoPos"></span></p>
  0:<input type="range" min="0" max="180" class="slider" id="0" onchange="updateSliderPWM(this)"/><br>
  1:<input type="range" min="0" max="180" class="slider" id="1" onchange="updateSliderPWM(this)"/><br>
  2:<input type="range" min="0" max="180" class="slider" id="2" onchange="updateSliderPWM(this)"/><br>
  3:<input type="range" min="0" max="180" class="slider" id="3" onchange="updateSliderPWM(this)"/><br>
  4:<input type="range" min="0" max="180" class="slider" id="4" onchange="updateSliderPWM(this)"/><br>
  5:<input type="range" min="0" max="180" class="slider" id="5" onchange="updateSliderPWM(this)"/><br>
  6:<input type="range" min="0" max="180" class="slider" id="6" onchange="updateSliderPWM(this)"/><br>
  7:<input type="range" min="0" max="180" class="slider" id="7" onchange="updateSliderPWM(this)"/><br>
  8:<input type="range" min="0" max="180" class="slider" id="8" onchange="updateSliderPWM(this)"/><br>
  9:<input type="range" min="0" max="180" class="slider" id="9" onchange="updateSliderPWM(this)"/><br>
  10:<input type="range" min="0" max="180" class="slider" id="10" onchange="updateSliderPWM(this)"/><br>
  11:<input type="range" min="0" max="180" class="slider" id="11" onchange="updateSliderPWM(this)"/><br>
  12:<input type="range" min="0" max="180" class="slider" id="12" onchange="updateSliderPWM(this)"/><br>
  13:<input type="range" min="0" max="180" class="slider" id="13" onchange="updateSliderPWM(this)"/><br>
  14:<input type="range" min="0" max="180" class="slider" id="14" onchange="updateSliderPWM(this)"/><br>
  15:<input type="range" min="0" max="180" class="slider" id="15" onchange="updateSliderPWM(this)"/><br>
  <script>
    function updateSliderPWM(element) {
      var servonumber = element.id
  var sliderValue = document.getElementById(servonumber).value;
  console.log("servo "+servonumber+" set at "+sliderValue);
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/set?servo="+servonumber+"&angle="+sliderValue, true);
  xhr.send();
}
  </script>
</body>
</html>
)rawliteral";

int pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  return analog_value;
}

void notFound(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Not found");
}

void setup() {
    pwm.begin();
    pwm.setPWMFreq(FREQUENCY);
    Serial.begin(115200);
  
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.printf("WiFi Failed!\n");
        return;
    }

    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    
    // Display webpage
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/html", index_html);
    });

    // Send a GET request to <IP>/set?servo=x&angle=xxx
    server.on("/set", HTTP_GET, [] (AsyncWebServerRequest *request) {
        String servo;
        String angle;
        int servo_int;
        int angle_int;
        if (request->hasParam("servo")) 
        {
          if (request->hasParam("angle")) 
          {
            servo = request->getParam("servo")->value();
            angle = request->getParam("angle")->value();
            Serial.println("servo "+servo+" set at "+angle);
            servo_int = servo.toInt();
            angle_int = angle.toInt();
            pwm.setPWM(servo_int, 0, pulseWidth(180-angle_int));
            String message = "Set servo "+servo+" to "+angle+" degrees.";
            request->send(200, "text/plain", message);
          }
        }
    });

    // Send a GET request to <IP>/setmany?servo1=90&servo2=180....
    server.on("/setmany", HTTP_GET, [] (AsyncWebServerRequest *request) {
      for (int i = 0; i < 180; i++)
      {
        if (request->hasParam("servo"+String(i))) 
        {
          String angle = request->getParam("servo"+String(i))->value();
          int angle_int = angle.toInt();
          pwm.setPWM(i, 0, pulseWidth(180-angle_int));
          Serial.println("Set servo "+String(i)+" to angle "+String(angle));
        }
      }
      request->send(200, "text/plain", "All set.");
    });

    server.onNotFound(notFound);

    server.begin();
}

void loop() {
}
