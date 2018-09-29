/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo horizontal;
Servo vertical;
// create servo object to control a servo
// twelve servo objects can be created on most boards

int voltage = 0;
int threshold = 1000;



void setup() {
  Serial.begin(9600);    
  horizontal.attach(9);
  vertical.attach(10);


  horizontal.write(70);
  vertical.write(25);
}

void loop() {


    // read the input pin

  voltage = analogRead(3);
  Serial.println(voltage);
  

  if( voltage < threshold) {

    moveHorizontally();
  }

}


void moveHorizontally(){

    int angle = horizontal.read();
  
      
    
    if(angle >= 25 && angle <= 70){
      angle = angle - 10;
    }

     
    if(angle < 25){
  
      angle =  71;
       
    }
  
    if(angle > 70 ) {
  
      angle = angle + 10;
    }
  
    if(angle > 100) {
      angle = 70;
      moveVertically();
    
  }
horizontal.write(angle);



  
}
void moveVertically(){

    int angle = vertical.read();
  
      
    
    if(angle >= 0 && angle <= 25){
      angle = angle - 10;
    }

     
    if(angle < 0){
  
      angle =  26;
       
    }
  
    if(angle > 25 ) {
  
      angle = angle + 10;
    }
  
    if(angle > 65) {
      angle = 25;
     
    
  }
  vertical.write(angle);


}


