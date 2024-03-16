#include <Servo.h>
int speed;
int transmission;
Servo motor1;
Servo motor2;


void setup() {
    motor1.atach(10);
    motor2.atach(9);
    motor1.writeMicroseconds(800);
    motor2.writeMicroseconds(800);
    delay(5000);
    Serial.println("Servo is starting");

}

void loop(){
  if (softSerial.avaible()>0) {
    status
    
    speed = Serial.read();
    Serial.println(speed);

    speed = map(speed,800,2100);
    

    motor1 = writeMicroseconds(val);
    motor2 = writeMicroseconds(val);
    transmission = map(transmission,0,9);

    speed = (transmission * 144) + 800;
    

  }











}