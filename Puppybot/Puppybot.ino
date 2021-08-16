#include "EarMethods.h"
#include "EyeMethods.h"

void setup() {
  SetupSystem();
  SetupEars();
  SetupEyes();
}

void loop(){
  SystemCycleStart();
  EarSwitch();
  EyesSwitch();


  CycleEndEars();
  CycleEndEyes();
}
