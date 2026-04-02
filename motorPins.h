/*
Motor port definition
*/
struct Motor
{
  uint8_t pin0;
  uint8_t pin1;
  //Define that when voltage on pin1 is higher than pin0, it's forward rotation. Vice versus.
};

/*
For UNO, following pins support PWM:
3, 5, 6, 9, 10, 11
*/
const bool pinIsAnalog[20] = {0};
pinIsAnalog[3] = true;
pinIsAnalog[5] = true;
pinIsAnalog[6] = true;
pinIsAnalog[9] = true;
pinIsAnalog[10] = true;
pinIsAnalog[11] = true;
