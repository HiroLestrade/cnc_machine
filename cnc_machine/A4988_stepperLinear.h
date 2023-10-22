#include "Arduino.h"

class A4988_stepperLinear {
  private:
    int _stepPin;
    int _dirPin;
    int _enablePin;
    int _screwSteps;
    float _screwLen;
    float _resolution;
    int _posSteps;
    float _pos;
    int _dir;

  public:
    static const int CLOCKWISE = 0;
    static const int C_CLOCKWISE = 1;
    A4988_stepperLinear(int stepPin, int dirPin, int enablePin, int screwSteps, float screwLen);
    void oneStep(int dir);
    String where();
};
