#include <Servo.h>

Servo myservo;
int angle = 90;

void setup()
{
  myservo.attach(9);
  myservo.write(100);
  delay(150);
  myservo.detach();
  Serial.begin(9600);
  for (int i = 30; i <= 45; i++){
     pinMode(i, OUTPUT);
     digitalWrite(i, LOW);
  }
  pinMode(3,OUTPUT);  
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  analogWrite(3, 255);
}
//void down_with(){
//    digitalWrite(38, LOW);
//  digitalWrite(39, HIGH);
//  digitalWrite(40, LOW);
//  digitalWrite(41, HIGH);
//  digitalWrite(42, LOW);
//  digitalWrite(43, HIGH);
//  digitalWrite(44, LOW);
//  digitalWrite(45, HIGH);
//  
//   digitalWrite(30, LOW);
//  digitalWrite(31, HIGH);
//  digitalWrite(32, LOW);
//  digitalWrite(33, HIGH);
//  digitalWrite(34, LOW);
//  digitalWrite(35, HIGH);
//  digitalWrite(36, LOW);
//  digitalWrite(37, HIGH);
//
//  
//  }
void up(){
  digitalWrite(38, HIGH);
  digitalWrite(39, LOW);
  digitalWrite(40, HIGH);
  digitalWrite(41, LOW);
  digitalWrite(42, HIGH);
  digitalWrite(43, LOW);
  digitalWrite(44, HIGH);
  digitalWrite(45, LOW);  
}
void narrowRight(){
  digitalWrite(30, HIGH);
  digitalWrite(31, LOW);
  digitalWrite(32, HIGH);
  digitalWrite(33, LOW);
  digitalWrite(34, LOW);
  digitalWrite(35, HIGH);
  digitalWrite(36, LOW);
  digitalWrite(37, HIGH);   
}
void narrowLeft(){
  digitalWrite(30, LOW);
  digitalWrite(31, HIGH);
  digitalWrite(32, LOW);
  digitalWrite(33, HIGH);
  digitalWrite(34, HIGH);
  digitalWrite(35, LOW);
  digitalWrite(36, HIGH);
  digitalWrite(37, LOW);
  
}
void forward(){
  digitalWrite(30, LOW);
  digitalWrite(31, HIGH);
  digitalWrite(32, LOW);
  digitalWrite(33, HIGH);
  digitalWrite(34, LOW);
  digitalWrite(35, HIGH);
  digitalWrite(36, LOW);
  digitalWrite(37, HIGH);

}
void down(){
  digitalWrite(38, LOW);
  digitalWrite(39, HIGH);
  digitalWrite(40, LOW);
  digitalWrite(41, HIGH);
  digitalWrite(42, LOW);
  digitalWrite(43, HIGH);
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
}
void backward(){
  digitalWrite(30, HIGH);
  digitalWrite(31, LOW);
  digitalWrite(32, HIGH);
  digitalWrite(33, LOW);
  digitalWrite(34, HIGH);
  digitalWrite(35, LOW);
  digitalWrite(36, HIGH);
  digitalWrite(37, LOW);
}
void reset(){  
  digitalWrite(30, LOW);
  digitalWrite(31, LOW);
  digitalWrite(32, LOW);
  digitalWrite(33, LOW);
  digitalWrite(34, LOW);
  digitalWrite(35, LOW);
  digitalWrite(36, LOW);
  digitalWrite(37, LOW);
  digitalWrite(38, LOW);
  digitalWrite(39, LOW);
  digitalWrite(40, LOW);
  digitalWrite(41, LOW);
  digitalWrite(42, LOW);
  digitalWrite(43, LOW);
  digitalWrite(44, LOW);
  digitalWrite(45, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);   
}

void open(){
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH); 
}
void close(){
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);   
}

void loop(){
  myservo.write(90);
  if (Serial.available()){
    char msg = Serial.read();
    if (msg == 'z') reset();
    else if (msg == 'u') up();
    else if (msg == 'd') down();
    else if (msg == 'f') forward();
    else if (msg == 'b') backward();
    //else if (msg == 'c') wideRight();
    //else if (msg == 'a') wideLeft();
    else if (msg == 'r') narrowRight();
    else if (msg == 'l') narrowLeft();  
//    else if (msg == 't')  down_with();
    else if (msg == 'j' && angle < 140){
      myservo.attach(9);
      angle += 5;
      myservo.write(angle);
      Serial.println(angle);
      delay(150);
      myservo.detach();
    }
    else if (msg == 'g' && angle > 100){
      myservo.attach(9);
      angle -= 5;
      myservo.write(angle);
      Serial.println(angle);      
      delay(150);
      myservo.detach();      
    }
    else if (msg == 'p'){
      close();
    }
    else if (msg == 'i'){
      open();
    }
  }
}
