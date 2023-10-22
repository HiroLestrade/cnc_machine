#include "gcodeInterpreter.h"

String instruction;

void setup() {
  Serial.begin(9600);
  //turn on motors
  Serial.println("Ready, waiting for instructions...");
}

void loop() {
  if (Serial.available()) {
    instruction = Serial.readString();
    gcodeInterpreter(instruction);
    Serial.println("Ready, waiting for instructions...");
  }
}
