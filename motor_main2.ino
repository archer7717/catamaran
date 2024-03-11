#include <Servo.h>   
 Servo motor1;
 Servo motor2;
int left; //для напрвления моторами влево
int right;//для напрвления моторами вправо 
int val = 800;
int speed;
int LED = 13;
int v;
void setup()
{

   motor1.attach(5);
   motor2.attach(6);
   motor1.writeMicroseconds(800); //готовим мотор к работе
   motor2.writeMicroseconds(800); //готовим мотор к работе
   delay(2000);


  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
}

void loop()
{
  
  if (Serial.available())
  {
    v = Serial.read();
    Serial.println(v);

 if (isdigit(v)){
      //Serial.println(v);
      speed = int(v-48);  
      Serial.println(speed);
    }

    
    
    
    if (val == 'F')//вперёд
    {
      motor1.writeMicroseconds(1000);
      motor2.writeMicroseconds(1000);
      digitalWrite(LED, HIGH);
      Serial.println("Forward");
    }

    if (val == 'B')
    {
      motor1.writeMicroseconds(800);
      motor2.writeMicroseconds(800);
    
    }

     speed = constrain(sp, 0, 9);


    val = (speed*167) + 800;
    
    val = constrain(val,805,2100);

    motor1 = writeMicroseconds(val);
    motor2 = writeMicroseconds(val);
    left = val;
    right = val;

    
    
    /*if ( val == 'B')//назад
    {
      motor1.writeMicroseconds(1000);
      motor2.writeMicroseconds(1000);
      Serial.println("Right");
      digitalWrite(LED, LOW);
    }
    */
    
    if ( val == 'L')//лево
    {
      left = (sp*1+) + 800;
      Serial.println(left);
      
    }
    
    
    if ( val == 'R')//вправо
    {
     
    right = (sp*1+) + 800;

      motor1.writeMicroseconds(1500);
      motor2.writeMicroseconds(1000);
      Serial.print("Right");
    }

    if (val == 'B')//стоп 
    {
      motor1.writeMicroseconds(800);
      motor2.writeMicroseconds(800);
      
    
    }

    
      motor1.writeMicroseconds(turnR);
      motor2.writeMicroseconds(turnL); 


  }
}
