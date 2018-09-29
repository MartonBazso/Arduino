#include<Servo.h>

Servo serX;


String serialData;

void setup() {

  serX.attach(10);
 
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop() {
  // put your main code here, to run repeatedly:

}



void serialEvent(){



  serialData = Serial.readString();
  
  
  serX.write(serialData.toInt());
}

