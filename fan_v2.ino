//ARDUINO HOCAM TEMPERATURE CONTROLLED FAN v2
#include <OLED_I2C.h>
float Temperature;
float value;
int lm35pin = A3;
int motor = 3;
float x;
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
OLED  myOLED(SDA, SCL, 8);
void setup () {

  pinMode(motor, OUTPUT);
  myOLED.begin();

  myOLED.clrScr();

}

void loop () {
  value = analogRead(lm35pin); //read analog values from A0
  value = (value / 1023) * 5000; //converting analog value into mV
  Temperature = value / 10; // converting mV to Celcius
  myOLED.setFont(SmallFont);
  myOLED.print("SICAKLIK ^C ", 25, 0);
  myOLED.setFont(MediumNumbers);
  myOLED.printNumF(Temperature , 2, 30, 10);
  myOLED.setFont(SmallFont);

  myOLED.print("DONUS HIZI(0-255) ", 25, 35);
  myOLED.setFont(MediumNumbers);
  myOLED.printNumF(float(x), 1 , 30, 45);
  myOLED.update();


  if (Temperature >= 24 && Temperature <= 26)
  {
    x = 50;
    analogWrite(motor, x);
  }

  else if (Temperature > 26 && Temperature <= 28)
  { x = 80;
    analogWrite(motor, x);
  }
  else if (Temperature > 28 && Temperature <= 30)
  { x = 130;
    analogWrite(motor, x);
  }
  else if (Temperature > 30 && Temperature <= 32)
  {
    x = 190;
    analogWrite(motor, x);
  }
  else if (Temperature > 32 )
  {

    x = 255;
    analogWrite(motor, x);
  }
  else
  {
    x = 0;
    analogWrite(motor, 0);
  }
  delay(1000);
}
