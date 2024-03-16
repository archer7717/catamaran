
#include <Servo.h>
char val;
 Servo motor1;
 Servo motor2;


  int i=0; //Случайная переменная, назначенная циклам
  int j=0; //Случайная переменная, назначенная циклам
  int state; //Переменная сигнала от устройства Bluetooth
  int vSpeed;
void setup() {
   Serial.begin(9600); // подключаем последовательный порт
   motor1.attach(10); // привязываем сервопривод к выходу 10

  
   
   
}
 
void loop() {
  //Остановите автомобиль, когда соединение Bluetooth отключено.
 //(Удалите "//" подстроки для активации.)
//     if(digitalRead(BTState)==LOW) { state='S'; }

   
 if (Serial.available()) {
       state = Serial.read();
       val = Serial.read(); // переменная val равна полученной команде

       if (state == '1') { vSpeed = 30; } // при 1 поворачиваем серво на 10
       if (state == '2') { vSpeed = 45; } // при 2 поворачиваем серво на 45
       if (state == '3') { vSpeed = 60;} // при 3 поворачиваем серво на 90
       val = Serial.read();
   }
  //Сохранить входящие данные в переменную " состояние

  /***********************İleri****************************/
  //Если входящие данные "F" автомобиль идет вперед.
    if (val == 'F') {
      motor1.write(vSpeed);
      motor2.write(vSpeed);
    }
  /**********************İleri Sol************************/
  //Автомобиль идет вперед влево(по диагонали), если входящие данные " G.
    else if (state == 'G') {
      motor1.write(vSpeed);
      motor2.write(vSpeed); 
    }
  /**********************İleri Sağ************************/
  //Если входящие данные' I ' автомобиль идет вперед вправо(по диагонали).
    else if (state == 'I') {
      motor1.write(vSpeed);
      motor2.write(vSpeed);     
    }
  /***********************Geri****************************/
  //Автомобиль возвращается, если входящие данные " B.
    else if (state == 'B') {
      motor1.write(vSpeed);
      motor2.write(vSpeed); 
    }
  /**********************Geri Sol************************/
  //Если данные из ' H ' автомобиль возвращается влево(по диагонали) 
    else if (state == 'H') {
      motor1.write(vSpeed);
      motor2.write(vSpeed); 
    }
  /**********************Geri Sağ************************/
  //Если входящие данные 'J' автомобиль возвращается вправо(по диагонали)
    else if (state == 'J') {
      motor1.write(vSpeed);
      motor2.write(vSpeed);  
    }
  /***************************Sol*****************************/
  //Если входящие данные 'L' автомобиль идет влево.
    else if (state == 'L') {
      motor1.write(vSpeed);
      motor2.write(vSpeed); 
    }
  /***************************Sağ*****************************/
  //Если входящие данные 'R' автомобиль идет вправо
    else if (state == 'R') {
      motor1.write(vSpeed);
      motor2.write(vSpeed);    
    }
  
  /************************Stop*****************************/
  //Остановить автомобиль, если входящие данные' s.
    else if (state == 'S'){
      motor1.write(0);
      motor2.write(0); 
    }  
}

)