String gcode = "G00 X1.1 Y0.5 F2";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(parseNumber("M", gcode));
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

float getValue(String key, String cmmnd){
  int keyIndex = cmmnd.indexOf(key);

  if(keyIndex == -1) return -1;
  
  int endIndex = cmmnd.indexOf(" ", keyIndex);
  String value = cmmnd.substring(keyIndex + 1, endIndex);

  return value.toFloat();
}
