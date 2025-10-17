#include <Servo.h>
#define CLK 11
#define DT 10

int counter = 20;
int currentStateCLK;
int lastStateCLK;
String currentDir = "";

Servo ESB;
Servo ESC; 

int Speed; 

void setup(){
  Serial.begin(9600);
ESB.attach(12,1000,2000);
ESC.attach(9,1000,2000);
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  lastStateCLK = digitalRead(CLK);
}

void loop(){

  // Read the current state of CLK
  currentStateCLK = digitalRead(CLK);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK != lastStateCLK && currentStateCLK == 1) {

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT) != currentStateCLK) {
      counter--;
      currentDir = "CCW";
    } else {
      // Encoder is rotating CW so increment
      counter++;
      currentDir = "CW";
    }

    Serial.print(" | Counter: ");
    Serial.println(counter);
  }

  // Remember last CLK state
  lastStateCLK = currentStateCLK;

  Speed = counter;
  ESB.write(Speed);
  ESC.write(Speed);
  delay(1);
}