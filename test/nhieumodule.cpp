#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver mod_1 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver mod_2 = Adafruit_PWMServoDriver(0x41);
Adafruit_PWMServoDriver mod_3 = Adafruit_PWMServoDriver(0x42);

#define SERVOMIN  90 //độ dài xung tối thiểu
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
  mod_2.begin();
  mod_3.begin();

  mod_1.setOscillatorFrequency(27000000);
  mod_1.setPWMFreq(60);

  mod_2.setOscillatorFrequency(27000000);
  mod_2.setPWMFreq(60);

  mod_3.setOscillatorFrequency(27000000);
  mod_3.setPWMFreq(60);
}

void loop() 
{
  for(int goc=0; goc<=180; goc+=10)
  {
    delay(100);
    mod_1.setPWM(0, 0, topulse(goc)); //4096
  }
  delay(1000);

  for(int goc=180; goc>=0; goc-=10)
  {
    delay(100);
    mod_1.setPWM(0, 0, topulse(goc));
  }
  delay(1000);

  //////////////// Module 2 //////////////////////////////
  for(int goc=0; goc<=180; goc+=10)
  {
    delay(100);
    mod_2.setPWM(5, 0, topulse(goc)); //4096
  }
  delay(1000);

  for(int goc=180; goc>=0; goc-=10)
  {
    delay(100);
    mod_2.setPWM(5, 0, topulse(goc));
  }
  delay(1000);
}