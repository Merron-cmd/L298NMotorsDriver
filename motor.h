/*
PWM interval
*/
#define motor_period 5

/*
==========L298N Functions==========
*/

void setPWM(uint8_t port, uint8_t pwm);
void setPWMTime(uint8_t port, uint8_t pwm, int ms);

void setPWM(uint8_t port, uint8_t pwm)
{
  pinMode(port, OUTPUT);
  pwm = (pwm < 256) ? pwm : 255;
  digitalWrite(port, HIGH);
  int i;
  for(i = 0; i < pwm; i ++)
  {
    delayMicroseconds(motor_period);
  }
  digitalWrite(port, LOW);
  for(i = pwm; i < 255; i ++)
  {
    delayMicroseconds(motor_period);
  }
}

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