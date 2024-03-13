#include <Servo.h>   
 Servo motor1;
 Servo motor2;
int left; //для напрвления моторами влево
int right;//для напрвления моторами вправо 
int val;
int LED = 13;
void setup()
{

   motor1.attach(5);
   motor2.attach(6);
   motor1.writeMicroseconds(800); //готовим мотор к работе
   motor2.writeMicroseconds(800); //готовим мотор к работе
   delay(2000);



}

void loop()
{
  
  if (Serial.available())
  {
    val = Serial.read();
    
    switch_speed = constrain(switch_speed,800,2100);
    
    
    
    if (val == 'F')//вперёд
    {
      motor1.writeMicroseconds(1000);
      motor2.writeMicroseconds(1000);
      digitalWrite(LED, HIGH);
    }

    
    
    
    if ( val == 'B')//назад
    {
      motor1.writeMicroseconds(1000);
      motor2.writeMicroseconds(1000);
      Serial.println("Right");
      digitalWrite(LED, LOW);
    }
    
    
    if ( val == 'L')//лево
    {
      motor1.writeMicroseconds(1000);
      motor2.writeMicroseconds(1500);
      Serial.println("Left");
      
      digitalWrite(LED, LOW);
    }
    
    
    if ( val == 'R')//вправо
    {
      motor1.writeMicroseconds(1500);
      motor2.writeMicroseconds(1000);
      Serial.print("Right");
    }
    
    
    if ( val == 'B')//назад
    {

      digitalWrite(LED, LOW);
    
    
    }
  }
}