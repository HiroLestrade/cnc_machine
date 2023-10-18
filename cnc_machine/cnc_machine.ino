//String gcode = "G00 X1.1 Y0.5 F2";

void setup() {
  Serial.begin(9600);
  //turn on motors
  Serial.println("Ready, waiting for instructions...");
}

void loop() {
  if(Serial.available()){
    instruction = Serial.read();
    gcodeInterpreter(instruction);
    Serial.println("Ready, waiting for instructions..."); 
  }
}

float getValue(String key, String cmmnd){
  int keyIndex = cmmnd.indexOf(key);

  if(keyIndex == -1) return -1;
  
  int endIndex = cmmnd.indexOf(" ", keyIndex);
  String value = cmmnd.substring(keyIndex + 1, endIndex);

  return value.toFloat();
}
