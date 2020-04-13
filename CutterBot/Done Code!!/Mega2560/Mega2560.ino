#include <MemoryFree.h>
#include <EEPROM.h>
#include<AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
String inString;

void setup() {
  Serial.begin(115200);
  Serial3.begin(115200);
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
}

void loop() 
{
  
}

void serialEvent3() {
  while (Serial3.available()) {
    char inChar = Serial3.read();
    Serial.write(inChar);
    inString += inChar;
    if (inChar == ']') {
      if (inString.indexOf("[FORWARD]")>0) 
      { 
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        motor3.run(FORWARD);
        motor4.run(FORWARD);
      }
      else if (inString.indexOf("[BACKWARD]")>0) 
      {
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
        motor3.run(BACKWARD);
        motor4.run(BACKWARD);
      }
      else if (inString.indexOf("[RIGHT]")>0) 
      {
        motor3.run(FORWARD);
        motor4.run(FORWARD);
      }
      else if (inString.indexOf("[LEFT]")>0) 
      {
        motor1.run(FORWARD);
        motor2.run(FORWARD);
      }
      else if (inString.indexOf("[STOP]")>0) 
      {
        motor1.run();
        motor2.run();
        motor3.run();
        motor4.run();
      }
      inString = "";
    }
  }
}
