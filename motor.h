#include "motorPins.h"

/*
PWM interval
*/
#define MOTOR_PERIOD 5

#define FORWARD_ROTATE 0
#define REVERSE_ROTATE 1

/*
==========L298N Functions==========
*/

void setPWM(uint8_t port, uint8_t pwm);
void setPWMTime(uint8_t port, uint8_t pwm, int ms);
void setAnalogPWMTime(uint8_t port, uint8_t pwm, int ms);

void stopMotor(Motor motor);
void setMotor(Motor motor, bool direction, uint8_t speed, int ms);

/*
Name: stopMotor
Function: To stop a motor.
*/

void stopMotor(Motor motor)
{
  pinMode(motor.pin0, OUTPUT);
  pinMode(motor.pin1, OUTPUT);

  digitalWrite(motor.pin0, LOW);
  digitalWrite(motor.pin1, LOW);
}

/*
Name: setMotor
Function: To set a motor's parameters.
'motor' provides the pins, 'direction' is the direction of the rotation,
'speed' corresponds with PWM parameter, 'ms' is the lasting time in the unit of
milliseconds.
*/

void setMotor(Motor motor, bool direction, uint8_t speed, int ms)
{
  pinMode(motor.pin0, OUTPUT);
  pinMode(motor.pin1, OUTPUT);

  uint8_t negativePin = (direction)? motor.pin0 : motor.pin1;
  uint8_t positivePin = (direction)? motor.pin1 : motor.pin0;

  digitalWrite(negativePin, LOW);
  setPWMTime(positivePin, speed, ms);
}

/*
Name: setPWM
Function: set the port's PWM mannually, 'port' is the number of the pin
and 'pwm' is the width. The range of 'pwm' is 0 ~ 255.
MOTOR_PERIOD is the lasting time of one period which can be modified if necessary.
*/

void setPWM(uint8_t port, uint8_t pwm)
{
  pinMode(port, OUTPUT);
  pwm = (pwm < 256) ? pwm : 255;
  digitalWrite(port, HIGH);
  int i;
  for(i = 0; i < pwm; i ++)
  {
    delayMicroseconds(MOTOR_PERIOD);
  }
  digitalWrite(port, LOW);
  for(i = pwm; i < 255; i ++)
  {
    delayMicroseconds(MOTOR_PERIOD);
  }
}


/*
Name: setPWMTime
Function: Using the 'setPWM' function for a certain time. The lasting time
is defined by 'ms', with the unit milliseconds.
*/

void setPWMTime(uint8_t port, uint8_t pwm, int ms)
{
  int time = micros();
  while(ms)
  {
    setPWM(port, pwm);
    if(micros() - time >= 1000)
    {
      time = micros();
      ms --;
    }
  }
}

/*
Name: setAnalogPWMTime
Function: Using the 'analogWrite' function for a certain time. The lasting time
is defined by 'ms', with the unit milliseconds.
*/

void setAnalogPWMTime(uint8_t port, uint8_t pwm, int ms)
{
  int time = micros();
  analogWrite(port, pwm);
  while(ms)
  {
    if(micros() - time >= 1000)
    {
      time = micros();
      ms --;
    }
  }
}