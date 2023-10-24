#include "A4988_stepperLinear.h"

A4988_stepperLinear::A4988_stepperLinear(){

}

A4988_stepperLinear::A4988_stepperLinear(int stepPin, int dirPin, int enablePin, int screwSteps, float screwLen) {
  _stepPin = stepPin;
  _dirPin = dirPin;
  _enablePin = enablePin;
  _screwSteps = screwSteps;             //[steps]
  _screwLen = screwLen;                 //[mm]
  _resolution = screwLen / screwSteps;  //[mm/step]
  _posSteps = 0;
  _pos = 0;
  _dir = A4988_stepperLinear::CLOCKWISE;

  pinMode(_stepPin, OUTPUT);
  pinMode(_dirPin, OUTPUT);
  pinMode(_enablePin, OUTPUT);

  digitalWrite(_enablePin, LOW);
};

void A4988_stepperLinear::oneStep(int dir) {
  digitalWrite(_dirPin, dir);

  digitalWrite(_stepPin, HIGH);
  delay(5);
  digitalWrite(_stepPin, LOW);
  delay(5);

  if (dir == A4988_stepperLinear::CLOCKWISE) {
    _posSteps++;
    _pos += _resolution;
  }
  else {
    _posSteps--;
    _pos -= _resolution;
  }
};

String A4988_stepperLinear::where(){
  return "Position:\t" + (String)_posSteps + " [steps]\t" + (String)_pos + " [mm]";
}
