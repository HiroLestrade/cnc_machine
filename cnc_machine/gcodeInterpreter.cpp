#include "gcodeInterpreter.h"

float x, y, f, p;

void gcodeInterpreter(String instruction) {
  int command = getValue("G", instruction);
  switch (command) {
    case 0:
      x = getValue("X", instruction);
      y = getValue("Y", instruction);
      f = getValue("F", instruction);
      Serial.println("Move absolute to (X, Y): (" + String(x) + "," + String(y) + ")");
      break;
    case 1:
      x = getValue("X", instruction);
      y = getValue("Y", instruction);
      f = getValue("F", instruction);
      Serial.println("Move relarive to (X, Y): (" + (String)x + "," + (String)y + ")");
      break;
    case 2:
      Serial.println("Clockwise arc");
      break;
    case 3:
      Serial.println("Counter-clockwise arc");
      break;
    case 4:
      p = getValue("P", instruction);
      Serial.println("Do nothing for " + String(p) + " seconds");
      break;
    case 90:
      Serial.println("Absolute mode");
      break;
    case 91:
      Serial.println("Relative mode");
      break;
    case 92:
      x = getValue("X", instruction);
      y = getValue("Y", instruction);
      Serial.println("Change logical position to (X, Y): (" + String(x) + "," + String(y) + ")");
      break;
  }

  command = getValue("M", instruction);
  switch (command) {
    case 18:
      Serial.println("Turn off power to motors");
      break;
    case 100:
      help();
      break;
    case 114:
      Serial.println("Report position and feedrate");
      break;
  }
}

void help() {
  Serial.println("cnc_machine system");
  Serial.println("G00 [X] [Y] [F] - move in absolute mode");
  Serial.println("G01 [X] [Y] [F] - move in relative mode");
  Serial.println("G02 - clockwise arc");
  Serial.println("G03 - counter-clockwise arc");
  Serial.println("G04 [P] - do nothing for p seconds");
  Serial.println("G90 - absolute mode");
  Serial.println("G91 - relative mode");
  Serial.println("G92 [X] [Y] - change logical position");
  Serial.println("M18 - turn off power to motors");
  Serial.println("M100 - help");
  Serial.println("M114 - where");
}

float getValue(String key, String instruction) {
  int keyIndex = instruction.indexOf(key);

  if (keyIndex == -1) return -1;

  int endIndex = instruction.indexOf(" ", keyIndex);
  String value = instruction.substring(keyIndex + 1, endIndex);

  return value.toFloat();
}
