
/*
1 Отрегулировать мотор от 800 до 2800 за 3 секунды (void setup)
2 Полключение блютуз модуля  (void loop) 


*/







// подключение библиотеки
#include <Servo.h>
int val = 800;
// создание объекта
Servo motor1;
Servo motor2;
//Пин подключения мотора
char v;
int sp;
int turnR;
int turnL;
void setup()
{
  
  Serial.begin(9600);
  motor1.attach(2);
  motor2.attach(3);
  motor1.writeMicroseconds(800);
  motor2.writeMicroseconds(800);
  delay(5000);
  motor1.writeMicroseconds(2800);
  motor2.writeMicroseconds(2800);
  delay(1000);
  Serial.println("Motor is ready");
}

void loop()
{
  if (Serial.available()>0)
  { 
    v = Serial.read(); 
    Serial.println(v);
    
    if (isdigit(v)){
      //Serial.println(v);
      sp = int(v-48);
      Serial.println(sp);
    }
    sp = constrain(sp, 0, 9);
    //Serial.println(sp);

        
    //Serial.println(sp);
    val = sp*167 + 800;
    //val++;
    val = constrain(val, 805, 2100);
    motor1.writeMicroseconds(val);
    motor2.writeMicroseconds(val);
    turnR = val;
    turnL = val;
    //Serial.println(val);
    
    if (v == 'R' )
    {
      turnR = (sp+1)*167+800;   
      Serial.println('turnR'); 
    }
    if (v == 'L')
    {
      turnL = (sp+1)*167+800;   
      Serial.println('turnL'); 
    }
    
  
  motor1.writeMicroseconds(turnR);
  motor2.writeMicroseconds(turnL); 
    
    }
 
}
