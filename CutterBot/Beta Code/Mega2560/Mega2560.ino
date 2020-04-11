#include <MemoryFree.h>
#include <EEPROM.h>
#include<AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
String inString;
#define pin 24
void setup() {
  Serial.begin(115200);
  Serial3.begin(115200);
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  pinMode(pin,OUTPUT);
  digitalWrite(pin,LOW);
}

void loop() 
{
  
}

void serialEvent3() {
  digitalWrite(pin,LOW);
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
        motor1.run(RELEASE);
        motor2.run(RELEASE);
        motor3.run(FORWARD);
        motor4.run(FORWARD);
      }
      else if (inString.indexOf("[LEFT]")>0) 
      {
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        motor3.run(RELEASE);
        motor4.run(RELEASE);
      }
      else if (inString.indexOf("[STOP]")>0) 
      {
        motor1.run(RELEASE);
        motor2.run(RELEASE);
        motor3.run(RELEASE);
        motor4.run(RELEASE);
      }
      else if (inString.indexOf("[ON]")>0) 
      {
        digitalWrite(pin,HIGH);
      }
      else if (inString.indexOf("[OFF]")>0) 
      {
        digitalWrite(pin,LOW);
      }
      inString = "";
    }
  }
}
