/*
first H-BRIDGE = LEFT 
seccond H-BRIDGE = RIGHT 
Third H-BRIDGE = UP,DOWN
fourth H-BRIDGE  = FWR ,BWR
*/
void setup(){
for(int i = 2 ; i <=13;i++)
  pinMode(i,OUTPUT);
Serial.begin(9600);
}
void move_motors(string m_char, int acc){
  if (m_char == 'f'){
    analogWrite(2,acc);
    digitalWrite(3,LOW);
    analogWrite(4,acc);
    digitalWrite(5,LOW);
  }
  else if(m_char == 'b')
  {
    analogWrite(2,acc);
    digitalWrite(3,HIGH);
    analogWrite(4,acc);
    digitalWrite(5,HIGH);
  }
  else if(m_char == 'l')
  {
    analogWrite(2,acc);
    digitalWrite(3,HIGH);
    analogWrite(4,acc);
    digitalWrite(5,LOW);
  }
    else if(m_char == 'r')
  {
    analogWrite(2,acc);
    digitalWrite(3,LOW);
    analogWrite(4,acc);
    digitalWrite(5,HIGH);
  }
    else if(m_char == 'u')
  {
    analogWrite(6,acc);
    digitalWrite(7,LOW);
    analogWrite(8,acc);
    digitalWrite(9,LOW);
  }
    else if(m_char == 'd')
  {
    analogWrite(6,acc);
    digitalWrite(7,HIGH);
    analogWrite(8,acc);
    digitalWrite(9,HIGH);
  } 
    else if (m_char == 'a')
    {
    analogWrite(6,acc);
    digitalWrite(7,HIGH);
    analogWrite(8,acc);
    digitalWrite(9,HIGH);
    analogWrite(2,acc);
    digitalWrite(3,LOW);
    analogWrite(4,acc);
    digitalWrite(5,LOW);
      
    }
    else if (m_char == 'c')
    {
    analogWrite(6,acc);
    digitalWrite(7,HIGH);
    analogWrite(8,acc);
    digitalWrite(9,HIGH);
    analogWrite(2,acc);
    digitalWrite(3,HIGH);
    analogWrite(4,acc);
    digitalWrite(5,HIGH);
      
    }    
    else if (m_char == 'k')
    {
    analogWrite(6,acc);
    digitalWrite(7,HIGH);
    analogWrite(8,acc);
    digitalWrite(9,HIGH);
    analogWrite(2,acc);
    digitalWrite(3,LOW);
    analogWrite(4,acc);
    digitalWrite(5,HIGH);
      
    }      
    else if (m_char == 'j')
    {
    analogWrite(6,acc);
    digitalWrite(7,HIGH);
    analogWrite(8,acc);
    digitalWrite(9,HIGH);
    analogWrite(2,acc);
    digitalWrite(3,HIGH);
    analogWrite(4,acc);
    digitalWrite(5,LOW);
      
    }    
    else if(m_char == 'z')
  {
  for(int i = 2 ; i <=9;i++)
    digitalWrite(i,LOW);
  } 
}
void loop(){
 if (Serial.available()){
char id = Serial.read();
int speedd=Serial.parseInt();
move_motors(id,speedd);
  }
}
