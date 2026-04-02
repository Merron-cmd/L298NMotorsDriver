/*
Motor port definition
*/
#define Motor1_0 3
#define Motor1_1 5


/*
PWM interval
*/
#define motor_period 5

/*
==========L298N Functions==========
*/

void setPWM(uint8_t port, uint8_t pwm);
void setPWMTime(uint8_t port, uint8_t pwm, int ms);

void setup() 
{
  Serial.begin(9600);
  pinMode(Motor1_0, OUTPUT);
  pinMode(Motor1_1, OUTPUT);
  digitalWrite(Motor1_0, LOW);
  setPWMTime(Motor1_1, 128, 10000);
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