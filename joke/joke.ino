#include <Servo.h>
int speed;
int left;
 // переменная для скорости катамарана с 800 2100
char signal; // переменная для принятия сигнала с Блютуз
int  transmition; // переменная для счётчика передачи 
Servo motor1;
Servo motor2;






void setup() {
  Serial.begin(9600);
  motor1.attach(9);
  motor1.attach(10);

  motor1.writeMicroseconds(800);
  motor2.writeMicroseconds(800);
  delay(5000);
  motor1.writeMicroseconds(2100);
  motor2.writeMicroseconds(2100);
  delay(5000);
  Serial.println("Servo is starting");

}

void loop() {
 if (Serial.available()>0)
    {
    signal = Serial.read();

     if (isDigit(signal))
     {
      transmition = int(signal-48);
      Serial.println(transmition); 

      transmition = ((transmition)<(0)?(0):((transmition)>(9)?(9):(transmition)));
      speed = ((speed)<(800)?(800):((speed)>(2100)?(2100):(speed)));
      
     }
  }
}
