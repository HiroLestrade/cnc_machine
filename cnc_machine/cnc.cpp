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

A4988_stepperLinear CNC::getMotorX() {
  return _motor_x;
}

A4988_stepperLinear CNC::getMotorY() {
  return _motor_y;
}

A4988_stepperLinear CNC::getMotorZ() {
  return _motor_z;
}

void CNC::line(int newx, int newy, int newz) {
  //Bresenham 3d algorithm
  _motor_x.enable();
  delay(5);

  int p1;
  int p2;

  int dx = newx - _motor_x.getPos();
  int dy = newy - _motor_y.getPos();
  int dz = newz - _motor_z.getPos();

  int xdir = dx > 0 ? 0 : 1;
  int ydir = dy > 0 ? 0 : 1;
  int zdir = dz > 0 ? 0 : 1;

  dx = abs(dx);
  dy = abs(dy);
  dz = abs(dz);

  if (dx >= dy && dx >= dz) {
    p1 = 2 * dy  - dx ;
    p2 = 2 * dz  - dx ;

    while (abs(newx - _motor_x.getPos()) >= _motor_x.getResolution()) {
      _motor_x.oneStep(xdir);
      if (p1 >= 0) {
        for (int i = 0; i < 3; i++) {
          _motor_y.oneStep(ydir);
        }
        p1 -= 2 * dx;
      }
      if (p2 >= 0) {
        for (int i = 0; i < 3; i++) {
          _motor_z.oneStep(zdir);
        }
        p2 -= 2 * dx;
      }
      p1 += 2 * dy;
      p2 += 2 * dz;
    }
  }

  else if (dy >= dx && dy >= dz) {
    p1 = 2 * dx - dy;
    p2 = 2 * dz - dy;

    int cont = 0;

    while (abs(newy - _motor_y.getPos()) >= _motor_y.getResolution()) {
      _motor_y.oneStep(ydir);
      if (p1 >= 0) {
        if (cont == 6) {
          _motor_x.oneStep(xdir);
          cont = 0;
        }
        p1 -= 2 * dy;
      }
      if (p2 >= 0) {

        _motor_z.oneStep(zdir);
        p2 -= 2 * dy;
      }
      p1 += 2 * dx;
      p2 += 2 * dz;

      cont++;
    }
  }

  else if (dz >= dx && dz >= dy) {
    p1 = 2 * dx - dz;
    p2 = 2 * dy - dz;

    int cont = 0;

    while (abs(newz - _motor_z.getPos()) >= _motor_z.getResolution()) {
      _motor_z.oneStep(zdir);
      if (p1 >= 0) {
        if (cont == 6) {
          _motor_x.oneStep(xdir);
        }
        p1 -= 2 * dz;
      }
      if (p2 >= 0) {
        _motor_y.oneStep(ydir);
        p2 -= 2 * dz;
      }
      p1 += 2 * dx;
      p2 += 2 * dy;
    }
    cont++;
  }

  _motor_x.disable();
}

void CNC::test() {
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
