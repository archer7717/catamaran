#include <Servo.h>
char signal;
int speed;
int left;
int right;
int transmission;
Servo motor1;
Servo motor2;
int speedr;


void setup() {
  
    motor1.attach(10);
    motor2.attach(9);
    motor1.writeMicroseconds(800);
    motor2.writeMicroseconds(800);
    delay(5000);
    Serial.println("Servo is starting");

}

void loop()
{
  if (Serial.available()>0) {
     signal = Serial.read();
    
     if (isDigit(signal))
     {
      transmission = signal;
       Serial.println(transmission); 
     }
    
    
    
    speed = Serial.read();
    Serial.println(speed);

    speed = constrain(speed,800,2100);
    

    motor1.writeMicroseconds(speed);
    motor2.writeMicroseconds(speed);
    transmission = constrain(transmission,0, 9);

    speed = (transmission * 144) + 800;
    left = speed;
    right = speed;
    speedr = ((transmission - 1) * 144) + 800;
    if (signal == 'L')
    {

     motor1 = ((transmission + 1) * 144) + 800;
     motor2 = speedr;
      //left;
      Serial.println("left");
      }
    if (signal == 'F')
    {
      speed;
       Serial.println("forward")
      }
    
    if (signal == 'R')
    {
      
      speedr = motor1
      Serial.println("right");
      }

    if (signal == 'B')
    {
      speed = 0;
      Serial.println("stop");
      }
    
  motor1.writeMicroseconds(right);
  motor2.writeMicroseconds(left);
  }











}
