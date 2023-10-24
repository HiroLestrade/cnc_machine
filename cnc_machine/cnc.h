#include "Arduino.h"
#include "A4988_stepperLinear.h"

class CNC {
  private:
    A4988_stepperLinear _motor_x;
    A4988_stepperLinear _motor_y;
    A4988_stepperLinear _motor_z;

  public:
    CNC();
    void setMotor_x(int stepPin, int dirPin, int enablePin, int steps, float screw);
    void setMotor_y(int stepPin, int dirPin, int enablePin, int steps, float screw);
    void setMotor_z(int stepPin, int dirPin, int enablePin, int steps, float screw);
    void line(int newx, int newy, int newz);
};
