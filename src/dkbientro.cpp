#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver mod_1 = Adafruit_PWMServoDriver(0x40);

#define SERVOMIN  90
#define SERVOMAX  600

int bientro = A0;
int gt_bientro;

int goc;

int topulse(int goc)
{
  int xung = map(goc, 0, 180, SERVOMIN, SERVOMAX);
  return xung;
}

void setup() 
{
  Serial.begin(115200);
  mod_1.begin();

  pinMode(bientro, INPUT);

  mod_1.setOscillatorFrequency(27000000);
  mod_1.setPWMFreq(60);
}

void loop() 
{
    gt_bientro = analogRead(bientro);

    goc = map(gt_bientro, 0, 1023, 0, 180);

    mod_1.setPWM(0, 0, topulse(goc));

    Serial.print("Goc: "); Serial.println(goc);
}