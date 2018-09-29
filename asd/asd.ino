#include <SoftwareSerial.h>




SoftwareSerial HC05(0, 1);

void setup() 
{
  
}

void loop()
{

  if(HC05.available() >0){

    Serial.println(HC05.read());
    
  }


    
}


