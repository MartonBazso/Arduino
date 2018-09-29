#include <Servo.h>

int lefteye = 4; 
int righteye = 3;

int command;

Servo bh;
Servo jh;
Servo be;
Servo je;

int basebh = 85; //0 hátra,180 előre
int basejh = 95; //180 hátra,0 előre
int basebe = 85; //0 hátra,180 előre
int baseje = 75; //180 hátra,0 előre 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(lefteye,OUTPUT);
  pinMode(righteye,OUTPUT);
  
  digitalWrite(lefteye,HIGH);
  digitalWrite(righteye,HIGH);
  
  bh.attach(11);
  jh.attach(10);
  je.attach(12);
  be.attach(13);

  bh.write(basebh);
  jh.write(basejh);
  be.write(basebe);
  je.write(baseje);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  blink();
  if(Serial.available() > 0){
    bh.attach(11);
    jh.attach(10);
    je.attach(12);
    be.attach(13);
    command = Serial.parseInt();
    switch (command) {
    case 1:
      sit();
      break;
    case 2:
      forward();
      break;
    case 3:
      wink();
      break;
    case 4:
      backward();
      break;

     case 5:
      left();
      break;
    case 6:
      right();
      break;
      
    default:
      stand();
      break;
  }
  }
  
}


void serialEvent(){
  command = Serial.parseInt();
  Serial.println(Serial.readString());
 
}

void blink(){
   if(random(1,100000) > 99998){
    
      digitalWrite(lefteye,LOW);
      digitalWrite(righteye,LOW);
      delay(250);
      digitalWrite(lefteye,HIGH);
      digitalWrite(righteye,HIGH);
   }
}

void wink(){
  
      digitalWrite(lefteye,LOW);
      
      delay(500);
      digitalWrite(lefteye,HIGH);
      
}

void forward(){

    

  
  
  
  
}


void backward(){
  
}

void left(){
  
}

void right(){
  
}

void sit(){
  bh.write(basebh+45);
  jh.write(basejh-50);
 
}

void stand(){
  
  bh.write(basebh);
  jh.write(basejh);
  be.write(basebe);
  je.write(baseje);
  delay(250);
  bh.detach();
  jh.detach();
  je.detach();
  be.detach();
}



