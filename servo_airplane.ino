#include <Servo.h>
Servo leftwing;
Servo rightwing;
Servo backLeft;
Servo backRight;
int pos = 0;
const int SW_pin = 7;
const int X_pin = 2;
const int Y_pin = 3;
const int SW2_pin = 10; 
const int X2_pin = 0; 
const int Y2_pin = 1; 

void setup() {
  leftwing.attach(9);
  rightwing.attach(8);
   backLeft.attach(5);
    backRight.attach(6);
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
    pinMode(SW2_pin, INPUT);
  digitalWrite(SW2_pin, HIGH);
  Serial.begin(9600);
  leftwing.write(0);
  rightwing.write(0);
  backLeft.write(0);
  backRight.write(0);
}

void loop() {
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print(" | ");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X2_pin));
  Serial.print(" | ");
  Serial.print("Y-axis: ");
  Serial.print(analogRead(Y2_pin));
  Serial.println(" | ");
  delay(200);
  if(analogRead(Y2_pin)>=520){
leftwing.write(45);
rightwing.write(45);
backLeft.write(45);
backRight.write(45);
  }
  else if(analogRead(Y2_pin)<=500){
leftwing.write(135);
rightwing.write(135);
backLeft.write(135);
backRight.write(135);
  }
  else if(analogRead(X_pin)>=700){
leftwing.write(160);
rightwing.write(20);
  }
    else if(analogRead(X_pin)>=525){
leftwing.write(135);
rightwing.write(45);                
  }
  else if(analogRead(X_pin)<=254){
leftwing.write(20); 
rightwing.write(160);                    
  }
    else if(analogRead(X_pin)<=514){
leftwing.write(45);   
rightwing.write(135);                  
  }
 else{
  leftwing.write(90);
  rightwing.write(90);
 }
  }