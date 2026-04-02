#include "motor.h"

void setup() 
{
  Serial.begin(9600);
  while(!Serial);
  Serial.println(A0);
  /*pinMode(Motor1_0, OUTPUT);
  pinMode(Motor1_1, OUTPUT);
  digitalWrite(Motor1_0, LOW);
  setPWMTime(Motor1_1, 128, 10000);*/
  /*uint16_t time = micros();
  while(1)
  {
    setPWM(Motor1_1, 255);
  }
  time = micros();
  while(micros() - time <= 1000000)
  {
    setPWM(Motor1_1, 128);
  }*/
}

void loop()
{

}