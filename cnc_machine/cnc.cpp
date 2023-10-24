#include "cnc.h"

CNC::CNC() {

}

void CNC::setMotor_x(int stepPin, int dirPin, int enablePin, int steps, float screw) {
  _motor_x = A4988_stepperLinear(stepPin, dirPin, enablePin, steps, screw);
}

void CNC::setMotor_y(int stepPin, int dirPin, int enablePin, int steps, float screw) {
  _motor_y = A4988_stepperLinear(stepPin, dirPin, enablePin, steps, screw);
}

void CNC::setMotor_z(int stepPin, int dirPin, int enablePin, int steps, float screw) {
  _motor_z = A4988_stepperLinear(stepPin, dirPin, enablePin, steps, screw);
}

void CNC::line(int newx, int newy, int newz) {
  for (int i = 0; i < 50; i++) {
    _motor_x.oneStep(A4988_stepperLinear::CLOCKWISE);
    Serial.println(_motor_x.where());
  }
  delay(3000);
  for (int i = 0; i < 50; i++) {
    _motor_x.oneStep(A4988_stepperLinear::C_CLOCKWISE);
    Serial.println(_motor_x.where());
  }
  delay(3000);
}
