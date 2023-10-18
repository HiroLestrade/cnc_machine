//String gcode = "G00 X1.1 Y0.5 F2";

void setup() {
  Serial.begin(9600);
  //turn on motors
  Serial.println("Ready, waiting for instructions...");
}

void loop() {
  if (Serial.available()) {
    instruction = Serial.read();
    gcodeInterpreter(instruction);
    Serial.println("Ready, waiting for instructions...");
  }
}

void gcodeInterpreter(String instruction) {
  int command = getValue("G", instruction);
  switch (command) {
    case 0:
      float x = getValue("X", instruction);
      float y = getValue("Y", instruction);
      float f = getValue("F", instruction);
      Serial.println("Move absolute to (X, Y):" + "(" + String(x) + "," + String(y) + ")");
      break;
    case 1:
      float x = getValue("X", instruction);
      float y = getValue("Y", instruction);
      float f = getValue("F", instruction);
      Serial.println("Move relarive to (X, Y):" + "(" + String(x) + "," + String(y) + ")");
      break;
    case 2:
      Serial.println("Clockwise arc");
      break;
    case 3:
      Serial.println("Counter-clockwise arc");
      break;
    case 4:
      float p = getValue("P", instruction);
      Serial.println("Do nothing for " + String(P) + " seconds");
      break;
    case 90:
      Serial.println("Absolute mode");
      break;
    case 91:
      Serial.println("Relative mode");
      break;
    case 92:
      float x = getValue("X", instruction);
      float y = getValue("Y", instruction);
      Serial.println("Change logical position to (X, Y):" + "(" + String(x) + "," + String(y) + ")");
      break;
    default:
      Serial.println("No G instructions");
  }

  command = getValue("M", instruction);
  switch (command) {
    case 18:
      Serial.println("Turn off power to motors");
      break;
    case 100:
      Serial.println("Print out instructions for the human");
      break;
    case 114:
      Serial.println("Report position and feedrate");
      break;
    default:
      Serial.println("No M instructions");
  }
}

float getValue(String key, String instruction) {
  int keyIndex = instruction.indexOf(key);

  if (keyIndex == -1) return -1;

  int endIndex = instruction.indexOf(" ", keyIndex);
  String value = instruction.substring(keyIndex + 1, endIndex);

  return value.toFloat();
}
