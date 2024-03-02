// подключение библиотеки
#include <Servo.h>
// создание объекта
Servo motor;
//Пин подключения мотора
int mot_pin = 9;

void setup()
{
  // инициализация мотора
  motor.attach(mot_pin);
  Serial.begin(9600);
}

void loop()
{
   // регулирование потенциометром
   int speed=map(analogRead(A0),1023,0,800,2300);
   Serial.println(speed);
   motor.writeMicroseconds(speed);
   delay(20);
}