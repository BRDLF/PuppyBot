#ifndef EarDefines
#define EarDefines

#include <VarSpeedServo.h>

#define yawPinR A3
#define pitchPinR A2
#define rollPinR  A1

#define yawUp 10
#define pitchUp 16
//#define yawPinL A0
//#define pitchPinL 15
//#define rollPinL  14

bool is_going_to_move_ears;
uint16_t delay_ears = 0;
uint32_t timer_ears_last_active;

const uint16_t (*rightEar)[3] = NULL;
const uint16_t (*leftEar)[3] = NULL;

VarSpeedServo yawRight;
VarSpeedServo pitchRight;
VarSpeedServo rollRight;
VarSpeedServo yawLeft;
VarSpeedServo pitchLeft;
VarSpeedServo rollLeft;

enum earsState {NEUTRAL, TWITCH, FEAR}state_ears;

#endif
