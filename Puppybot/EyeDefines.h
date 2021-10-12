#ifndef EyeDefines
#define EyeDefines

#include <FastLED.h>

#define visorPin 9      //pin for Visor
#define kMH 8           //height
#define kMW 32          //width
#define kMM 256         //total LEDs

enum eyesState {STARE, BLINK, BLUSHEND, BLUSHHOLD, BLUSHSTART, SMILE} state_eyes;

CRGB leds[kMM];

uint16_t delay_eyes = 0;
uint32_t timer_last_active_eyes;
uint32_t delay_blink = 2100;

bool is_going_to_move_eyes;

//const uint16_t (*current_frame)[51][2] = NULL;
const uint32_t (*current_frame)[8] = NULL;

#endif
