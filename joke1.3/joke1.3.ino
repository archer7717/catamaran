#include <Servo.h> 

#include <iarduino_Pressure_BMP.h>   // Подключаем библиотеку для работы с датчиками BMP180 или BMP280
iarduino_Pressure_BMP sensor;
int speed;
int myservo;//сервопривод для поднятие и опускания контейнера с датчиками
int left;
int right;
 // переменная для скорости катамарана с 800 2100
char signal; // переменная для принятия сигнала с Блютуз
int  transmition; // переменная для счётчика передачи 
Servo motor1;
Servo motor2;
Servo myservo;






void setup() {
  Serial.begin(9600);
  motor1.attach(9);
  motor2.attach(10);
  myservo.attach(11);

  motor1.writeMicroseconds(800);
  motor2.writeMicroseconds(800);
  delay(5000);
  motor1.writeMicroseconds(2100);
  motor2.writeMicroseconds(2100);
  delay(5000);
  Serial.println("Servo is starting");

}

void loop() {

   if(sensor.read(1))                 {
    Serial.println((String)"P = " + sensor.pressure + "\tMM.PT.CT, \t T = " + sensor.temperature + " *C, \t\t B = "+sensor.altitude+" M.");
    }
  
  else                               {Serial.println("HET OTBETA OT CEHCOPA");}
                                     // Читаем показания (давление возвращается в Па)
  if(sensor.read(2))                 {
    Serial.println((String)"P = " + sensor.pressure + "\tPa, \t\t T = "     + sensor.temperature + " *C, \t\t B = "+sensor.altitude+" M.");
    }
  
  else                               {Serial.println("HET OTBETA OT CEHCOPA");}
 


 if (Serial.available()>0)
    {
    signal = Serial.read();

     if (isDigit(signal))
     {
      transmition = int(signal-48);
      Serial.println(transmition); 
     }

      transmition = ((transmition)<(0)?(0):((transmition)>(9)?(9):(transmition)));
      speed = ((speed)<(800)?(800):((speed)>(2100)?(2100):(speed)));

      speed = (transmition * 144) + 800;
      left = speed;
      right = speed;
      motor1.writeMicroseconds(speed);
      motor2.writeMicroseconds(speed);

      if (signal == 'F')
      {
      motor1.writeMicroseconds(speed);
      motor2.writeMicroseconds(speed);
       Serial.println("forward");
       Serial.println(speed);
      }

      if (signal == 'L')
      {
         Serial.begin(9600);
        left = (transmition * 144) + 800;
        Serial.println("left");
        Serial.println(speed);
        
      }

            if (signal == 'R')
      {
         Serial.begin(9600);
        right = (transmition * 144) + 800;
        Serial.println("right");
        Serial.println(speed);
      }




            if (signal == 'X')
      {
         Serial.begin(9600);
      myservo.write(180);
      delay(15000);
      myservo.write(0);

      }


            if (signal == 'x')
      {
         Serial.begin(9600);
      myservo.write(0);

      }


      motor1.writeMicroseconds(left);
      motor1.writeMicroseconds(right);
      
     
  }
}