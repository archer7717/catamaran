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
    Serial.begin(9600);
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
      transmission = int(signal-48);
       Serial.println(transmission); 
     }
    
    
    
    speed = Serial.read();
    


    speed = constrain(speed,800,2100);
    
    

    motor1.writeMicroseconds(speed);
    motor2.writeMicroseconds(speed);
    transmission = constrain(transmission,0, 9);

    speed = (transmission * 144) + 800;
    left = speed;
    right = speed;
    
    if (signal == 'L')
    {

     left = (transmission+1) *144+800;
      Serial.println(left);
      }
    if (signal == 'F')
    {
      motor1.writeMicroseconds(speed);
      motor2.writeMicroseconds(speed);
       Serial.println("forward");
      }
    
    if (signal == 'R')
    {
      
      right = (transmission+1)*144+800;
      Serial.println(right);
      }

    
  motor1.writeMicroseconds(right);
  motor2.writeMicroseconds(left);
  }











}
