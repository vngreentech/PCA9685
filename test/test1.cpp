#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver mod_1 = Adafruit_PWMServoDriver(0x40);

#define SERVOMIN  90 //độ dài xung tối thiểu; xung PPM
#define SERVOMAX  600

int topulse(int goc) //chuyển góc thành xung
{
  int xung = map(goc, 0, 180, SERVOMIN, SERVOMAX);
  return xung;
}

void setup() 
{
  Serial.begin(115200);

  mod_1.begin();
  mod_1.setOscillatorFrequency(27000000);
  mod_1.setPWMFreq(60);
}

void loop() 
{
  for(int goc=0; goc<=180; goc+=10)
  {
    delay(100);
    mod_1.setPWM(15, 0, topulse(goc)); //4096
  }

  delay(1000);

  for(int goc=180; goc>=0; goc-=10)
  {
    delay(100);
    mod_1.setPWM(15, 4096, topulse(goc));
  }

  delay(1000);
}